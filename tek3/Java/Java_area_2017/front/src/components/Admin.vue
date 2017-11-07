<template>
  <section id="content">
    <header-bar></header-bar>
    <section id="body" v-if="admin">
      <h1> Send Newsletter </h1>
      <form v-on:submit="onSubmit">
        <div id="subject">
          <label>Subject : </label>
          <input type="text" v-model="subject">
        </div>
        <div id="message">
          <label>Message : </label>
          <textarea v-model="message"></textarea>
        </div>
        <input id="submit" type="submit"/>
      </form>
      <div class="success" v-if="mailSuccess" v-on:click="removeMessages">
        <p>
          Your newsletter is send ! ;D
        </p>
      </div>
      <div class="error" v-if="mailErr" v-on:click="removeMessages">
        <p>
          Error we couldn't send your newsletter...
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
    name: 'Admin',
    components: {
      'header-bar': Header,
      'footer-bar': Footer
    },
    data: function () {
      return {
        admin: Auth.isAdmin(),
        subject: '',
        message: '',
        mailSuccess: false,
        mailErr: false
      }
    },
    methods: {
      onSubmit (e) {
        e.preventDefault()
        this.$http.post('http://localhost:4567/mails', {
          'subject': this.subject,
          'message': this.message
        }, {
          headers: {
            'token': Auth.getToken()
          }
        }).then(() => {
          this.mailSuccess = true
        }, () => {
          this.mailErr = true
        })
      },
      removeMessages (e) {
        this.mailErr = false
        this.mailSuccess = false
      }
    }
  }
</script>

<style>
  #subject, #message, #submit {
    margin-bottom: 2%;
  }
</style>
