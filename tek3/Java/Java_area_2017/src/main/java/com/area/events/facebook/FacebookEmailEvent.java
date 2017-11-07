package com.area.events.facebook;

import com.area.events.Event;
import com.area.events.FacebookEvent;
import com.area.models.User;
import lombok.Data;
import lombok.EqualsAndHashCode;
import twitter4j.JSONException;
import twitter4j.JSONObject;

@EqualsAndHashCode(callSuper = true)
@Data
public class FacebookEmailEvent extends Event implements FacebookEvent{

    private String value;

    @Override
    public void parse(JSONObject value) {
        try {
            this.setValue(value.getString("value"));
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
}
