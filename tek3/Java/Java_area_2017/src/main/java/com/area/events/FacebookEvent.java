package com.area.events;

import com.area.models.User;
import twitter4j.JSONObject;

public interface FacebookEvent  {

    public void parse(JSONObject value);

}
