"use strict";

module.exports = (r, models) => {

    const { Commands } = models;

    return {
        create: function(params) {
            const { client_mac, type, data } = params;
            const command = new Commands({ client_mac, type, data});
            return command.save();
        }
    }
};