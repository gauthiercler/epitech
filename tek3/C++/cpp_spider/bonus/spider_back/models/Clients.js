"use strict";

module.exports = (r, models) => {

    const { Clients } = models;

    return {
        create: function(params) {
            const { os, mac, antivirus } = params;
            const newCategory = new Clients({os, mac, antivirus});
            return newCategory.save()
        },

        getByMac: function(mac) {
            return (Clients.getAll(mac, {index: 'mac'}).limit(1).run());
        },

        listAllClients: function () {
            return (Clients.run());
        },
        subscribe: function (cb) {
            Clients.changes().run().then((feed) => {
                feed.each((e, d) => {
                    cb(d);
                })
            });
        }
    }
};