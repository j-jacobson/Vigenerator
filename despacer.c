#include <stdio.h>
#include <ctype.h>
#include <string.h>


int i, j;
char key[100], copy[100];

int main(){

  fgets(key, 100, stdin);
  for(i = 0, j = 0; i < sizeof(key); i++){
    
    if(isdigit(key[i]) | isalpha(key[i])){
      copy[j] = key[i];
      j++;
    }
  }

  for(i = 0; i < sizeof(copy); i++)
    printf("%c", copy[i]);
}
