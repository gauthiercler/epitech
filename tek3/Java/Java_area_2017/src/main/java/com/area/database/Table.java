package com.area.database;

import java.sql.Statement;

public interface Table {

    void create(Statement stat);
    void drop(Statement stat);

}
