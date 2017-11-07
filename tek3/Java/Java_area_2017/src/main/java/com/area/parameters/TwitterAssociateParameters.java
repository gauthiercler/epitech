package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class TwitterAssociateParameters implements Parameters.requestParameter {

    private String accessToken;
    private String accessTokenSecret;

    public boolean isValid() {
        return !accessToken.isEmpty() && !accessTokenSecret.isEmpty();
    }
}
