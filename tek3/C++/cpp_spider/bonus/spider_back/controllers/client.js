"use strict";

module.exports = (router, models) => {
    const { Clients } = models;

    router.get('/', async (req, res) => {
        try {
            let cli = await Clients.listAllClients();
            res.json({
                data: cli
            });
        } catch (e) {
            res.sendStatus(500);
        }
    });

    router.get('/:mac', async (req, res) => {
        try {
            let client = await Clients.getByMac(req.params.mac);
            res.json({data: client[0]});
        } catch (e) {
            res.sendStatus(500);
        }
    });
};