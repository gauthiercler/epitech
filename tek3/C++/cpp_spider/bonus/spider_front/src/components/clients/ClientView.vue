<template>
  <div class="client-view">
    <div class="columns is-centered">
      <div class="column is-narrow">
        <div class="columns is-centered">
          <figure class="image is-128x128">
            <v-gravatar v-if="client.mac" :hash="client.mac" :size="128" default-img="identicon"></v-gravatar>
          </figure>
        </div>
        <div class="field is-grouped" v-if="client.mac && client.os && client.antivirus">
          <div class="control">
            <div class="tags has-addons">
              <span class="tag is-dark">MAC</span>
              <span class="tag is-info">{{ client.mac }}</span>
            </div>
          </div>
          <div class="control">
            <div class="tags has-addons">
              <span class="tag is-dark">Operating System</span>
              <span class="tag is-danger">{{ client.os }}</span>
            </div>
          </div>
          <div class="control">
            <div class="tags has-addons">
              <span class="tag is-dark">Antivirus</span>
              <span class="tag is-success">{{ client.antivirus }}</span>
            </div>
          </div>
        </div>
      </div>
    </div>
    <clients-command></clients-command>
    <clients-logs></clients-logs>
  </div>
</template>

<script>
  import Gravatar from 'vue-gravatar'
  import ClientsLogs from '@/components/clients/ClientsLogs'
  import ClientsCommand from '@/components/clients/ClientsCommand'
  import api from '@/api/index'

  export default {
    name: 'client-view',
    components: { 'v-gravatar': Gravatar, ClientsLogs, ClientsCommand },
    props: ['mac'],
    data () {
      return {
        client: Object
      }
    },
    created () {
      api.client.getByMac(this.mac).then(response => {
        this.client = response.data.data
      })
    }
  }
</script>
