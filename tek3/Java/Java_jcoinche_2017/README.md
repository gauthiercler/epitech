# JCoinche Documentation

## Installation

`gradle package` pour compiler le client et serveur dans le dossier **target**

`gradle test` pour générer les tests automatisés en utilisant **JUnit**

`gradle cover` pour générer les rapports de couverture en utilisant **Jacoco**

## Fonctionnement

Le serveur fonctionne de manière complétement asynchrone en utilisant la librairie réseau **netty**.
Il n'y a donc aucune boucle de jeu et tout est géré en utilisant des callbacks.

Il est possible d'accepter plus de 4 clients simultanément.
En effet la gestion des clients est faite en utilisant un LobbyManger qui va gérer les différents clients ainsi que les différentes rooms.

Les clients seront insérés dans une room existente ou dans une nouvelle créée s'il n'y a pas de rooms disponibles.
Cela permet l'execution de plusieurs parties simultanément avec un nombre de joueurs indéfinis.

La communication Client / Serveur se fait en utilisant le format d'échange ProtoBuf de Google.
Celui ci permet de générer des classes en fonction de modèles de donnés définis et ensuite de sérialiser ces classes lors de la communication

La communication Client / Serveur s'effectue toujours comme suit:

- Le serveur envoit une **Request** au client
- Le client reçoit la **Request** et la traite
- Le client renvoit au serveur une **Response**
- Le serveur reçoit la **Response**  et la traite.

Cela permet de simplifier la communication entre le serveur et les différents clients.

Liste des **Request** avec leur **Data** associée

| Request       | Data           |
|:-------------:|:--------------:|
| ListHand      | liste de `Card`|
| AskCard       | message        |
| AskBet        | message        |
| Log           | message        |

Liste des **Response** avec leur **Data** associée

| Response      | Data           |
|:-------------:|:--------------:|
| ListHand      | message ("ok") |
| AskCard       | objet `Card`   |
| AskBet        | objet `Bet`    |
| Log           | message ("ok") |
