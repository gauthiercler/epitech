package eu.epitech.epicture.api;


import java.util.ArrayList;
import java.util.List;

public class ApiManager {

    private static ApiManager instance = null;

    public static ApiManager getInstance() {
        if (instance == null)
            instance = new ApiManager();
        return instance;
    }

    private List<Class> apis = new ArrayList<>();

    public void AddApi(Class api) {
        if (!apis.contains(api))
            apis.add(api);
    }

    public List<Class> getApis() {
        return apis;
    }
}
