module.exports = config => {
    const thinky    = require('thinky')(config.rethinkdb);
    const r         = thinky.r;
    const type      = thinky.type;
    const regex = "\\b([0-9a-fA-F]{2}:??){5}([0-9a-fA-F]{2})\\b";
    const flag = "";

    const Clients = thinky.createModel("clients", {
        os:        type.string().required(),
        mac:       type.string().regex(regex, flag).required(),
        antivirus: type.string().required()
    });

    Clients.ensureIndex('mac');

    const Commands = thinky.createModel("commands", {
        client_mac: type.string().regex(regex, flag).required(),
        type:       type.string().required(),
        data:       type.string().required()
    });

    Commands.ensureIndex('client_mac');

    const Logs = thinky.createModel("logs", {
        client_mac: type.string().regex(regex, flag),
        timestamp:  type.number().required(),
        process:    type.string().required(),
        data:       type.any().required(),
        type:       type.string().required()
    });

    Logs.ensureIndex('client_mac');

    const Ping = thinky.createModel("ping", {
        type:       type.string().required(),
        data:       type.number().required()
    });

    const Response = thinky.createModel("responses", {
        mac:        type.string().regex(regex, flag).required(),
        type:       type.string().required(),
        timestamp:  type.number().required(),
        command:    type.string().required(),
        stdout:     type.string().required(),
        stderr:     type.string().required(),
        exitcode:   type.number().required()
    });

    Response.ensureIndex('mac');

    const allModels = { Clients, Commands, Logs, Ping, Response };

    return {
        Clients:     require('./models/Clients')(r, allModels),
        Commands:    require('./models/Command')(r, allModels),
        Logs:        require('./models/Logs')(r, allModels),
        Ping:        require('./models/Ping')(r, allModels),
        Response:     require('./models/Response')(r, allModels)
    }

};