package eu.epitech.epicture;


import android.arch.persistence.room.Database;
import android.arch.persistence.room.Room;
import android.arch.persistence.room.RoomDatabase;
import android.content.Context;

import eu.epitech.epicture.dao.AccountDao;
import eu.epitech.epicture.models.Account;

@Database(entities = {Account.class}, version = 3)
public abstract class AppDatabase extends RoomDatabase {

    private static final String DB_NAME = "data.db";

    public abstract AccountDao accountDao();


    private static AppDatabase instance;

    public static AppDatabase getInstance(Context context) {
        if (instance == null) {
            instance = create(context);
        }
        return instance;
    }

    private static AppDatabase create(final Context context) {
        return Room.databaseBuilder(
                context,
                AppDatabase.class,
                DB_NAME)
                .fallbackToDestructiveMigration() // TODO Use migrations instead
                .build();
    }
}

