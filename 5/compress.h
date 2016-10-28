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
Map* doSplit(char * split, Map* map);

#endif /* !splitter_h */
