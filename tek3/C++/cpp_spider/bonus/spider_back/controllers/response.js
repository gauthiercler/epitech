"use strict";

module.exports = (router, models) => {
    const { Response } = models;

    router.get('/', async (req, res) => {
        try {
            let cli = await Response.listAll();
            res.json({
                data: cli
            });
        } catch (e) {
            res.sendStatus(500);
        }
    });

    router.get('/:mac', async (req, res) => {
        try {
            let client = await Response.findByMac(req.params.mac);
            res.json({data: client});
        } catch (e) {
            res.sendStatus(500);
        }
    });
};