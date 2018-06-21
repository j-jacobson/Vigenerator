#include <stdio.h>
#include <ctype.h>

int i, j, k, columns;
char key[1000], choice[1];

int main(){

  while((choice != 'T') & (choice != 'E') & (choice != 'D')){
    printf("Show (T)able, (E)ncrypt message, or (D)ecrypt message?: ");
    scanf("%c", choice);
  }

  if(choice == 'T')
    table();

  else if(choice == 'E')
    encrypt();

  else if(choice == 'D')
    decrypt();


int table(){
  columns = 0;

  while(columns < 1 | columns > 50){
    printf("Type the number of columns you need: ");
    scanf("%d", &columns);
    if(columns < 1)
      printf("Too few columns.");
    else if(columns > 100)
      printf("Too many columns.");
  }

  char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  printf("Type your key: ");
  scanf("%s", key);
  printf("\n    ");
/* print the first row, the key, offset by a space. */
  for(i = 0, j = 0; i < columns; i++, j++){
    if(!(key[j]))
      j = 0;
    printf("%c ", key[j]);
  }
  printf("\n  -");
  for(i = 0; i < columns; i++)
    printf("--");
  printf("\n");
/* print the letter of the alphabet, a '|' character, and then the letter that should be next in that alphabet */

  for(j = 0; j < 26; j++){
    printf("%c |", abc[j]);
    for(i = 0, k = 0; i < columns; i++, k++){
      if(!key[k])
        k = 0;

      if((key[k] + j + 1) > 'z'){
        printf(" %c", (key[k] + j - ('z' - 'a')));
        continue;
      }

      printf(" %c", key[k] + j + 1);
    }

    printf("\n");
  }
}


