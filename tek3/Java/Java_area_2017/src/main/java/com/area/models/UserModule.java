package com.area.models;

import lombok.Data;
import lombok.Getter;

@Getter
public class UserModule {

    private int id;
    private int user_id;
    private String listener;
    private String handler;

    public UserModule setUserId(int id)
    {
        user_id = id;
        return this;
    }

    public UserModule setListener(String listener)
    {
        this.listener = listener;
        return this;
    }

    public UserModule setHandler(String handler)
    {
        this.handler = handler;
        return this;
    }
    public UserModule setId(int id)
    {
        this.id = id;
        return this;
    }
}
