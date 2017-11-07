package com.jcoinche.client;

import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.SimpleChannelInboundHandler;

public class ClientInboundHandler extends SimpleChannelInboundHandler<Request.ProtoRequest> {

	private Client client;

	public ClientInboundHandler(Client client) {
		this.client = client;
	}

	@Override
	public void handlerRemoved(ChannelHandlerContext context) {
		System.out.println("~>   You have been disconnected by the server.");
		ChannelFuture future = context.channel().close();
		future.addListener((ChannelFutureListener) future_l -> System.exit(0));
	}

    @Override
    public void channelRead0(ChannelHandlerContext context, Request.ProtoRequest message) throws Exception {
		this.client.getGameManager().getLock().lock();
		try {
			switch (message.getType()) {
				case LIST_HAND:
					this.client.getGameManager().receiveHand(message);
					break;
				case ASK_CARD:
					this.client.getGameManager().playCard(message);
					break;
				case ASK_BET:
					this.client.getGameManager().askBet(message);
					break;
				case LOG:
					this.client.getGameManager().assessLog(message);
					break;
			}
		} finally {
			this.client.getGameManager().getLock().unlock();
		}
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext context, Throwable cause) {
        cause.printStackTrace();
        context.close();
    }
}
