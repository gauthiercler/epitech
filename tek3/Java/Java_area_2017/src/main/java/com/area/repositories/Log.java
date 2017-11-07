package com.area.repositories;

import lombok.Getter;

import java.util.Date;

public class Log {

    public enum Type {
        FACEBOOK,
        TWITTER,
        DROPBOX
    }

    @Getter private Type type;
    @Getter private String id;
    @Getter private Date time;

    public Log(Type type, String id)
    {
        this.type = type;
        this.id = id;
        this.time = new Date();
    }

    public Log(Type type, long id)
    {
        this.type = type;
        this.id = String.valueOf(id);
        this.time = new Date();
    }

    @Override
    public boolean equals(Object obj) {
        Log log = (Log)obj;

        return (log.getId().equals(this.id) && log.getType().equals(this.type));
    }
}