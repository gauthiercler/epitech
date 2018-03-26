package eu.epitech.epicture.api.imgur;

import android.arch.lifecycle.LiveData;
import android.arch.lifecycle.MutableLiveData;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;


import com.squareup.moshi.JsonAdapter;
import com.squareup.moshi.Moshi;

import java.io.File;
import java.io.IOException;

import eu.epitech.epicture.AppDatabase;
import eu.epitech.epicture.BuildConfig;
import eu.epitech.epicture.LoginActivity;
import eu.epitech.epicture.R;
import eu.epitech.epicture.api.ApiManager;
import eu.epitech.epicture.api.IApi;
import eu.epitech.epicture.api.handlers.AccountImagesHandler;
import eu.epitech.epicture.api.handlers.Api;
import eu.epitech.epicture.api.handlers.FavoriteGetHandler;
import eu.epitech.epicture.api.handlers.FavoriteSetHandler;
import eu.epitech.epicture.api.handlers.LoginHandler;
import eu.epitech.epicture.api.handlers.LoginInitializer;
import eu.epitech.epicture.api.handlers.SearchHandler;
import eu.epitech.epicture.api.handlers.UploadHandler;
import eu.epitech.epicture.tasks.UpdateAccount;
import eu.epitech.epicture.helpers.UrlParser;
import eu.epitech.epicture.models.Account;
import eu.epitech.epicture.tasks.InsertAccount;
import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.MediaType;
import okhttp3.MultipartBody;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.RequestBody;
import okhttp3.Response;


@Api
public class ImgurApi implements IApi {

    private Moshi moshi = new Moshi.Builder().build();

    private static final MediaType MEDIA_TYPE_JSON = MediaType.parse("text/json; charset=utf-8");
    private static final MediaType MEDIA_TYPE_PNG = MediaType.parse("image/png");

    public static final int apiId = 0;
    private static final String LOGIN_URL = "https://api.imgur.com/oauth2/authorize?client_id=" + BuildConfig.IMGUR_CLIENT + "&response_type=token&state=imgur&max_auth_age=0";
    private AppCompatActivity context = null;

    public ImgurApi(AppCompatActivity context) {
        this.context = context;
        ApiManager.getInstance().AddApi(this.getClass());
    }

    @Override
    @LoginInitializer(id = apiId)
    public void login() {
        AppDatabase.getInstance(context);

        Intent intent = new Intent(context, LoginActivity.class);
        intent.putExtra(LoginActivity.URL, LOGIN_URL);
        context.startActivity(intent);
    }

    @Override
    public void logout() {
        Account account = new Account();
        account.setName(context.getString(R.string.imgur));
        account.setTypeId(apiId);
        account.setAccessToken(null);
        account.setLogged(false);

        new UpdateAccount().execute(account);
    }


    @LoginHandler(uri = "login.imgur.epicture.epitech.eu")
    public void handleConnection(String url) {
        try {
            UrlParser parser = new UrlParser(url);

            final Account account = new Account();
            account.setTypeId(apiId);
            account.setName(context.getString(R.string.imgur));
            account.setAccessToken(parser.get("access_token"));
            account.setUsername(parser.get("account_username"));
            account.setLogged(true);

            LiveData<Account> data = AppDatabase.getInstance(null).accountDao().findOneById(apiId);

            data.observe(context, found -> {
                if (found == null)
                    new InsertAccount().execute(account);
                else
                    new UpdateAccount().execute(account);
                context.onBackPressed();
                data.removeObservers(context);
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @FavoriteGetHandler
    public LiveData<GalleryImage> getFavorites() {
        MutableLiveData<GalleryImage> data = new MutableLiveData<>();

        LiveData<Account> observer = AppDatabase.getInstance(context).accountDao().findOneById(apiId);

        observer.observe(context, account -> {
            observer.removeObservers(context);
            if (account != null && account.isLogged()) {
                OkHttpClient client = new OkHttpClient();

                Request request = new Request.Builder()
                        .url("https://api.imgur.com/3/account/" + account.getUsername() + "/favorites")
                        .addHeader("Authorization", "Bearer " + account.getAccessToken())
                        .build();

                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(@NonNull Call call, @NonNull IOException e) { e.printStackTrace(); }

                    @Override
                    public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                        try {
                            String ret = response.body().string();

                            JsonAdapter<GalleryImage> jsonAdapter = moshi.adapter(GalleryImage.class);
                            GalleryImage gallery = jsonAdapter.fromJson(ret);

                            data.postValue(gallery);
                        } catch (Exception e) { e.printStackTrace(); }
                    }
                });
            }

        });

        return data;
    }

    @FavoriteSetHandler
    public void setFavorite(String hash) {
        LiveData<Account> observer = AppDatabase.getInstance(context).accountDao().findOneById(apiId);
        observer.observe(context, account -> {
            observer.removeObservers(context);
            if (account != null && account.isLogged()) {
                OkHttpClient client = new OkHttpClient();

                RequestBody body = RequestBody.create(null, new byte[]{});

                Request request = new Request.Builder()
                        .url("https://api.imgur.com/3/image/" + hash + "/favorite")
                        .header("Authorization", "Bearer " + account.getAccessToken())
                        .post(body)
                        .build();

                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(Call call, IOException e) {

                    }

                    @Override
                    public void onResponse(Call call, Response response) throws IOException {

                    }
                });
            }
        });
    }

    @AccountImagesHandler
    public LiveData<GalleryImage> getAccountImages() {
        MutableLiveData<GalleryImage> data = new MutableLiveData<>();

        LiveData<Account> observer = AppDatabase.getInstance(context).accountDao().findOneById(apiId);

        observer.observe(context, account -> {
            observer.removeObservers(context);
            if (account != null && account.isLogged()) {
                OkHttpClient client = new OkHttpClient();

                Request request = new Request.Builder()
                        .url("https://api.imgur.com/3/account/me/images")
                        .addHeader("Authorization", "Bearer " + account.getAccessToken())
                        .build();

                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(@NonNull Call call, @NonNull IOException e) { e.printStackTrace(); }

                    @Override
                    public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                        try {
                            String ret = response.body().string();

                            System.out.println(ret);

                            JsonAdapter<GalleryImage> jsonAdapter = moshi.adapter(GalleryImage.class);
                            GalleryImage gallery = jsonAdapter.fromJson(ret);

                            data.postValue(gallery);
                        } catch (Exception e) { e.printStackTrace(); }
                    }
                });
            }

        });

        return data;
    }

    @UploadHandler
    public void uploadImage(ImageUpload image) {
        LiveData<Account> observer = AppDatabase.getInstance(context).accountDao().findOneById(apiId);

        observer.observe(context, account -> {
            observer.removeObservers(context);
            if (account != null && account.isLogged()) {
                OkHttpClient client = new OkHttpClient();

                RequestBody requestBody = new MultipartBody.Builder()
                        .setType(MultipartBody.FORM)
                        .addFormDataPart("title", image.title)
                        .addFormDataPart("description", image.description)
                        .addFormDataPart("type", image.type)
                        .addFormDataPart("name", image.name)
                        .addFormDataPart("image", image.name,
                                RequestBody.create(MEDIA_TYPE_PNG, new File(image.image)))
                        .build();

                Request request = new Request.Builder()
                        .url("https://api.imgur.com/3/image")
                        .header("Authorization", "Bearer " + account.getAccessToken())
                        .post(requestBody)
                        .build();

                client.newCall(request).enqueue(new Callback() {
                    @Override
                    public void onFailure(Call call, IOException e) {

                    }

                    @Override
                    public void onResponse(Call call, Response response) throws IOException {

                    }
                });
            }
        });
    }

    @SearchHandler
    public MutableLiveData<GalleryImage> search(String query) {
        MutableLiveData<GalleryImage> data = new MutableLiveData<>();

        OkHttpClient client = new OkHttpClient();

        final Request request = new Request.Builder()
                .header("Authorization", "Client-ID " + BuildConfig.IMGUR_CLIENT)
                .url("https://api.imgur.com/3/gallery/search/top/all/1?q=" + query)
                .build();

        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(@NonNull Call call, @NonNull IOException e) {}

            @Override
            public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                String ret = response.body().string();

                System.out.println(ret);


                JsonAdapter<GalleryImage> jsonAdapter = moshi.adapter(GalleryImage.class);

                data.postValue(jsonAdapter.fromJson(ret));
            }
        });
        return data;
    }
}
