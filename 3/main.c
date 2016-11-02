
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char* argv[]){

    FILE *input, *output;
    long fileSize;
    char **set ;
    char *buffer, *split;
    int iter = 1;



    if((input = fopen(argv[1], "r")) != NULL){

        fseek(input, 0L, SEEK_END);
        fileSize = ftell(input);
        rewind(input);

        set = malloc(sizeof(char*)*fileSize);
        buffer = (char*) calloc(1, fileSize+1);

        fgets(buffer, fileSize ,input);
        split = strtok(buffer, "},{");
        set[0]="";

        while(split != NULL){
             set[iter] = split;
             split = strtok(NULL, "},{");
             iter++;
        }

        fclose(input);
    }

    if((output = fopen("output", "w")) != NULL){
        int i,j, max_bits;
        short bit;

        for(i=0; i< pow(2,iter-1); i++){

            fprintf(output, "{");
            max_bits = floor(log2(i));

            for(j=0; j<= max_bits; j++){
                bit = (i>>j) & 1;

                if(bit == 1){
                    fprintf(output,"%s", set[j+1]);
                }
                if(j<max_bits && bit == 1){
                    fprintf(output,",");
                }


            }
            fprintf(output,"}, ");
        }
        fclose(output);
    }
    printf("Subsets generated and wrote to file [output]");
    return 0;
}
