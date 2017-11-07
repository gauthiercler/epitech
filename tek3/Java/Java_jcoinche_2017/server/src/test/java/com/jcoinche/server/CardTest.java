package com.jcoinche.server;

import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.*;

public class CardTest {
    @Test
    public void getnbPoints() throws Exception {
        Card test = new Card(Card.CardType.SPADES, Card.CardValue.ACE);
        Assert.assertEquals(11, test.getnbPoints(GameAttr.Trump.DIAMONDS));
    }

}