


## Adapter

* Rechercher et remplacer `RomlessGame` par le nom du jeu dans tous les fichiers du projet.
  

## Réglages 


### Clavier
Le keyrepeat se configure dans le fichier `keyrepeat.c` 
```
static unsigned char keydelay   = 5;  // 32; // 
static unsigned char keyrepeat  = 1;  // 4; // 
```

## Ajouter la routine de tracé de ligne hires

Copier le fichier `line.s` dans le répertoire `code`
Ajouter `line` à la liste OSDKFILE dans `osdk_build.bat` 

Ajouter et configurer les paramètres 
```C
#define CLIP_LEFT	8
#define CLIP_RIGHT	220
#define CLIP_TOP	1
#define CLIP_BOTTOM	136

#define USE_ACCURATE_CLIPPING
```


Faire le précalcul des tables dans l'initialisation du jeu:
```C
void gameInit(void){

	LoadFileAt(HIRES_SCREEN, 0xA000);

    GenerateTables();
}
```

Le tracé d'une ligne se fait avec l'appel:
```C
LargeX0= 120;
LargeY0= ...;
LargeX1= ...;
LargeY1= ...;
DrawClippedLine();
```

Si on veut travailler avec une version bufferisé de l'écran graphique, on doit:

- inclure le fichier screen.s
- définir la macro `USE_BUFFERED_SCREEN`.
Le buffer ecran sera implanté en mémoire à l'adresse contenu dans `_ADR_SCREEN_BUFFER` 


```C 
#define USE_BUFFERED_SCREEN
#define _ADR_SCREEN_BUFFER 8500
```

**ATTENTION** : Il conviendra de précautionneusement choisir un adresse qui n'entre pas en collision avec autre chose.
Car il est défini en `.bss` dans `screen.s` et le linker ne lui réserve pas d'espace.

```
#include "params.h"

    .bss
* = $_ADR_SCREEN_BUFFER    
hires_screen_buffer .dsb 5480
```

La mise à jour de l'affichage graphique se fait alors par l'appel:

```C
ScreenCopyHires();
```

## Ajouter du contenu à charger



Dumper un charset
```
wm $B400 1024 stdcharset.bin
wm $B800 896 altcharset.bin
```

Dumper un écran texte
```
wm $BB80 1120 txtscreen.bin
``` 

Dumper un écran hires
```
wm $A000 8160 hrscreen.bin
```
ou 8191 

Copier le fichier dumpé vers le répertoire `data` du jeu
```batch
COPY %OSDK%\Oricutron\fichier.bin data
```

Dans le fichier `code/floppybuilderscript.txt`, ajouter 

```batch
AddFile ..\data\fichier.bin
AddDefine LOADER_FICHIER {FileIndex}
```

Dans le programme source du jeu, ajouter l'instruction de chargement du fichier

```C
LoadFileAt(LOADER_FICHIER, 0xBB80);
````
