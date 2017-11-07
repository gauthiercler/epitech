package com.jcoinche.client;

import java.util.Arrays;
import java.util.EnumMap;
import java.util.List;
import java.util.Map;

public class GameAttr {
    public enum Trump {
        ALL,
        NONE,
        SPADES,
        HEARTS,
        DIAMONDS,
        CLUBS
    }
    public enum TrumpType {
        ALL,
        NONE,
        TRUMP,
        NOTRUMP
    }
    public static final Map<TrumpType, List<Integer>> pointsTable;
    static {
        pointsTable = new EnumMap<>(TrumpType.class);
        pointsTable.put(TrumpType.ALL, Arrays.asList(0, 0, 9, 5, 14, 2, 3, 7));
        pointsTable.put(TrumpType.NONE, Arrays.asList(0, 0, 0, 10, 2, 3, 4, 19));
        pointsTable.put(TrumpType.TRUMP, Arrays.asList(0, 0, 14, 10, 20, 3, 4, 11));
        pointsTable.put(TrumpType.NOTRUMP, Arrays.asList(0, 0, 0, 10, 2, 3, 4, 11));
    }
}
