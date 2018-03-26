package eu.epitech.epicture;

import android.content.Context;
import android.net.Uri;

import com.squareup.picasso.Downloader;

import java.io.IOException;
import java.io.InputStream;

public class LocalImageDownloader implements Downloader {

    private Context _context;

    public LocalImageDownloader(Context context) {
        _context = context;
    }

    @Override
    public Response load(Uri uri, int networkPolicy) throws IOException {
        InputStream in = _context.getContentResolver().openInputStream(Uri.parse(uri.getPath()));
        return new Response(in, false, -1);
    }

    @Override
    public void shutdown() {

    }
}
