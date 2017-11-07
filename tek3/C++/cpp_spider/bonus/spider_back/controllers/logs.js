"use strict";

module.exports = (router, models) => {

    const { Logs } = models;

    router.get('/', async (req, res) => {
        try {
            let logs = await Logs.getAllLogs();
            res.json({data: logs});
        } catch (e) {
            res.sendStatus(500);
        }
    });

    router.get('/:mac', async (req, res) => {
        try {
            let logs = await Logs.findByMac(req.params.mac);
            res.json({data: logs});
        } catch(e) {
            res.sendStatus(500);
        }
    });

};