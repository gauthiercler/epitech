package com.area.controllers;

import com.area.pipeline.FacebookPipeline;
import spark.Request;
import spark.Response;
import twitter4j.JSONArray;
import twitter4j.JSONObject;

public class FacebookWebHookController {

    public static String test(Request request, Response response) {
        return request.queryParams("hub.challenge");
    }

    public static String callback(Request request, Response response) {
        System.out.println(request.body());
        try {
            JSONObject obj = new JSONObject(request.body());
            JSONArray data = obj.getJSONArray("entry")
                    .getJSONObject(0)
                    .getJSONArray("changes");
            String uid = obj.getJSONArray("entry").getJSONObject(0).getString("uid");
            FacebookPipeline.run(data, uid);
        } catch (Exception e) {
            System.err.println("FacebookWebHook : " + e);
        }

        return request.queryParams("hub.challenge");
    }
}
