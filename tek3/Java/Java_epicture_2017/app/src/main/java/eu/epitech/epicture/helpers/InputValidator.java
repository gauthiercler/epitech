package eu.epitech.epicture.helpers;

import android.text.TextUtils;

public class InputValidator {
    public static boolean isNullOrEmpty(String string) {
        return TextUtils.isEmpty(string.trim());
    }

}
