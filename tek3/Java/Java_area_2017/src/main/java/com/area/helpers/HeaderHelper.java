package com.area.helpers;

import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_OK;

public class HeaderHelper {

    public static void type(Request request, Response response)
    {
        response.type("application/json");
        response.status(HTTP_OK);
    }

    public static String options(Request request, Response response)
    {
        String accessControlRequestHeaders = request
                .headers("Access-Control-Request-Headers");
        if (accessControlRequestHeaders != null) {
            response.header("Access-Control-Allow-Headers",
                    accessControlRequestHeaders);
        }

        String accessControlRequestMethod = request
                .headers("Access-Control-Request-Method");
        if (accessControlRequestMethod != null) {
            response.header("Access-Control-Allow-Methods",
                    accessControlRequestMethod);
        }

        return "ok";
    }

    public static void AccessControllOrigin(Request request, Response response) {
        response.header("Access-Control-Allow-Origin", "*");
    }
}
