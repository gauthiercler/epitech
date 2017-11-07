<template>
  <div class="modal-card">
    <header class="modal-card-head">
      <p class="modal-card-title">Send a command</p>
    </header>
    <section class="modal-card-body">
      <b-field label="Type">
        <b-input type="text" v-model="type" placeholder="Type" required>
        </b-input>
      </b-field>

      <b-field label="Command">
        <b-input type="text" v-model="data" placeholder="Command" required></b-input>
      </b-field>

    </section>
    <footer class="modal-card-foot">
      <button class="button" type="button" @click="$parent.close()">Close</button>
      <button class="button is-warning" :disabled="!this.isValid" @click="sendCommand">Send</button>
    </footer>
  </div>
</template>

<script>
  import api from '@/api/index'

  export default {
    name: 'command-form',
    data () {
      return {
        type: '',
        data: ''
      }
    },
    computed: {
      isValid () {
        return this.type.length > 0 && this.data.length > 0
      }
    },
    methods: {
      error () {
        this.$toast.open({
          duration: 5000,
          message: `An error occurred`,
          type: 'is-danger'
        })
      },
      success () {
        this.$toast.open({
          duration: 5000,
          message: `Command successfully sent`,
          type: 'is-success'
        })
      },
      sendCommand () {
        api.commands.create(this.$parent.$parent.$parent.mac, {type: this.type, data: this.data}).then(response => {
          if (response.data.success === true) {
            this.success()
            this.$parent.close()
          } else this.error()
        })
      }
    }
  }
</script>

<style scoped>
  .modal-card {
    width: auto;
  }
</style>
