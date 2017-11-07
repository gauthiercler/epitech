package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class LoginParameters implements Parameters.requestParameter {
    private String username;
    private String password;

    public boolean isValid() {
        return username != null && !username.isEmpty() &&
                password != null && !password.isEmpty();
    }
}
