package eu.epitech.epicture.fragments;

import android.arch.lifecycle.LiveData;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.v4.app.Fragment;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.GridView;

import java.util.List;

import eu.epitech.epicture.AccountsActivity;
import eu.epitech.epicture.ImageActivity;
import eu.epitech.epicture.ImageGridAdapter;
import eu.epitech.epicture.R;
import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.api.imgur.Image;

public class HomeFragment extends Fragment {
    private ImageGridAdapter adapter;

    public HomeFragment() {

    }

    @Override
    public void onCreate(Bundle savedInstance) {
        super.onCreate(savedInstance);
        setHasOptionsMenu(true);
        this.setRetainInstance(true);
    }

    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, ViewGroup container, Bundle savedInstane) {
        View view = inflater.inflate(R.layout.fragment_home, container, false);

        GridView gridView = view.findViewById(R.id.grid_view_perso);

        AccountManager accountManager = new AccountManager();
        LiveData<List<Image>> data = accountManager.getAccountsImages((AppCompatActivity) this.getActivity());
        data.observe(this.getActivity(), images -> {
            if (images != null) {
                adapter = new ImageGridAdapter(this.getActivity(), images);
                gridView.setAdapter(adapter);
            }
        });

        gridView.setOnItemClickListener((parent, view1, position, id) -> {
            Image image = adapter.getItem(position);

            Intent intent = new Intent(getActivity(), ImageActivity.class);
            Bundle bundle = new Bundle();
            bundle.putSerializable(Image.SERIALIZE_ID, image);
            intent.putExtras(bundle);
            startActivity(intent);
        });

        return view;
    }

    @Override
    public void onCreateOptionsMenu(Menu menu, MenuInflater inflater) {
        inflater.inflate(R.menu.login, menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.accounts:
                goToAccounts();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    private void goToAccounts() {
        Intent intent = new Intent(this.getActivity(), AccountsActivity.class);
        startActivity(intent);
    }
}
