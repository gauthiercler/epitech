package com.area.events;

import com.area.models.User;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode
@Data
public class Event {
    private User user;

    public boolean isValid() {
        return true;
    }
}
