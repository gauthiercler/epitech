<template>
  <div class="clients">
    <hero title="Client"></hero>
    <router-view></router-view>
  </div>
</template>

<script>
  import Hero from '@/components/Hero'

  export default {
    name: 'clients',
    components: { Hero }
  }
</script>

<style>

</style>
