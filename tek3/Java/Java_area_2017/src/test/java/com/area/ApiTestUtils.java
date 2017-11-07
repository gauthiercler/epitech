package com.area;

import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.util.EntityUtils;
import org.json.JSONObject;

public class ApiTestUtils {

	public static JSONObject createUser(CloseableHttpClient client, String username, String password) throws Exception {
		HttpPost postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"" + username + "\",\n\t\"password\": \"" + password + "\",\n\t\"email\": \"emailRegisterDuplicate@email.com\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponse = client.execute(postRequest);
		String					responseBody = EntityUtils.toString(httpResponse.getEntity());

		return new JSONObject(responseBody);
	}

	public static JSONObject connectUser(CloseableHttpClient client, String username, String password) throws Exception {
		HttpPost postRequest = new HttpPost("http://localhost:4567/login");
		String			jsonRequest = "{\n\t\"username\": \"" + username + "\",\n\t\"password\": \"" + password + "\"\n}";
		StringEntity body = new StringEntity(jsonRequest);

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponse = client.execute(postRequest);
		String					responseBody = EntityUtils.toString(httpResponse.getEntity());

		return new JSONObject(responseBody);
	}

	public static JSONObject getUser(CloseableHttpClient client, int id) throws Exception {
		HttpGet getRequest = new HttpGet("http://localhost:4567/user/" + Integer.toString(id));

		JSONObject admin = ApiTestUtils.connectUser(client, "root", "root");
		getRequest.setHeader("Content-Type", "application/json");
		getRequest.setHeader("token", admin.get("token").toString());

		CloseableHttpResponse	httpResponse = client.execute(getRequest);
		return new JSONObject(EntityUtils.toString(httpResponse.getEntity()));
	}
}
