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


/*for(iter_output = output; NULL != iter_output; iter_output = iter_output->next){

    if(strcmp(word_2, toLower(iter_output->text)) == 0 && strlen(iter_output->text)>0 && strlen(iter_2->text)>0 ){
        //iter_output->count = iter_output->count+1;
        printf("0: %s \n", word_2);

    }
    else{
        printf("1: %s \n", word_2);
    }
}*/

Map* checkContain(Map* map_1, Map* map_2){
    Map* iter_1;
    Map* iter_2;
    Map* iter_output;
    Map* output;
    int retVal;
    char *tempVal;
    output = createMap("");

        for(iter_1 = map_1; NULL != iter_1; iter_1 = iter_1->next){
            for(iter_2 = map_2; NULL != iter_2; iter_2 = iter_2->next){
                retVal=0;
                char* word_1 = toLower(iter_1->text);
                char* word_2 = toLower(iter_2->text);

                //printf("%s -- %s \n",word_1, word_2);
                if(strcmp(word_1, word_2) == 0 && strlen(word_1)>0 && strlen(word_2)>0){
                    //printf("Compare %s -- %s \n",word_1, word_2);
                    tempVal = NULL;
                    break;
                }
                else if(strlen(word_1)>0 && strlen(word_2)>0){
                    printf("Not Compare %s -- %s \n",word_1, word_2);
                    tempVal = word_2;
                }
            }
            printf("temp %s \n",tempVal);
            if(tempVal){
                printf("ADD %s \n",tempVal);
            }

        }

    return output;

}
