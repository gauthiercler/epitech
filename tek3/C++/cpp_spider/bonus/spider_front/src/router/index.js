import Vue from 'vue'
import Router from 'vue-router'
import Home from '@/components/Home'
import Clients from '@/components/Clients'
import ClientsList from '@/components/clients/ClientsList'
import ClientView from '@/components/clients/ClientView'
import Logs from '@/components/Logs'

Vue.use(Router)

export default new Router({
  mode: 'history',
  routes: [
    {
      path: '/',
      name: 'home',
      component: Home
    },
    {
      path: '/client',
      component: Clients,
      children: [
        { path: '', component: ClientsList, name: 'client' },
        { path: ':mac', component: ClientView, props: true, name: 'client.view' }
      ]
    },
    {
      path: '/logs',
      component: Logs,
      name: 'logs'
    }
  ]
})
