# FdF — Wireframe (projet 42)

Une petite application en C pour visualiser des cartes 3D (wireframes) à partir de fichiers `.fdf` (projet pédagogique de l'école 42).

## Aperçu

`FdF` lit des fichiers de hauteur (format `.fdf`) et affiche une représentation filaire en 2D isométrique ou en perspective à l'aide de la MiniLibX (X11) — avec gestion des couleurs, zoom, déplacement et rotation.

Image illustrative :

![capture d'écran](./france.png)

## Fonctionnalités

- Lecture de fichiers `.fdf` (cartes de hauteur)
- Affichage isométrique
- Zoom, translation et rotation de la carte
- Palette de couleurs / couleurs par hauteur
- Gestion basique d'optimisation pour grandes cartes

## Prérequis

- Linux (X11)
- compilateur `gcc`
- `make`
- `libc` standard
- MiniLibX (fournie dans `minilibx-linux/`)

La MiniLibX est incluse dans le dépôt (`minilibx-linux/`) : suivez sa `README.md` pour l'installer si nécessaire.

## Compilation

Le projet contient un `Makefile` à la racine. Pour compiler :

```bash
make
```

Cela va compiler la bibliothèque `libft`, la MiniLibX (si besoin) et l'exécutable `fdf` dans le dossier racine ou selon le `Makefile` du projet.

Pour nettoyer les fichiers objets et l'exécutable :

```bash
make clean
make fclean
```

## Usage

```bash
./fdf <map.fdf>
```

Exemple :

```bash
./fdf test_maps/42.fdf
```

Si aucun fichier n'est fourni ou si le fichier n'est pas valide, le programme affiche un message d'erreur et se termine.

## Contrôles (raccourcis clavier souris)

Les contrôles standard :

- Flèches : déplacer la vue
- Molette / +/- : zoom
- R / T : rotation (ou autres touches selon la configuration dans `keyhook.c`)
- ESC : quitter

Consultez `srcs/keyhook.c` pour la liste exacte des touches et comportements implémentés.

## Format des maps (`.fdf`)

Chaque fichier `.fdf` contient des lignes d'entiers séparés par des espaces représentant les hauteurs. Exemple :

```
0 0 0 0
0 1 2 0
0 0 0 0
```

Des valeurs hexadécimales pour la couleur peuvent être présentes (format `val,color`), vérifiez `create_map.c` pour le parsing précis.

## Structure du projet

- `srcs/` : sources C du projet
- `includes/` : en-têtes publics (`fdf.h`)
- `libft/` : utilitaires fournis (bibliothèque personnelle)
- `minilibx-linux/` : MiniLibX (lib graphique)
- `test_maps/` : plusieurs `.fdf` d'exemple

## Dépannage & conseils

- Si l'exécution échoue avec une erreur MiniLibX, assurez-vous d'avoir les dépendances X11 installées.
- Pour de grandes maps, augmenter la taille de la fenêtre peut nécessiter d'ajuster les paramètres d'optimisation dans `opti_over_size.c`.
- Utilisez `valgrind` pour détecter les fuites mémoire lors du développement :

```bash
valgrind --leak-check=full ./fdf test_maps/42.fdf
```

## Auteur

Projet réalisé par David Lacuey pour l'école 42.

