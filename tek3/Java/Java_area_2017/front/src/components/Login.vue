<template>
  <section id="content">
    <header-bar></header-bar>
    <section id="body">
      <section id="form" v-if="!auth">
        <h1 class="title">Login</h1>
        <form v-on:submit="onFormSubmit">
          <label>
            <input type="text" v-model="username" placeholder="Username">
          </label>
          <label>
            <input type="password" v-model="password" placeholder="Password">
          </label>
          <input type="submit" value="Submit">
        </form>
        <div class="success" v-if="signSuccess" v-on:click="removeMessages">
          <p>
            Nice ! Welcome back :)
          </p>
        </div>
        <div class="error" v-if="signErr" v-on:click="removeMessages">
          <p>
            Error, we couldn't log you :(
          </p>
        </div>
      </section>
      <section v-else>
        <h1 class="title">Already log !</h1>
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
        Auth.login(this, JSON.stringify(data), () => {
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
