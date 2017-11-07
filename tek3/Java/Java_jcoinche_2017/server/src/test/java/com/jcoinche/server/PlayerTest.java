package com.jcoinche.server;

import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

import java.util.List;
import java.util.Set;

public class PlayerTest {

    private Player player;

    @Before
    public void setUp() {
        player = new Player();
    }

    @Test
    public void getScore() throws Exception {
    }

    @Test
    public void setBet() throws Exception {
    }

    @Test
    public void getBet() throws Exception {
    }

    @Test
    public void getId() throws Exception {
    }

    @Test
    public void putCard() throws Exception {
        Card card = new Card(Card.CardType.SPADES, Card.CardValue.EIGHT);
        player.addCard(card);
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.SEVEN));
        player.putCard(card);
        Assert.assertEquals(player.getHandSize(), 1);
    }

    @Test
    public void hasCard() throws Exception {
        Card card = new Card(Card.CardType.SPADES, Card.CardValue.EIGHT);
        player.addCard(card);
        Assert.assertEquals(player.hasCard(card), true);
        Card fake = new Card(Card.CardType.SPADES, Card.CardValue.SEVEN);
        Assert.assertEquals(player.hasCard(fake), false);
    }

    @Test
    public void addScore() throws Exception {
        player.addScore(100);
        Assert.assertEquals(player.getScore(), 100);
    }

    @Test
    public void getHandSize() throws Exception {
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.EIGHT));
        Assert.assertEquals(player.getHandSize(), 1);
    }

    @Test
    public void addCard() throws Exception {
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.JACK));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.ACE));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.TEN));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.NINE));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.EIGHT));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.SEVEN));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.KING));
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.QUEEN));
        player.addCard(new Card(Card.CardType.HEARTS, Card.CardValue.KING));
        Assert.assertEquals(player.getHandSize(), 8);
    }

    @Test
    public void getHand() throws Exception {
        player.addCard(new Card(Card.CardType.SPADES, Card.CardValue.EIGHT));
        List<Card> hand = player.getHand();
        Assert.assertEquals(hand.size(), 1);
    }

}