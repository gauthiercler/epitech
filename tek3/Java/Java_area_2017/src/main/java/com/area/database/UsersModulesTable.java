package com.area.database;

import java.sql.SQLException;
import java.sql.Statement;

public class UsersModulesTable implements Table {

    static public final String ID = "ID";
    static public final String USER_ID = "USER_ID";
    static public final String LISTENER = "LISTENER";
    static public final String HANDLER = "HANDLER";

    public UsersModulesTable (Statement stat)
    {
        create(stat);
    }

    @Override
    public void create(Statement stat) {
        try {
            stat.execute("CREATE TABLE users_modules(" +
                    ID + " INT PRIMARY KEY NOT NULL," +
                    USER_ID + " INT NOT NULL," +
                    LISTENER + " TEXT NOT NULL," +
                    HANDLER + " TEXT NOT NULL" +
                    ");");
        } catch (SQLException e) {
            System.out.println("[WARNING] " + e.toString());
        }
    }

    @Override
    public void drop(Statement stat) {
        try {
            stat.executeQuery("DROP TABLE users_modules;");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
