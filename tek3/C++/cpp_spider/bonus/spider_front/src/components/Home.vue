<template>
  <div class="home">
    <hero title="Spider" subtitle="Epitech Project"></hero>
    <div class="content">
      <blockquote>
        Spider est un projet Epitech ayant pour but de créer un client Windows afin de récupérer les évènements de l'utilisateur (Clavier, Souris, ...).
        Ce client doit être connecté avec un serveur linux afin de pouvoir enregistrer les logs de l'utilisateur et de pouvoir les exploiter.
        Cette interface permet donc de voir ce qui se passe en base de donnée mais aussi d'ajouter des commandes qui seront lu en temps réel par le serveur et éxécuté par le client.
      </blockquote>
      <p></p>
    </div>
  </div>
</template>

<script>
  import Hero from '@/components/Hero'

  export default {
    name: 'home',
    components: {
      Hero
    }
  }
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style>
</style>
