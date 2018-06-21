#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
#define MAX_KEY_SZ 500
#define MAX_MESSAGE_SZ 500
*/
int i, j, k, columns;
char key[500], choice[1], encrypted[500], message[500];

int table(){

  do{
    printf("Type the number of columns you need: ");
    scanf("%d", &columns);
    /*fgets(columns, MAX_COLUMNS, stdin);*/
    if(columns < 1)
      printf("ERROR: Too few columns.\n");
    else if(columns > 100)
      printf("ERROR: Too many columns.\n");
  }
  while(columns < 1 | columns > 50);

/*  char abc[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};*/
  printf("Type your key: ");
  /*fgets(key, MAX_KEY_SZ, stdin);*/
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
    printf("%c |", 'a' + j);
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


int encrypt(){

  do{
    printf("Please type your message: ");
    /*fgets(message, MAX_MESSAGE_SZ, stdin);*/
    scanf("%s", message);
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {
    printf("Please type your key: ");
    /*fgets(key, MAX_KEY_SZ, stdin);*/
    scanf("%s", key);
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
    /*fgets(message, MAX_MESSAGE_SZ, stdin);*/
    scanf("%s", message);
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {
    printf("Please type your key: ");
    /*fgets(key, MAX_KEY_SZ, stdin);*/
    scanf("%s", key);
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

  /*free(message);
  free(key);
  free(encrypted);*/
}

