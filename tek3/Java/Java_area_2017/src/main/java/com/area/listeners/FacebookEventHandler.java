package com.area.listeners;

import com.area.events.Event;
import com.area.events.TwitterEvent;
import com.area.events.dropbox.DropboxFileAddedEvent;
import com.area.events.dropbox.DropboxFileRemovedEvent;
import com.area.events.dropbox.DropboxFolderCreatedEvent;
import com.area.events.twitter.TwitterStatusEvent;
import com.area.helpers.FacebookHelper;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import facebook4j.Facebook;
import facebook4j.FacebookFactory;
import facebook4j.auth.AccessToken;

public class FacebookEventHandler extends Event {

    @EventHandler(name = "facebookOnTweet")
    public void onTweet(TwitterStatusEvent event) {
        FacebookHelper.post(event.getUser(), event.getValue());
    }

    @EventHandler(name = "facebookOnDropboxAddedFile")
    public void onDropboxAddedFile(DropboxFileAddedEvent event) { FacebookHelper.post(event.getUser(), event.getValue()); }

    @EventHandler(name = "facebookOnDropboxCreatedFolderFile")
    public void onDropboxCreatedFolderFile(DropboxFolderCreatedEvent event) { FacebookHelper.post(event.getUser(), event.getValue()); }

    @EventHandler(name = "facebookOnDropboxRemovedFile")
    public void onDropboxRemovedFile(DropboxFileRemovedEvent event) { FacebookHelper.post(event.getUser(), event.getValue()); }

/*    @EventHandler
    public void onAddedFile(DropboxFileAddedEvent event) { FacebookHelper.post(event.getUser(), event.getValue()); } */
}
