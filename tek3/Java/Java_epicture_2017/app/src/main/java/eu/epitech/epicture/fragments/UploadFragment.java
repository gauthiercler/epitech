package eu.epitech.epicture.fragments;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.drawable.BitmapDrawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.provider.MediaStore;
import android.support.design.widget.TextInputLayout;
import android.support.v4.app.Fragment;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.util.Base64;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;

import com.squareup.picasso.Picasso;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;

import eu.epitech.epicture.LocalImageDownloader;
import eu.epitech.epicture.R;
import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.api.imgur.ImageUpload;
import eu.epitech.epicture.helpers.InputValidator;

public class UploadFragment extends Fragment {

    public static final int PICK_IMAGE = 1;
    public static final int TAKE_PICTURE = 2;

    private ImageView imageView;
    private boolean loadedImage = false;

    public UploadFragment() {}

    @Override
    public void onCreate(Bundle savedStateInstance) {
        super.onCreate(savedStateInstance);
        this.setRetainInstance(true);
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (resultCode == Activity.RESULT_OK) {
            this.loadedImage = true;

            switch (requestCode) {
                case PICK_IMAGE:
                    Uri imageUri;
                    imageUri = data.getData();
                    Picasso picassoInstance = new  Picasso.Builder(this.getActivity().getApplicationContext()).downloader(new LocalImageDownloader(this.getContext())).build();

                    picassoInstance.with(this.getActivity())
                            .load(imageUri)
                            .into(imageView);
                    break;
                case TAKE_PICTURE:
                    Bitmap bitmap = (Bitmap) data.getExtras().get("data");
                    imageView.setImageBitmap(bitmap);
                    break;
            }
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstane) {
        return inflater.inflate(R.layout.fragment_upload, container, false);
    }

    private void showPictureDialog(){
        AlertDialog.Builder pictureDialog = new AlertDialog.Builder(this.getContext());
        pictureDialog.setTitle(getText(R.string.select_action));
        String[] pictureDialogItems = {
                getString(R.string.select_from_gallery),
                getString(R.string.select_from_camera) };
        pictureDialog.setItems(pictureDialogItems,
                (dialog, which) -> {
                    switch (which) {
                        case 0:
                            choosePhotoFromGallery();
                            break;
                        case 1:
                            takePhotoFromCamera();
                            break;
                    }
                });
        pictureDialog.show();
    }

    private void choosePhotoFromGallery() {
        Intent pickPhoto = new Intent(Intent.ACTION_PICK,
                android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
        startActivityForResult(pickPhoto , PICK_IMAGE);
    }

    private void takePhotoFromCamera() {
        Intent takePicture = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
    startActivityForResult(takePicture, TAKE_PICTURE);
    }

    public String saveImageFile(Bitmap bitmap) {
        FileOutputStream out = null;
        String filename = getFilename();
        try {
            out = new FileOutputStream(filename);
            bitmap.compress(Bitmap.CompressFormat.PNG, 100, out);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return filename;
    }

    private String getFilename() {
        File file = getContext().getCacheDir();
        if (!file.exists()) {
            file.mkdirs();
        }
        String uriSting = (file.getAbsolutePath() + "/"
                + "tmp" + ".png");
        return uriSting;
    }

    private void uploadImage() {
        ImageUpload image = new ImageUpload();
        EditText title = this.getActivity().findViewById(R.id.image_title);
        EditText description = this.getActivity().findViewById(R.id.image_description);

        if (!this.loadedImage)
            return ;

        if (InputValidator.isNullOrEmpty(title.getText().toString())) {
            TextInputLayout til = this.getActivity().findViewById(R.id.image_title_layout);
            til.setError(getString(R.string.title_missing));
            return ;
        }

        if (InputValidator.isNullOrEmpty(description.getText().toString())) {
            TextInputLayout til = this.getActivity().findViewById(R.id.image_description_layout);
            til.setError(getString(R.string.description_missing));
            return ;
        }


         Bitmap bm = ((BitmapDrawable)imageView.getDrawable()).getBitmap();

        String path = saveImageFile(bm);

        image.description = description.getText().toString();
        image.title = title.getText().toString();
        image.type = "png";
        image.name  = image.title + "." + image.type;
        image.image = path;

        System.out.println(path);
        AccountManager manager = new AccountManager();

        manager.uploadImage((AppCompatActivity)this.getActivity(), image);
    }

    @Override
    public void onViewCreated(View view, Bundle savedInstanceState) {
        Button selectImage = view.findViewById(R.id.select_image_button);
        Button uploadImage = view.findViewById(R.id.upload_image_button);
        imageView = this.getActivity().findViewById(R.id.upload_image_preview);

        selectImage.setOnClickListener(v -> showPictureDialog());
        uploadImage.setOnClickListener(v -> uploadImage());
    }
}
