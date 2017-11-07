package com.jcoinche.client;

public class Card {
    public enum CardType {
        SPADES,
        HEARTS,
        DIAMONDS,
        CLUBS
    }
    public enum CardValue {
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    }
    private CardType type;
    private CardValue value;

    public Card(CardType type, CardValue value) {
        this.type = type;
        this.value = value;
    }

    public CardType getType() {
        return type;
    }

    public CardValue getValue() {
        return value;
    }

    public int getnbPoints(GameAttr.Trump trump) {
        if (trump == GameAttr.Trump.ALL || trump == GameAttr.Trump.NONE)
            return GameAttr.pointsTable.get(GameAttr.TrumpType.valueOf(trump.toString())).get(this.value.ordinal());
        if (trump.toString().equals(this.type.toString()))
            return GameAttr.pointsTable.get(GameAttr.TrumpType.TRUMP).get(this.value.ordinal());
        return GameAttr.pointsTable.get(GameAttr.TrumpType.NOTRUMP).get(this.value.ordinal());
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof Card))
            return false;
        Card card = (Card)obj;
        return card.getType() == this.type && card.getValue() == this.getValue();
    }

    @Override
    public int hashCode() {
        return type.hashCode();
    }
}
