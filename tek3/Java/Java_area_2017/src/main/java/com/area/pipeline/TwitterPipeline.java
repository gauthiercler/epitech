package com.area.pipeline;

import com.area.events.twitter.TwitterStatusEvent;
import com.area.listeners.EventFactory;
import com.area.models.User;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import twitter4j.StallWarning;
import twitter4j.Status;
import twitter4j.StatusDeletionNotice;
import twitter4j.StatusListener;

public class TwitterPipeline {

    public static void run(Status status, User user) {
        LogsRepository logsRepository = LogsRepository.getInstance();

        if (!logsRepository.contains(new Log(Log.Type.TWITTER, status.getId()))) {
            logsRepository.addLog(new Log(Log.Type.TWITTER, status.getId()));
            TwitterStatusEvent event = new TwitterStatusEvent();

            event.setUser(user);
            event.setValue(status.getText());
            EventFactory.onEvent(event);
        }

    }

}
