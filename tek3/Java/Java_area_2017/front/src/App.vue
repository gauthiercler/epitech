<template>
  <section id="app">
    <router-view/>
  </section>
</template>

<script>
export default {
  name: 'app',
  test: 'test'
}
</script>

<style>
  @import url('https://fonts.googleapis.com/css?family=Gloria+Hallelujah|Julius+Sans+One');

  h1 {
    font-size: 28px;
  }
  h2 {
    font-size: 24px;
  }

  .beauty {
    font-family: 'Gloria Hallelujah', cursive;
  }

  body {
    font-family: 'Julius Sans One', sans-serif;
  }

  body, h1, h2, h3, p, footer, header, section {
    margin: 0;
  }

  a {
    color: black;
    text-decoration: none;
  }

  /* custom-body */

  #body {
    font-family: 'Gloria Hallelujah', cursive;
    min-height: 65vh;
    text-align: center;
  }

  .success, .error {
    position: absolute;
    width: 100%;
    top: 50%;
    color: white;
  }

  .success p, .error p {
    width: 25%;
    margin: auto;
    box-shadow: 0 0 2px 0 black;
    font-weight: 900;
  }

  .success p {
    background: #13c913e6;
  }

  .error p {
    background: #c33c3ce6;
  }

</style>
