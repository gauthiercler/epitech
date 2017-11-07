// The Vue build version to load with the `import` command
// (runtime-only or standalone) has been set in webpack.base.conf with an alias.
import Vue from 'vue'
import App from './App'
import router from './router'
import Buefy from 'buefy'
import socketio from 'socket.io-client'
import SocketIO from 'vue-socket.io'
import 'buefy/lib/buefy.css'

Vue.config.productionTip = false
Vue.use(Buefy)

const socket = socketio('http://10.26.111.192:3333', {transports: ['websocket']})

Vue.use(SocketIO, socket)

/* eslint-disable no-new */
new Vue({
  el: '#app',
  router,
  template: '<App/>',
  components: { App }
})
