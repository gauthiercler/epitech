package com.area.controllers;

import com.area.Router;
import com.area.ApiTestUtils;
import com.area.TestInitializer;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.entity.StringEntity;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.junit.*;
import spark.Spark;


import static java.net.HttpURLConnection.*;
import static org.junit.Assert.*;

public class SecurityControllerTest extends TestInitializer {

	private CloseableHttpClient		httpClient = HttpClients.custom().build();

	@Test
	public void register() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"usernameRegister\",\n\t\"password\": \"passwordRegister\",\n\t\"email\": \"emailRegister@email.com\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;
//		JSONObject		jsonResponse;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponse = this.httpClient.execute(postRequest);
		statusCode = httpResponse.getStatusLine().getStatusCode();
//		jsonResponse = new JSONObject(httpResponse.getEntity().getContent().toString());
		assertEquals(HTTP_OK, statusCode);
	}

	@Test
	public void	registerDuplicate() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"usernameRegisterDuplicate\",\n\t\"password\": \"passwordRegisterDuplicate\",\n\t\"email\": \"emailRegisterDuplicate@email.com\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		this.httpClient.execute(postRequest);
		CloseableHttpResponse	httpResponse = this.httpClient.execute(postRequest);
		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_CONFLICT, statusCode);
	}

	@Test
	public void	registerInvalidUsername() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"\",\n\t\"password\": \"passwordRegisterInvalidUsername\",\n\t\"email\": \"emailRegisterInvalidUsername@email.com\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseEmptyUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseEmptyUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);

		jsonRequest = "{\n\t\"password\": \"passwordRegisterInvalidUsername\",\n\t\"email\": \"emailRegisterInvalidUsername@email.com\"\n}";
		body = new StringEntity(jsonRequest);

		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseNoUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseNoUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);
	}

	@Test
	public void	registerInvalidPassword() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"usernameRegisterInvalidPassword\",\n\t\"password\": \"\",\n\t\"email\": \"emailRegisterInvalidPassword@email.com\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseEmptyPassword = this.httpClient.execute(postRequest);
		statusCode = httpResponseEmptyPassword.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);

		jsonRequest = "{\n\t\"username\": \"usernameRegisterInvalidPassword\",\n\t\"email\": \"emailRegisterInvalidPassword@email.com\"\n}";
		body = new StringEntity(jsonRequest);

		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseNoUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseNoUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);
	}

	@Test
	public void	registerInvalidEmail() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/register");
		String			jsonRequest = "{\n\t\"username\": \"usernameRegisterInvalidEmail\",\n\t\"password\": \"passwordRegisterInvalidEmail\",\n\t\"email\": \"\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseEmptyEmail = this.httpClient.execute(postRequest);
		statusCode = httpResponseEmptyEmail.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);

		jsonRequest = "{\n\t\"username\": \"usernameRegisterInvalidEmail\",\n\t\"password\": \"passwordRegisterInvalidEmail\"\n}";
		body = new StringEntity(jsonRequest);

		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseNoUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseNoUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);
	}

	@Test
	public void	login() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/login");
		String			jsonRequest = "{\n\t\"username\": \"usernameLogin\",\n\t\"password\": \"passwordLogin\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		ApiTestUtils.createUser(this.httpClient, "usernameLogin", "passwordLogin");
		CloseableHttpResponse	httpResponse = this.httpClient.execute(postRequest);
		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_OK, statusCode);
	}

	@Test
	public void	loginNonExistent() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/login");
		String			jsonRequest = "{\n\t\"username\": \"usernameLoginNonExistent\",\n\t\"password\": \"passwordLoginNonExistent\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponse = this.httpClient.execute(postRequest);
		statusCode = httpResponse.getStatusLine().getStatusCode();
		assertEquals(HTTP_FORBIDDEN, statusCode);
	}

	@Test
	public void	loginInvalidUsername() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/login");
		String			jsonRequest = "{\n\t\"password\": \"passwordLoginInvalidUsername\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseNoUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseNoUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);

		jsonRequest = "{\n\t\"username\": \"\",\n\t\"password\": \"passwordLoginInvalidUsername\"\n}";
		body = new StringEntity(jsonRequest);
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseEmptyUsername = this.httpClient.execute(postRequest);
		statusCode = httpResponseEmptyUsername.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);
	}

	@Test
	public void	loginInvalidPassword() throws Exception {
		HttpPost		postRequest = new HttpPost("http://localhost:4567/login");
		String			jsonRequest = "{\n\t\"username\": \"usernameLoginInvalidPassword\"\n}";
		StringEntity	body = new StringEntity(jsonRequest);
		int				statusCode;

		postRequest.setHeader("Content-Type", "application/json");
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseNoPassword = this.httpClient.execute(postRequest);
		statusCode = httpResponseNoPassword.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);

		jsonRequest = "{\n\t\"username\": \"passwordLoginInvalidPassword\",\n\t\"password\": \"\"\n}";
		body = new StringEntity(jsonRequest);
		postRequest.setEntity(body);

		CloseableHttpResponse	httpResponseEmptyPassword = this.httpClient.execute(postRequest);
		statusCode = httpResponseEmptyPassword.getStatusLine().getStatusCode();
		assertEquals(HTTP_BAD_REQUEST, statusCode);
	}
}