package eu.epitech.epicture.api.imgur;

import java.io.Serializable;

public class Image implements Serializable {
    public static final String SERIALIZE_ID = "Image";
    public String id;
    public String title;
    public String description;
    public Integer dateTime;
    public String type;
    public Boolean animated;
    public Integer width;
    public Integer height;
    public Integer size;
    public Integer views;
    public String bandwidth;
    public String deletehash;
    public String link;
    public String gifv;
    public String mp4;
    public Integer mp4_size;
    public Boolean looping;
    public String vote;
    public Boolean favorite;
    public Boolean nsfw;
    public Integer comment_count;
    public String topic;
    public Integer topic_id;
    public String section;
    public String account_url;
    public Integer account_id;
    public Integer ups;
    public Integer downs;
    public Integer points;
    public Integer score;
    public Boolean is_album;
}
