# Projet de Shell Simple

## Présentation

Ce projet vise à créer un shell simple reproduisant les fonctionnalités de base du shell Unix. Le shell est conçu pour exécuter des commandes, gérer des processus et gérer la redirection des entrées/sorties.

## Tâches du Projet

### 0. README, man, AUTHORS
- **Fichiers :**
    - `README.md` : Aperçu, compilation, tests et détails de soumission.
    - `man_1_simple_shell` : Page de manuel pour le shell.
    - `AUTHORS` : Liste des contributeurs.

### 1. Betty serait fière
- **Description :** Écrire un code qui réussit les vérifications de style Betty.
- **Fichiers :**
    - Fichiers de code à écrire en suivant le style Betty.

### 2. Simple shell 0.1
- **Description :** Écrire un interpréteur de ligne de commande UNIX.
- **Usage :** `simple_shell`
- **Fonctionnalités :**
    - Afficher une invite et attendre que l'utilisateur saisisse une commande.
    - L'invite est affichée à nouveau après chaque exécution de commande.
    - Les lignes de commande sont simples, sans fonctionnalités avancées.
    - Gérer les erreurs et la condition de "fin de fichier".
    - Une exécution non trouvée résulte en un message d'erreur.

### 3. Simple shell 0.2
- **Description :** Améliorer le shell pour gérer les lignes de commande avec des arguments.

### 4. Simple shell 0.3
- **Description :** Étendre le shell pour gérer le PATH et éviter les appels inutiles à `fork`.
- **Exemples :**
    ```bash
    $ ./shell_0.3
    :) /bin/ls
    :) ls
    :) ls -l /tmp
    ```

### 5. Simple shell 0.4
- **Description :** Implémenter la commande intégrée `exit` qui quitte le shell.
- **Usage :** `exit`

### 6. Simple shell 1.0
- **Description :** Implémenter la commande intégrée `env` qui affiche l'environnement courant.
- **Exemple :**
    ```bash
    $ ./simple_shell
    $ env
    USER=julien
    LANGUAGE=en_US
    ...
    ```

## Exigences

### Générales
- **Éditeurs autorisés :** vi, vim, emacs
- **Compilation :** `gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
- **Style de codage :** Le code doit suivre le style Betty et être vérifié avec `betty-style.pl` et `betty-doc.pl`.
- **Gestion de la mémoire :** Assurer l'absence de fuites mémoire.
- **Fonctions par fichier :** Pas plus de 5 fonctions par fichier.
- **Fichiers d'en-tête :** Gardes d'inclusion dans les fichiers d'en-tête.
- **Appels système :** Utiliser les appels système uniquement lorsque nécessaire.

### GitHub
- Un dépôt de projet par groupe.
- Éviter de cloner/forker un dépôt de projet avec le même nom avant la deuxième date limite pour éviter un score de 0%.

## Compilation et Tests

### Compilation
```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Tests
Mode interactif
bash
Copy code
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Mode non interactif
bash
Copy code
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
Informations supplémentaires
Sortie : Identique à /bin/sh.
Format d'erreur :
bash
Copy code
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
Documentation : Commentaires détaillés dans le code.
Collaboration : Encouragée, mais chaque étudiant doit avoir son propre dépôt GitHub.
