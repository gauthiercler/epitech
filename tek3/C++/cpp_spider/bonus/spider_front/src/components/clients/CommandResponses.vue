<template>
  <div class="modal-card">
    <header class="modal-card-head">
      <p class="modal-card-title">Command Responses</p>
    </header>
    <section class="modal-card-body">
      <b-table :data="datas" paginated :per-page="20">
        <template scope="props" slot="header">
          <b-tooltip :active="!!props.column.meta" :label="props.column.meta" dashed>
            {{ props.column.label }}
          </b-tooltip>
        </template>
        <template scope="props">
          <b-table-column field="timestamp" label="Date" meta="Date" width="40" date sortable>
            {{ props.row.timestamp | timestampToDate}}
          </b-table-column>
          <b-table-column field="type" label="TYPE" meta="Type" width="40" sortable>
            {{ props.row.type }}
          </b-table-column>
          <b-table-column field="command" label="CMD" meta="Command" width="40" sortable>
            {{ props.row.command }}
          </b-table-column>
          <b-table-column field="stdout" label="stdout" meta="Standard Output" width="40" sortable>
            {{ props.row.stdout }}
          </b-table-column>
          <b-table-column field="stderr" label="stderr" meta="Standard Error Output" width="40">
            {{ props.row.stderr }}
          </b-table-column>
          <b-table-column field="exitcode" label="Exitcode" meta="Exit Code" width="40" sortable>
            {{ props.row.exitcode }}
          </b-table-column>
        </template>
      </b-table>
    </section>
    <footer class="modal-card-foot">
      <button class="button" type="button" @click="$parent.close()">Close</button>
    </footer>
  </div>
</template>

<script>
  import api from '@/api/index'

  export default {
    name: 'command-responses',
    data () {
      return {
        datas: [],
        mac: this.$parent.$parent.$parent.mac
      }
    },
    created () {
      api.response.getAllByMac(this.mac).then(response => {
        this.datas = response.data.data
      })
    },
    sockets: {
      newResponse (data) {
        if (data.mac === this.mac) this.datas.push(data)
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
