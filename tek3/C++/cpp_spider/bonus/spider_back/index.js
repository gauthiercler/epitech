"use strict";

import 'babel-polyfill'
import express    from 'express'
import bodyParser from 'body-parser'
import { Server } from 'http'
import socketio from 'socket.io'
import cors from 'cors'

const app     = express();
const http = Server(app);
const io = socketio(http);


app.use(bodyParser.json());
app.use(bodyParser.urlencoded({extended: true}));
app.use(cors());

const config  = require('./config');
const models = require('./schema')(config);
app.use(require('express-status-monitor')());
require('./routes')(app, models, io);
require('./controllers/feed')(app, models, io);


http.listen(config.express.port, function() {
    console.log('Express server listening on port ' + config.express.port + '.')
})