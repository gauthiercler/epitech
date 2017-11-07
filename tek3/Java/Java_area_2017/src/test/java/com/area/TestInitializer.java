package com.area;

import com.area.Router;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.json.JSONObject;
import org.junit.BeforeClass;
import spark.Spark;

import java.io.File;
import java.nio.file.Files;

public class TestInitializer {

	private static boolean		initialized = false;
	private static CloseableHttpClient	httpClient = HttpClients.custom().build();
	protected	static JSONObject			admin;

	@BeforeClass
	public static void		setupServer() throws Exception {
		if (!initialized) {
			File	dbFile = new File("test.db");
			if (dbFile.delete()) {
				System.out.println("Deleted db file");
			}
			System.out.println("Setting up server");
			Router.main(null);
			Spark.awaitInitialization();


			admin = ApiTestUtils.createUser(httpClient, "root", "root");
			initialized = true;
			Thread.sleep(1000);
		}
	}
}
