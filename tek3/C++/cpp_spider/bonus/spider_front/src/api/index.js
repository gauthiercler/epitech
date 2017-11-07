import HTTP from '@/http-common'

export default {
  client: {
    getAll () { return HTTP.get('/client') },
    getByMac (mac) { return HTTP.get(`/client/${mac}`) }
  },
  logs: {
    getAll () { return HTTP.get('/logs') },
    getByMac (mac) { return HTTP.get(`/logs/${mac}`) }
  },
  commands: {
    create (mac, datas) {
      return HTTP.post(`/commands/${mac}`, datas)
    }
  },
  response: {
    getAll () { return HTTP.get('/response') },
    getAllByMac (mac) { return HTTP.get(`/response/${mac}`) }
  }
}
