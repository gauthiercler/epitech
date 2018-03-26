package eu.epitech.epicture.api;


import android.arch.lifecycle.LiveData;
import android.arch.lifecycle.MutableLiveData;
import android.support.v7.app.AppCompatActivity;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;

import eu.epitech.epicture.api.handlers.AccountImagesHandler;
import eu.epitech.epicture.api.handlers.FavoriteGetHandler;
import eu.epitech.epicture.api.handlers.FavoriteSetHandler;
import eu.epitech.epicture.api.handlers.LoginInitializer;
import eu.epitech.epicture.api.handlers.SearchHandler;
import eu.epitech.epicture.api.handlers.UploadHandler;
import eu.epitech.epicture.api.imgur.GalleryImage;
import eu.epitech.epicture.api.imgur.Image;
import eu.epitech.epicture.api.imgur.ImageUpload;
import eu.epitech.epicture.api.imgur.ImgurApi;

public class AccountManager {

    private static final List<Class> apis = new ArrayList<Class>() {{
        add(ImgurApi.class);
    }};

    public LiveData<List<Image>> getFavorite(AppCompatActivity context) {
        MutableLiveData<List<Image>> data = new MutableLiveData<>();
        data.setValue(new ArrayList<>());

        for (Class clazz : apis) { // TODO Change with reflexion
            for (Method method : clazz.getMethods()) {
                FavoriteGetHandler favoriteHandler = method.getAnnotation(FavoriteGetHandler.class);
                if (favoriteHandler != null) {
                    try {
                        LiveData<GalleryImage> observer = (LiveData<GalleryImage>) method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context));
                        observer.observe(context, galleryImage -> {
                                    observer.removeObservers(context);
                                    List<Image> list = data.getValue();
                                    list.addAll(galleryImage.data);
                                    data.postValue(filterUrls(list));
                                }
                        );
                    } catch (Exception ignored) {
                    }
                }

            }
        }
        return data;
    }

    public boolean uploadImage(AppCompatActivity context, ImageUpload image) {
        try {
            for (Class clazz : apis) { // TODO Change with reflexion
                for (Method method : clazz.getMethods()) {
                    UploadHandler uploadHandler = method.getAnnotation(UploadHandler.class);
                    if (uploadHandler != null) {
                        method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context), image);
                        return true;
                    }
                }
            }
        } catch (Exception ignored) { ignored.printStackTrace(); }
        return false;
    }

    public boolean setFavorite(AppCompatActivity context, String hash) {
        try {
            for (Class clazz : apis) { // TODO Change with reflexion
                for (Method method : clazz.getMethods()) {
                    FavoriteSetHandler favoriteHandler = method.getAnnotation(FavoriteSetHandler.class);
                    if (favoriteHandler != null) {
                        method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context), hash);
                        return true;
                    }
                }
            }
        } catch (Exception ignored) { ignored.printStackTrace(); }
        return false;
    }


    public LiveData<List<Image>> search(AppCompatActivity context, String query) {
        MutableLiveData<List<Image>> data = new MutableLiveData<>();
        data.setValue(new ArrayList<>());

        for (Class clazz : apis) { // TODO Change with reflexion
            for (Method method : clazz.getMethods()) {
                SearchHandler favoriteHandler = method.getAnnotation(SearchHandler.class);
                if (favoriteHandler != null) {
                    try {
                        LiveData<GalleryImage> observer = (LiveData<GalleryImage>) method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context), query);
                        observer.observe(context, galleryImage -> {
                                    observer.removeObservers(context);
                                    List<Image> list = data.getValue();
                                    list.addAll(galleryImage.data);
                                    data.postValue(filterUrls(list));
                                }
                        );
                    } catch (Exception ignored) {
                    }
                }

            }
        }
        return data;
    }

    public LiveData<List<Image>> getAccountsImages(AppCompatActivity context) {
        MutableLiveData<List<Image>> data = new MutableLiveData<>();
        data.setValue(new ArrayList<>());

        for (Class clazz : apis) { // TODO Change with reflexion
            for (Method method : clazz.getMethods()) {
                AccountImagesHandler imagesHandler = method.getAnnotation(AccountImagesHandler.class);
                if (imagesHandler != null) {
                    try {
                        LiveData<GalleryImage> observer = (LiveData<GalleryImage>) method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context));
                        observer.observe(context, galleryImage -> {
                                    observer.removeObservers(context);
                                    List<Image> list = data.getValue();
                                    list.addAll(galleryImage.data);
                                    data.postValue(filterUrls(list));
                                }
                        );
                    } catch (Exception ignored) {
                    }
                }

            }
        }
        return data;
    }

    public boolean login(AppCompatActivity context, int apiId) {
        try {
            for (Class clazz : apis) { // TODO Change with reflexion
                for (Method method : clazz.getMethods()) {
                    LoginInitializer loginHandler = method.getAnnotation(LoginInitializer.class);
                    if (loginHandler != null && loginHandler.id() == apiId) {
                        method.invoke(clazz.getConstructor(AppCompatActivity.class).newInstance(context));
                        return true;
                    }
                }
            }
        } catch (Exception ignored) { ignored.printStackTrace(); }
        return false;
    }

    private List<Image> filterUrls(List<Image> images) {
        ArrayList<Image> filtered = new ArrayList<>();


        for (Image image : images) {

            if (image != null && (image.is_album == null || !image.is_album))
                filtered.add(image);
        }

        return filtered;
    }
}
