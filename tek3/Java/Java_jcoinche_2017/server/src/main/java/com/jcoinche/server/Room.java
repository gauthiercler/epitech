package com.jcoinche.server;

import java.util.*;
import java.util.function.Predicate;

public class Room {
    public static final int maxPlayers = 4;

    private ArrayList<Player>   players;
    private final int           id;
    private Game                game;

    public Room(int id) {
        players = new ArrayList<>();
        this.id = id;
    }

    public boolean addPlayer(Player player) throws Exception {
        if (this.getNbPlayers() < maxPlayers) {
            players.add(player);
            System.out.println("Added player w/ ID : " + player.getId());
            System.out.println("To room w/ ID : " + Integer.toString(this.getId()));
            if (this.getNbPlayers() == maxPlayers) {
                game = new Game(players);
                game.start();
            }
            return true;
        }
        return false;
    }

    public boolean  removePlayer(Player player) {
        return this.players.remove(player);
    }

    public Player       getPlayer(Player player) {
        Predicate<Player>   predicate = playerP -> playerP.getId().equals(player.getId());
        return this.players.stream().filter(predicate).findFirst().orElse(null);
    }

    public ArrayList<Player> getPlayers() {
        return this.players;
    }

    public int getId() { return this.id; }

    public int getNbPlayers() {
        return players.size();
    }

    public Game getGame() {
        return this.game;
    }
}
