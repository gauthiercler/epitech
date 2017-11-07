package com.area.controllers;

import com.area.helpers.Parameters;
import com.area.helpers.TwitterHelper;
import com.area.models.User;
import com.area.parameters.TwitterAssociateParameters;
import com.area.repositories.UsersRepository;
import com.area.stream.TwitterListener;
import com.area.stream.TwitterListenerFactory;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_NOT_FOUND;

public class TwitterController {
    public static String associate(Request request, Response response)
    {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        TwitterAssociateParameters parameters = Parameters.fill(request, response, TwitterAssociateParameters.class);

        if (parameters == null)
            return "";
        else if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        user.setTwitterAccessToken(parameters.getAccessToken());
        user.setTwitterAccessTokenSecret(parameters.getAccessTokenSecret());
        user.setTwitterID(TwitterHelper.getUserId(user.getTwitterAccessToken(), user.getTwitterAccessTokenSecret()));
        UsersRepository.commit(user);
        if (user.getTwitterAccessToken() != null && user.getTwitterAccessTokenSecret() != null)
            TwitterListenerFactory.createListener(user);
        TwitterListenerFactory.createListener(user);
        return "";
    }

    public static String disassociate(Request request, Response response) {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        user.setTwitterAccessToken(null);
        user.setTwitterAccessTokenSecret(null);
        user.setTwitterID(null);
        UsersRepository.commit(user);
        return "";
    }
}
