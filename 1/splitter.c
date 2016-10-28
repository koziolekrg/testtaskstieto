#include "splitter.h"

Map *createMap(char *atext){
    Map* element = malloc(sizeof(Map));
    if(NULL != element){
        element->text = atext;
        element->count = 1;
        element->next = NULL;
    }
    return element;
}

void deleteMap(Map* map){
    if(NULL != map->next){
        deleteMap(map->next);
    }
    free(map);
}

Map *addMap(Map*amap, char *atext){
    Map* element = createMap(atext);
    if(NULL != element){
        element->next = amap;
    }
    return element;
}

char *toLower(char *text){
    int i;
    char* valueToLower = strdup(text);

    for(i = 0; i<strlen(text); i++){
        valueToLower[i] = tolower(valueToLower[i]);
    }

    return valueToLower;
}

Map* doSplit(char * split, Map* map){
    int i;
    Map* iter;
    int retVal;

    while(split != NULL){

        retVal=0;

        if(split != NULL){
            for(iter = map; NULL != iter; iter = iter->next){

                char* valueToLower = toLower(iter->text);
                char* splitToLower = toLower(split);

                if(strcmp(splitToLower,  valueToLower) == 0){
                    retVal = 1;
                    iter->count = iter->count+1;
                }

            }

        }

        if(split!=NULL && retVal == 0){
            map = addMap(map, split);
        }
        split = strtok(NULL, " -,.;");


    }

    return map;
}

