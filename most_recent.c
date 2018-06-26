#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZ 500

int i, j, k, columns;

char message[100], key[100];
char message_raw[100], key_raw[100];
char encrypted[100];
char choice[1];

int table(){

  do{
    printf("Type the number of columns you need: ");
    scanf("%d", columns);
    if(columns < 1)
      printf("ERROR: Too few columns.\n");
    else if(columns > 50)
      printf("ERROR: Too many columns.\n");
  }
  while(columns < 1 | columns > 50);

  printf("Type your key: ");

  fgets(key, MAX_SZ, stdin);
  for(i = 0, j = 0; i < strlen(key_raw); i++){
    if(key_raw[i] == ' ')
      continue;
    key[j++] = key_raw[i];
  }

/* print the first row, the key, offset by a space. */

  for(i = 0, j = 0, printf("\n    "); i < columns; i++, j++){
    if(!(key[j]))
      j = 0;
    printf("%c ", key[j]);
  }

  for(i = 0, printf("\n  -"); i < 20; i++)
    printf("--");
  printf("\n");

/* print the letter of the alphabet, a '|' character, and then the letter that should be next in that alphabet */

  for(k = 0; k < 26; k++){
    printf("%c |", 'a' + k);
    for(i = 0, j = 0; i < 20; i++, j++){
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

    fgets(message, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(message); i++){
      if(message[i] == ' '){
        continue;
        k++;
      }
      message[j++] = message[i];
    }

    for( ;k > 0; k--)
      message[j++] = '\0';

    for(i = 0; i < strlen(message); i++)
      printf("%c", message[i]);

    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {

    printf("Please type your key: ");

    fgets(key, MAX_SZ, stdin);
    for(i = 0, j = 0; i < sizeof(key); i++){
      if(key[i] == ' ')
        continue;
      printf("%c", key[i]);
      key[j++] = key[i];
    }

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
    /*despaced(&message);*/

    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {
    printf("Please type your key: ");
    /*despaced(&key);*/

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
    fgets(choice, MAX_SZ, stdin);
    /*scanf("%c", choice);*/
  }
  while((*choice != 'T') & (*choice != 'E') & (*choice != 'D'));

  if((*choice == 'T') | (*choice == 't'))
    table();

  else if((*choice == 'E') | (*choice == 'e'))
    encrypt();

  else if((*choice == 'D') | (*choice == 'd'))
    decrypt();

}

