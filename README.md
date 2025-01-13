Projet : Saturne Incline
Description
Ce projet vise à générer une image en perspective d'une représentation inclinée de la planète Saturne et de ses anneaux. Il repose sur des calculs géométriques précis pour modéliser et rendre visuellement la planète avec des effets d'inclinaison et de dégradés, tout en utilisant les propriétés de la géométrie des ellipses.

Fonctionnalités
Génération de Saturne avec ses anneaux inclinés.
Rendu des ombres pour donner une profondeur réaliste.
Ajout de dégradés de couleurs pour simuler les détails de la planète et de ses anneaux.
Création d'une image finale au format BMP.
Fichiers principaux
Geometrie.h
Contient des fonctions géométriques, comme le calcul des distances et l'appartenance des points à des ellipses ou des anneaux inclinés.

OutilsCreationImage.cpp
Fournit les outils pour créer des images BMP, notamment l'écriture des pixels et des en-têtes DIB.

main.cpp
Implémente la logique principale pour configurer les paramètres de Saturne, effectuer les calculs géométriques, et générer l'image finale.

Prérequis
Compilateur compatible avec le langage C++.
Environnement supportant la bibliothèque mathématique standard et les entrées/sorties.
Instructions pour compiler et exécuter
Cloner le projet depuis le dépôt GitHub :

bash
Copier le code
git clone <url_du_repot>
cd SaturneIncline
Compiler le code source avec un compilateur tel que g++ :

bash
Copier le code
g++ -o SaturneIncline main.cpp OutilsCreationImage.cpp -lm
Exécuter le programme :

bash
Copier le code
./SaturneIncline
L'image générée sera sauvegardée dans le dossier images_creees sous le nom saturne_perspective_jeudi2.bmp.

Contribution
Ce projet a été réalisé par Riantseheno Miandry Nathan .
Toute contribution est la bienvenue via des issues ou des pull requests.
Remarques
Les calculs impliquent des géométries complexes, notamment des ellipses inclinées. Les commentaires dans le code détaillent chaque étape du traitement pour faciliter la compréhension et la maintenance.
