package com.area.models;

import com.area.repositories.UsersModulesRepository;
import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

@Getter
public class User
{

    private int id;
    private String username;
    private String password;
    private String email;
    private String token;
    private List<String> roles = new ArrayList<>();

    private String facebookAccessToken;
    private String twitterAccessToken;
    private String twitterAccessTokenSecret;
    private String dropboxAccessToken;
    private String dropboxCursor;
    private String twitterID;
    private String facebookUUID;
    private String dropboxID;

    public User setEmail(String mail)
    {
        email = mail;
        return (this);
    }

    public boolean isValid()
    {
        return !username.isEmpty() && !password.isEmpty();
    }

    public User setId(int id)
    {
        this.id = id;
        return this;
    }

    public User setUsername(String username)
    {
        this.username = username;
        return this;
    }

    public User setPassword(String password)
    {
        this.password = password;
        return this;
    }

    public User setToken(String token)
    {
        this.token = token;
        return this;
    }

    public User setFacebookAccessToken(String facebookAccessToken)
    {
        this.facebookAccessToken = facebookAccessToken;
        return this;
    }

    public User setTwitterAccessToken(String twitterAccessToken)
    {
        this.twitterAccessToken = twitterAccessToken;
        return this;
    }

    public User setDropboxAccessToken(String dropboxAccessToken) {
    	this.dropboxAccessToken = dropboxAccessToken;
    	return this;
	}

	public User setDropboxCursor(String cursor) {
        this.dropboxCursor = cursor;
        return this;
    }

    public User addRole(String role)
    {
        if (!roles.contains(role))
            roles.add(role);
        return this;
    }

    public User removeRole(String role)
    {
        if (roles.contains(role))
            roles.remove(role);
        return this;
    }

    public User setFacebookUUID(String facebookUUID)
    {
        this.facebookUUID = facebookUUID;
        return this;
    }

    public User setTwitterID(String value) {
        this.twitterID = value;
        return this;
    }

    public User setDropboxID(String dropboxID) {
    	this.dropboxID = dropboxID;
    	return this;
	}

    public User setTwitterAccessTokenSecret(String value) {
        this.twitterAccessTokenSecret = value;
        return this;
    }

    public boolean hasRole(String role) {
        return roles.contains(role);
    }

    public boolean isRegistered(String listenerName, String handlerName) {
        System.out.println("Checking if User is register " + listenerName + " => " + handlerName);
        return UsersModulesRepository.listening(this, listenerName, handlerName);
    }
}
