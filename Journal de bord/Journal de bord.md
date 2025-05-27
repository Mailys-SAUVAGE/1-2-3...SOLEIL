# Notre journal de bord

## Semaine du 7 au 13 avril : Lancement du projet

Cette semaine a été le lancement concret de notre projet ; nous étions d’accord sur l’idée du « 1, 2, 3 Soleil » et le projet était validé par les enseignants. Nous avons donc commencé à lister l’ensemble des éléments à prendre en compte pour la conception de notre version du jeu en visualisant au brouillon les différentes étapes du jeu pour bien en comprendre la logique.

Après avoir fait cette liste exhaustive et discuté avec les professeurs, nous nous sommes rendues compte que notre première idée de faire une double face pour que deux joueurs jouent face à face était probablement trop ambitieuse pour un premier projet comme celui-ci. Nous avons donc fait le choix de nous concentrer sur une seule « face » plus réalisable et techniquement abordable.

Ensuite, nous avons commencé à réfléchir sur le choix du matériel le plus adapté à chaque besoin : qu’utilisons-nous pour détecter le mouvement, un capteur ultrasons ou pas ? Quels en sont les avantages ? Partons-nous sur un écran OLED ou des LEDs ? Etc.

---

## Semaine du 14 au 20 avril : Diagramme de Gantt, schéma fonctionnel et matériel

Nous avons poursuivi la structuration du projet en nous répartissant trois tâches :

- **Clarah** : Je me suis occupée du schéma fonctionnel permettant de clarifier les différentes étapes du jeu et l’enchaînement logique entre les actions, ce qui nous servira de base tout au long de la programmation. Pour avoir quelque chose de clair mais complet, je l’ai fait sous forme d’algorigramme avec des boucles.

- **Imène** : J’ai finalisé le choix du matériel nécessaire pour chaque étape du projet. J’ai pesé le pour et le contre de chaque option, tout en échangeant avec les professeurs pour clarifier ce que nous allions mettre en place. En parallèle, j’ai effectué des recherches sur Internet pour voir ce qui se faisait déjà dans des projets similaires. J’ai ensuite sélectionné définitivement le matériel que nous utiliserons pour chaque étape. Après validation de la part des professeurs, j’ai transmis la liste afin que nous puissions disposer de tout le matériel nécessaire dès la semaine suivante, et ainsi commencer concrètement le projet.

- **Maïlys** : Durant cette deuxième semaine, je me suis chargée de réaliser le diagramme de Gantt, qui nous a permis d’organiser notre travail de façon claire et équilibrée. Lors de la conception, j’ai essayé de rendre la répartition des tâches équitable tout en prenant en compte les difficultés ou préférences techniques de chacune. Le planning est structuré de manière à commencer par les modules simples (buzzer, LEDs) à tester individuellement, avant d’envisager leur intégration dans une boucle principale. J’ai rencontré quelques difficultés à estimer le temps nécessaire pour chaque tâche.

---

## Semaine du 21 au 27 avril : Préparation de la présentation intermédiaire

Cette semaine a été principalement dédiée à la préparation de la présentation intermédiaire. Nous avons mis au propre l’ensemble de nos idées et avancées depuis le début du projet. Nous avons mis au propre nos motivations, précisé notre problématique et défini clairement les objectifs pédagogiques et techniques du jeu. Nous avons également détaillé les étapes du fonctionnement du dispositif en nous appuyant sur le schéma fonctionnel réalisé la semaine précédente, et listé le matériel utilisé pour chaque étape du jeu.

La réalisation du diaporama et la préparation de l’oral intermédiaire nous ont permis de visualiser l’ensemble du projet de manière claire. Enfin, cela a aussi été l’occasion de faire un point sur les obstacles rencontrés jusqu’ici (choix techniques, cohérence des modules, faisabilité) et sur ce qu’il nous reste encore à accomplir pour aboutir à quelque chose de fonctionnel.

---

## Semaine du 28 avril au 4 mai : Programmation des premiers codes

- **Clarah** : J’ai travaillé sur le code du capteur à ultrasons, la première étape essentielle du programme global pour permettre au dispositif de détecter la position de départ de l’enfant dans le jeu. Pour cela, je me suis appuyée sur le code de base mis à disposition par le professeur sur GitHub, que j’ai adapté à notre projet.  
  J’ai donc créé une fonction nommée `lireDistanceUltrason` qui permet de mesurer la distance entre le capteur et un objet (ici, l’enfant/le joueur). Cette mesure est indispensable pour valider que l’enfant se trouve à la bonne distance et commencer la partie.

- **Imène** : Cette semaine, j’ai travaillé sur les codes liés aux LEDs, au buzzer et au bouton-poussoir, des éléments essentiels pour l’interaction et le déroulement du jeu.  
  - **Buzzer** : sons pour les différentes phases du jeu : bip court pendant le décompte, alerte si mouvement détecté, et mélodie de victoire.  
  - **LEDs** : vertes pour le décompte, rouges si le joueur bouge, dorées en cas de victoire.  
  - **Bouton** : détection d’appui, déclenche le son de victoire, les LEDs dorées, et arrête la partie.

- **Maïlys** : Je me suis concentrée sur le code du capteur PIR (mouvement). J’ai développé une fonction qui renvoie `true` ou `false` selon s’il y a eu un mouvement ou non. J’ai aussi commencé à tester différentes réactions possibles à un mouvement détecté.

---

## Semaine du 5 au 11 mai : Synchronisation et codages

Nous avons travaillé sur la synchronisation des LEDs et du buzzer pour qu’ils réagissent en même temps lors du décompte ou des autres phases du jeu. Nous avons aussi sélectionné les sons les plus adaptés pour rendre le jeu plus ludique.

En fin de semaine, nous avons codé la détection de mouvement via une fonction `detecterMouvement`. Elle interroge le capteur PIR et déclenche des réactions (LEDs rouges, buzzer) si l’enfant bouge après le « Soleil ! ».

- **Maïlys** : En parallèle, je me suis chargée de l’activation du capteur ultrason via le bouton, pour lancer la partie.

---

## Semaine du 12 au 18 mai : Synchronisation des codes

Cette semaine a été consacrée à l’intégration des différents modules codés séparément : bouton, buzzer, LEDs, capteur de mouvement, capteur à ultrasons.  
Nous avons rassemblé le tout dans une boucle principale structurée selon le schéma fonctionnel initial. Cela a permis de clarifier la logique du jeu et d’éviter les erreurs.

---

## Semaine du 19 au 25 mai : Tests, ajustements et README

Après avoir fusionné les codes, nous avons réparti les dernières tâches :

- **Clarah** : Rédaction du README pour présenter notre projet sur GitHub et mise au propre de ce journal de bord.
- **Imène** : Réalisation des premiers tests complets. Quelques bugs ont été corrigés pour améliorer la fluidité et la synchronisation.
- **Maïlys** : Construction du support physique du projet.

