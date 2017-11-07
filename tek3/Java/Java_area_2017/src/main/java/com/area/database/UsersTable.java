package com.area.database;

import java.sql.SQLException;
import java.sql.Statement;

public class UsersTable implements Table {

    // Col names of the table users
    static public final String USERID = "ID";
    static public final String USERNAME = "USERNAME";
    static public final String USERPASS = "PASSWORD";
    static public final String USERMAIL = "EMAIL";
    static public final String USERTOKEN = "TOKEN";
    static public final String USERROLES = "ROLES";
    static public final String USERFB = "FACEBOOKTOKEN";
    static public final String USERTW = "TWITTERTOKEN";
    static public final String USERTWS = "TWITTERTOKENSECRET";
    static public final String USERTWID = "TWITTERTOKENID";
    static public final String USERFBUID = "FACEBOOKUID";
    static public final String USERDB = "DROPBOXTOKEN";
    static public final String USERDBID = "DROPBOXID";
    static public final String USERDBCR = "DROPBOXCURSOR";

    public UsersTable (Statement stat)
    {
        create(stat);
    }

    @Override
    public void create(Statement stat) {
        try {
            stat.execute("CREATE TABLE users(" +
                    USERID + " INT PRIMARY KEY NOT NULL," +
                    USERNAME + " TEXT NOT NULL," +
                    USERPASS + " TEXT NOT NULL," +
                    USERMAIL + " TEXT NOT NULL," +
                    USERTOKEN + " TEXT NOT NULL," +
                    USERROLES + " TEXT NOT NULL," +
                    USERFB + " TEXT NOT NULL," +
                    USERTW + " TEXT NOT NULL," +
                    USERTWS + " TEXT NOT NULL," +
                    USERTWID + " TEXT NOT NULL," +
                    USERFBUID + " TEXT NOT NULL," +
                    USERDB + " TEXT NOT NULL," +
                    USERDBID + " TEXT NOT NULL," +
                    USERDBCR + " TEXT NOT NULL" +
                    ");");
        } catch (SQLException e) {
            System.out.println("[WARNING] " + e.toString());
        }
    }

    @Override
    public void drop(Statement stat) {
        try {
            stat.executeQuery("DROP TABLE users;");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
