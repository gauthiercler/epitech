<template>
  <header>
    <router-link class="home-link" to="/">
      <h2>Area</h2>
    </router-link>
  </header>
</template>

<script>
  export default {
    name: 'Header'
  }
</script>

<style>
  header {
    display: flex;
    height: 15vh;
    background: #3cb8e9b3;
    color: white;
    text-align: center;
    box-shadow: 0 0 3px 0 gray;
    margin-bottom: 5vh;
  }

  .home-link {
    margin: auto;
  }

  .home-link h2 {
    font-size: 34px;
    text-shadow: 0 3px #2a94bf;
    color: white;
  }

</style>
