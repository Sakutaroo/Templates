# C

Le principe des pointeurs sur fonctions est de comparer votre argument avec une liste (map) d'arguments définis. Selon la correspondance entre les éléments, l'adresse de la fonction sera retournée.

Déclaration :

	int (*fptr)(int)
Cette déclaration contient le retour de la fonction (ici, le premier `int`) et les paramètres que va prendre votre fonction (ici, le deuxième `int`).<br />
`(*fptr)` est le nom du pointeur. C'est essentiel d'ajouter une `*` entre les parenthèses afin de spécifier qu'il s'agit bien d'un pointeur sur fonction et non d'un prototype classique.

Nous allons le déclarer dans un structure qui va également prendre une autre variable qui va nous permettre de savoir dans quel cas nous appelons une certaine fonction (Exemple : si str = "test" alors nous appelons la fonction execute_test). Cette variable peut être du type que vous souhaitez.<br />
Au final, voici notre structure :

	typedef struct command_s {
	    char *command;
	    int (*fptr)(int);
	} command_t;
<br />
Passons maintenant au programme :<br /><br />
Initialisation :

	const command_t *com = NULL
Nous l'initialisons à `NULL` dans notre programme en faisant référence à notre structure.<br />
`command_t` correspond au nom de notre structure.
`*com` correspond au nom de notre pointeur sur fonction, c'est cette variable qui va stocker l'adresse du pointeur.
<br /><br /><br />
Nous allons ensuite créer une nouvelle fonction afin de récupérer l'adresse de la fonction à appeler. Cette fonction va nous servir à parcourir une "map" qui contient les différentes fonctions à appeler.<br />
Cette fonction va retourner notre pointeur donc il va être du type de notre structure :

	const command_t *find_command(char *your_var)
Voici le prototype de notre fonction, nous y retrouvons le type de notre structure et également en argument un `char *` : cet argument va nous permettre de savoir quelle fonction nous allons devoir appeler. Cet élément est défini au préalable dans notre structure :

	char *command;
Il nous reste plus qu'à créer la fonction qui parcourt notre "map" (que nous allons créer un peu plus tard) et qui compare les éléments de celle-ci avec celui que nous avons mis en paramètre.<br />
Pour parcourir notre map, c'est assez simple : une boucle for suffit ! Mais laquelle ? Celle-ci :

	for (int index = 0; command_map[index].fptr != NULL; index += 1)
Quelques explications s'imposent ! Si vous connaissez et comprenez le principe des tableaux, ce ne sera pas très compliqué à comprendre.<br />
Comme dans un tableau, notre "map" se finit par `NULL`.<br />
`command_map` correspond à notre nom de fonction pour notre "map" (c'était compliqué à deviner sans avoir créer la fonction, c'est vrai). Et donc, nous avons un index qui va nous permetter de nous déplacer dans notre "map" (tout comme un tableau, nous commençons à 0 pour avoir le premier élement).<br />
Et pour finir le `.fptr` va faire référence au nom du pointeur (que nous avons défini dans notre structure).<br />

Ensuite, dans cette boucle il faut comparer les élements de la "map" avec notre argument. J'ai pris en exemple un `char *` donc nous allons utiliser la fonction `strcmp` :

	if (strcmp(your_var, command_map[index].command) == 0)
Petit point technique : si les deux chaînes de caractères sont les mêmes alors la fonction `strcmp` retourne la valeur `0`.<br />
`your_var` correspond à notre argument.<br />
`command_map[index].command` : nous retrouvons donc notre nom de fonction de la "map" `command_map` avec notre index. Le `.command` correspond aux chaînes de caractères que nous allons définir dans notre map juste après (ce n'est pas grave si vous ne comprenez pas encore son utilité, ce sera plus clair une fois que la "map" sera créée).<br />
Et donc que faisons-nous si cette condition est vraie (donc si `strcmp` retourne `0`) ?<br />
Nous allons tout simplement retourner l'adresse de la fonction trouvée dans la "map", de cette façon :

	return &command_map[index];
`&` correspond à l'adresse.<br />
Nous avons maintenant fini cette fonction, voilà ce que nous avons :

	for (int index = 0; command_map[index].fptr != NULL; index += 1) {
	    if (strcmp(your_var, command_map[index].command) == 0) {
	        return &command_map[index];
	    }
	}
Il nous reste malgré tout un petit problème à régler avant de passer à la création de la "map". Cette fonction a, pour le moment, une faille : si notre argument ne correspond à aucun élément de la "map". Donc pour cela, il nous suffit simplement d'ajouter un retour à la toute fin. Nous pouvons retourner `NULL` pour bien préciser que le programme n'a rien trouvé. Avec ce petit ajustement, nous avons :

	for (int index = 0; command_map[index].fptr != NULL; index += 1) {
	    if (strcmp(your_var, command_map[index].command) == 0) {
	        return &command_map[index];
	    }
	}
	return NULL;
Nous avons donc fini cette fonction !<br />
Il nous reste la fameuse "map" à créer ! Vous allez voir que certaines parties pas encore très claires vont s'éclaircir !<br /><br />

Prototype de la fonction "map" :

	static const command_t command_map[]
Nous reprenons encore une fois notre structure avec `command_t` et vous retrouvez le nom de la fonction `command_map`. C'est cette fonction que nous avons appelée tout au long de la fonction précédente.<br />
La rédaction de la fonction est un peu particulière donc je vais vous la présenter et nous allons la décortiquer ensuite donc n'ayez pas peur en lisant le code !

	static const command_t command_map[] = {
	    {.command = "test", .fptr = your_function}, // Ajouter des éléments sous cette ligne si besoin
	    {.command = NULL, .fptr = NULL}
	};
Tout à l'heure, je vous parlais de la fonction `strcmp` avec laquelle nous comparions nos éléments.<br />
Rappel : `if (strcmp(your_var, command_map[index].command) == 0)`<br />
Nous retrouvons donc notre `.command` qui était bien sombre quand je vous en ai parlé.<br />
Vous vous rappelez de notre structure ? Nous avions mis notre pointeur mais aussi une autre variable. Nous la retrouvons ici : `char *command`<br />
`.fptr = your_function` correspond à la fonction que vous voulez appeler si la condition (faite dans la fonction précédente) est vraie.<br />
Vous pouvez ajouter autant d'éléments que vous le souhaitez à partir du moment qu'ils sont situés au-dessus du `NULL` (c'est notre condition d'arrêt, il serait donc dommage d'ajouter des éléments en-dessous).<br />
Félécitations vous venez de créer votre "map" !<br />
Il reste une dernière étape à faire pour que tout cela soit fonctionnel.<br /><br />

Certes nous avons une fonction qui retourne soit l'adresse de la fonction soit `NULL` mais nous ne l'avons pas assignée à une variable. Egalement nous n'avons pas fait appel à cette fonction !<br />
Au tout début, nous avions créé une variable.<br />
Rappel : `const command_t *com = NULL`<br />
Nous allons appeler notre fonction qui parcourt la "map" et compare les éléments :

	com = find_command(str);
`find_command` correspond à notre fonction.<br />
`str` est un `char *`, c'est lui qui sera comparé avec les éléments de la "map".<br />
Attention ! Avant d'appeler votre fonction avec son adresse : il ne faut pas oublier de tester si votre pointeur n'est pas `NULL`.<br />
Une fois cela fait, nous pouvons appeler notre fonction sans aucun problème :

	com->fptr(nb);
`nb` est un `int` que nous donnons en paramètre de la fonction (les types des paramètres ont été définis dans la structure).<br />
`com->fptr` appelle la fonction (son adresse est stockée dans `*com`) et `fptr` est le pointeur que nous avons défini dans notre structure.<br /><br /><br />

Si malgré les explications, ce n'est pas encore très claire : n'hésitez pas à regarder le code dans le fichier .c et .h (il est fonctionnel). Il reprend les mêmes éléments qu'expliqués ici.<br />
Il ne faut pas hésiter à tester les réactions de votre programme avec divers arguments et types.
<br/>
"La théorie est absurde sans la pratique et la pratique est aveugle sans la théorie." - Kant<br /><br />

Commandes :

| Command          | Result                                                        |
|------------------|---------------------------------------------------------------|
| `make`           | Builds the executable.                                        |
| `make clean`     | Removes all files created by the build.                       |
| `make fclean`    | Calls `make clean` and removes executables.                   |
| `make debug`     | Calls `make fclean` and then `make` with debug symbols.       |
| `make re`        | Calls `make fclean` and then `make`.                          |
| `make exec`      | Calls `make debug` and then execute the binary with valgrind. |
