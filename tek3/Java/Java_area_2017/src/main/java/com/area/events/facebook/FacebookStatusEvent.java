package com.area.events.facebook;

import com.area.events.Event;
import com.area.events.FacebookEvent;
import com.area.models.User;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import lombok.Data;
import lombok.EqualsAndHashCode;
import twitter4j.JSONException;
import twitter4j.JSONObject;

@EqualsAndHashCode(callSuper = true)
@Data
public class FacebookStatusEvent extends Event implements FacebookEvent {

    private String value;
    private String id;
    private boolean valid = true;

    @Override
    public void parse(JSONObject packet) {
        System.out.println("===== IN FACEBOOK STATUS EVENT =====");
        LogsRepository logsRepository = LogsRepository.getInstance();
        try {
            this.setValue(packet.getString("value"));
            this.setId(packet.getString("id"));
            if (logsRepository.contains(new Log(Log.Type.FACEBOOK, packet.getString("id"))))
                this.valid = false;
            else
                logsRepository.addLog(new Log(Log.Type.FACEBOOK, packet.getString("id")));
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }

    @Override
    public boolean isValid() {
        return this.valid;
    }
}
