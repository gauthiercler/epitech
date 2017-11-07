package com.area.controllers;

import com.area.helpers.MailDeliver;
import com.area.helpers.Parameters;
import com.area.helpers.Serializer;
import com.area.models.User;
import com.area.parameters.LoginParameters;
import com.area.parameters.RegisterParameters;
import com.area.repositories.UsersRepository;
import com.area.responses.TokenResponse;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.*;
import static spark.Spark.externalStaticFileLocation;
import static spark.Spark.halt;

public class SecurityController
{

    public static String login(Request request, Response response)
    {
        LoginParameters parameters = Parameters.fill(request, response, LoginParameters.class);
        TokenResponse tokenResponse = new TokenResponse();

        if (parameters == null)
            return "";
        User user = UsersRepository.login(parameters.getUsername(), parameters.getPassword());
        if (user == null) {
            response.status(HTTP_FORBIDDEN);
            return "";
        }
        response.status(HTTP_OK);
        tokenResponse.setId(user.getId());
        tokenResponse.setToken(user.getToken());
        return Serializer.toJson(tokenResponse);
    }

    public static String register(Request request, Response response)
    {
        RegisterParameters parameters = Parameters.fill(request, response, RegisterParameters.class);
        TokenResponse tokenResponse = new TokenResponse();

        if (parameters == null)
            return "";
        if (UsersRepository.findByUsername(parameters.getUsername()) != null) {
            response.status(HTTP_CONFLICT);
            return "";
        }
        User user = UsersRepository.create(parameters);
        if (user == null) {
            response.status(HTTP_INTERNAL_ERROR);
            return "";
        }
        response.status(HTTP_OK);
        tokenResponse.setId(user.getId());
        tokenResponse.setToken(user.getToken());
        UsersRepository.commit(user);
        MailDeliver.getInstance().sendTo(user.getEmail(), "[AREA] Welcome",
                "Bienvenue " + user.getUsername() + " ! :D\nVoici votre password : " + user.getPassword());
        return Serializer.toJson(tokenResponse);
    }

    public static void isConnected(Request request, Response response) {
        if (UsersRepository.findByToken(request.headers("token")) == null)
            halt(HTTP_FORBIDDEN, "");
    }

    public static void isAdmin(Request request, Response response) {
        if (request.requestMethod().equals("OPTIONS"))
            return ;

        User user = UsersRepository.findByToken(request.headers("token"));
        if (user == null || !user.hasRole("ADMIN"))
            halt(HTTP_FORBIDDEN, "");
    }


    public static void isAdminOrOwner(Request request, Response response)
    {
        if (request.requestMethod().equals("OPTIONS"))
            return ;
        User user = null;
        User owner = null;
        try {
            user = UsersRepository.findByToken(request.headers("token"));
            owner = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        } catch (Exception e) {
            System.out.println("An error occurred cause by non existing userId. Please check that before action isAdminOrOwner is only used with an :userId given with url");
            halt(HTTP_INTERNAL_ERROR, "");
        }
        if (user == null || owner == null || (!user.hasRole("ADMIN") && user != owner))
            halt(HTTP_FORBIDDEN, "");
    }
}
