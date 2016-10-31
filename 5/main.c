#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void compress(char *str){

    char *astr = malloc(strlen(str)*sizeof(char));
    char *temp = malloc(strlen(str)*sizeof(char));

    memcpy(temp, str, strlen(str));



    for(astr, temp; *temp; temp++){
        int count = 1;
        astr[0] = temp[0];
        while(temp[0] == temp[1]){
            count++;
            temp++;
        }

        if(count > 1){
            printf("%s",astr);
            printf("%d", count);
        }
        else{
            printf("%s",astr);

        }
    }

}


int main(int argc, char* argv[]){


    char *str = malloc(sizeof(char) * 128);

    printf("Enter text you want to compress: ");
    scanf("%126s", str);


    printf("origin: %s\n",str);

    printf("compressed: ");
    compress(str);

    printf("\n");

    free(str);

    
    return 0;
}
