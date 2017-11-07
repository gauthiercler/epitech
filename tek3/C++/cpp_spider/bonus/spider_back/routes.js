import express from 'express'

const routes = [
    'client',
    'logs',
    'commands',
    'response'
];

/*const nestedRoutes = new Map();
nestedRoutes.set('users', ['posts']);*/

module.exports = (app, models) => {

    for (let route of routes) {
        let router = express.Router();
        require(`./controllers/${route}`)(router, models);
        app.use(`/${route}`, router)
    }

    /*  for (let [parent, routes] of nestedRoutes) {
        for (let route of routes) {
          let nestedRouter = express.Router({mergeParams: true});
          require(`./controllers/${route}`)(nestedRouter, models);
          app.use(`/${parent}/:id/${route}`, nestedRouter)
        }
      }*/

};
