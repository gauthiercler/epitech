package eu.epitech.epicture;

import android.graphics.Color;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.webkit.WebView;

import eu.epitech.epicture.api.LoginWebView;


public class LoginActivity extends AppCompatActivity {

    public static final String URL = "url";

    @Override
    protected void onCreate(Bundle savedInstance) {
        super.onCreate(savedInstance);
        this.setContentView(R.layout.activity_login);

        String url = getIntent().getStringExtra(URL);

        WebView webView = findViewById(R.id.view);
        webView.clearCache(true);
        webView.setBackgroundColor(Color.TRANSPARENT);
        webView.loadUrl(url);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.setWebViewClient(new LoginWebView(this));
    }


}
