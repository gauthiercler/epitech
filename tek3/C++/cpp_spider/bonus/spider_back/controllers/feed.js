"use strict";

module.exports = (router, models, io) => {
    const { Clients, Logs, Response } = models;

    Clients.subscribe((msg) => {
        io.sockets.emit('newClient', msg);
    });

    Logs.subscribe((msg) => {
        io.sockets.emit('newLog', msg);
    });

    Response.subscribe((msg) => {
        io.sockets.emit('newResponse', msg);
    });

    io.on('connection', (socket) => {
        console.log('Connected');
    });
};