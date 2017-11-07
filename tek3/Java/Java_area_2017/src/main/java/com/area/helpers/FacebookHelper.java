package com.area.helpers;

import com.area.models.User;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import facebook4j.Facebook;
import facebook4j.FacebookException;
import facebook4j.FacebookFactory;
import facebook4j.auth.AccessToken;

public class FacebookHelper {
    public static String getUserId(String accessToken) {
        Facebook facebook = FacebookFactory.getSingleton();

        facebook.setOAuthAccessToken(new AccessToken(accessToken, null));
        try {
            return facebook.getMe().getId();
        } catch (FacebookException ignored) {
        }
        return null;
    }

    public static void post(User user, String value) {
        Facebook facebook = FacebookFactory.getSingleton();

        facebook.setOAuthPermissions("email,publish_actions");
        facebook.setOAuthAccessToken(new AccessToken(user.getFacebookAccessToken(), null));
        try {
            String fullid = facebook.postStatusMessage(value);
            String id = fullid.substring(0, fullid.indexOf("_"));
            LogsRepository.getInstance().addLog(new Log(Log.Type.FACEBOOK, id));
        } catch (Exception e) {
            System.err.println(e);
        }
    }
}
