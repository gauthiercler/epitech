<template>
  <div class="columns is-centered">
    <div class="column is-narrow">
      <button class="button is-primary" @click="isResponseActive = true">View command responses</button>
    </div>
    <div class="column is-narrow">
      <button class="button is-warning" @click="isCommandFormActive = true">Send a command</button>
    </div>

    <b-modal :active.sync="isCommandFormActive" has-modal-card>
      <command-form></command-form>
    </b-modal>
    <b-modal :active.sync="isResponseActive" has-modal-card>
      <command-responses></command-responses>
    </b-modal>
  </div>
</template>

<script>
  import CommandForm from '@/components/clients/CommandForm'
  import CommandResponses from '@/components/clients/CommandResponses'

  export default {
    name: 'clients-command',
    components: {
      CommandForm,
      CommandResponses
    },
    data () {
      return {
        isCommandFormActive: false,
        isResponseActive: false
      }
    }
  }
</script>
