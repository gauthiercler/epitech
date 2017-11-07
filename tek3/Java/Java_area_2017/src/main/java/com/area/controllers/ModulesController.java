package com.area.controllers;

import com.area.helpers.Parameters;
import com.area.helpers.Serializer;
import com.area.models.User;
import com.area.parameters.ModuleParameters;
import com.area.repositories.UsersModulesRepository;
import com.area.repositories.UsersRepository;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_NOT_FOUND;

public class ModulesController {

    public static String enable(Request request, Response response)
    {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        ModuleParameters parameters = Parameters.fill(request, response, ModuleParameters.class);

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        if (parameters == null)
            return "";
        if (!UsersModulesRepository.listening(user, parameters.getListener(), parameters.getHandler()))
            UsersModulesRepository.listen(user, parameters.getListener(), parameters.getHandler());
        return "";
    }

    public static String disable(Request request, Response response)
    {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
        ModuleParameters parameters = Parameters.fill(request, response, ModuleParameters.class);

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        if (parameters == null)
            return "";
        UsersModulesRepository.unlisten(user, parameters.getListener(), parameters.getHandler());
        return "";
    }

    public static String index(Request request, Response response) {
        User user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

        if (user == null) {
            response.status(HTTP_NOT_FOUND);
            return "";
        }
        return Serializer.toJson(UsersModulesRepository.find(user));
    }
}
