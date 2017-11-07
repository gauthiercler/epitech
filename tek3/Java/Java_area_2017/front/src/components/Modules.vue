<template>
  <section id="content">
    <header-bar></header-bar>
    <section id="body">
      <h1>Modules</h1>
      <div id="lists" v-if="auth">
        <form v-on:submit="onSubmit">
        <div id="listener-list">
          <h2> On Action : </h2>
          <select v-model="listenerSelected">
            <option v-for="listener in listeners">{{ listener }}</option>
          </select>
        </div>
        <div id="handler-list">
          <h2> Do Reaction : </h2>
          <select v-model="handlerSelected">
            <option v-for="handler in handlers" :disabled="!isCompatible(handler)">{{ handler }}</option>
          </select>
        </div>
          <input type="submit" :disabled="!isValidForm">
        </form>
      </div>

      <h1>Delete Modules</h1>
      <ul>
        <li v-for="module in modulesList">
          {{ module.listener }} + {{ module.handler }}
          <button @click="deleteModule(module)"> Delete </button>
        </li>
      </ul>


      <div class="success" v-if="sendSuccess" v-on:click="removeMessages">
        <p>
          Success ! :D
        </p>
      </div>
      <div class="error" v-if="sendErr" v-on:click="removeMessages">
        <p>
          Error we couldn't send your Action/Reaction :'(
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
    name: 'Modules',
    components: {
      'header-bar': Header,
      'footer-bar': Footer
    },
    computed: {
      isValidForm () {
        return this.listenerSelected.length && this.handlerSelected
      }
    },
    methods: {
      onSubmit (e) {
        e.preventDefault()
        if (this.isValidForm) {
          this.$http.post('http://localhost:4567/user/' + Auth.getId() + '/modules', {
            'listener': this.listenerSelected,
            'handler': this.handlerSelected
          }, {
            headers: {
              'token': Auth.getToken()
            }
          }).then(() => {
            this.sendSuccess = true
            this.getModulesList()
          }, () => {
            this.sendErr = true
          })
        }
      },
      removeMessages (e) {
        this.sendErr = false
        this.sendSuccess = false
      },
      isCompatible (handler) {
        if (this.listenerSelected.length) {
          return (handler.search(this.listenerSelected.match(/[A-Z][a-z]+/g)[0]) !== -1)
        }
      },
      deleteModule (module) {
        this.$http.delete('http://localhost:4567/user/' + Auth.getId() + '/modules', {
          body: {
            'listener': module.listener,
            'handler': module.handler
          },
          headers: {
            'token': Auth.getToken()
          }
        }).then(() => {
          this.sendSuccess = true
          this.getModulesList()
        }, () => {
          this.sendErr = true
        })
      },
      getModulesList () {
        this.$http.get('http://localhost:4567/user/' + Auth.getId() + '/modules', {
          headers: {
            'token': Auth.getToken()
          }
        }).then((response) => {
          this.modulesList = response.data
          console.log(this.modulesList)
        })
      }
    },
    created () {
      this.getModulesList()
    },
    data: function () {
      return {
        auth: Auth.getAuth(),
        sendSuccess: false,
        sendErr: false,
        listeners: [
          'DropboxFileAddedEvent',
          'DropboxFileRemovedEvent',
          'DropboxFolderCreatedEvent',
          'FacebookAboutEvent',
          'FacebookBirthdayEvent',
          'FacebookEmailEvent',
          'FacebookFirstNameEvent',
          'FacebookLastNameEvent',
          'FacebookLocaleEvent',
          'FacebookPictureEvent',
          'FacebookQuotesEvent',
          'FacebookReligionEvent',
          'FacebookStatusEvent',
          'FacebookWebsiteEvent'
        ],
        handlers: [
          'facebookOnTweet',
          'twitterOnFacebookEvent',
          'twitterOnFacebookBirthdayBirthday',
          'twitterOnFacebookEmail',
          'twitterOnFacebookFistName',
          'twitterOnFacebookLastName',
          'twitterOnFacebookPicture',
          'twitterOnFacebookReligion',
          'twitterOnFacebookQuote',
          'twitterOnFacebookStatus',
          'twitterOnFacebookWebsite',
          'twitterOnDropboxAddedFile',
          'twitterOnDropboxCreatedFolderFile',
          'twitterOnDropboxRemovedFile',
          'facebookOnDropboxAddedFile',
          'facebookOnDropboxCreatedFolderFile',
          'facebookOnDropboxRemovedFile'
        ],
        listenerSelected: '',
        handlerSelected: '',
        modulesList: []
      }
    }
  }
</script>

<style>
  #lists {
    margin: 2%;
  }
</style>
