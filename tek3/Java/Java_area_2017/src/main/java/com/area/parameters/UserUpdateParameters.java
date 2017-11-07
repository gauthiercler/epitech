package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

import java.util.List;

@Data
public class UserUpdateParameters implements Parameters.requestParameter {

    private String password;
    private List<String> roles;

    public boolean isValid() {
        return true;
    }
}
