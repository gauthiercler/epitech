package com.jcoinche.client;

import io.netty.channel.ChannelInitializer;
import io.netty.channel.socket.SocketChannel;

import io.netty.handler.codec.protobuf.ProtobufDecoder;
import io.netty.handler.codec.protobuf.ProtobufEncoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32FrameDecoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32LengthFieldPrepender;

public class ClientChannelInitializer extends ChannelInitializer<SocketChannel>{

	private Client client;

	ClientChannelInitializer(Client client) {
		this.client = client;
	}

    @Override
    public void initChannel(SocketChannel channel) throws Exception {

		channel.pipeline().addLast("frameEncoder", new ProtobufVarint32LengthFieldPrepender());
		channel.pipeline().addLast("protobufEncoder", new ProtobufEncoder());

		channel.pipeline().addLast(new ClientOutboundHandler());

		channel.pipeline().addLast("frameDecoder", new ProtobufVarint32FrameDecoder());
        channel.pipeline().addLast("protobufDecoder", new ProtobufDecoder(Request.ProtoRequest.getDefaultInstance()));

		channel.pipeline().addLast(new ClientInboundHandler(client));
//        channel.pipeline().addLast("stringEncoder", new StringEncoder(CharsetUtil.UTF_8));
//        channel.pipeline().addLast("stringDecoder", new StringDecoder(CharsetUtil.UTF_8));
    }
}
