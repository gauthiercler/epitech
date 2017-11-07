package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class FacebookAssociateParameters implements Parameters.requestParameter {

    private String accessToken;

    public boolean isValid() {
        return !accessToken.isEmpty();
    }
}
