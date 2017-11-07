package com.area.helpers;

import com.mailjet.client.ClientOptions;
import com.mailjet.client.MailjetClient;
import com.mailjet.client.MailjetRequest;
import com.mailjet.client.MailjetResponse;
import com.mailjet.client.errors.MailjetException;
import com.mailjet.client.errors.MailjetSocketTimeoutException;
import com.mailjet.client.resource.Emailv31;
import org.json.JSONArray;
import org.json.JSONObject;

public class MailDeliver {

    private static MailDeliver mail = new MailDeliver();
    private MailjetClient client;
    private MailjetRequest req;
    private MailjetResponse res;

    private MailDeliver()
    {
        String APIKey = "17bf68cdf02e9d9b5ccad87bfcaad36c";
        String pAPIKey = "25c6f79eb837fb279f907c9e57002971";

        this.client = new MailjetClient(APIKey, pAPIKey, new ClientOptions("v3.1"));
    }

    public static MailDeliver getInstance()
    {
        return (mail);
    }

    public MailjetResponse getRes() {
        return (this.res);
    }

    public boolean sendTo(String to, String subject, String txt) {
        this.req = new MailjetRequest(Emailv31.resource)
                .property(Emailv31.MESSAGES, new JSONArray()
                        .put(new JSONObject()
                                .put(Emailv31.Message.FROM, new JSONObject()
                                        .put("Email", "valentin.montagne@epitech.eu")
                                        .put("Name", "Area Test"))
                                .put(Emailv31.Message.TO, new JSONArray()
                                        .put(new JSONObject()
                                                .put("Email", to)
                                                .put("Name", to)))
                                .put(Emailv31.Message.SUBJECT, subject)
                                .put(Emailv31.Message.TEXTPART, txt)));
        try {
            this.res = this.client.post(this.req);
        } catch (MailjetException | MailjetSocketTimeoutException e) {
            e.printStackTrace();
            return (false);
        }
        return (true);
    }
}