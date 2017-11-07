package com.area.pipeline;

import com.area.events.DropboxEvent;
import com.area.events.Event;
import com.area.events.dropbox.DropboxFileAddedEvent;
import com.area.events.dropbox.DropboxFileRemovedEvent;
import com.area.events.dropbox.DropboxFolderCreatedEvent;
import com.area.listeners.EventFactory;
import com.area.models.User;
import com.area.repositories.UsersRepository;
import com.dropbox.core.DbxRequestConfig;
import com.dropbox.core.v2.DbxClientV2;
import com.dropbox.core.v2.files.ListFolderGetLatestCursorBuilder;
import com.dropbox.core.v2.files.ListFolderResult;
import org.json.JSONArray;
import org.json.JSONObject;

public class DropboxPipeline {

	public enum DropboxPipelineEvents {
		FILE(DropboxFileAddedEvent.class),
		FOLDER(DropboxFolderCreatedEvent.class),
		DELETED(DropboxFileRemovedEvent.class);

		private Class	clazz = null;
		DropboxPipelineEvents(Class clazz) { this.clazz = clazz; }

		public Class get() { return this.clazz; }
	}

	public static void	run(JSONArray users_changes) {
		for (int i = 0; i < users_changes.length(); i += 1) {
			try {

				String		userId = users_changes.get(i).toString().replace("dbid:", "");

				System.out.println("User : " + userId);

				User				user = UsersRepository.findByDropboxID(userId);
				DbxRequestConfig	config = new DbxRequestConfig("Area");
				DbxClientV2			client = new DbxClientV2(config, user.getDropboxAccessToken());

				assessChanges(client, user);

			} catch (Exception e) {
				System.err.println("DropboxPipeline : " + e.getMessage());
			}
		}
	}

	public static void	assessChanges(DbxClientV2 client, User user) throws Exception {
		ListFolderResult Directorychanges = client.files().listFolderContinue(user.getDropboxCursor());
		System.out.println("Entries to S : " + Directorychanges.getEntries().toString());

		try {
			JSONArray	entries = new JSONArray(Directorychanges.getEntries().toString());
			for (int i = 0; i < entries.length(); i++) {
				assessFileChange(user, entries.getJSONObject(i));
			}
		} catch (Exception e) {
			System.err.println("DropBoxPipeline-DChanges : " + e.getMessage());
		}

		user.setDropboxCursor(Directorychanges.getCursor());
		UsersRepository.commit(user);
		if (Directorychanges.getHasMore()) {
			assessChanges(client, user);
		}
	}

	public static void	assessFileChange(User user, JSONObject fileChange) {
		try {
			String					type = fileChange.get(".tag").toString();
			DropboxPipelineEvents	eventType = DropboxPipelineEvents.valueOf(type.toUpperCase());

			DropboxEvent	event = (DropboxEvent) eventType.get().newInstance();
			((Event) event).setUser(user);
			event.parse(fileChange);
			if (((Event) event).isValid()) {
				EventFactory.onEvent((Event) event);
			}
		} catch (Exception e) {
			System.err.println("DropboxPipeline assessFileChange : " + e);
		}
	}
}
