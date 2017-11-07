package com.area.listeners;

import com.area.events.Event;

import java.lang.reflect.Method;

public class EventFactory {

    public static void onEvent(final Event event) {
        new Thread(() -> runEvent(event)).start();
    }

    public static void runEvent(final Event event) {
        for (EventManager.Handlers handler : EventManager.Handlers.values()) {
            for (Method method : handler.get().getMethods()) {
                EventHandler eventHandler = method.getAnnotation(EventHandler.class);
                if (eventHandler != null) {
                    Class[] params = method.getParameterTypes();

                    if (params.length != 1 || !event.getClass().getSimpleName().equals(params[0].getSimpleName()) || !event.getUser().isRegistered(event.getClass().getSimpleName(), eventHandler.name()))
                        continue;

                    try {
                        method.invoke(handler.get().newInstance(), event);
                    } catch (Exception e) {
                        System.err.println(e);
                    }
                }
            }
        }
    }
}
