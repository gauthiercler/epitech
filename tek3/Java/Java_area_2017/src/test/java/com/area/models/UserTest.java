package com.area.models;

import org.junit.Test;

import static org.junit.Assert.*;

public class UserTest {
	@Test
	public void isValid() throws Exception {
		User	user = new User();

		user.setUsername("Username");
		user.setPassword("Password");
		assertEquals(user.isValid(), true);
	}

	@Test
	public void	isNotValidUsername() throws Exception {
		User	user = new User();

		user.setUsername("");
		user.setPassword("Password");
		assertEquals(user.isValid(), false);
	}

	@Test
	public void	isNotValidPassword() throws Exception {
		User	user = new User();

		user.setUsername("Username");
		user.setPassword("");
		assertEquals(user.isValid(), false);
	}

	@Test
	public void setId() throws Exception {
		User 	user = new User();

		user.setId(0);
		assertEquals(user.getId(), 0);
	}

	@Test
	public void setUsername() throws Exception {
		User	user = new User();

		user.setUsername("User");
		assertEquals(user.getUsername(), "User");
	}

	@Test
	public void setPassword() throws Exception {
		User	user = new User();

		user.setPassword("Password");
		assertEquals(user.getPassword(), "Password");
	}

	@Test
	public void setToken() throws Exception {
		User	user = new User();

		user.setToken("token");
		assertEquals(user.getToken(), "token");
	}

	@Test
	public void setFacebookAccessToken() throws Exception {
		User	user = new User();

		user.setFacebookAccessToken("facebookToken");
		assertEquals(user.getFacebookAccessToken(), "facebookToken");
	}

	@Test
	public void setTwitterAccessToken() throws Exception {
		User	user = new User();

		user.setTwitterAccessToken("twitterToken");
		assertEquals(user.getTwitterAccessToken(), "twitterToken");
	}

	@Test
	public void	noRoleOnConstruction() throws Exception {
		User	user = new User();

		assertEquals(user.getRoles().size(), 0);
	}

	@Test
	public void addRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		assertEquals(user.getRoles().size(), 1);
		assertEquals(user.getRoles().get(0), "Role");
	}

	@Test
	public void	addDuplicateRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		user.addRole("Role");
		assertEquals(user.getRoles().size(), 1);
		assertEquals(user.getRoles().get(0), "Role");
	}

	@Test
	public void removeExistingRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		user.removeRole("Role");
		assertEquals(user.getRoles().size(), 0);
	}

	@Test
	public void	removeNonExistingRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		user.removeRole("");
		assertEquals(user.getRoles().size(), 1);
		assertEquals(user.getRoles().get(0), "Role");
	}

	@Test
	public void hasExistingRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		assertEquals(user.hasRole("Role"), true);
	}

	@Test
	public void	hasNonExistingRole() throws Exception {
		User	user = new User();

		user.addRole("Role");
		assertEquals(user.hasRole(""), false);
	}
}