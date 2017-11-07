package com.area.stream;

import com.area.models.User;
import com.area.pipeline.TwitterPipeline;
import twitter4j.StallWarning;
import twitter4j.Status;
import twitter4j.StatusDeletionNotice;
import twitter4j.StatusListener;

public class TwitterListener implements StatusListener {

    private final User user;

    public TwitterListener (User user) {
        this.user = user;
    }

    @Override
    public void onStatus(Status status) {
        if (String.valueOf(status.getUser().getId()).equals(this.user.getTwitterID())) {
            TwitterPipeline.run(status, user);
        }
    }

    @Override
    public void onDeletionNotice(StatusDeletionNotice statusDeletionNotice) {

    }

    @Override
    public void onTrackLimitationNotice(int numberOfLimitedStatuses) {

    }

    @Override
    public void onScrubGeo(long userId, long upToStatusId) {

    }

    @Override
    public void onStallWarning(StallWarning warning) {

    }

    @Override
    public void onException(Exception ex) {

    }
}
