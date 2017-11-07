// Auth module

import router from '@/router'

const API_URL = 'http://localhost:4567'
const LOGIN_URL = API_URL + '/login'
const SIGNUP_URL = API_URL + '/register'
const USERINFO = API_URL + '/user/'

export default {

  user: {
    auth: false
  },
  checkAuth () {
    this.user.auth = !!localStorage.getItem('token')
  },
  getAuth () {
    this.checkAuth()
    return (this.user.auth)
  },
  isAdmin () {
    return localStorage.getItem('admin')
  },
  getToken () {
    return localStorage.getItem('token')
  },
  getId () {
    return localStorage.getItem('id')
  },
  sign (self, resp) {
    resp.json().then((data) => {
      this.user.auth = true
      localStorage.setItem('token', data.token)
      localStorage.setItem('id', data.id)
      this.getRole(self)
    })
  },
  getRole (self) {
    self.$http.get(USERINFO + this.getId(), {
      headers: {
        'token': this.getToken()
      }
    }).then((resp) => {
      resp.json().then(data => {
        if (data['roles'].indexOf('ADMIN') !== -1) {
          localStorage.setItem('admin', true)
        } else {
          localStorage.setItem('admin', false)
        }
        // router.go('/')
      })
    })
  },
  login (self, props, onSuccess, onError) {
    self.$http.post(LOGIN_URL, props).then((resp) => {
      onSuccess()
      this.sign(self, resp)
    }, onError)
  },
  register (self, props, onSuccess, onError) {
    self.$http.post(SIGNUP_URL, props).then((resp) => {
      this.sign(self, resp)
      onSuccess()
    }, onError)
  },
  sendToken (self, tokenURL, token, onSuccess, onError) {
    self.$http.post(tokenURL, token, {
      headers: {
        'token': this.getToken()
      }
    }).then(onSuccess, onError)
  },
  disconnect () {
    localStorage.setItem('token', '')
    localStorage.setItem('id', '')
    localStorage.setItem('admin', false)
    router.go('/login')
  }

}
