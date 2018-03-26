package eu.epitech.epicture;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.Toast;

import com.squareup.picasso.Picasso;

import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.api.imgur.Image;

public class ImageActivity extends AppCompatActivity {
    Image image = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_image);

        Bundle bundle = this.getIntent().getExtras();
        if (bundle != null) {
            image = (Image) bundle.getSerializable(Image.SERIALIZE_ID);
        }

        if (image != null) {
            ImageView imageView = findViewById(R.id.image_view);
            Picasso.with(this)
                    .load(image.link)
                    .into(imageView);
        }

        FloatingActionButton shareButton = findViewById(R.id.share_button);
        shareButton.setOnClickListener(v -> {
            ClipboardManager clipboardManager = (ClipboardManager)getSystemService(CLIPBOARD_SERVICE);
            clipboardManager.setPrimaryClip(ClipData.newPlainText("link", image.link));

            Toast toast = Toast.makeText(this, R.string.copy_link_toast, Toast.LENGTH_LONG);
            toast.show();
        });

        FloatingActionButton favoriteButton = findViewById(R.id.favorite_button);
        favoriteButton.setOnClickListener(v -> {

            AccountManager manager = new AccountManager();

            manager.setFavorite(this, image.id);
            Toast toast = Toast.makeText(this, R.string.update_favorite_toast, Toast.LENGTH_LONG);
            toast.show();
        });
    }
}
