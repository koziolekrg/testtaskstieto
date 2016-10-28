#ifndef splitter_h
#define splitter_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct map{
    char* text;
    int count;
    struct map *next;
}Map;

Map *createMap(char *atext);
void deleteMap(Map* map);
Map *addMap(Map*amap, char *atext);
char *toLower(char *text);
Map* splitBuffer(char *buffer);
Map* checkContain(Map* map_1, Map* map_2);


#endif /* !splitter_h */
