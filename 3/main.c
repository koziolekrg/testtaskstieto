#include "splitter.h"


int main(int argc, char* argv[]){

    if(argc<3){
        printf("Please type file name");
    }
    else{
        FILE *file;
        FILE *save;

        long fileSize;

        char *buffer_1;
        char buffer_2 [256];

        Map* output;
        Map* iter;
        Map* buffermap;
        size_t len;
        int line;
        line = 0;

        if((file = fopen(argv[1], "r")) != NULL){
            fseek(file, 0L, SEEK_END);
            fileSize = ftell(file);
            rewind(file);

            buffer_1 = (char*) calloc(1, fileSize+1);

            if(buffer_1 != NULL){
                fgets(buffer_1, fileSize ,file);

            }
            fclose(file);
            buffermap = splitBuffer(buffer_1);
        }


        save = fopen("output", "w");

        if((file = fopen(argv[2], "r")) != NULL){
            while (fgets(buffer_2, sizeof(buffer_2), file)) {
                //printf("%s", buffer_2);

                output = checkContain(buffermap, splitBuffer(buffer_2));
                line ++;

                //output = splitBuffer(buffer_2);

                for(iter = output; NULL != iter; iter = iter->next){
                    if(strlen(iter->text)>0){
                        fprintf(save,"%i %s \n",line, iter->text);
                        //printf("%i %s \n",line, iter->text);
                    }
                }

            }
            fclose(file);
            fclose(save);
        }

        free(buffer_1);
    }



    return 0;
}
