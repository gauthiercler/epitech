package com.area.pipeline;

import com.area.events.Event;
import com.area.events.FacebookEvent;
import com.area.events.facebook.*;
import com.area.listeners.EventFactory;
import com.area.repositories.UsersRepository;
import twitter4j.JSONArray;
import twitter4j.JSONObject;

public class FacebookPipeline {

    public enum FacebookPipelineEvents {
        ABOUT(FacebookAboutEvent.class),
        BIRTHDAY(FacebookBirthdayEvent.class),
        EMAIL(FacebookEmailEvent.class),
        FIRST_NAME(FacebookFirstNameEvent.class),
        LAST_NAME(FacebookLastNameEvent.class),
        LOCALE(FacebookLocaleEvent.class),
        PICTURE(FacebookPictureEvent.class),
        QUOTES(FacebookQuotesEvent.class),
        RELIGION(FacebookReligionEvent.class),
        STATUS(FacebookStatusEvent.class),
        WEBSITE(FacebookWebsiteEvent.class);

        private Class clazz = null;
        FacebookPipelineEvents(Class clazz) {
            this.clazz = clazz;
        }

        public Class get() {
            return this.clazz;
        }
    }

    public static void run(JSONArray changes, String uid) {
        for (int i = 0; i < changes.length(); i += 1) {
            try {
                JSONObject o = (JSONObject) changes.get(i);

                FacebookPipelineEvents type = FacebookPipelineEvents.valueOf(o.getString("field").toUpperCase());

                FacebookEvent event = (FacebookEvent) type.get().newInstance();
                ((Event) event).setUser(UsersRepository.findByFacebookUUID(uid));
                event.parse(o);

                if (((Event) event).isValid())
                    EventFactory.onEvent((Event) event);
            } catch (Exception e) {
                System.err.println("FacebookPipeline : " + e);
            }
        }
    }
}
