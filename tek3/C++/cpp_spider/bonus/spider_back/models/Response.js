"use strict";

module.exports = (r, models) => {

    const { Response } = models;

    return {
        findByMac: function(mac) {
            return (Response.getAll(mac, {index: 'mac'}).run());
        },

        listAll: function () {
            return (Response.run());
        },

        subscribe: function (cb) {
            Response.changes().run().then((feed) => {
                feed.each((e, d) => {
                    cb(d);
                })
            });
        }
    }
};