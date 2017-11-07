package com.area.database;

import com.area.models.User;
import com.area.models.UserModule;
import org.apache.commons.lang3.StringUtils;

import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import static com.area.database.UsersModulesTable.*;
import static com.area.database.UsersTable.*;

public class DatabaseHandler {

    //Instance
    static private DatabaseHandler db = new DatabaseHandler();

    private Connection c;
    private Statement stmt;
    private boolean running;
    private ResultSet rs;
    private ArrayList<Table> tables;

    // SQLite Grammar
    static private final String END = ";";
    static private final String SET = " SET ";
    static private final String WHERE = " WHERE ";
    static private final String SQL_SELECT_USERS = "SELECT * FROM users";
    static private final String SQL_UPDATE_USERS = "UPDATE users";
    static private final String SQL_DELETE_USERS = "DELETE FROM users";
    static private final String SQL_INSERT_USERS = "INSERT INTO users VALUES ";
    static private final String SQL_INSERT_USERS_MODULE = "INSERT INTO users_modules VALUES ";
    static private final String SQL_DELETE_USERS_MODULE = "DELETE FROM users_modules";

    static private final String SQL_SELECT_USERS_MODULES = "SELECT * FROM users_modules";

    public static DatabaseHandler getInstance()
    {
        return (db);
    }

    private DatabaseHandler () {
        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:test.db");
            stmt = c.createStatement();
            running = true;
            initTables();
        } catch (ClassNotFoundException | SQLException e) {
            e.printStackTrace();
            running = false;
        }
    }

    private void initTables()
    {
        tables = new ArrayList<>();
        tables.add(new UsersTable(stmt));
        tables.add(new UsersModulesTable(stmt));
    }

    public boolean isRunning()
    {
        return (running);
    }

    public void close()
    {
        try {
            rs.close();
            stmt.close();
            c.close();
            running = false;
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public HashMap<Integer, User> getUsers()
    {
        HashMap<Integer, User> users = new HashMap<>();

        try {
            rs = stmt.executeQuery(SQL_SELECT_USERS + END);
            while (rs.next())
            {
                User user = new User();
                user.setId(rs.getInt(USERID)).setUsername(rs.getString(USERNAME))
                        .setPassword(rs.getString(USERPASS)).setEmail(rs.getString(USERMAIL)).setToken(rs.getString(USERTOKEN))
                        .setFacebookAccessToken(rs.getString(USERFB)).setTwitterAccessToken(rs.getString(USERTW))
                        .setTwitterAccessTokenSecret(rs.getString(USERTWS)).setTwitterID(rs.getString(USERTWID))
                        .setFacebookUUID(rs.getString(USERFBUID))
                        .setDropboxAccessToken(rs.getString(USERDB)).setDropboxID(rs.getString(USERDBID)).setDropboxCursor(rs.getString(USERDBCR));
                String[] roles = rs.getString(USERROLES).split(",");
                for (String r : roles)
                    user.addRole(r);
                users.put(user.getId(), user);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return (users);
        }
        return (users);
    }

    public void updateUser(User u)
    {
        try {
            stmt.execute(String.format("%s%s%s=\"%s\",%s=\"%s\",%s=\"%s\",%s=\"%s\",%s=\"%s\", %s=\"%s\",%s=\"%s\", %s=\"%s\",%s=\"%s\",%s=\"%s\",%s=\"%s\",%s=\"%s\",%s=\"%s\"%s%s=%d%s",
                    SQL_UPDATE_USERS,
                    SET,
                    USERNAME,
                    u.getUsername(),
                    USERPASS,
                    u.getPassword(),
                    USERMAIL,
                    u.getEmail(),
                    USERTOKEN,
                    u.getToken(),
                    USERROLES,
                    StringUtils.join(u.getRoles(), ','),
                    USERFB,
                    u.getFacebookAccessToken(),
                    USERTW,
                    u.getTwitterAccessToken(),
                    USERTWS,
                    u.getTwitterAccessTokenSecret(),
                    USERTWID,
                    u.getTwitterID(),
                    USERFBUID,
                    u.getFacebookUUID(),
                    USERDB,
                    u.getDropboxAccessToken(),
                    USERDBID,
                    u.getDropboxID(),
                    USERDBCR,
                    u.getDropboxCursor(),
                    WHERE,
                    USERID,
                    u.getId(),
                    END));
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void updateUsers(HashMap<Integer, User> users)
    {
        for (User u : users.values())
            updateUser(u);
    }

    public void insert(User u)
    {
        try {
            stmt.execute(String.format("%s(\"%d\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\",\"%s\")%s",
                    SQL_INSERT_USERS,
                    u.getId(),
                    u.getUsername(),
                    u.getPassword(),
                    u.getEmail(),
                    u.getToken(),
                    StringUtils.join(u.getRoles(), ','),
                    u.getFacebookAccessToken(),
                    u.getTwitterAccessToken(),
                    u.getTwitterAccessTokenSecret(),
                    u.getTwitterID(),
                    u.getFacebookUUID(),
                    u.getDropboxAccessToken(),
                    u.getDropboxID(),
                    u.getDropboxCursor(),
                    END));
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void insert(UserModule module)
    {
        try {
            stmt.execute(String.format("%s(\"%d\",\"%d\",\"%s\",\"%s\")%s",
                    SQL_INSERT_USERS_MODULE,
                    module.getId(),
                    module.getUser_id(),
                    module.getListener(),
                    module.getHandler(),
                    END));
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void delete(User u)
    {
        try {
            stmt.execute(SQL_DELETE_USERS + WHERE + USERID + "=" + u.getId());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<UserModule> getUsersModules() {
        List<UserModule> usersModules = new ArrayList<>();

        try {
            rs = stmt.executeQuery(SQL_SELECT_USERS_MODULES + END);
            while (rs.next())
            {
                UserModule userModule = new UserModule();
                userModule.setId(rs.getInt(ID)).setUserId(rs.getInt(USER_ID)).setListener(rs.getString(LISTENER))
                        .setHandler(rs.getString(HANDLER));
                usersModules.add(userModule);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            return (usersModules);
        }
        return (usersModules);
    }

    public void delete(UserModule userModule) {
        try {
            stmt.execute(SQL_DELETE_USERS_MODULE + WHERE + ID + "=" + userModule.getId());
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
