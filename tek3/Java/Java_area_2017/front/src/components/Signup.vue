<template>
  <section id="content">
    <header-bar></header-bar>
    <section id="body">
      <section id="form" v-if="!auth">
        <h1 class="title">Signup</h1>
        <form v-on:submit="onFormSubmit">
          <label>
            <input type="text" v-model="username" placeholder="username">
          </label>
          <label>
            <input type="password" v-model="password">
          </label>
          <label>
            <input type="email" v-model="email" placeholder="email">
          </label>
          <input type="submit">
        </form>
        <div id="profil">
          <h3>Username</h3>
          <p>{{username}}</p>
          <h3>Email</h3>
          <p>{{email}}</p>
        </div>
        <div class="success" v-if="signSuccess" v-on:click="removeMessages">
          <p>
            Your account is created !<br>
            Check your email ;)
          </p>
        </div>
        <div class="error" v-if="signErr" v-on:click="removeMessages">
          <p>
            Error we couldn't create your account :/
          </p>
        </div>
      </section>
      <section v-else>
        <h1 class="title">You already have an account</h1>
      </section>
    </section>
    <footer-bar></footer-bar>
  </section>
</template>

<script>
  import Header from '@/components/Header'
  import Footer from '@/components/Footer'
  import Auth from '../auth'

  export default {
    name: 'Signup',
    data: function () {
      return {
        username: '',
        password: '',
        email: '',
        auth: Auth.getAuth(),
        signErr: false,
        signSuccess: false
      }
    },
    components: {
      'header-bar': Header,
      'footer-bar': Footer
    },
    methods: {
      onFormSubmit (e) {
        e.preventDefault()
        let data = {}
        data['username'] = this.username
        data['password'] = this.password
        data['email'] = this.email
        Auth.register(this, JSON.stringify(data), () => {
          this.signSuccess = true
        }, () => {
          this.signErr = true
        })
      },
      removeMessages (e) {
        this.signErr = false
        this.signSuccess = false
      }
    }
  }
</script>

<style>
  .title {
    margin-bottom: 2%;
  }

  #profil {
    margin-top: 2%;
  }

  #profil h3 {
    margin-bottom: 0.5%;
    margin-top: 0.5%;
  }

</style>
