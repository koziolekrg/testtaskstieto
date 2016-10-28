#include "compress.h"
#include <stdio.h>
#include <string.h>
   

char* StrCompress(char *myStr)
{
  char *s, *in;
  for (s = myStr, in = myStr; *s; s++) {
    int count = 1;
    in[0] = s[0]; in++;
    while (s[0] == s[1]) {
      count++;
      s++;
    }
    if (count > 1) {
      int len = sprintf(in, "%d", count);
      in += len;
    }
  }
  in[0] = 0;
  return myStr;
}


int main(int argc, char* argv[]){

 char string[] = "pppqqaweeel";

 printf("%s",StrCompress(string));

    
    return 0;
}
