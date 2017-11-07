package com.area.parameters;

import com.area.helpers.Parameters;
import lombok.Data;

@Data
public class EmailParameters implements Parameters.requestParameter {
    private String subject;
    private String message;

    public boolean isValid()
    {
        return (subject != null && !subject.isEmpty()
                && message != null && !message.isEmpty());
    }

}
