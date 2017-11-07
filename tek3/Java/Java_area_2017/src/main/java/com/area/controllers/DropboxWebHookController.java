package com.area.controllers;

import com.area.pipeline.DropboxPipeline;
import org.json.JSONArray;
import org.json.JSONObject;
import spark.Request;
import spark.Response;

public class DropboxWebHookController {

	public static String	confirm(Request request, Response response) {
		System.out.println("In DropboxWHC :: confirm");
		return request.queryParams("challenge");
	}

	public static String	callback(Request request, Response response) {
		System.out.println("Body : " + request.body());

		try {
			JSONObject	body = new JSONObject(request.body());
			JSONObject	listFolder = body.getJSONObject("list_folder");
			JSONArray	users = listFolder.getJSONArray("accounts");

			DropboxPipeline.run(users);

		} catch (Exception e) {
			System.err.println("DropboxWebHook : " + e.getMessage());
		}
		System.out.println("In dropbox callback");
		return request.queryParams("challenge");
	}
}
