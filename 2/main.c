#include "splitter.h"


int main(int argc, char* argv[]){

    if(argc<3){
        printf("Please type file name");
    }
    else{
        FILE *file;

        long fileSize;

        char *buffer_1;
        char *buffer_2;

        Map* output;
        Map* iter;


        if((file = fopen(argv[1], "r")) != NULL){

            fseek(file, 0L, SEEK_END);
            fileSize = ftell(file);
            rewind(file);

            buffer_1 = (char*) calloc(1, fileSize+1);

            if(buffer_1 != NULL){
                fgets(buffer_1, fileSize ,file);

            }


            fclose(file);
        }

        if((file = fopen(argv[2], "r")) != NULL){

            fseek(file, 0L, SEEK_END);
            fileSize = ftell(file);
            rewind(file);

            buffer_2 = (char*) calloc(1, fileSize+1);

            if(buffer_2 != NULL){
                fgets(buffer_2, fileSize ,file);
            }
            fclose(file);
        }


         output = checkContain(splitBuffer(buffer_1), splitBuffer(buffer_2));


         for(iter = output; NULL != iter; iter = iter->next){
                if(strlen(iter->text)>0){
                    printf("%s %i \n", iter->text, iter->count);
                }
            } 

        /*if((file = fopen("output", "w")) != NULL){
            for(iter = output; NULL != iter; iter = iter->next){
                if(strlen(iter->text)>0){
                    fprintf(file, "%s %i \n", iter->text, iter->count);
                }
            }
            fclose(file);
        }*/


        free(buffer_1);
 	free(buffer_2);
    }
    return 0;
}
