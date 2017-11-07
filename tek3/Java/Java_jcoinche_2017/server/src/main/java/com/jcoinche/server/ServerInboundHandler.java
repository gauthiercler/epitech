package com.jcoinche.server;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.SimpleChannelInboundHandler;

import java.util.ArrayList;
import java.util.Objects;

public class ServerInboundHandler extends SimpleChannelInboundHandler<Response.ProtoResponse> {

    private Server      server;

    ServerInboundHandler(Server server) { this.server = server; }

    @Override
    public void handlerAdded(ChannelHandlerContext context) throws Exception {
    	this.server.getLobbyManager().getLock().lock();
    	try {
			this.server.getLobbyManager().assignPlayer(this.server.getLobbyManager().getPlayerManager().addPlayer(context));
		} finally {
    		this.server.getLobbyManager().getLock().unlock();
		}
	}

    @Override
    public void handlerRemoved(ChannelHandlerContext context) throws Exception {
    	this.server.getLobbyManager().getLock().lock();
    	try {

			System.out.println("In handler removed for player w/ id : " + context.channel().id().asLongText());

			Player	player = this.server.getLobbyManager().getPlayerManager().getPlayerById(context.channel().id().asLongText());
			Room	room = this.server.getLobbyManager().getRoomManager().getRoomWithPlayer(player);

			if (room != null) {
				ArrayList<Player> roomPlayers = room.getPlayers();

				this.server.getLobbyManager().getRoomManager().removeRoom(room);
				for (Player roomPlayer : roomPlayers) {
					if (!roomPlayer.getId().equals(player.getId())) {
						this.server.getLobbyManager().disconnectPlayer(roomPlayer);
					}
				}
				this.server.getLobbyManager().disconnectPlayer(player);
			}
		} finally {
    		this.server.getLobbyManager().getLock().unlock();
		}
    }

    @Override
    public void channelRead0(ChannelHandlerContext context, Response.ProtoResponse message) throws Exception {
    	this.server.getLobbyManager().getLock().lock();
    	try {
			Player player = this.server.getLobbyManager().getPlayerManager().getPlayerById(context.channel().id().asLongText());

			System.out.println("Got response of type : " + message.getType() + " from client w/ ID : " + player.getId());
			System.out.println("Waiting message of type " + player.getAwaitedResponse().toString());
			switch (message.getType()) {
				// TODO :: Verify functions and send wrong command to client
				case LIST_HAND:
					this.server.getLobbyManager().assessListCardResponse(player, message);
					break;
				case ASK_CARD:
					this.server.getLobbyManager().assessAskCardResponse(player, message);
					break;
				case ASK_BET:
					this.server.getLobbyManager().assessAskBetResponse(player, message);
					break;
				case LOG:
					this.server.getLobbyManager().assessLogResponse(player, message);
					break;

			}
		} finally {
    		this.server.getLobbyManager().getLock().unlock();
		}
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext context, Throwable cause) {
        cause.printStackTrace();
        context.close();
    }

}
