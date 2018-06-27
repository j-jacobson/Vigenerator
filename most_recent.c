/*

Title: Vigenerator v3.0
Author: Jonathan Jacobson (jonjacobson715@airmail.cc)
Github: https://github.com/j-jacobson/Vigenerator/

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZ 500

int i, j, k;
int columns;

char message[100], key[100];
char message_raw[100], key_raw[100], columns_raw[100];
char encrypted[100];
char choice[1];


/* Problems that should be fixed in the future:

  * The algorithm only works for lowercase letters.
  * Symbols are practically unsupported. I don't know how the regular cipher handles them.
    Maybe they should just be stripped from the message like spaces are. The function isalpha() could
    help with this.
  * Numbers are unsupported. They should be converted and encrypted somehow. Maybe a seperate version
    of the algorithm should be created for them, it is important information.
  * A guy on stack exchange said that you should use strtol() instead of atoi() because it has better error handling.

*/

int table(){

  do{

/* Get the number of columns and convert to an integer. */

    printf("Type the number of columns you need: ");

    fgets(columns_raw, MAX_SZ, stdin);
    columns = atoi(columns_raw);

/* Size checking. */
    if(columns < 1)
      printf("ERROR: Too few columns.\n");
    else if(columns > 50)
      printf("ERROR: Too many columns.\n");
  }
  while(columns < 1 | columns > 50);

/* Get the Key and remove the spaces */

  printf("Type your key: ");

  fgets(key_raw, MAX_SZ, stdin);
  for(i = 0, j = 0; i < strlen(key_raw); i++){
    if(key_raw[i] == ' ' | key_raw[i] == '\n')
      continue;
    key[j++] = key_raw[i];
  }

/* Print the first row, the Key, offset by a space. */

  for(i = 0, j = 0, printf("\n    "); i < columns; i++, j++){
    if(!(key[j]))
      j = 0;
    printf("%c ", key[j]);
  }

  for(i = 0, printf("\n  -"); i < columns; i++)
    printf("--");
  printf("\n");

/* Table making function. */
/* Print the letter of the alphabet, a '|' character, and then the letter that should be next in that alphabet. */

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



/* Encryption function */
int encrypt(){

  do{

/* Get Message and remove the spaces. */

    printf("Please type your message: ");

    fgets(message_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(message_raw); i++){
      if(message_raw[i] == ' ' | message_raw[i] == '\n'){
        continue;
        k++;
      }
      message[j++] = message_raw[i];
    }

/* For dubugging. Prints the Message the algorithm recieves. */

    /*for(i = 0; i < strlen(message); i++)
      printf("%c", message[i]);*/

/* Length checking. */
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {

/* Get Key and remove spaces. */

    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < sizeof(key_raw); i++){
      if(key_raw[i] == ' ' | key_raw[i] == '\n')
        continue;
      key[j++] = key_raw[i];
    }

/* Length checking. */
    if(strlen(key) < (strlen(message) / 4))
      printf("ERROR: Key too short.\n");
    if(strlen(key) > 500)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < (strlen(message) / 4)) | strlen(key) > 500);

/* Encryption algorithm. */
/* The distance that the message character is from 'a'
 is added to the letter of the key for that column.
 1 is added because the key is not the first row of the column, just the header. */

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

/* Decryption function. */
int decrypt(){

do{

/* Get Message and remove the spaces. */
    printf("Please type your message: ");

    fgets(message_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(message_raw); i++){
      if(message_raw[i] == ' ' | message_raw[i] == '\n')
        continue;
    message[j++] = message_raw[i];
    }

/* Length checking. */
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > 500)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > 500);

  do {

/* Get Key and remove the spaces. */
    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(key_raw); i++){
      if(key_raw[i] == ' ' | key_raw[i] == '\n')
        continue;
      key[j++] = key_raw[i];
    }

/* Length checking. */
    if(strlen(key) < (strlen(message) / 4))
      printf("ERROR: Key too short.\n");
    if(strlen(key) > 500)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < (strlen(message) / 4)) | strlen(key) > 500);

/* Decryption algorithm. */
/* The distance that the key is from 'a' is subtracted from the encrypted message, undoing the encryption.
 1 is subtracted due to the key not being the first row of the Tabula Recta. */

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


/* Main function. Allows user to pick from options Encrypt, Decrypt, or Show Table. */
int main(){

  do{
    printf("Show (T)able, (E)ncrypt message, or (D)ecrypt message?: ");
    fgets(choice, MAX_SZ, stdin);

  }

/* This could probably be replaced/enhanced with the lower() function. */
  while((*choice != 'T') & (*choice != 'E') & (*choice != 'D'));

  if((*choice == 'T') | (*choice == 't'))
    table();

  else if((*choice == 'E') | (*choice == 'e'))
    encrypt();

  else if((*choice == 'D') | (*choice == 'd'))
    decrypt();

}

