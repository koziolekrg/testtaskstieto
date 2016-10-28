#include "splitter.h"


int main(int argc, char* argv[]){

    if(argc<2){
        printf("Please type file name");
    }
    else{
        FILE *file;
        long fileSize;
        char* buffer;
        char *split;
        Map* output;
        Map* iter;


        if((file = fopen(argv[1], "r")) != NULL){

            fseek(file, 0L, SEEK_END);
            fileSize = ftell(file);
            rewind(file);

            buffer = (char*) calloc(1, fileSize+1);

            if(buffer != NULL){
                fgets(buffer, fileSize ,file);
                split = strtok(buffer, " -,.;");
                output = createMap("");

                output = doSplit(buffer, output);
            }
            fclose(file);
        }
        if((file = fopen("output", "w")) != NULL){
            for(iter = output; NULL != iter; iter = iter->next){
                if(strlen(iter->text)>0){
                    fprintf(file, "%s %i \n", iter->text, iter->count);
                }
            }
            fclose(file);
        }
	deleteMap(output);
        free(buffer);

    }
    return 0;
}
