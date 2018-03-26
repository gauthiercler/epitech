package eu.epitech.epicture.adapters;


import android.annotation.SuppressLint;
import android.content.Context;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.TextView;

import java.util.List;

import eu.epitech.epicture.R;
import eu.epitech.epicture.api.AccountManager;
import eu.epitech.epicture.models.Account;
import eu.epitech.epicture.tasks.UpdateAccount;

public class AccountAdapter extends ArrayAdapter<Account> {

    private Context context;

    public AccountAdapter(Context context, int textViewResourceId) {
        super(context, textViewResourceId);
        this.context = context;
    }

    public AccountAdapter(Context context, int resource, List<Account> items) {
        super(context, resource, items);
        this.context = context;
    }

    @SuppressLint({"InflateParams", "SetTextI18n"})
    @NonNull
    @Override
    public View getView(int position, View convertView, @NonNull ViewGroup parent) {

        View view = convertView;

        if (view == null) {
            LayoutInflater vi;
            vi = LayoutInflater.from(getContext());
            view = vi.inflate(R.layout.adapter_account, null);
        }

        Account acc = getItem(position);

        if (acc != null) {
            String nameStr = acc.getName();
            TextView name = view.findViewById(R.id.name);
            Button action = view.findViewById(R.id.button);

            if (acc.isLogged())
                nameStr += " (" + acc.getUsername() + ")";
            if (name != null)
                name.setText(nameStr);

            if (action != null) {
                if (acc.isLogged()) {
                    action.setText(context.getText(R.string.disconnect));
                    action.setOnClickListener(v -> logout(acc));
                } else {
                    action.setText(context.getText(R.string.connect));
                    action.setOnClickListener(v -> login(acc));
                }
            }
        }

        return view;
    }

    private void login(Account acc) {
        AccountManager manager = new AccountManager();
        manager.login((AppCompatActivity)context, acc.getTypeId());
    }

    private void logout(Account acc) {
        acc.setLogged(false);
        new UpdateAccount().execute(acc);
    }

}