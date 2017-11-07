<template>
  <section id="content">
    <header-bar></header-bar>
    <section id="body">
      <h1>Welcome to Area</h1>
      <div v-if="!auth">
        <div class="half">
          <h2>Sign In !</h2>
          <router-link class="custom-button" to="/login">Sign in</router-link>
        </div>
        <div class="half">
          <h2>Sign Up !</h2>
          <router-link class="custom-button" to="/signup">Sign up</router-link>
        </div>
      </div>
      <div id="panel" v-else>
        <ul id="links">
          <li><router-link to="/modules">Modules</router-link></li>
          <li><a @click="disconnect">Disconnect</a></li>
          <li v-if="admin"><router-link to="/admin">Admin</router-link></li>
        </ul>
        <div id="tokens">
          <div id="dropbox">
            <img src="../assets/dropbox.png" width="50">
            <form v-on:submit="onSubmitDropbox">
              <input type="text" v-model="dropboxToken" placeholder="Dropbox Token">
              <input type="submit">
            </form>
          </div>
          <div id="facebook">
            <img src="../assets/facebook.png" width="50">
            <form v-on:submit="onSubmitFacebook">
              <input type="text" v-model="facebookToken" placeholder="Facebook Token">
              <input type="submit">
            </form>
          </div>
          <div id="twitter">
            <img src="../assets/twitter.png" width="50">
            <form v-on:submit="onSubmitTwitter">
              <input type="text" v-model="twitterToken" placeholder="Twitter Token">
              <input type="text" v-model="secretTwitterToken" placeholder="Secret Twitter Token">
              <input type="submit">
            </form>
          </div>
        </div>
      </div>
      <div class="success" v-if="sendSuccess" v-on:click="removeMessages">
        <p>
          Your token is send !
        </p>
      </div>
      <div class="error" v-if="sendErr" v-on:click="removeMessages">
        <p>
          Error we couldn't send your token :(
        </p>
      </div>
    </section>
    <footer-bar></footer-bar>
  </section>
</template>

<script>
  import Header from '@/components/Header'
  import Footer from '@/components/Footer'
  import Auth from '../auth'

  export default {
    name: 'Home',
    components: {
      'header-bar': Header,
      'footer-bar': Footer
    },
    data: function () {
      return {
        auth: Auth.getAuth(),
        admin: false,
        dropboxToken: '',
        facebookToken: '',
        twitterToken: '',
        secretTwitterToken: '',
        sendErr: false,
        sendSuccess: false
      }
    },
    created () {
      this.auth = Auth.getAuth()
      if (this.auth) {
        this.$http.get('http://localhost:4567/user/' + Auth.getId(), {
          headers: {
            'token': Auth.getToken()
          }
        }).then((resp) => {
          resp.json().then(data => {
            if (data['roles'].indexOf('ADMIN') !== -1) {
              this.admin = true
            }
          })
        })
      }
    },
    methods: {
      disconnect () {
        Auth.disconnect()
        this.auth = Auth.getAuth()
      },
      submit (tokenURL, token) {
        Auth.sendToken(this, tokenURL, token, () => {
          this.sendSuccess = true
        }, (err) => {
          console.log(err)
          this.sendErr = true
        })
      },
      onSubmitDropbox (e) {
        e.preventDefault()
        this.submit('http://localhost:4567/user/' + Auth.getId() + '/dropbox', { accessToken: this.dropboxToken })
      },
      onSubmitFacebook (e) {
        e.preventDefault()
        this.submit('http://localhost:4567/user/' + Auth.getId() + '/facebook', { accessToken: this.facebookToken })
      },
      onSubmitTwitter (e) {
        e.preventDefault()
        this.submit('http://localhost:4567/user/' + Auth.getId() + '/twitter', {
          accessToken: this.twitterToken,
          accessTokenSecret: this.secretTwitterToken
        })
      },
      removeMessages (e) {
        this.sendErr = false
        this.sendSuccess = false
      }
    }
  }
</script>

<style>

  .half {
    display: inline-block;
    width: 45vw;
    margin-top: 2%;
  }

  .half h2 {
    width: 100%;
    margin: auto auto 10%;
  }

  .custom-button {
    padding: 1%;
    background: #335fc9ad;
    border-radius: 4%;
    text-transform: uppercase;
    color: white;
    font-weight: 900;
    box-shadow: 0 0 1px 0 gray;
    transition: all 0.4s ease;
  }

  .custom-button:hover {
    background: #6189eab3;
    box-shadow: 0 0 3px 0 gray;
  }

  #disconnect {
    cursor: pointer;
    margin-top: 2%;
  }

  #links {
    display: block;
    width: 25%;
    height: 100%;
    margin-bottom: 2%;
  }

  #links li {
    list-style: none;
    display: block;
    padding: 5%;
    background: #3cb8e9b3;
    box-shadow: 0 0 1px 0 black;
    transition: all 0.6s ease;
    margin-bottom: 2%;
  }

  #links li:hover {
    background: #2f7cd2b3 !important;
    box-shadow: 0 0 3px 0 black !important;
  }

  #links li:hover a {
    transform: scale(2);
  }

  #links a {
    cursor: pointer;
    color: white;
    text-transform: uppercase;
    font-size: 20px;
    font-weight: 900;
  }

  #tokens {
    width: 70%;
  }

  #panel {
    display: inline-flex;
    width: 100%;
    margin-top: 3%;
  }

  #dropbox, #facebook, #twitter {
    width: 100%;
    margin: 2%;
  }

  #dropbox img, #facebook img, #twitter img {
    transition: all 0.7s ease;
  }

  #dropbox:hover img, #facebook:hover img, #twitter:hover img {
    transform: scale(1.2);
  }

  #dropbox img, #facebook img, #twitter img {
    margin: auto;
  }

  #dropbox form, #facebook form, #twitter form {
    margin: auto;
  }

</style>
