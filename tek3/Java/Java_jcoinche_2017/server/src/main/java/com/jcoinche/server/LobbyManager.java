package com.jcoinche.server;

import java.util.concurrent.locks.ReentrantLock;

public class LobbyManager {

	private static LobbyManager instance;
	private PlayerManager	playerManager;
	private RoomManager		roomManager;
	private RequestBuilder	requestBuilder;
	private ReentrantLock	lock;

	public static LobbyManager getInstance() {
		if (instance == null)
			instance = new LobbyManager();
		return instance;
	}

	private LobbyManager() {
		this.playerManager = new PlayerManager();
		this.roomManager = new RoomManager();
		this.requestBuilder = new RequestBuilder();
		this.lock = new ReentrantLock();
	}

	public PlayerManager	getPlayerManager() { return this.playerManager; }
	public RoomManager		getRoomManager() { return this.roomManager; }
	public RequestBuilder getRequestBuilder() { return requestBuilder; }

	public void				assignPlayer(Player player) throws Exception {
		Room	room = this.getRoomManager().getAvailableRoom();

		if (room == null) {
			room = this.getRoomManager().createRoom();
		}
		room.addPlayer(player);
	}

	public boolean			assignPlayerToRoom(Player player, Room room) throws Exception {
		return this.roomManager.getRoom(room).addPlayer(player);
	}

	public void				disconnectPlayer(Player player) throws Exception {
		System.out.println("Disconnecting player w/ ID : " + player.getId());
		player.getChannelContext().writeAndFlush("Bye-Bye");
		player.getChannelContext().disconnect().sync();
		System.out.println("After disconnect sync");

		this.playerManager.deletePlayer(player);
		System.out.println("After delete player in disconnect");
	}

	public void				disconnectPlayerById(String id) throws Exception {
		this.disconnectPlayer(this.getPlayerManager().getPlayerById(id));
	}

	public boolean			assessListCardResponse(Player player, Response.ProtoResponse response) throws Exception {
		System.out.println("In assessListCardResponse");
		if (response.getType() != player.getAwaitedResponse()) {
			System.out.println("Got wrong response type : " + response.getType() + " from client w/ ID : " + player.getId());
			return false;
		}
		Game game = this.getRoomManager().getRoomWithPlayer(player).getGame();
		if (game.getState() == Game.State.BET)
			game.askBetTick();
		else
			game.askCardTick();
		return (response.hasListHand() && response.getListHand().getMessage().equals("OK"));
	}

	public boolean			assessAskCardResponse(Player player, Response.ProtoResponse response)  throws Exception {
		System.out.println("In assessCardResponse");
		System.out.println("Got card play : " + response.getAskCard().getCard().getType() + "::" + response.getAskCard().getCard().getValue());
		if (response.getType() != player.getAwaitedResponse()) {
			System.out.println("Got wrong response type : " + response.getType() + " from client w/ ID : " + player.getId());
			return false;
		}
		Card card = new Card(Card.CardType.valueOf(response.getAskCard().getCard().getType().toString()),
				Card.CardValue.valueOf(response.getAskCard().getCard().getValue().toString()));
		this.getRoomManager().getRoomWithPlayer(player).getGame().playCard(player, card);
		return true;
	}

	public boolean			assessAskBetResponse(Player player, Response.ProtoResponse response) throws Exception {
		System.out.println("In assessAskBetResponse");
		if (response.getType() != player.getAwaitedResponse()) {
			System.out.println("Got wrong response type : " + response.getType() + " from client w/ ID : " + player.getId());
			return false;
		}
		Bet bet = new Bet(response.getAskBet().getBet().getAmout(), GameAttr.BetType.valueOf(response.getAskBet().getBet().getType().toString()));
		this.getRoomManager().getRoomWithPlayer(player).getGame().chooseBet(player, bet);
		return true;
	}

	public boolean			assessLogResponse(Player player, Response.ProtoResponse response) throws Exception {
		System.out.println("In assessLogResponse");
		if (response.getType() != player.getAwaitedResponse()) {
			System.out.println("Got wrong response type : " + response.getType() + " from client w/ ID : " + player.getId());
			return false;
		}
		Game game = this.getRoomManager().getRoomWithPlayer(player).getGame();
		if (game.getBroadcastState())
			game.broadcastTick();
		else
			game.tick();
		return (response.hasLog() && response.getLog().getMessage().equals("OK"));
	}

	public void 		sendRequest(Player player, Request.ProtoRequest request) throws Exception {
		player.getChannelContext().channel().writeAndFlush(request).sync();
	}

	public ReentrantLock getLock() {
		return lock;
	}
}
