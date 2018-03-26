package eu.epitech.epicture.fragments;

import android.arch.lifecycle.LiveData;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.SearchView;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;

import java.util.ArrayList;
import java.util.List;

import eu.epitech.epicture.ImageActivity;
import eu.epitech.epicture.ImageGridAdapter;
import eu.epitech.epicture.R;
import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.api.imgur.Image;

public class SearchFragment extends Fragment {

    GridView gridView;
    private ImageGridAdapter adapter;

    private ArrayList<Image> images = new ArrayList<>();

    @Override
    public void onCreate(Bundle savedBundle) {
        super.onCreate(savedBundle);
        this.setRetainInstance(true);
    }


    @Override
    public void onCreateOptionsMenu( Menu menu, MenuInflater inflater) {
        inflater.inflate(R.menu.main, menu);

        MenuItem myActionMenuItem = menu.findItem(R.id.action_search);
        SearchView searchView = (SearchView) myActionMenuItem.getActionView();
        AppCompatActivity context = (AppCompatActivity) getActivity();

        searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
            @Override
            public boolean onQueryTextSubmit(String query) {

                if (!query.isEmpty()) {
                    AccountManager accountManager = new AccountManager();
                    LiveData<List<Image>> data = accountManager.search(context, query);
                    data.observe(context, images -> {
                        if (images != null) {
                            adapter = new ImageGridAdapter(context, images);
                            gridView.setAdapter(adapter);
                        }
                    });
                }

                if(!searchView.isIconified()) {
                    searchView.setIconified(true);
                }
                myActionMenuItem.collapseActionView();
                return false;
            }

            @Override public boolean onQueryTextChange(String newText) {return false;}
        });
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstane) {

        final View view = inflater.inflate(R.layout.fragment_search, container, false);
        setHasOptionsMenu(true);

        gridView = view.findViewById(R.id.grid_view_search);
        gridView.setAdapter(new ImageGridAdapter(this.getActivity(), images));

        return view;
    }

    @Override
    public void onViewCreated(@NonNull View view, Bundle savedInstance) {

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
