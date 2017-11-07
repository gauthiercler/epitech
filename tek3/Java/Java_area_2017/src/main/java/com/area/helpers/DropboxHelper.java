package com.area.helpers;

import com.dropbox.core.DbxException;
import com.dropbox.core.DbxRequestConfig;
import com.dropbox.core.v2.DbxClientV2;
import com.dropbox.core.v2.files.ListFolderGetLatestCursorBuilder;

public class DropboxHelper {
	public static String	getUserId(String accessToken) {
		DbxRequestConfig config = new DbxRequestConfig("Area");
		DbxClientV2 client = new DbxClientV2(config, accessToken);

		try {
			return client.users().getCurrentAccount().getAccountId().replace("dbid:", "");
		} catch (DbxException ignored) {

		}
		return null;
	}

	public static String	getUserCursor(String accessToken) {
		DbxRequestConfig config = new DbxRequestConfig("Area");
		DbxClientV2 client = new DbxClientV2(config, accessToken);

		try {
			ListFolderGetLatestCursorBuilder	request = client.files().listFolderGetLatestCursorBuilder("");
			request.withRecursive(true);
			return request.start().getCursor();
		} catch (DbxException ignored) {

		}
		return null;
	}
}
