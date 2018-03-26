package eu.epitech.epicture.tasks;


import android.os.AsyncTask;

import eu.epitech.epicture.AppDatabase;
import eu.epitech.epicture.models.Account;

public class InsertAccount extends AsyncTask<Account, Void, Void> {
    @Override
    protected Void doInBackground(Account... accounts) {
        AppDatabase.getInstance(null).accountDao().insert(accounts);
        return null;
    }
}
