package com.area.events.dropbox;

import com.area.events.DropboxEvent;
import com.area.events.Event;
import com.area.repositories.Log;
import com.area.repositories.LogsRepository;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.json.JSONObject;

@EqualsAndHashCode(callSuper = true)
@Data
public class DropboxFileRemovedEvent extends Event implements DropboxEvent {
	private String value;
	private boolean valid = true;

	@Override
	public void parse(JSONObject file) {
		String			name = file.get("name").toString();
		String			path = file.get("path_display").toString();

		this.setValue("[Dropbox] Removed " + name + " in " + path);
		System.out.println(this.value);
	}

	@Override
	public boolean isValid() { return this.valid; }
}
