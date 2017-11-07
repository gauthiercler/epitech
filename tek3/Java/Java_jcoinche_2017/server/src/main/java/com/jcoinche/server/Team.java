package com.jcoinche.server;

public class Team {
    private int score;
    private int totalScore;
    private boolean coinche;
    private boolean surcoinche;
    private Bet     bet;
    private TeamState state;

    public TeamState getState() {
        return state;
    }

    public void setState(TeamState state) {
        this.state = state;
    }

    public void addTotalScore(int nb) {
        this.totalScore += nb;
    }

    public int getTotalScore() {
        return this.totalScore;
    }

    public boolean isCoinche() {
        return coinche;
    }

    public void setCoinche(boolean coinche) {
        this.coinche = coinche;
    }

    public boolean isSurcoinche() {
        return surcoinche;
    }

    public void setSurcoinche(boolean surcoinche) {
        this.surcoinche = surcoinche;
    }

    public enum TeamState {
        ATTACKER,
        DEFENDER
    }

    public Team() {
        score = 0;
        coinche = false;
        surcoinche = false;
        state = TeamState.DEFENDER;
        totalScore = 0;
    }

    public int getScore() {
        return score;
    }

    public void resetScore() {
        this.score = 0;
    }

    public void addScore(int score) {
        this.score += score;
    }

    public Bet getBet() {
        return bet;
    }

    public void setBet(Bet bet) {
        this.bet = bet;
    }
}
