#include <stdio.h>

int c, i;
char out[100];

int main(){

  i = 0;

  while((c = getchar()) != '\n'){
    if((c != ' '))
      out[i++] = c;
  }

  for(i = 0; i < sizeof(out); i++)
    printf("%c", out[i]);
}
