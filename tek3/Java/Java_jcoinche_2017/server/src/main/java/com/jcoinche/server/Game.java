package com.jcoinche.server;

import java.util.*;
import java.util.function.Predicate;

public class Game {
    private ArrayList<Player>   players;
    private CardsGame           deck;
    private GameAttr.Trump      trump;
    private RequestBuilder      builder;

    private int                 playerTurn;
    private int                 broadcastCount;
    private boolean             broadcastState;
    private State               state;
    private Map<Player, Card>   table;
    private ArrayList<Team>     teams;

    public State getState() {
        return state;
    }

    public enum State {
        BET,
        FOLD,
        COUNTING
    }

    public Game(ArrayList<Player> players) {
        this.players = players;
        this.table = new HashMap<>();
        this.deck = new CardsGame();
        this.builder = new RequestBuilder();
        this.teams = new ArrayList<>();
        this.broadcastState = false;
    }

    public void disconnectPlayer(Player player) throws Exception {
        LobbyManager.getInstance().disconnectPlayer(player);
    }

    public void endGame() throws Exception {
        System.out.println("Game ended");
        for (Player player : this.players) {
            this.disconnectPlayer(player);
        }
    }

    public void initTeams() {
        for (Team team : this.teams) {
            team.setState(Team.TeamState.DEFENDER);
            team.setCoinche(false);
            team.setSurcoinche(false);
            team.resetScore();
        }
    }

    public void createTeams() {
        for (int i = 0; i < this.players.size() / 2; i++)
            this.teams.add(new Team());
    }

    public void startBetState() throws Exception {
        this.createTeams();
        this.initTeams();
        for (Player player : this.players)
            player.setBet(new Bet(0, GameAttr.BetType.NONE));
        this.state = State.BET;
        this.playerTurn = 0;
        this.deck.generate();
        this.deck.shuffle();
        this.giveCards();
        System.out.println(this.players.size() + " players in the room");
        this.askBet();
    }

    public void startFoldState() throws Exception {
        this.playerTurn = 0;
        this.state = State.FOLD;
        this.askCard();
    }

    public void giveNCards(int nbCards) {
        for (Player current : this.players) {
            for (int i = 0; i < nbCards; i++)
                current.addCard(this.deck.giveOne());
        }
    }

    public void giveCards() {
        this.giveNCards(3);
        this.giveNCards(2);
        this.giveNCards(3);
    }

    public void start() throws Exception {
        this.startBetState();
    }

    public void broadcastMessage(String message) throws Exception {
        this.broadcastState = true;
        for (Player player : players)
            this.sendRequest(player, builder.buildLogRequest(message));
    }

    public boolean getBroadcastState() {
        return this.broadcastState;
    }

    public void broadcastTick() throws Exception {
        this.broadcastCount += 1;
        if (broadcastCount == GameAttr.totalPlayers) {
            broadcastCount = 0;
            broadcastState = false;
            this.tick();
        }
    }

    boolean isEnded() {
        for (Team team : this.teams) {
            System.out.println("SCORES -> " + team.getScore());
            if (team.getScore() > GameAttr.scoreToWin)
                return true;
        }
        return false;
    }

    public void askCard() throws Exception {
        this.sendRequest(this.players.get(playerTurn), builder.buildListHandRequest(this.players.get(playerTurn).getHand()));
    }

    public void askCardTick() throws Exception {
        this.sendRequest(this.players.get(this.playerTurn), builder.buildAskCardRequest("~>   Choose the card to put on the table"));
    }

    public void askBet() throws Exception {
        this.sendRequest(this.players.get(playerTurn), builder.buildListHandRequest(this.players.get(playerTurn).getHand()));
    }

    public void askBetTick() throws Exception {
        this.sendRequest(this.players.get(this.playerTurn), builder.buildAskBetRequest("~>   Choose your bet"));
    }

    public void nextPlayer() {
        this.playerTurn += 1;
        this.playerTurn %= 4;
    }

    public boolean isHighestBet(int value) {
        Predicate<Player> predicate = elem -> elem.getBet() != null && elem.getBet().getValue() >= value;
        return players.stream().filter(predicate).count() == 0;
    }

    public boolean hasBet() {
        return players.stream().filter(elem -> elem.getBet().getValue() > 0).count() > 0;
    }

    public void chooseBet(Player player, Bet bet) throws Exception {
        if (!bet.isSpecialType()) {
            if (!this.isHighestBet(bet.getValue()) || bet.getValue() % 10 != 0 || bet.getValue() < 80) {
                this.sendRequest(player, builder.buildLogRequest("Invalid bet (min 80, multiple of 10 and higher than previous), try again"));
                return;
            }
        } else {
            bet.setValue(0);
            if (bet.getType() == GameAttr.BetType.COINCHE) {
                if (!this.hasBet()) {
                    this.sendRequest(player, builder.buildLogRequest("You can't coinche if no one has bet something"));
                    return ;
                }
                else if (this.getOpponent(player).isCoinche())
                    this.getTeam(player).setSurcoinche(true);
                else {
                    this.getTeam(player).setCoinche(true);
                }
            }
        }
        player.setBet(bet);
        this.nextPlayer();
        this.broadcastMessage("~>   Player " + this.players.indexOf(player) + " bet " + bet.getType() + "::" + bet.getValue());
    }

    public Player getTeamMate(Player player) {
        return this.players.get((players.indexOf(player) + 2) % 4);
    }

    public void playCard(Player player, Card card) throws Exception {
        if (!player.putCard(card)) {
            this.sendRequest(player, builder.buildLogRequest("Invalid card, try again"));
            return ;
        }
        this.table.put(player, card);
        this.nextPlayer();
        this.broadcastMessage("~>   Player " + this.players.indexOf(player) + " played " + card.getType() + "::" + card.getValue());
    }

    private Player getHighestBetPLayer() {
        Player highest = this.players.get(0);
        for (Player player : players) {
            if (player.getBet().getValue() > highest.getBet().getValue())
                highest = player;
        }
        return highest;
    }

    public boolean handsAreEmpty() {
        Predicate<Player> predicate = elem -> elem.getHandSize() > 0;
        return this.players.stream().filter(predicate).count() == 0;
    }

    public boolean hasSurcoinche() {
        for (Team team : this.teams) {
            if (team.isSurcoinche())
                return true;
        }
        return false;
    }

    public void tick() throws Exception {
        if (this.getState() == Game.State.BET) {
            Predicate<Player> predicate = elem -> elem.getBet() != null && elem.getBet().isSpecialType();
            long passedCount = this.players.stream().filter(predicate).count();
            if (passedCount == GameAttr.totalPlayers) {
                System.out.println("~>   Everyone passed, starting a new round");
                this.startBetState();
            } else if ((passedCount == GameAttr.totalPlayers - 1 && this.getHighestBetPLayer().getBet().getValue() > 0) || this.hasSurcoinche()) {
                Player highestPlayer = this.getHighestBetPLayer();
                this.trump = GameAttr.Trump.values()[highestPlayer.getBet().getType().ordinal()];
                this.getTeam(highestPlayer).setBet(highestPlayer.getBet());
                this.getTeam(highestPlayer).setState(Team.TeamState.ATTACKER);
                this.startFoldState();
            }
            else {
                this.askBet();
            }
        }
        else {
            if (this.table.size() == GameAttr.totalPlayers)
                this.assessTable();
            else if (this.handsAreEmpty()) {
                if (this.players.get(0).getHandSize() == 0) {
                    if (this.state != State.COUNTING)
                        this.assessRound();
                    if (this.isEnded())
                        this.endGame();
                    else
                        this.startBetState();
                } else
                    this.startFoldState();
            } else {
                this.askCard();

            }
        }
    }

    public void assessRound() throws Exception {
        this.state = State.COUNTING;
        Team attacker = this.getAttackerTeam();
        Team defender = this.getDefenderTeam();

        System.out.println("Attacker bet was => " + attacker.getBet().getValue());
        if (attacker.getScore() >= 82) {
            if (attacker.isSurcoinche())
                attacker.addTotalScore((attacker.getScore() + attacker.getBet().getValue()) * 4);
            else if (defender.isCoinche())
                attacker.addTotalScore((attacker.getScore() + attacker.getBet().getValue()) * 2);
            else
                attacker.addTotalScore(attacker.getScore() + attacker.getBet().getValue());
            defender.addTotalScore(defender.getScore());
        } else {
            if (attacker.isSurcoinche())
                defender.addTotalScore((162 + defender.getScore() + attacker.getBet().getValue()) * 4);
            else if (defender.isCoinche())
                defender.addTotalScore((162 + defender.getScore() + attacker.getBet().getValue()) * 2);
            else
                defender.addTotalScore(162 + defender.getScore() + attacker.getBet().getValue());
        }
        this.broadcastMessage("~>   Game ended\n~>   Attacker score: " + attacker.getTotalScore() + "\n~>   Defender score: " + defender.getTotalScore());
    }

    public Team getAttackerTeam() {
        return this.teams.stream().filter(elem -> elem.getState() == Team.TeamState.ATTACKER).findFirst().get();
    }

    public Team getDefenderTeam() {
        return this.teams.stream().filter(elem -> elem.getState() == Team.TeamState.DEFENDER).findFirst().get();
    }

    public void setPlayerTurn(Player player) {
        this.playerTurn = this.players.indexOf(player);
    }

    public void assessTable() throws Exception {
        int sum = 0;
        Map.Entry<Player, Card> winner = this.table.entrySet().iterator().next();
        for (Map.Entry<Player, Card> current : this.table.entrySet()) {
            if (current.getValue().getnbPoints(this.trump) > winner.getValue().getnbPoints(this.trump))
                winner = current;
            sum += current.getValue().getnbPoints(this.trump);
        }
        this.getTeam(winner.getKey()).addScore(sum);
        this.setPlayerTurn(winner.getKey());
        this.table.clear();
        this.broadcastMessage("~>   Player " + this.players.indexOf(winner.getKey()) + " won the round with " + sum + " points");
    }

    public Team getTeam(Player player) {
        return this.teams.get(this.players.indexOf(player) % 2);
    }

    public Team getOpponent(Player player) {
        return this.teams.get((this.players.indexOf(player) + 1) % 2);
    }

    public void sendRequest(Player player, Request.ProtoRequest request) throws Exception {
        player.setAwaitedResponse(Response.ProtoResponse.Type.valueOf(request.getType().toString()));
        player.getChannelContext().channel().writeAndFlush(request);
    }
}
