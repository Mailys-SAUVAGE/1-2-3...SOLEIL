# 1-2-3...SOLEIL
Projet de CSF sur Arduino

Il faut bien penser à installer la librairie **FastLED** par Daniel Garcia avant de tester le code.
Pour cela, ouvrir le gestionnaire de bibliotheque (3ème à gauche sur Arduino IDE), rechercher le nom et "INSTALLER".

Avant de téléverser le code, assurez-vous d'avoir correctement sélectionné votre carte :

1. Ouvrez Arduino IDE
2. Allez dans **Outils > Carte > RFThings AVR Boards**
3. Selectionnez : RFThings UCA


Couleurs :
- Vert : 1,2,3... (mouvement autorisé)
- Orqnge : ...SOLEIL (détection)
- Rouge : (mouvement détecté)
- Or : Victoire

Amélioration possible : 
- Avec un capteur plus précis, afficher, via les leds, où se trouve le joueur par rapport à la distance requise pour start le jeu.
