package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class ModuleParameters implements Parameters.requestParameter {

    private String listener;
    private String handler;

    public boolean isValid()
    {
        return !listener.isEmpty() && !handler.isEmpty();
    }
}
