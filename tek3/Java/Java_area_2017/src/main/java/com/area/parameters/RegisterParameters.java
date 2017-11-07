package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class RegisterParameters implements Parameters.requestParameter {
    private String username;
    private String password;
    private String email;

    public boolean isValid() {
        return username != null && !username.isEmpty() &&
                password != null && !password.isEmpty() &&
                email != null && !email.isEmpty();
    }
}