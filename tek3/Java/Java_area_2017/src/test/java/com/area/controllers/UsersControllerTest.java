package com.area.controllers;

import com.area.ApiTestUtils;
import com.area.Router;
import com.area.TestInitializer;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpDelete;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.json.JSONArray;
import org.json.JSONObject;
import org.junit.*;
import spark.Spark;

import java.util.ArrayList;

import static java.net.HttpURLConnection.HTTP_FORBIDDEN;
import static java.net.HttpURLConnection.HTTP_NOT_FOUND;
import static java.net.HttpURLConnection.HTTP_OK;
import static org.junit.Assert.*;

public class UsersControllerTest extends TestInitializer {

	private CloseableHttpClient		httpClient = HttpClients.custom().build();

	@Test
	public void		getUsers() throws Exception {
		HttpGet		getRequest = new HttpGet("http://localhost:4567/users");
		JSONArray	users;
		int			statusCode;

		getRequest.setHeader("Content-Type", "application/json");
		getRequest.setHeader("token", admin.get("token").toString());

		CloseableHttpResponse	httpResponse = this.httpClient.execute(getRequest);
		String					responseBody = EntityUtils.toString(httpResponse.getEntity());

		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_OK, statusCode);

		users = new JSONArray(responseBody);
		JSONObject	user = users.getJSONObject(0);
		assertEquals(1, user.get("id"));
		assertEquals("root", user.get("username"));
	}

	@Test
	public void		getUser() throws Exception {
		HttpGet		getRequest = new HttpGet("http://localhost:4567/user/1");
		JSONObject	user;
		int			statusCode;

		getRequest.setHeader("Content-Type", "application/json");
		System.out.println("Admin token : " + admin.get("token").toString());
		getRequest.setHeader("token", admin.get("token").toString());

		CloseableHttpResponse	httpResponse = this.httpClient.execute(getRequest);
		String					responseBody = EntityUtils.toString(httpResponse.getEntity());

		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_OK, statusCode);

		user = new JSONObject(responseBody);
		assertEquals(1, user.get("id"));
		assertEquals("root", user.get("username"));
	}

	@Test
	public void		getNonExistentUser() throws Exception {
		HttpGet		getRequest = new HttpGet("http://localhost:4567/user/1238381");
		int			statusCode;

		getRequest.setHeader("Content-Type", "application/json");
		getRequest.setHeader("token", admin.get("token").toString());

		CloseableHttpResponse	httpResponse = this.httpClient.execute(getRequest);

		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_FORBIDDEN, statusCode);
	}

/*	@Test
	public void		deleteUser() throws Exception {
		JSONObject	user = ApiTestUtils.createUser(this.httpClient, "deleteUser", "deleteUser");

		JSONObject	addedUser = ApiTestUtils.getUser(this.httpClient, Integer.parseInt(user.get("id").toString()));
		assertEquals(user.get("id"), addedUser.get("id"));

		System.out.println("Delete request : http://localhost:4567/user/" + addedUser.get("id").toString());
		HttpDelete	deleteRequest = new HttpDelete("http://localhost:4567/user/" + addedUser.get("id").toString());

		System.out.println("Token : " + admin.get("token").toString());
		deleteRequest.setHeader("token", admin.get("token").toString());

		CloseableHttpResponse	httpResponse = this.httpClient.execute(deleteRequest);
		System.out.println("Body : " + EntityUtils.toString(httpResponse.getEntity()));
		assertEquals(HTTP_OK, httpResponse.getStatusLine().getStatusCode());
	} */

/*	@Test
	public void		updateUser() throws Exception {
		JSONObject	user = ApiTestUtils.createUser(this.httpClient, "updateUser", "updateUser");


		System.out.println("Created User w/ ID : " + user.get("id").toString());

		HttpPost	postRequest = new HttpPost("http://localhost:4567/user/" + user.get("id").toString());
		String		jsonRequest = "{\n\t\"password\": \"newPassword\",\n\t\"roles\": [\"TEST\"]}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setHeader("token", admin.get("token").toString());
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponse = this.httpClient.execute(postRequest);

		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_OK, statusCode);

		JSONObject	updatedUser = ApiTestUtils.getUser(this.httpClient, Integer.parseInt(user.get("id").toString()));
		JSONArray roles = updatedUser.getJSONArray("roles");
		assertEquals(roles.get(1), "TEST");
	} */
}