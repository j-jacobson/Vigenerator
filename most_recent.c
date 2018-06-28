/*

Title: Vigenerator v3.0
Author: Jonathan Jacobson (jonjacobson715@airmail.cc)
Github: https://github.com/j-jacobson/Vigenerator/

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZ 1000

int i, j, k;
int columns;

char message[MAX_SZ], key[MAX_SZ];
char message_raw[MAX_SZ], key_raw[MAX_SZ], columns_raw[MAX_SZ];
char encrypted[MAX_SZ];
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

/* Replace any number in the key with the their word equivalent. Probably not very useful for a key. */
    if(isdigit(key_raw[i])){
      if(key_raw[i] == '0'){
        key[j++] = 'z';
        key[j++] = 'e';
        key[j++] = 'r';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '1'){
        key[j++] = 'o';
        key[j++] = 'n';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '2'){
        key[j++] = 't';
        key[j++] = 'w';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '3'){
        key[j++] = 't';
        key[j++] = 'h';
        key[j++] = 'r';
        key[j++] = 'e';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '4'){
        key[j++] = 'f';
        key[j++] = 'o';
        key[j++] = 'u';
        key[j++] = 'r';
      }
      else if(key_raw[i] == '5'){
        key[j++] = 'f';
        key[j++] = 'i';
        key[j++] = 'v';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '6'){
        key[j++] = 's';
        key[j++] = 'i';
        key[j++] = 'x';
      }
      else if(key_raw[i] == '7'){
        key[j++] = 's';
        key[j++] = 'e';
        key[j++] = 'v';
        key[j++] = 'e';
        key[j++] = 'n';
      }
      else if(key_raw[i] == '8'){
        key[j++] = 'e';
        key[j++] = 'i';
        key[j++] = 'g';
        key[j++] = 'h';
        key[j++] = 't';
      }
      else if(key_raw[i] == '9'){
        key[j++] = 'n';
        key[j++] = 'i';
        key[j++] = 'n';
        key[j++] = 'e';
      }
    }

    if(!(isalpha(key_raw[i])))
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

/* Replace any number in the key with the their word equivalent. Probably not very useful for a key. */
      if(isdigit(message_raw[i])){
        if(message_raw[i] == '0'){
          message[j++] = 'z';
          message[j++] = 'e';
          message[j++] = 'r';
          message[j++] = 'o';
        }
        else if(message_raw[i] == '1'){
          message[j++] = 'o';
          message[j++] = 'n';
          message[j++] = 'e';
        }
        else if(message_raw[i] == '2'){
          message[j++] = 't';
          message[j++] = 'w';
          message[j++] = 'o';
        }
        else if(message_raw[i] == '3'){
          message[j++] = 't';
          message[j++] = 'h';
          message[j++] = 'r';
          message[j++] = 'e';
          message[j++] = 'e';
        }
        else if(message_raw[i] == '4'){
          message[j++] = 'f';
          message[j++] = 'o';
          message[j++] = 'u';
          message[j++] = 'r';
        }
        else if(message_raw[i] == '5'){
          message[j++] = 'f';
          message[j++] = 'i';
          message[j++] = 'v';
          message[j++] = 'e';
        }
        else if(message_raw[i] == '6'){
          message[j++] = 's';
          message[j++] = 'i';
          message[j++] = 'x';
        }
        else if(message_raw[i] == '7'){
          message[j++] = 's';
          message[j++] = 'e';
          message[j++] = 'v';
          message[j++] = 'e';
          message[j++] = 'n';
        }
        else if(message_raw[i] == '8'){
          message[j++] = 'e';
          message[j++] = 'i';
          message[j++] = 'g';
          message[j++] = 'h';
          message[j++] = 't';
        }
        else if(message_raw[i] == '9'){
          message[j++] = 'n';
          message[j++] = 'i';
          message[j++] = 'n';
          message[j++] = 'e';
        }
      }


      if(!(isalpha(message_raw[i])))
        continue;

      message[j++] = tolower(message_raw[i]);
    }
  while(strlen(message) < 1)

/* For dubugging. Prints the Message the algorithm recieves. */

    /*for(i = 0; i < strlen(message); i++)
      printf("%c", message[i]);*/

/* Length checking. */
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > MAX_SZ)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > MAX_SZ);

  do {

/* Get Key and remove spaces. */

    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < sizeof(key_raw); i++){

    if(isdigit(key_raw[i])){
      if(key_raw[i] == '0'){
        key[j++] = 'z';
        key[j++] = 'e';
        key[j++] = 'r';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '1'){
        key[j++] = 'o';
        key[j++] = 'n';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '2'){
        key[j++] = 't';
        key[j++] = 'w';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '3'){
        key[j++] = 't';
        key[j++] = 'h';
        key[j++] = 'r';
        key[j++] = 'e';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '4'){
        key[j++] = 'f';
        key[j++] = 'o';
        key[j++] = 'u';
        key[j++] = 'r';
      }
      else if(key_raw[i] == '5'){
        key[j++] = 'f';
        key[j++] = 'i';
        key[j++] = 'v';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '6'){
        key[j++] = 's';
        key[j++] = 'i';
        key[j++] = 'x';
      }
      else if(key_raw[i] == '7'){
        key[j++] = 's';
        key[j++] = 'e';
        key[j++] = 'v';
        key[j++] = 'e';
        key[j++] = 'n';
      }
      else if(key_raw[i] == '8'){
        key[j++] = 'e';
        key[j++] = 'i';
        key[j++] = 'g';
        key[j++] = 'h';
        key[j++] = 't';
      }
      else if(key_raw[i] == '9'){
        key[j++] = 'n';
        key[j++] = 'i';
        key[j++] = 'n';
        key[j++] = 'e';
      }
    }

      if(!(isalpha(key_raw[i])))
        continue;
      key[j++] = key_raw[i];
    }

/* Length checking. */
    if(strlen(key) < 1)
      printf("ERROR: Key too short.\n");
    if(strlen(key) > MAX_SZ)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < 1) | strlen(key) > MAX_SZ);

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
      if(!(isalpha(message_raw[i])))
        continue;
    message[j++] = message_raw[i];
    }

/* Length checking. */
    if(strlen(message) < 1)
      printf("ERROR: Message too short.\n");
    else if(strlen(message) > MAX_SZ)
      printf("ERROR: Message too long.\n");
  }
  while(strlen(message) < 1 | strlen(message) > MAX_SZ);

  do {

/* Get Key and remove the spaces. */
    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(key_raw); i++){

    if(isdigit(key_raw[i])){
      if(key_raw[i] == '0'){
        key[j++] = 'z';
        key[j++] = 'e';
        key[j++] = 'r';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '1'){
        key[j++] = 'o';
        key[j++] = 'n';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '2'){
        key[j++] = 't';
        key[j++] = 'w';
        key[j++] = 'o';
      }
      else if(key_raw[i] == '3'){
        key[j++] = 't';
        key[j++] = 'h';
        key[j++] = 'r';
        key[j++] = 'e';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '4'){
        key[j++] = 'f';
        key[j++] = 'o';
        key[j++] = 'u';
        key[j++] = 'r';
      }
      else if(key_raw[i] == '5'){
        key[j++] = 'f';
        key[j++] = 'i';
        key[j++] = 'v';
        key[j++] = 'e';
      }
      else if(key_raw[i] == '6'){
        key[j++] = 's';
        key[j++] = 'i';
        key[j++] = 'x';
      }
      else if(key_raw[i] == '7'){
        key[j++] = 's';
        key[j++] = 'e';
        key[j++] = 'v';
        key[j++] = 'e';
        key[j++] = 'n';
      }
      else if(key_raw[i] == '8'){
        key[j++] = 'e';
        key[j++] = 'i';
        key[j++] = 'g';
        key[j++] = 'h';
        key[j++] = 't';
      }
      else if(key_raw[i] == '9'){
        key[j++] = 'n';
        key[j++] = 'i';
        key[j++] = 'n';
        key[j++] = 'e';
      }
    }

      if(!(isalpha(key_raw[i])))
        continue;
      key[j++] = key_raw[i];
    }

/* Length checking. */
    if(strlen(key) < 1)
      printf("ERROR: Key too short.\n");
    if(strlen(key) > MAX_SZ)
      printf("ERROR: Key too long.\n");
  }
  while((strlen(key) < 1) | strlen(key) > MAX_SZ);

/* Decryption algorithm. */
/* The distance that the key is from 'a' is subtracted from the encrypted message, undoing the encryption.
 1 is subtracted due to the key not being the first row of the Tabula Recta. */

  printf("Your decrypted message is: ");

  for(i = 0, j = 0; i < strlen(message); i++, j++){
    if(!key[j])
      j = 0;
    if(message[i] - (key[j] - 'a') - 1 < 'a'){
      printf("%c", message[i] - key[j] + 'z');
      continue;
    }
    else if(message[i] - (key[j] - 'a') - 1 > 'z'){
      printf("%c", key[j] + message[i] - 'z');
      continue;
    }
   /*
    else if((message[i] - (key[j] - 'a') - 1) < 'a'){
      printf("%c", message[i] - (key[j] - 'a') - 1 + 'z');
      continue;
    }
    else if((message[i] - (key[j] - 'a') - 1) > 'z'){
      printf("%c", message[i] - (key[j] - 'a') - 1 - 'z');
      continue;
    }
    */
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
