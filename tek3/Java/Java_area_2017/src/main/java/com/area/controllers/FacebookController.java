package com.area.controllers;

import com.area.helpers.FacebookHelper;
import com.area.helpers.Parameters;
import com.area.models.User;
import com.area.parameters.FacebookAssociateParameters;
import com.area.repositories.UsersRepository;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_NOT_FOUND;

public class FacebookController {

    public static String associate(Request request, Response response)
    {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        FacebookAssociateParameters parameters = Parameters.fill(request, response, FacebookAssociateParameters.class);

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        } else if (parameters == null)
            return "";
        user.setFacebookAccessToken(parameters.getAccessToken());
        user.setFacebookUUID(FacebookHelper.getUserId(parameters.getAccessToken()));
        UsersRepository.commit(user);
        return "";
    }

    public static String disassociate(Request request, Response response) {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        user.setFacebookAccessToken(null);
        user.setFacebookUUID(null);
        UsersRepository.commit(user);
        return "";
    }
}
