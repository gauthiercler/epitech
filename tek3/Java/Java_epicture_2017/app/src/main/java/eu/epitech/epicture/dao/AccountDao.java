package eu.epitech.epicture.dao;


import android.arch.lifecycle.LiveData;
import android.arch.persistence.room.Dao;
import android.arch.persistence.room.Insert;
import android.arch.persistence.room.Query;
import android.arch.persistence.room.Update;

import java.util.List;

import eu.epitech.epicture.models.Account;

@Dao
public interface AccountDao {

    @Query("SELECT * FROM account WHERE typeId = :id LIMIT 1")
    LiveData<Account> findOneById(int id);

    @Query("SELECT * FROM account")
    LiveData<List<Account>> findAll();

    @Insert
    void insert(Account... accounts);

    @Update
    void update(Account... accounts);

}
