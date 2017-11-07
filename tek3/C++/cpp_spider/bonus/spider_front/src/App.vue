<template>
  <div id="app">
    <navigation></navigation>
    <div class="container">
      <transition name="slide-fade">
        <router-view></router-view>
      </transition>
    </div>
    <footer-spider></footer-spider>
  </div>
</template>

<script>
  import Navigation from '@/components/Navigation'
  import Footer from '@/components/Footer'

  export default {
    name: 'app',
    components: {
      Navigation,
      'footer-spider': Footer
    }
  }
</script>

<style>
  .slide-fade-enter-active {
    transition: all .5s ease;
  }
  .slide-fade-enter, .slide-fade-leave-to
    /* .slide-fade-leave-active below version 2.1.8 */ {
    transform: translateX(10px);
    opacity: 0;
  }
</style>
