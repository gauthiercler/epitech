package com.area.helpers;


import com.fasterxml.jackson.databind.ObjectMapper;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_BAD_REQUEST;
import static java.net.HttpURLConnection.HTTP_INTERNAL_ERROR;
import static jdk.nashorn.internal.runtime.regexp.joni.Config.log;

public class Parameters
{
    public interface requestParameter {
        boolean isValid();
    }

    public static <T extends requestParameter> T fill(Request request, Response response, Class<T> type)
    {
        try {
            ObjectMapper mapper = new ObjectMapper();
            T parameters = mapper.readValue(request.body(), type);
            if (!parameters.isValid()) {
                response.status(HTTP_BAD_REQUEST);
                return null;
            }
            return parameters;
        } catch (Exception e) {
            response.status(HTTP_INTERNAL_ERROR);
            log.println(e.getMessage());
            return null;
        }
    }
}
