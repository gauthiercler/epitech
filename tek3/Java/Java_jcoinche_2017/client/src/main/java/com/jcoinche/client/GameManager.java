package com.jcoinche.client;

import io.netty.channel.ChannelFuture;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.concurrent.locks.ReentrantLock;
import java.util.regex.Pattern;

public class GameManager {

	private Scanner			inputScanner;
	private ResponseBuilder	responseBuilder;
	private ArrayList<Card>	hand;
	private ChannelFuture	serverChannel;
	private ReentrantLock	lock;

	public GameManager(ChannelFuture serverChannel) {
		this.serverChannel = serverChannel;
		this.inputScanner = new Scanner(System.in);
		this.responseBuilder = new ResponseBuilder();
		this.hand = new ArrayList<>();
		this.lock = new ReentrantLock();
	}

	public String	getUserInput() {
		return inputScanner.nextLine();
	}

	public void 	sendResponse(Response.ProtoResponse response) throws Exception {
		this.serverChannel.channel().writeAndFlush(response);
	}

	public void 	receiveHand(Request.ProtoRequest request) throws Exception {
		this.hand.clear();
		System.out.println("~>   Your hand   <~\n");
		for (Request.ProtoRequest.Card card : request.getListHand().getCardsList()) {
			System.out.println(card.getType() + " :: " + card.getValue());
			this.hand.add(new Card(Card.CardType.valueOf(card.getType().toString()), Card.CardValue.valueOf(card.getValue().toString())));
		}
		System.out.println("");
		this.sendResponse(this.responseBuilder.buildListHandResponse());
	}

	public void 	playCard(Request.ProtoRequest request) throws Exception {
		System.out.println(request.getAskCard().getMessage());

		String		input;
		String[]	cardPlay;

		do {
			input = this.getUserInput().replaceAll("\\n\\r", "");
		} while (!this.isValidCardPlay(input));

		cardPlay = input.split("\\s");
		this.sendResponse(this.responseBuilder.buildAskCardResponse(Response.ProtoResponse.CardType.valueOf(cardPlay[0]), Response.ProtoResponse.CardValue.valueOf(cardPlay[1])));
	}

	public void 	askBet(Request.ProtoRequest request) throws Exception {
		System.out.println(request.getAskBet().getMessage());

		String		input;
		String[]	betPlay;

		do {
			input = this.getUserInput().replace("\\n\\r", "");
		} while (!this.isValidBet(input));

		betPlay = input.split("\\s");
		this.sendResponse(this.responseBuilder.buildAskBetResponse((betPlay.length == 1 ? 0 : Integer.parseInt(betPlay[1])), Response.ProtoResponse.BetType.valueOf(betPlay[0])));
	}

	public void 	assessLog(Request.ProtoRequest request) throws Exception {
		System.out.println(request.getLog().getMessage());
		this.sendResponse(this.responseBuilder.buildLogResponse());
	}

	private boolean	isValidCardPlay(String input) {
		if (!Pattern.matches("(SPADES|HEARTS|DIAMONDS|CLUBS)\\s+(SEVEN|EIGHT|NINE|TEN|JACK|QUEEN|KING|ACE)", input)) {
			return false;
		}
		String[]	cardPlay = input.split("\\s");
		for (Card card : this.hand) {
			if (card.getType() == Card.CardType.valueOf(cardPlay[0]) && card.getValue() == Card.CardValue.valueOf(cardPlay[1])) {
				return true;
			}
		}
		return false;
	}

	private boolean	isValidBet(String input) {
		return Pattern.matches("(COINCHE|PASS)|(ALL|NONE|SPADE|HEART|DIAMOND|CLUB)\\s+[0-9]+", input);
	}

	public ReentrantLock getLock() {
		return lock;
	}
}
