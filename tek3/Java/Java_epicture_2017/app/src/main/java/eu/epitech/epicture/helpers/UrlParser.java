package eu.epitech.epicture.helpers;


import java.net.URL;
import java.net.URLDecoder;
import java.util.HashMap;
import java.util.Map;

public class UrlParser {

    private Map<String, String> parameters = new HashMap<>();

    public UrlParser(String rawUrl) {
        try {
            URL url = new URL(rawUrl);
            String query = url.getQuery();
            String ref = url.getRef();

            String[] params = query.split("&");
            String[] refs = ref.split("&");

            addData(parameters, params);
            addData(parameters, refs);
        } catch (Exception ignored) {}
    }

    private void addData(Map<String, String> container, String[] datas) {
        try {

            for (String param : datas) {
                int idx = param.indexOf("=");
                container.put(URLDecoder.decode(param.substring(0, idx), "UTF-8"), URLDecoder.decode(param.substring(idx + 1), "UTF-8"));
            }
        } catch (Exception ignored) {}

    }

    public String get(String key) {
        System.out.println(parameters);
        return parameters.get(key);
    }
}
