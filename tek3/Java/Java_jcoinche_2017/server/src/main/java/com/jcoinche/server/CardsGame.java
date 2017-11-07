package com.jcoinche.server;

import java.util.Collections;
import java.util.LinkedList;

public class CardsGame {
    private LinkedList<Card> deck;

    public CardsGame() {
        this.deck = new LinkedList<>();
    }

    public void generate() {
        for (Card.CardValue value : Card.CardValue.values()) {
            for (Card.CardType type : Card.CardType.values()) {
                deck.add(new Card(type, value));
            }
        }
    }

    public void shuffle() {
        Collections.shuffle(deck);
    }

    public Card giveOne() {
        return deck.pop();
    }

    public boolean isEmpty() {
        return deck.isEmpty();
    }

    public int getSize() {
        return deck.size();
    }

    public LinkedList<Card> getDeck() {
        return new LinkedList<>(deck);
    }
}
