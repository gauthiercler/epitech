package com.area.controllers;

import com.area.helpers.MailDeliver;
import com.area.helpers.Parameters;
import com.area.helpers.Serializer;
import com.area.models.User;
import com.area.parameters.EmailParameters;
import com.area.parameters.UserUpdateParameters;
import com.area.repositories.UsersRepository;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_FORBIDDEN;
import static java.net.HttpURLConnection.HTTP_NOT_FOUND;
import static java.net.HttpURLConnection.HTTP_OK;

public class UsersController {

    public static String index(Request request, Response response)
    {
        response.status(HTTP_OK);
        return Serializer.toJson(UsersRepository.findAll());
    }

    public static String get(Request request, Response response) {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        } else {
            response.status(HTTP_OK);
            return Serializer.toJson(user);
        }
    }

    public static String delete(Request request, Response response) {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        MailDeliver.getInstance().sendTo(user.getEmail(), "[AREA] Good Bye !",
                "Au revoir " + user.getUsername() + " !");
        UsersRepository.delete(user);
        response.status(HTTP_OK);
        return "";
    }

    public static String update(Request request, Response response)
    {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        User client = UsersRepository.findByToken(request.headers("token"));

        UserUpdateParameters parameters = Parameters.fill(request, response, UserUpdateParameters.class);
        if (user == null || client == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        } else if (parameters == null)
            return "";
        if (!client.hasRole("ADMIN")) // Only admin have enough rights to change user's roles
            parameters.setRoles(null);
        UsersRepository.update(user, parameters);
        return "";
    }

    public static String email(Request request, Response response)
    {
        User client = UsersRepository.findByToken(request.headers("token"));
        EmailParameters param = Parameters.fill(request, response, EmailParameters.class);

        if (client == null || param == null) {
            response.status(HTTP_NOT_FOUND);
            return ("");
        }
        UsersRepository.sendMail(param.getSubject(), param.getMessage());
        response.status(HTTP_OK);
        return ("");
    }

}
