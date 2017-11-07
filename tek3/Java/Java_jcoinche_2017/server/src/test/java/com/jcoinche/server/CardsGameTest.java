package com.jcoinche.server;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.LinkedList;

public class CardsGameTest {

    private CardsGame deck;

    @Before
    public void setup() {
        deck = new CardsGame();
    }

    @Test
    public void getSize() throws Exception {
        deck.generate();
        Assert.assertEquals(Card.CardType.values().length * Card.CardValue.values().length, deck.getSize());
    }

    @Test
    public void generate() throws Exception {
        deck.generate();
        Assert.assertEquals(deck.isEmpty(), false);
    }

    @Test
    public void shuffle() throws Exception {
        deck.generate();
        LinkedList<Card> copy = deck.getDeck();
        deck.shuffle();
        LinkedList<Card> shuffle = deck.getDeck();
        int count = 0;
        for (int idx = 0; idx < deck.getSize(); idx++) {
            Card first = copy.get(idx);
            Card second = shuffle.get(idx);
            if (first.getType() == second.getType() && first.getValue() == second.getValue())
                break;
        }
        Assert.assertNotEquals(count, deck.getSize());
    }

    @Test
    public void giveOne() throws Exception {
        deck.generate();
        int size = deck.getSize();
        deck.giveOne();
        Assert.assertEquals(deck.getSize(), size - 1);
    }

    @Test
    public void isEmpty() throws Exception {
        deck.generate();
        int size = deck.getSize();
        for (int i = 0; i < size; i++)
            deck.giveOne();
        Assert.assertEquals(deck.isEmpty(), true);
    }

}