var webpack = require('webpack');
var path    = require('path');
var fs      = require('fs');
var StartServerPlugin = require('start-server-webpack-plugin');
var nodeModules = {};

fs.readdirSync('node_modules')
    .filter(function(x) {
        return ['.bin'].indexOf(x) === -1;
    })
    .forEach(function(mod) {
        nodeModules[mod] = 'commonjs ' + mod;
    });

module.exports = {
    watch: false,
    entry: ['./index.js'],
    target: 'node',
    output: {
        path: path.join(__dirname, 'dist'),
        filename: 'index.js'
    },
    externals: nodeModules,
    module: {
        loaders: [{
            test: /\.jsx?$/,
            exclude: ['/node_modules/', '/dist/'],
            loader: 'babel-loader',
            query: {
                presets: ['es2015', 'stage-0']
            }
        }]
    },
    plugins: [
        new StartServerPlugin('index.js')
    ]

};