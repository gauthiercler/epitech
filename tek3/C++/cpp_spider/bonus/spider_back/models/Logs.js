"use strict";

module.exports = (r, models) => {

    const { Logs } = models;

    return {
        getAllLogs: function () {
            return (Logs.run());
        },

        findByMac: function (client_mac) {
            return (Logs.getAll(client_mac, {index: 'client_mac'}).run());
        },

        subscribe: function (cb) {
            Logs.changes().run().then((feed) => {
               feed.each((e, d) => {
                   cb(d);
                });
            });
        }
    }
};