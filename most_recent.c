#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZ 500

int i, j, k, columns;

char message[100], key[100];
char raw[100], out[100];
char encrypted[100];
char choice[1];

void despaced(char *out){
  while((k = getchar()) != '\n'){
    if((k != ' '))
      out[i++] = k;
  }
}

int table(){

/*  do{
    printf("Type the number of columns you need: ");
    scanf("%i", &columns);
    if(columns < 1)
      printf("ERROR: Too few columns.\n");
    else if(columns > 50)
      printf("ERROR: Too many columns.\n");
  }
  while(columns < 1 | columns > 50);
*/
  printf("Type your key: ");
/*  fgets(key, 100, stdin);*/
/*  despaced(&key);*/
  while((k = getchar()) != '\n'){
    if((k != ' '))
      key[i++] = k;
  }
  for(i = 0; i < sizeof(key); i++)
    printf("%c", key[i]);

/* print the first row, the key, offset by a space. */
  for(i = 0, j = 0, printf("\n    "); i < 20/*columns*/; i++, j++){
    if(!(key[j]))
      j = 0;
    printf("%c ", key[j]);
  }

  for(i = 0, printf("\n  -"); i < columns; i++)
    printf("--");
  printf("\n");

/* print the letter of the alphabet, a '|' character, and then the letter that should be next in that alphabet */

  for(k = 0; k < 26; k++){
    printf("%c |", 'a' + k);
    for(i = 0, j = 0; i < columns; i++, j++){
      if(!key[j])
        j = 0;

      if((key[j] + k + 1) > 'z'){
        printf(" %c", (key[j] + k - ('z' - 'a')));
        continue;
      }

      printf(" %c", key[j] + k + 1);
    }

    printf("\n");
  }
}


int encrypt(){

  do{
    printf("Please type your message: ");
    despaced(&message);

    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {
    printf("Please type your key: ");
    despaced(&key);
    if(strlen(key) < (strlen(message) / 4))
      printf("ERROR: Key too short.\n");
    if(strlen(key) > 500)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < (strlen(message) / 4)) | strlen(key) > 500);

  printf("Your encrypted message is: ");

  for(i = 0, j = 0; i < strlen(message); i++, j++){
    if(!key[j])
      j = 0;
    if(key[j] + (message[i] - 'a') + 1 > 'z'){
      printf("%c", key[j] + message[i] - 'z');
      continue;
    }
    printf("%c", key[j] + (message[i] - 'a') + 1);
  }
  printf("\n");
}

int decrypt(){

/* get the message */
/* get the key */

/* algorhythm should be
  decrypted = message - (key - a)
*/
do{
    printf("Please type your message: ");
    despaced(&message);

    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {
    printf("Please type your key: ");
    despaced(&key);

    if(strlen(key) < (strlen(message) / 4))
      printf("ERROR: Key too short.\n");
    if(strlen(key) > 500)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < (strlen(message) / 4)) | strlen(key) > 500);

  printf("Your decrypted message is: ");

  for(i = 0, j = 0; i < strlen(message); i++, j++){
    if(!key[j])
      j = 0;
    if(message[i] - (key[j] - 'a') < 'a'){
      printf("%c", message[i] - key[j] + 'z');
      continue;
    }
    else if(message[i] - (key[j] - 'a') > 'z'){
      printf("%c", key[j] + message[i] - 'z');
      continue;
    }
    printf("%c", message[i] - (key[j] - 'a') - 1);
  }
  printf("\n");

}



int main(){

  do{
    printf("Show (T)able, (E)ncrypt message, or (D)ecrypt message?: ");
    scanf("%c", choice);
  }
  while((*choice != 'T') & (*choice != 'E') & (*choice != 'D'));

  if((*choice == 'T') | (*choice == 't'))
    table();

  else if((*choice == 'E') | (*choice == 'e'))
    encrypt();

  else if((*choice == 'D') | (*choice == 'd'))
    decrypt();

}

