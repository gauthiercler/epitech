package com.jcoinche.server;

import java.util.ArrayList;

public class RequestBuilder {

	public Request.ProtoRequest		buildListHandRequest(ArrayList<Card> cards) {
		Request.ProtoRequest.Builder			requestBuilder = Request.ProtoRequest.newBuilder();
		Request.ProtoRequest.ListHand.Builder	listHandBuilder = Request.ProtoRequest.ListHand.newBuilder();

		requestBuilder.setType(Request.ProtoRequest.Type.LIST_HAND);
		System.out.println("Building hand for " + Integer.toString(cards.size()) + " cards");

		for (Card card : cards) {
			Request.ProtoRequest.Card.Builder	cardBuilder = Request.ProtoRequest.Card.newBuilder();

			cardBuilder.setType(Request.ProtoRequest.CardType.valueOf(card.getType().toString()));
			cardBuilder.setValue(Request.ProtoRequest.CardValue.valueOf(card.getValue().toString()));
			listHandBuilder.addCards(cardBuilder);
		}
		requestBuilder.setListHand(listHandBuilder);
		return requestBuilder.build();
	}

	public Request.ProtoRequest		buildAskCardRequest(String message) {
		Request.ProtoRequest.Builder			requestBuilder = Request.ProtoRequest.newBuilder();
		Request.ProtoRequest.AskCard.Builder	askCardBuilder = Request.ProtoRequest.AskCard.newBuilder();

		requestBuilder.setType(Request.ProtoRequest.Type.ASK_CARD);

		askCardBuilder.setMessage(message);
		requestBuilder.setAskCard(askCardBuilder);
		return requestBuilder.build();
	}

	public Request.ProtoRequest		buildAskBetRequest(String message) {
		Request.ProtoRequest.Builder			requestBuilder = Request.ProtoRequest.newBuilder();
		Request.ProtoRequest.AskBet.Builder		askBetBuilder = Request.ProtoRequest.AskBet.newBuilder();

		requestBuilder.setType(Request.ProtoRequest.Type.ASK_BET);

		askBetBuilder.setMessage(message);
		requestBuilder.setAskBet(askBetBuilder);
		return requestBuilder.build();
	}

	public Request.ProtoRequest		buildLogRequest(String message) {
		Request.ProtoRequest.Builder			requestBuilder = Request.ProtoRequest.newBuilder();
		Request.ProtoRequest.Log.Builder		logBuilder = Request.ProtoRequest.Log.newBuilder();

		requestBuilder.setType(Request.ProtoRequest.Type.LOG);

		logBuilder.setMessage(message);
		requestBuilder.setLog(logBuilder);
		return requestBuilder.build();
	}
}
