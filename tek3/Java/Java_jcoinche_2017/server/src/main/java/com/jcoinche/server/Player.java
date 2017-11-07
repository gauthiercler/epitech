package com.jcoinche.server;

import io.netty.channel.ChannelHandlerContext;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Set;

public class Player {
    private int score;
    private ChannelHandlerContext	channelContext; // TODO :: Server method to flush remvoed Context regularly in case of abrupt disconnection
	private Response.ProtoResponse.Type		awaitedResponse;
    private Bet bet;
    private ArrayList<Card> hand;
    public static final int maxCardsByHand = 8;

    public void addCard(Card card) {
        if (hand.size() < maxCardsByHand)
            hand.add(card);
    }

    public Player(ChannelHandlerContext channelContext) {
        this.channelContext = channelContext;
        this.awaitedResponse = Response.ProtoResponse.Type.VOID;
        this.hand = new ArrayList<>();
        this.score = 0;
    }

    public Player() {
        this.channelContext = null;
        this.awaitedResponse = Response.ProtoResponse.Type.VOID;
        this.hand = new ArrayList<>();
        this.score = 0;
    }

    public ArrayList<Card> getHand() {
        return this.hand;
    }

    public int getHandSize() {
        return hand.size();
    }

    public void addScore(int scoreToAdd) {
        score += scoreToAdd;
    }

    public int getScore() {
        return score;
    }

    public void setBet(Bet bet) {
        this.bet = bet;
    }

    public Bet getBet() {
        return bet;
    }

    public String getId() {
        return this.channelContext.channel().id().asLongText();
    }

    public ChannelHandlerContext getChannelContext() {
    	return this.channelContext;
	}

    public boolean hasCard(Card card) {
        return hand.stream().anyMatch(p -> p.equals(card));
    }

    public boolean putCard(Card card) {
        return hand.remove(card);
    }

	public Response.ProtoResponse.Type getAwaitedResponse() {
		return awaitedResponse;
	}

	public void setAwaitedResponse(Response.ProtoResponse.Type awaitedResponse) {
		this.awaitedResponse = awaitedResponse;
	}
}
