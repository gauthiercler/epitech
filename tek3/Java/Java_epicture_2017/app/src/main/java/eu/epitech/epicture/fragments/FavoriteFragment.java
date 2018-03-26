package eu.epitech.epicture.fragments;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.Fragment;
import android.support.v4.widget.SwipeRefreshLayout;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.GridView;

import eu.epitech.epicture.ImageActivity;
import eu.epitech.epicture.ImageGridAdapter;
import eu.epitech.epicture.R;
import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.api.imgur.Image;

public class FavoriteFragment extends Fragment {
    GridView gridView;
    SwipeRefreshLayout swipeContainer;
    private ImageGridAdapter adapter;

    public void requestFavorite() {
        AccountManager manager = new AccountManager();
        manager.getFavorite((AppCompatActivity)this.getActivity()).observe(this, images -> {
            adapter = new ImageGridAdapter(FavoriteFragment.this.getActivity(), images);
            gridView.setAdapter(adapter);
            swipeContainer.setRefreshing(false);
        });
    }

    @Override
    public void onCreate(Bundle savedInstance) {
        super.onCreate(savedInstance);
        this.setRetainInstance(true);
    }

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstane) {
        return inflater.inflate(R.layout.fragment_favorite, container, false);
    }

    @Override
    public void onViewCreated(@NonNull View view, Bundle savedInstanceState) {
        swipeContainer = this.getActivity().findViewById(R.id.swipe_container);
        swipeContainer.setOnRefreshListener(FavoriteFragment.this::requestFavorite);
        gridView = view.findViewById(R.id.grid_view_favorite);
        this.requestFavorite();

        swipeContainer.setColorSchemeResources(android.R.color.holo_blue_bright,
                android.R.color.holo_green_light,
                android.R.color.holo_orange_light,
                android.R.color.holo_red_light);

        gridView.setOnItemClickListener((parent, view1, position, id) -> {
            Image image = adapter.getItem(position);

            Intent intent = new Intent(getActivity(), ImageActivity.class);
            Bundle bundle = new Bundle();
            bundle.putSerializable(Image.SERIALIZE_ID, image);
            intent.putExtras(bundle);
            startActivity(intent);
        });
    }
}
