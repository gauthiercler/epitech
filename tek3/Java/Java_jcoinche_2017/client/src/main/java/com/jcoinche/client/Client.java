package com.jcoinche.client;

import io.netty.bootstrap.Bootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelOption;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.nio.NioSocketChannel;

public class Client {

    private String  host;
    private int     port;
    private ChannelFuture   serverChannel;
    private GameManager     gameManager;

    public static void main(String[] args) throws Exception {
        String  host = (args.length > 0 ? args[0] : "127.0.0.1");
        int     port = (args.length > 1 ? Integer.parseInt(args[1]) : 8080);

        Client client = new Client(host, port);
        if (client.connect()) { client.run();
        } else { System.out.println("Couldn't connect to server"); }
    }

    private Client(String host, int port) {
        this.host = host;
        this.port = port;
    }

    private boolean connect() {
        NioEventLoopGroup   handlerGroup = new NioEventLoopGroup(2);

        try {
            Bootstrap client = new Bootstrap();

            client.group(handlerGroup)
                    .channel(NioSocketChannel.class)
                    .handler(new ClientChannelInitializer(this))
                    .option(ChannelOption.SO_KEEPALIVE, true);

            System.out.println("~>   Connecting to " + this.host + "::" + this.port + " ...");
            this.serverChannel = client.connect(this.host, this.port);
        } catch (Exception error) {
            System.out.println("Client Connection Exception :: " + error.getMessage());
            return false;
        }
        System.out.println("~>   Successfully connected to server.\n");
        return true;
    }

    private void run() throws Exception {
        System.out.println("~>   Waiting for a coinche game to start...\n");
        this.gameManager = new GameManager(this.serverChannel);
        this.serverChannel.channel().closeFuture().sync();
    }

    public GameManager getGameManager() {
        return gameManager;
    }
}
