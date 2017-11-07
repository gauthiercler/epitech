<template>
  <section class="hero">
    <div class="hero-body">
      <div class="container">
        <h1 class="title">
          {{ title }}
        </h1>
        <h2 class="subtitle">
          {{ subtitle }}
        </h2>
      </div>
    </div>
  </section>
</template>

<script>
  export default {
    name: 'hero',
    props: {
      title: {
        type: String,
        required: true
      },
      subtitle: {
        type: String
      }
    }
  }
</script>
