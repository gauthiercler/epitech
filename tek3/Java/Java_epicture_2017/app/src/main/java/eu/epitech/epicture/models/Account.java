package eu.epitech.epicture.models;


import android.arch.persistence.room.ColumnInfo;
import android.arch.persistence.room.Entity;
import android.arch.persistence.room.PrimaryKey;

import lombok.Getter;
import lombok.Setter;

@Entity
public class Account {

    @PrimaryKey
    @Getter @Setter private int typeId;

    @ColumnInfo(name = "name")
    @Getter @Setter private String name;

    @ColumnInfo(name = "access_token")
    @Getter @Setter private String accessToken;

    @ColumnInfo(name = "username")
    @Getter @Setter private String username;

    @ColumnInfo(name = "logged")
    @Getter @Setter private boolean logged;
}
