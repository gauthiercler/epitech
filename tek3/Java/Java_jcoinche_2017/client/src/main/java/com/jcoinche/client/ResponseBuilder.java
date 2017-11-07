package com.jcoinche.client;

public class ResponseBuilder {

	public Response.ProtoResponse	buildListHandResponse() {
		Response.ProtoResponse.Builder			responseBuilder = Response.ProtoResponse.newBuilder();
		Response.ProtoResponse.ListHand.Builder	listHandBuilder = Response.ProtoResponse.ListHand.newBuilder();

		responseBuilder.setType(Response.ProtoResponse.Type.LIST_HAND);
		listHandBuilder.setMessage("OK");
		responseBuilder.setListHand(listHandBuilder);
		return responseBuilder.build();
	}

	public Response.ProtoResponse	buildAskCardResponse(Response.ProtoResponse.CardType cardType, Response.ProtoResponse.CardValue cardValue) {
		Response.ProtoResponse.Builder			responseBuilder = Response.ProtoResponse.newBuilder();
		Response.ProtoResponse.AskCard.Builder	askCardBuilder = Response.ProtoResponse.AskCard.newBuilder();
		Response.ProtoResponse.Card.Builder		cardBuilder = Response.ProtoResponse.Card.newBuilder();

		responseBuilder.setType(Response.ProtoResponse.Type.ASK_CARD);

		cardBuilder.setType(cardType);
		cardBuilder.setValue(cardValue);
		askCardBuilder.setCard(cardBuilder);
		responseBuilder.setAskCard(askCardBuilder);
		return responseBuilder.build();
	}

	public Response.ProtoResponse	buildAskBetResponse(int amount, Response.ProtoResponse.BetType betType) {
		Response.ProtoResponse.Builder			responseBuilder = Response.ProtoResponse.newBuilder();
		Response.ProtoResponse.AskBet.Builder	askBetBuilder = Response.ProtoResponse.AskBet.newBuilder();
		Response.ProtoResponse.Bet.Builder		betBuilder = Response.ProtoResponse.Bet.newBuilder();

		responseBuilder.setType(Response.ProtoResponse.Type.ASK_BET);

		betBuilder.setAmout(amount);
		betBuilder.setType(betType);
		askBetBuilder.setBet(betBuilder);
		responseBuilder.setAskBet(askBetBuilder);
		return responseBuilder.build();
	}

	public Response.ProtoResponse	buildLogResponse() {
		Response.ProtoResponse.Builder		responseBuilder = Response.ProtoResponse.newBuilder();
		Response.ProtoResponse.Log.Builder	logBuilder = Response.ProtoResponse.Log.newBuilder();

		responseBuilder.setType(Response.ProtoResponse.Type.LOG);
		logBuilder.setMessage("OK");
		responseBuilder.setLog(logBuilder);
		return responseBuilder.build();
	}
}
