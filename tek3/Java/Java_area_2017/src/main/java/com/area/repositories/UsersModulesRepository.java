package com.area.repositories;

import com.area.database.DatabaseHandler;
import com.area.models.User;
import com.area.models.UserModule;

import java.util.ArrayList;
import java.util.List;

public class UsersModulesRepository {

    static private List<UserModule> modules = DatabaseHandler.getInstance().getUsersModules();
    static private int autoIncrement = modules.size() > 0 ? modules.get(modules.size() - 1).getId() + 1 : 1;

    public static boolean listening(User user, String listener, String handler)
    {
        return findModule(user, listener, handler) != null;
    }

    public static void listen(User user, String listener, String handler)
    {
        UserModule module = new UserModule()
                .setId(autoIncrement++)
                .setUserId(user.getId())
                .setListener(listener)
                .setHandler(handler);

        modules.add(module);
        DatabaseHandler.getInstance().insert(module);
    }

    public static void unlisten(User user, String listener, String handler)
    {
        UserModule userModule = findModule(user, listener, handler);

        if (userModule != null) {
            modules.remove(userModule);
            DatabaseHandler.getInstance().delete(userModule);
        }

    }

    private static UserModule findModule(User user, String listener, String handler) {
        System.out.println("==================LISTING Modules====================");
        for (UserModule module : modules) {
            System.out.println("[" + module.getListener() + "] => " + module.getHandler());
            if (module.getUser_id() == user.getId() && module.getListener().equals(listener) && module.getHandler().equals(handler)) {
                System.out.println("FOUND MODULE");
                return module;
            }
        }
        System.out.println("================ FOUND NOTHING =============");
        return null;
    }

    public static List<UserModule> find(User user) {
        List<UserModule> userModules = new ArrayList<>();

        for (UserModule module : modules) {
            if (module.getUser_id() == user.getId())
                userModules.add(module);
        }
        return userModules;
    }
}
