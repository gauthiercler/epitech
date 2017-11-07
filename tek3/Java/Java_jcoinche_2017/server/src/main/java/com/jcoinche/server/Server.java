package com.jcoinche.server;

import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelOption;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.nio.NioServerSocketChannel;

import java.util.ArrayList;
import java.util.concurrent.atomic.AtomicInteger;

public class Server {

    private int				port;
    private LobbyManager    lobbyManager;

    public static void main(String[] args) throws Exception {
        int port = (args.length > 0 ? Integer.parseInt(args[0]) : 8080);

        new Server(port).run();
    }

    private Server(int port) {
    	this.port = port;
    	this.lobbyManager = LobbyManager.getInstance();
    }

    private void run() throws Exception {
        NioEventLoopGroup   acceptorGroup = new NioEventLoopGroup(2);
        NioEventLoopGroup   handlerGroup = new NioEventLoopGroup(10);

        try {
            ServerBootstrap     server = new ServerBootstrap();
            server.group(acceptorGroup, handlerGroup)
                    .channel(NioServerSocketChannel.class)
                    .childHandler(new ServerChannelInitializer(this))
                    .option(ChannelOption.SO_BACKLOG, 128)
                    .childOption(ChannelOption.SO_KEEPALIVE, true);

            ChannelFuture futureHandle = server.bind(port).sync();
            futureHandle.channel().closeFuture().sync();
            System.out.println("Server started on port {" + Integer.toString(port) + "}");
        } catch (Exception error) {
            System.out.println("Got exception in ServerBoostrap :: " + error.getMessage());
        } finally {
            acceptorGroup.shutdownGracefully();
            handlerGroup.shutdownGracefully();
        }
    }

	public LobbyManager getLobbyManager() { return this.lobbyManager; }
}
