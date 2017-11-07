package com.area.events.twitter;

import com.area.events.Event;
import com.area.events.TwitterEvent;
import lombok.Data;
import lombok.EqualsAndHashCode;

@EqualsAndHashCode(callSuper = true)
@Data
public class TwitterStatusEvent extends Event implements TwitterEvent {
    private String value;
}
