package com.jcoinche.server;

public class Bet {
    private int value;
    private GameAttr.BetType type;

    public int getValue() {
        return value;
    }

    public GameAttr.BetType getType() {
        return type;
    }

    public void setValue(int value) {
        this.value = value;
    }

    boolean isSpecialType() {
        return this.type == GameAttr.BetType.COINCHE || this.type == GameAttr.BetType.PASS;
    }

    public Bet(int value, GameAttr.BetType type) {
        this.value = value;
        this.type = type;
    }
}
