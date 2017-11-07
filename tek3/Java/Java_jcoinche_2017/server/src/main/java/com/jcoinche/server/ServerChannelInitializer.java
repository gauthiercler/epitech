package com.jcoinche.server;

import io.netty.channel.ChannelInitializer;
import io.netty.channel.socket.SocketChannel;
import io.netty.handler.codec.LengthFieldBasedFrameDecoder;
import io.netty.handler.codec.protobuf.ProtobufDecoder;
import io.netty.handler.codec.protobuf.ProtobufEncoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32FrameDecoder;
import io.netty.handler.codec.protobuf.ProtobufVarint32LengthFieldPrepender;
import io.netty.handler.codec.string.StringDecoder;
import io.netty.handler.codec.string.StringEncoder;
import io.netty.util.CharsetUtil;

public class ServerChannelInitializer extends ChannelInitializer<SocketChannel>{

    private Server      server;

    ServerChannelInitializer(Server server) { this.server = server; }

    @Override
    public void initChannel(SocketChannel channel) throws Exception {
        channel.pipeline().addLast("frameDecoder", new ProtobufVarint32FrameDecoder());
        channel.pipeline().addLast("protobufDecoder", new ProtobufDecoder(Response.ProtoResponse.getDefaultInstance()));

        // TODO :: Put encoder back below after
        channel.pipeline().addLast("frameEncoder", new ProtobufVarint32LengthFieldPrepender());
        channel.pipeline().addLast("protobufEncoder", new ProtobufEncoder());


//        channel.pipeline().addLast("stringEncoder", new StringEncoder(CharsetUtil.UTF_8));
        channel.pipeline().addLast(new ServerInboundHandler(this.server));




        channel.pipeline().addLast(new ServerOutboundHandler(this.server));

//        channel.pipeline().addLast("stringDecoder", new StringDecoder(CharsetUtil.UTF_8));
    }
    
}
