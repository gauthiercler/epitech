package com.area;

import com.area.controllers.*;
import com.area.helpers.HeaderHelper;
import com.area.stream.TwitterListenerFactory;

import java.lang.reflect.InvocationTargetException;

import static spark.Spark.*;
import static spark.debug.DebugScreen.enableDebugScreen;

public class Router {


    public static void main(String[] args) throws InvocationTargetException, IllegalAccessException, InstantiationException {
        enableDebugScreen();
        // Routing
        post("/login", SecurityController::login);
        post("/register", SecurityController::register);

        get("/users", UsersController::index);
        post("/mails", UsersController::email);

        get("/user/:userId", UsersController::get);
        delete("/user/:userId", UsersController::delete);
        post("/user/:userId", UsersController::update);

        post("/user/:userId/facebook", FacebookController::associate);
        delete("/user/:userId/facebook", FacebookController::disassociate);

        post("/user/:userId/modules", ModulesController::enable);
        delete("/user/:userId/modules", ModulesController::disable);
        get("/user/:userId/modules", ModulesController::index);

        get("/facebook/webhook", FacebookWebHookController::test);
        post("/facebook/webhook", FacebookWebHookController::callback);

        post("/user/:userId/twitter", TwitterController::associate);
        delete("/user/:userId/twitter", TwitterController::disassociate);

        post("/user/:userId/dropbox", DropboxController::associate);
        delete("/user/:userId/dropbox", DropboxController::disassociate);
        get("/dropbox/webhook", DropboxWebHookController::confirm);
        post("/dropbox/webhook", DropboxWebHookController::callback);

        // Headers
        before("*", HeaderHelper::type);
        before("*", HeaderHelper::AccessControllOrigin);

        // Security
        before("/users", SecurityController::isAdmin);
        before("/mails", SecurityController::isAdmin);
        before("/user/:userId", SecurityController::isAdminOrOwner);
        before("/user/:userId/*", SecurityController::isAdminOrOwner);

        options("/*", HeaderHelper::options);

        TwitterListenerFactory.setup();

    }
}
