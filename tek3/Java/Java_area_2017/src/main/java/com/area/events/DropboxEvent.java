package com.area.events;

import org.json.JSONObject;

public interface DropboxEvent {
	void parse(JSONObject value);
}
