# fractol

## Objectifs
Maintenant que vous avez pris en main votre première bibliothèque graphique :
la miniLibX, il est temps pour vous d’allumer tous les pixels de votre écran en même
temps !
Ce nouveau projet sera pour vous l’occasion de vous perfectionner dans l’utilisation
de la miniLibX, de vous faire découvrir/utiliser la notion mathémathique des nombres
complexes ainsi que de vous faire aborder la problématique de l’optimisation en programmation graphique.

## Consignes générales
- Ce projet ne sera corrigé que par des humains. Vous êtes donc libres d’organiser
et de nommer vos fichiers comme vous le désirez, en respectant néanmoins les
contraintes listées ici.
- L’exécutable doit s’appeller fractol.
- Vous devez rendre un Makefile.
- Votre Makefile devra compiler le projet, et doit contenir les règles habituelles. Il
ne doit recompiler le programme qu’en cas de nécessité.
- Si vous êtes malin et que vous utilisez votre biliothèque libft pour votre fractol,
vous devez en copier les sources et le Makefile associé dans un dossier nommé
libft qui devra être à la racine de votre dépôt de rendu. Votre Makefile devra
compiler la librairie, en appelant son Makefile, puis compiler votre projet.
- Vous ne devez pas utiliser de variables globales.
- Votre projet doit être à la Norme.
- Vous devez gérer les erreurs de façon raisonnée. En aucun cas votre programme
ne doit quitter de façon inattendue (segmentation fault, bus error, floating point
exception, etc...).
- Votre programme ne doit pas avoir de fuites mémoire
- Vous devez obligatoirement utiliser la miniLibX. Soit dans sa version présente
sur les dumps, soit à partir de ses sources. Si vous choisissez de travailler à partir
de ses sources, vous devez appliquer les mêmes règles que pour votre libft telles
que décrites au dessus.
- Dans le cadre de votre partie obligatoire, vous avez le droit d’utiliser les fonctions suivantes :
	- open, read, write, close
	- malloc, free
	- perror, strerror 
	- exit 
	- Toutes les fonctions de la lib math (-lm et man 3 math)
	- Toutes les fonctions de la miniLibX.
- Vous avez l’autorisation d’utiliser d’autres fonctions dans le cadre de vos bonus, à
condition que leur utilisation soit dûment justifiée lors de votre évaluation. Soyez
malins.

### Partie obligatoire
Ce projet consiste à créer un petit logiciel d’exploration fractale. Commencez donc
par voir ce qu’est une fractale.
Les contraintes sont les suivantes :
- Votre logiciel doit proposer au minimum 3 types de fractales différentes, dont au
moins l’ensemble de Julia et l’ensemble de Mandelbrot (soit au moins une troisième
fractale au choix).
- Il doit être possible de faire varier avec la souris (sans clic) le paramètre de l’ensemble de Julia. Pour les autres types de fractale, cela est laissé à votre discrétion.
- La molette de la souris permet de zoomer et dézoomer, et cela de façon quasi
infinie (modulo les limites de la machine). C’est le principe même des fractales.
- Il doit y avoir un jeu de couleur minimum pour ressentir la profondeur de chaque
fractale. Mieux : lâchez-vous sur les effets psychédéliques.
- Un paramètre est passé en ligne de commande pour définir quel type de fractale
est à afficher. Si il n’y a pas de paramètre fourni, ou si le paramètre est invalide,
le programme affiche la liste des paramètres disponibles et quitte proprement.

En ce qui concerne la représentation graphique :
- La touche ESC permettra de quitter le programme.
- L’utilisation des images de la minilibX est fortement conseillée

### Partie bonus
Voici quelques idées de bonus intéressants à réaliser. Vous pouvez évidemment ajouter
des bonus de votre invention, qui seront évalués à la discrétion de vos correcteurs.
- Le zoom pointe sur la position actuelle de la souris.
- En plus du zoom : déplacement avec les flèches.
- Faire tourner la palette de couleur.
- Implémenter le multi-threading.
- Plein de fractales sympa (des sites recensent plus d’une centaine de types différents).
- Repésentations en 3D.
- Deux paramètres valides en ligne de commande, deux fenêtres pour deux fractales.

## Note
112/100
