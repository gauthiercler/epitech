package com.area.stream;

import com.area.models.User;
import com.area.repositories.UsersRepository;
import twitter4j.TwitterStream;
import twitter4j.TwitterStreamFactory;
import twitter4j.auth.AccessToken;

import java.util.List;

public class TwitterListenerFactory {

    private static List<User> users;

    public static void setup() {
        users = UsersRepository.findAll();

        for (User user : users) {
            if (user.getTwitterAccessToken() != null && user.getTwitterAccessTokenSecret() != null)
                createListener(user);
        }
    }

    public static void createListener(User user) {
        TwitterStream stream = TwitterStreamFactory.getSingleton();

        if (user.getTwitterAccessToken() != null && user.getTwitterAccessTokenSecret() != null &&
                !user.getTwitterAccessToken().equals("null") && !user.getTwitterAccessTokenSecret().equals("null"))
        {
            try {
                stream.setOAuthAccessToken(new AccessToken(user.getTwitterAccessToken(), user.getTwitterAccessTokenSecret()));
                stream.addListener(new TwitterListener(user));
                stream.user();
            } catch (Exception e) {
                System.err.println(e);
            }
        }
    }
}
