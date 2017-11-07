package com.area.listeners;

import java.util.ArrayList;
import java.util.List;

public class EventManager {

    public static enum Handlers {

        FACEBOOK(FacebookEventHandler.class),
        TWITTER(TwitterEventHandler.class);

        private Class handler;
        Handlers(Class clazz) {
            this.handler = clazz;
        }

        public Class get() {
            return this.handler;
        }

    }
}
