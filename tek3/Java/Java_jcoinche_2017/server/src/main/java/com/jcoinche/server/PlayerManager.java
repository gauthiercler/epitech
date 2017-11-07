package com.jcoinche.server;

import io.netty.channel.ChannelHandlerContext;

import java.util.ArrayList;
import java.util.function.Predicate;

public class PlayerManager {

	private ArrayList<Player> players;

	public PlayerManager() {
		this.players = new ArrayList<>();
	}

	public Player		addPlayer(ChannelHandlerContext channelContext) {
		Player			player =  new Player(channelContext);
		this.players.add(player);
		System.out.println("Created player w/ ID : " + player.getId());
		return player;
	}

	public Player		getPlayer(Player player) {
		return this.players.get(this.players.indexOf(player));
	}

	public Player		getPlayerById(String id) {
		Predicate<Player>	predicate = player -> player.getId().equals(id);
		return this.players.stream().filter(predicate).findFirst().orElse(null);
	}

	public boolean		deletePlayer(Player player) {
		System.out.println("Deleted player w/ ID : " + player.getId());
		return this.players.remove(player);
	}

	public boolean		deletePlayerById(String id) {
		Predicate<Player>	predicate = player -> player.getId().equals(id);
		return this.deletePlayer(this.players.stream().filter(predicate).findFirst().orElse(null));
	}
}
