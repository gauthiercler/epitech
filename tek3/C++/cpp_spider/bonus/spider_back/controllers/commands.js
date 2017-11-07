"use strict";

module.exports = (router, models) => {

    const { Commands } = models;

    router.post('/:mac', async (req, res) => {
        try {
            Commands.create({
                client_mac: req.params.mac,
                type: req.body.type,
                data: req.body.data
            });
            res.json({
                success: true
            })
        } catch (e) {
            res.sendStatus(500);
        }
    });
};