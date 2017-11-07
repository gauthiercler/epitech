package com.jcoinche.server;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelOutboundHandlerAdapter;
import io.netty.channel.ChannelPromise;

public class ServerOutboundHandler extends ChannelOutboundHandlerAdapter {

    private Server      server;

    ServerOutboundHandler(Server server) { this.server = server; }

    @Override
    public void write(ChannelHandlerContext context, Object message, ChannelPromise promise) {
//        System.out.println("Trying to send : " + message);
        try {
        	context.writeAndFlush(message).sync();
		} catch (Exception e) {
        	System.out.println("Got Exception in write OutboundHandler :: " + e.getMessage());
		}
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext context, Throwable cause) {
        cause.printStackTrace();
        context.close();
    }
}
