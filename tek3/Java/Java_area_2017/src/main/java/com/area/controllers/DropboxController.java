package com.area.controllers;

import com.area.helpers.DropboxHelper;
import com.area.helpers.Parameters;
import com.area.models.User;
import com.area.parameters.DropboxAssociateParameters;
import com.area.repositories.UsersRepository;
import spark.Request;
import spark.Response;

import static java.net.HttpURLConnection.HTTP_FORBIDDEN;
import static java.net.HttpURLConnection.HTTP_NOT_FOUND;

public class DropboxController {

	public static String associate(Request request, Response response) {
		User	user = UsersRepository.findById(Integer.parseInt(request.params("userId")));
		DropboxAssociateParameters	parameters = Parameters.fill(request, response, DropboxAssociateParameters.class);

		if (user == null) {
			response.status(HTTP_NOT_FOUND);
			return "";
		} else if (parameters == null) {
			return "";
		}
		user.setDropboxAccessToken(parameters.getAccessToken());
		user.setDropboxID(DropboxHelper.getUserId(parameters.getAccessToken()));
		user.setDropboxCursor(DropboxHelper.getUserCursor(parameters.getAccessToken()));
		UsersRepository.commit(user);
		return "";
	}

	public static String disassociate(Request request, Response response) {
		User	user = UsersRepository.findById(Integer.parseInt(request.params("userId")));

		if (user == null) {
			response.status(HTTP_NOT_FOUND);
			return "";
		}
		user.setDropboxAccessToken(null);
		user.setDropboxID(null);
		user.setDropboxCursor(null);
		UsersRepository.commit(user);
		return "";
	}
}
