package eu.epitech.epicture;

import android.content.Context;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.squareup.picasso.Picasso;

import java.util.ArrayList;
import java.util.List;

import eu.epitech.epicture.api.imgur.Image;

public class ImageGridAdapter extends ArrayAdapter<Image> {
    private Context context;
    private LayoutInflater inflater;

    private ArrayList<Image> imageUrls;

    public ImageGridAdapter(Context context, List<Image> images) {
        super(context, R.layout.gridview_item_image, images);

        this.imageUrls = new ArrayList<>(images);

        this.context = context;


        inflater = LayoutInflater.from(context);
    }

    @NonNull
    @Override
    public View getView(int position, View convertView, @NonNull ViewGroup parent) {
            if (convertView == null) {
                convertView = inflater.inflate(R.layout.gridview_item_image, parent, false);
            }

            ImageView imageView = convertView.findViewById(R.id.grid_image);
            TextView textView = convertView.findViewById(R.id.grid_text);

            textView.setText(imageUrls.get(position).title);

            Picasso
                    .with(context)
                    .load(imageUrls.get(position).link)
                    .centerCrop()
                    .fit()
                    .into(imageView);
        return convertView;
    }
}

