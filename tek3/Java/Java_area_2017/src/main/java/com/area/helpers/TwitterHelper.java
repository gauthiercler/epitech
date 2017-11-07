package com.area.helpers;

import com.area.models.User;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import twitter4j.Status;
import twitter4j.Twitter;
import twitter4j.TwitterException;
import twitter4j.TwitterFactory;
import twitter4j.auth.AccessToken;

public class TwitterHelper {
    public static String getUserId(String accessToken, String secretToken) {
        Twitter twitter = TwitterFactory.getSingleton();

        twitter.setOAuthAccessToken(new AccessToken(accessToken, secretToken));
        try {
            return String.valueOf(twitter.getId());
        } catch (TwitterException e) {
        }
        return null;
    }

    public static void post(User user, String value) {
        Twitter twitter = TwitterFactory.getSingleton();

        twitter.setOAuthAccessToken(new AccessToken(user.getTwitterAccessToken(), user.getTwitterAccessTokenSecret()));
        try {
            Status tweet = twitter.updateStatus(value);
            LogsRepository.getInstance().addLog(new Log(Log.Type.TWITTER, tweet.getId()));
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
