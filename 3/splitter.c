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

Map* splitBuffer(char *buffer){
    Map* output;
    char* split_buffer;

    split_buffer = strtok(buffer, " -,.;");
    output = createMap("");

    while(split_buffer != NULL){
        output = addMap(output, split_buffer);
        split_buffer = strtok(NULL, " -,.;");

    }

    return output;
}

Map* checkContain(Map* map_1, Map* map_2){
    Map* iter_1;
    Map* iter_2;
    Map* iter_output;
    Map* output;
    int retVal;
    char *tempVal;

    output = createMap("");


    for(iter_1 = map_2; NULL != iter_1; iter_1 = iter_1->next){

        for(iter_2 = map_1; NULL != iter_2; iter_2 = iter_2->next){

		
            char* word_1 = toLower(iter_1->text);
            char* word_2 = toLower(iter_2->text);

            if(strcmp(word_1, word_2) == 0 && strlen(word_1)>0 && strlen(word_2)>0){
                tempVal = NULL;
                break;
            }
            else if(strlen(word_1)>0 && strlen(word_2)>0){
                tempVal = word_1;
            }

        }
        if(tempVal && strcmp(tempVal,"\n") != 0){
                output = addMap(output, tempVal);   

        }


    }

    return output;

}
