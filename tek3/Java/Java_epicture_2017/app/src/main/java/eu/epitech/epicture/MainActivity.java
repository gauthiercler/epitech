package eu.epitech.epicture;

import android.support.annotation.NonNull;
import android.support.design.widget.BottomNavigationView;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.ActionBar;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MenuItem;

import eu.epitech.epicture.api.imgur.ImgurApi;
import eu.epitech.epicture.fragments.FavoriteFragment;
import eu.epitech.epicture.fragments.HomeFragment;
import eu.epitech.epicture.fragments.SearchFragment;
import eu.epitech.epicture.fragments.UploadFragment;

public class MainActivity extends AppCompatActivity {

    Fragment searchFragment;
    Fragment homeFragment;
    Fragment favoriteFragment;
    Fragment uploadFragment;

    private BottomNavigationView.OnNavigationItemSelectedListener mOnNavigationItemSelectedListener
            = new BottomNavigationView.OnNavigationItemSelectedListener() {

        @Override
        public boolean onNavigationItemSelected(@NonNull MenuItem item) {
            switch (item.getItemId()) {
                case R.id.navigation_home:
                    showFragment(homeFragment);
                    return true;
                case R.id.navigation_search:
                    showFragment(searchFragment);
                    return true;
                case R.id.navigation_favorite:
                    showFragment(favoriteFragment);
                    return true;
                case R.id.navigation_upload:
                    showFragment(uploadFragment);
                    return true;
            }
            return false;
        }

    };

    private void showFragment(Fragment fragment) {
        FragmentManager fragmentManager = getSupportFragmentManager();
        fragmentManager.beginTransaction()
                .setCustomAnimations(R.anim.fade_in, R.anim.fade_out)
                .replace(R.id.content, fragment)
                .addToBackStack(null)
                .commit();
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ActionBar bar = getSupportActionBar();
        if (bar != null) {
            bar.setDisplayShowTitleEnabled(false);
        }

        homeFragment = new HomeFragment();
        searchFragment = new SearchFragment();
        favoriteFragment = new FavoriteFragment();
        uploadFragment = new UploadFragment();

        BottomNavigationView navigation = findViewById(R.id.navigation);
        navigation.setOnNavigationItemSelectedListener(mOnNavigationItemSelectedListener);

        showFragment(new HomeFragment());
    }
}
