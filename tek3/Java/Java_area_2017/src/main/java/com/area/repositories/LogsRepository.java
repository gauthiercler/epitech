package com.area.repositories;

import java.util.Date;
import java.util.LinkedList;

public class LogsRepository {

    //Instance
    static private LogsRepository logsRepository = new LogsRepository();
    LinkedList<Log> logs;

    private LogsRepository()
    {
        logs = new LinkedList<>();
    }

    private void cleanLogs()
    {
       logs.removeIf((Log log) -> (new Date().getTime() - log.getTime().getTime() > 600000));
    }

    public static LogsRepository getInstance()
    {
        return (logsRepository);
    }

    public void addLog(Log log)
    {
        cleanLogs();
        logs.addLast(log);
    }

    public boolean contains(Log log)
    {
        return (logs.contains(log));
    }

}
