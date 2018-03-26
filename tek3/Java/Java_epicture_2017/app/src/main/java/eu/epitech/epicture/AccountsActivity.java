package eu.epitech.epicture;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ListView;

import eu.epitech.epicture.adapters.AccountAdapter;
import eu.epitech.epicture.api.imgur.ImgurApi;
import eu.epitech.epicture.models.Account;
import eu.epitech.epicture.tasks.InsertAccount;

public class AccountsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_accounts);
        ListView listView = findViewById(R.id.list);


        AppDatabase.getInstance(this).accountDao().findAll().observe(this, accounts -> {
            if (accounts == null || accounts.size() == 0)
                initAccounts();
            else
                listView.setAdapter(new AccountAdapter(this, R.layout.adapter_account, accounts));
        });
    }

    private void initAccounts() {
        Account account = new Account();
        account.setName(getString(R.string.imgur));
        account.setTypeId(ImgurApi.apiId);
        account.setLogged(false);

        new InsertAccount().execute(account);
    }
}
