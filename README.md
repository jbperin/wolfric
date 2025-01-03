


## Adapter

* Rechercher et remplacer `wolfric` par le nom du jeu dans tous les fichiers du projet.
  

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

```batch
python tools\tile.py  assets\TransparentIcons.png 20 16
python tools\tile.py  assets\IUqsoh.gif 7 7 --replace_color 0 0 0 12  
python tools\tile.py  assets\bank4g.gif 3 3 --replace_color 0 0 0 12  
python tools\tile.py  assets\b0ZeE3.gif 1 3 --replace_color 0 0 0 12
python tools\tile.py  assets\E9LzHe.gif 5 4 --replace_color 0 0 0 12
python tools\tile.py  assets\UkM03M.gif 3 4  --replace_color 0 0 0 12
python tools\tile.py  assets\wKxWVm.gif 3 3  --replace_color 0 0 0 12
python tools\tile.py  assets\+P6O7U.gif 4 4  --replace_color 0 0 0 12
python tools\tile.py  assets\ProjectUtumno_full.png 95 64  
python tools\gif2buf.py assets\fire.gif
python tools\gif2buf_02.py assets\dog.webp data --replace_color 255 255 255
python .\tools\texture2buf.py assets\trees\mangrove_1.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_1.h
python .\tools\texture2buf.py assets\trees\mangrove_2.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_2.h
python .\tools\texture2buf.py assets\trees\mangrove_3.png --replace_color 0 0 0 12 > .\code\scene\textures\mangrove_3.h
python .\tools\texture2buf.py assets\trees\tree_1_lightred.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_lightred.h
python .\tools\texture2buf.py assets\trees\tree_1_red.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_red.h
python .\tools\texture2buf.py assets\trees\tree_1_yellow.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_1_yellow.h
python .\tools\texture2buf.py assets\trees\tree_2_lightred.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_lightred.h
python .\tools\texture2buf.py assets\trees\tree_2_red.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_red.h
python .\tools\texture2buf.py assets\trees\tree_2_yellow.png --replace_color 0 0 0 12 > .\code\scene\textures\tree_2_yellow.h


python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_6_4.png > .\code\scene\textures\arbalete.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_11_10.png > .\code\scene\textures\keys.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_11_11.png > .\code\scene\textures\chest.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_9.png > .\code\scene\textures\letter.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_10.png > .\code\scene\textures\parchment_close.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_11.png > .\code\scene\textures\parchment_open.h
python .\tools\texture2buf.py assets\TransparentIcons_tiles\tile_13_12.png > .\code\scene\textures\map.h


python tools\tile.py  assets\Fighter-F-01.png 4 7 --replace_color 0 117 117 6
python .\tools\texture2buf.py assets\Fighter-01_tiles\tile_0_0.png --cfill 152 0 136 > .\code\scene\textures\fighter_back.h
python .\tools\texture2buf.py assets\Fighter-01_tiles\tile_1_0.png --cfill 152 0 136 > .\code\scene\textures\fighter_right.h
python .\tools\texture2buf.py assets\Fighter-01_tiles\tile_2_0.png --cfill 152 0 136 > .\code\scene\textures\fighter_front.h
python .\tools\texture2buf.py assets\Fighter-01_tiles\tile_3_0.png --cfill 152 0 136 > .\code\scene\textures\fighter_left.h
python tools\tile.py  assets\Princess-01.png 4 7 --replace_color 0 117 117 6
python .\tools\texture2buf.py assets\Princess-01_tiles\tile_0_0.png --cfill 152 0 136 > .\code\scene\textures\princess_back.h
python .\tools\texture2buf.py assets\Princess-01_tiles\tile_1_0.png --cfill 152 0 136 > .\code\scene\textures\princess_right.h
python .\tools\texture2buf.py assets\Princess-01_tiles\tile_2_0.png --cfill 152 0 136 > .\code\scene\textures\princess_front.h
python .\tools\texture2buf.py assets\Princess-01_tiles\tile_3_0.png --cfill 152 0 136 > .\code\scene\textures\princess_left.h

python tools\tile.py  assets\bull.png 8 4
python tools\tile.py  assets\cat.png 8 16
python tools\tile.py  assets\dog.png 8 16
python tools\tile.py  assets\lpc_minotaur.png 21 13
python tools\tile.py  assets\horse-brown.png 20 4
python tools\tile.py  assets\creatures.png 30 4

python tools\tile.py  assets\0xWR6B.gif 4 5 --replace_color 0 0 0 6 
python tools\gif2buf.py  assets\0xWR6B_tiles\tile_1_0.gif assets\0xWR6B --name explosion --flist 0 1 2 4 > .\code\scene\textures\explosion.h
python tools\gif2buf.py  assets\0xWR6B_tiles\tile_1_1.gif assets\0xWR6B --name explosion_02 --flist 0 1 2 4 > .\code\scene\textures\explosion_02.h

python tools\tile.py  assets\E9LzHe.gif 5 4 --replace_color 0 0 0 24
python tools\gif2buf.py  assets\E9LzHe_tiles\tile_2_2.gif assets\E9LzHe --name explosion_03 --fnum 4 > .\code\scene\textures\explosion_03.h
python tools\gif2buf.py  assets\E9LzHe_tiles\tile_2_3.gif assets\E9LzHe --name explosion_04 --flist 0 2 3 5 > .\code\scene\textures\explosion_04.h

```