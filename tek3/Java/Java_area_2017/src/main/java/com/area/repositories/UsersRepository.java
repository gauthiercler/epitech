package com.area.repositories;

import com.area.database.DatabaseHandler;
import com.area.helpers.MailDeliver;
import com.area.models.User;
import com.area.parameters.RegisterParameters;
import com.area.parameters.UserUpdateParameters;

import java.util.*;
import java.util.function.Predicate;

public class UsersRepository
{
    static private Map<Integer, User> users = DatabaseHandler.getInstance().getUsers();
    private static int idAutoIncrement = users.size() > 0 ? users.get(users.size()).getId() + 1 : 1;

    public static User login(String username, String password)
    {
        User user = findByUsername(username);

        if (user == null || !user.getPassword().equals(password))
            return null;
        else
        {
            user.setToken(generateToken());
            commit(user);
            return user;
        }
    }

    public static User findByUsername(String username)
    {
        for (User user : users.values())
        {
            if (username.equals(user.getUsername()))
                return user;
        }
        return null;
    }

    public static User findByToken(String token)
    {
        for (User user : users.values())
        {
            if (token.equals(user.getToken()))
                return user;
        }
        return null;
    }

    public static User findByFacebookUUID(String uuid) {
        for (User user : users.values())
        {
            if (uuid.equals(user.getFacebookUUID()))
                return user;
        }
        return null;
    }

    public static User findByDropboxID(String id) {
        Predicate<User> predicate = user -> user.getDropboxID().equals(id);
        return users.values().stream().filter(predicate).findFirst().orElse(null);
    }

    public static User create(RegisterParameters parameters) {
        System.out.println(idAutoIncrement);
        User user = new User()
                .setId(idAutoIncrement++)
                .setUsername(parameters.getUsername())
                .setPassword(parameters.getPassword())
                .setEmail(parameters.getEmail())
                .setToken(generateToken())
                .addRole("USER")
                .setFacebookAccessToken(null)
                .setTwitterAccessToken(null)
                .setDropboxAccessToken(null)
                .setDropboxCursor(null);
        if (count() == 0)
            user.addRole("ADMIN");
        users.put(user.getId(), user);
        DatabaseHandler.getInstance().insert(user);
        return user;
    }

    public static List<User> findAll()
    {
        return new ArrayList<>(users.values());
    }

    public static int count()
    {
        return users.size();
    }

    private static String generateToken() {
        return UUID.randomUUID().toString().replace("-", "");
    }

    public static User findById(int id) {
        return users.get(id);
    }

    public static void delete(User user) {
        users.remove(user.getId());
        DatabaseHandler.getInstance().delete(user);
    }

    public static void update(User user, UserUpdateParameters parameters) {
        if (parameters.getPassword() != null)
            user.setPassword(parameters.getPassword());
        if (parameters.getRoles() != null)
            for (String role : parameters.getRoles()) {
                if (user.hasRole(role))
                    user.removeRole(role);
                else
                    user.addRole(role);
            }
        UsersRepository.commit(user);
    }

    public static void commit(User user)
    {
        DatabaseHandler.getInstance().updateUser(user);
    }

    public static void sendMail(String subject, String msg)
    {
        MailDeliver mailDeliver = MailDeliver.getInstance();

        for (User u : users.values())
        {
                System.out.println("Send to : " + u.getEmail());
                System.out.println("Send : " + mailDeliver.sendTo(u.getEmail(), subject, msg));
        }
    }

}
