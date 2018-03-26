package eu.epitech.epicture.api;

import android.support.v7.app.AppCompatActivity;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import java.lang.reflect.Method;
import java.net.URL;

import eu.epitech.epicture.api.handlers.LoginHandler;


public class LoginWebView extends WebViewClient {
    private static final String REDIRECT_URL = "https://login.imgur.epicture.epitech.eu";
    private AppCompatActivity context = null;

    public LoginWebView(AppCompatActivity context) {
        this.context = context;
    }


    @Override
    public boolean shouldOverrideUrlLoading(WebView view, String url) {
        try {
            URL parsedUrl = new URL(url);
            for (Class handler : ApiManager.getInstance().getApis()) {
                for (Method method : handler.getMethods()) {
                    LoginHandler eventHandler = method.getAnnotation(LoginHandler.class);
                    if (eventHandler != null && eventHandler.uri().equals(parsedUrl.getHost())) {
                        try {
                            method.invoke(handler.getDeclaredConstructor(AppCompatActivity.class).newInstance(context), url);
                            return true;
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
            view.loadUrl(url);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }
}
