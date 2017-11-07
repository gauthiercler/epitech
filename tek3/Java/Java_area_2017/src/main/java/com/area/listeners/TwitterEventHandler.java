package com.area.listeners;

import com.area.events.Event;
import com.area.events.dropbox.DropboxFileAddedEvent;
import com.area.events.dropbox.DropboxFileRemovedEvent;
import com.area.events.dropbox.DropboxFolderCreatedEvent;
import com.area.events.facebook.*;
import com.area.helpers.TwitterHelper;

public class TwitterEventHandler extends Event {

    @EventHandler(name = "twitterOnFacebookEvent")
    public void onAboutEvent(FacebookAboutEvent event) { TwitterHelper.post(event.getUser(), "About me : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookBirthdayBirthday")
    public void onBirthdayFacebook(FacebookBirthdayEvent event) { TwitterHelper.post(event.getUser(), "Birthday : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookEmail")
    public void onEmailFacebook(FacebookEmailEvent event) { TwitterHelper.post(event.getUser(), "Here is my new email on facebook : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookFistName")
    public void onFirstNameFacebook(FacebookFirstNameEvent event) {TwitterHelper.post(event.getUser(), "My firstname is : " + event.getValue());}

    @EventHandler(name = "twitterOnFacebookLastName")
    public void onLastNameFacebook(FacebookLastNameEvent event) { TwitterHelper.post(event.getUser(), "My lastname is : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookPicture")
    public void onPictureFacebook(FacebookPictureEvent event) { TwitterHelper.post(event.getUser(), "Posted picture on facebook : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookReligion")
    public void onReligionFacebook(FacebookReligionEvent event) { TwitterHelper.post(event.getUser(), "My religion : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookQuote")
    public void onQuotesFacebook(FacebookQuotesEvent event) { TwitterHelper.post(event.getUser(), "Favorite quote : " + event.getValue()); }

    @EventHandler(name = "twitterOnFacebookStatus")
    public void onStatusFacebook(FacebookStatusEvent event) {
        System.out.println("===== ON STATUS FACEBOOK EVENT TWITTER =====");
        TwitterHelper.post(event.getUser(), event.getValue()); }

    @EventHandler(name = "twitterOnFacebookWebsite")
    public void onWebsiteFacebook(FacebookWebsiteEvent event) { TwitterHelper.post(event.getUser(), "Added my website on facebook : " + event.getValue()); }

    @EventHandler(name = "twitterOnDropboxAddedFile")
    public void onDropboxAddedFile(DropboxFileAddedEvent event) { TwitterHelper.post(event.getUser(), event.getValue()); }

	@EventHandler(name = "twitterOnDropboxCreatedFolderFile")
	public void onDropboxCreatedFolderFile(DropboxFolderCreatedEvent event) { TwitterHelper.post(event.getUser(), event.getValue()); }

    @EventHandler(name = "twitterOnDropboxRemovedFile")
    public void onDropboxRemovedFile(DropboxFileRemovedEvent event) { TwitterHelper.post(event.getUser(), event.getValue()); }
}
