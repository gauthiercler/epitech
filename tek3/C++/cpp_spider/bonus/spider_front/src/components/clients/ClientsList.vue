<template>
  <b-table :data="datas" paginated :per-page="20">
    <template scope="props" slot="header">
      <b-tooltip :active="!!props.column.meta" :label="props.column.meta" dashed>
        {{ props.column.label }}
      </b-tooltip>
    </template>
    <template scope="props">
      <b-table-column field="avatar" label="Avatar" meta="Avatar" width="40">
        <figure class="image is-48x48">
          <v-gravatar :hash="props.row.mac" :size="128" default-img="identicon"></v-gravatar>
        </figure>
      </b-table-column>
      <b-table-column field="os" label="OS" meta="Operating System" width="40" sortable>
        {{ props.row.os }}
      </b-table-column>
      <b-table-column field="mac" label="MAC" meta="MAC Address" width="40" sortable>
        {{ props.row.mac }}
      </b-table-column>
      <b-table-column field="antivirus" label="Antivirus" meta="Antivirus" width="40" sortable>
        {{ props.row.antivirus }}
      </b-table-column>
      <b-table-column field="actions" label="Actions" meta="Actions" width="40">
        <router-link :to="{ name: 'client.view', params: { mac: props.row.mac }}" class="button is-dark">Voir plus</router-link>
      </b-table-column>
    </template>
  </b-table>
</template>

<script>
  import Gravatar from 'vue-gravatar'
  import api from '@/api/index.js'

  export default {
    name: 'clients_list',
    components: {
      'v-gravatar': Gravatar
    },
    data () {
      return {
        datas: []
      }
    },
    created () {
      api.client.getAll().then(response => {
        this.datas = response.data.data
      })
    },
    sockets: {
      newClient (data) {
        this.datas.push(data)
      }
    }
  }
</script>
