package com.jcoinche.client;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelPromise;
import io.netty.channel.ChannelOutboundHandlerAdapter;

public class ClientOutboundHandler extends ChannelOutboundHandlerAdapter {

    @Override
    public void write(ChannelHandlerContext context, Object message, ChannelPromise promise) throws Exception {
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
