/*

Title: Vigenerator v3.1
Author: Jonathan Jacobson (jonjacobson715@gmail.com)
Github: https://github.com/j-jacobson/Vigenerator/

*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SZ 10000

int i, j, k;
int columns;

char message[MAX_SZ], key[MAX_SZ];
char message_raw[MAX_SZ], key_raw[MAX_SZ], columns_raw[MAX_SZ];
char encrypted[MAX_SZ];
char choice[1];


/* Problems that should be fixed in the future:
  * A guy on stack exchange said that you should use strtol() instead of atoi() because it has better error handling.
  * numberToWord should be a function to promote reuse
  * despacer should be a separate function
*/

void digitToChar(const char *in, char *out) {
    int j = 0;  // Index for the out array

    // Loop through each character in 'in'
    for (int i = 0; in[i] != '\0'; i++) {
        if (isdigit(in[i])) {
            if (in[i] == '0') {
                out[j++] = 'z';
                out[j++] = 'e';
                out[j++] = 'r';
                out[j++] = 'o';
            }
            else if (in[i] == '1') {
                out[j++] = 'o';
                out[j++] = 'n';
                out[j++] = 'e';
            }
            else if (in[i] == '2') {
                out[j++] = 't';
                out[j++] = 'w';
                out[j++] = 'o';
            }
            else if (in[i] == '3') {
                out[j++] = 't';
                out[j++] = 'h';
                out[j++] = 'r';
                out[j++] = 'e';
                out[j++] = 'e';
            }
            else if (in[i] == '4') {
                out[j++] = 'f';
                out[j++] = 'o';
                out[j++] = 'u';
                out[j++] = 'r';
            }
            else if (in[i] == '5') {
                out[j++] = 'f';
                out[j++] = 'i';
                out[j++] = 'v';
                out[j++] = 'e';
            }
            else if (in[i] == '6') {
                out[j++] = 's';
                out[j++] = 'i';
                out[j++] = 'x';
            }
            else if (in[i] == '7') {
                out[j++] = 's';
                out[j++] = 'e';
                out[j++] = 'v';
                out[j++] = 'e';
                out[j++] = 'n';
            }
            else if (in[i] == '8') {
                out[j++] = 'e';
                out[j++] = 'i';
                out[j++] = 'g';
                out[j++] = 'h';
                out[j++] = 't';
            }
            else if (in[i] == '9') {
                out[j++] = 'n';
                out[j++] = 'i';
                out[j++] = 'n';
                out[j++] = 'e';
            }
        }
    }
}

/* Creates and prints the tabla recta */
void table() {

  do {
    /* Get the number of columns and convert to an integer. */
    printf("Type the number of columns you need: ");
    fgets(columns_raw, MAX_SZ, stdin);
    columns = atoi(columns_raw);

    /* Size checking. */
      if(columns < 1)
        printf("ERROR: Too few columns.\n");
      else if(columns > 50)
        printf("ERROR: Too many columns.\n");
  } while(columns < 1 | columns > 50);

  do{
    /* Get the Key and remove the spaces */
    printf("Type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(key_raw); i++) {
      /* Replace any number in the key with the their word equivalent. */
      if(isdigit(key_raw[i])) {
        digitToChar(&key_raw[i], key);
      }

      if(!(isalpha(key_raw[i]))) {
        continue;
      }
      key[j++] = toupper(key_raw[i]);
    }

    /* Size checking */
    if(strlen(key) < 1) {
      printf("ERROR: Key too short.\n");
    }
    else if(strlen(key) > MAX_SZ) {
      printf("ERROR: Key too long.\n");
    }

  } while(strlen(key) < 1 | strlen(key) > MAX_SZ);

  /* Print the first row, the Key, offset by a space. */
  for(i = 0, j = 0, printf("\n    "); i < columns; i++, j++) {
    if(!(key[j])) {
      j = 0;
    }
    printf("%c ", key[j]);
  }

  for(i = 0, printf("\n  -"); i < columns; i++) {
    printf("--");
  }
  printf("\n");

  /* Table making function. */
  /* Print the letter of the alphabet, a '|' character, and then the letter that should be next in that alphabet. */
  for(k = 0; k < 26; k++) {
    printf("%c |", 'a' + k);
    for(i = 0, j = 0; i < columns; i++, j++) {
      if(!key[j]) {
        j = 0;
      }

      // Handle lowercase and uppercase letters properly
      if ('a' <= key[j] && key[j] <= 'z') {
          // For lowercase letters
          if ((key[j] + 1 + k) > 'z') {
              printf(" %c", (key[j] + k - ('z' - 'a')));
          } else {
              printf(" %c", key[j] + k + 1);
          }
      } else if ('A' <= key[j] && key[j] <= 'Z') {
          // For uppercase letters
          if ((key[j] + k + 1) > 'Z') {
              printf(" %c", (key[j] + k - ('Z' - 'A')));
          } else {
              printf(" %c", key[j] + k + 1);
          }
      }
    }
    printf("\n");
  }
}

/* Encryption function */
void encrypt(){
  do{

    /* Get Message and remove the spaces. */
    printf("Please type your message: ");

    fgets(message_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(message_raw); i++){

      /* Replace any number in the Message with the their word equivalent. */
      if(isdigit(message_raw[i])) {
        digitToChar(&message_raw[i], key);
      }

      if(!(isalpha(message_raw[i]))) {
        continue;
      }

      message[j++] = message_raw[i];
    }

    /* Length checking. */
    if(strlen(message) < 1) {
      printf("ERROR: Message too short.\n");
    }
    else if(strlen(message) > MAX_SZ) {
      printf("ERROR: Message too long.\n");
    }
  } while(strlen(message) < 1 | strlen(message) > MAX_SZ);

  do {
    /* Get Key and remove spaces. */
    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < sizeof(key_raw); i++){

      if(isdigit(key_raw[i])) {
        digitToChar(&key_raw[i], key);
      }

      if(!(isalpha(key_raw[i])))
        continue;
      key[j++] = key_raw[i];
    }

    /* Length checking. */
    if(strlen(key) < 1) {
      printf("ERROR: Key too short.\n");
    }
    if(strlen(key) > MAX_SZ){
      printf("ERROR: Key too long.\n");
    }
  } while((strlen(key) < 1) | (strlen(key) > MAX_SZ));

  /* Encryption algorithm. */
  /* The distance that the message character is from 'a'
  is added to the letter of the key for that column.
  1 is added because the key is not the first row of the column, just the header. */
  printf("Your encrypted message is: ");

  for (i = 0, j = 0; i < strlen(message); i++, j++) {
    if (!key[j]) {
        j = 0;  // Reset key index when reaching the end of the key
    }

    int shift = key[j] - 'a';  // Shift amount from key character

     // Encrypt the message using the Vigenère cipher logic
    if (key[j] >= 'A' && key[j] <= 'Z') {
      shift = key[j] - 'A';  // Shift amount from key character
    }

    int newChar = message[i] + shift + 1;  // Apply shift

    // Handle wrap-around for encryption, considering both uppercase and lowercase
    if (isupper(message[i])) {
      if (newChar > 'Z') {
        // Wrap around to 'A' if the result is greater than 'Z'
        newChar = 'A' + (newChar - 'Z' - 1);
      } else if (newChar < 'A') {
        // Wrap around to 'Z' if the result is less than 'A'
        newChar = 'Z' - ('A' - newChar - 1);
      }
    } else if (islower(message[i])) {
      // For lowercase letters
      if (newChar < 'a') {
        // Wrap around to 'z' if below 'a'
        newChar = 'z' - ('a' - newChar - 1);
      }
      else if (newChar > 'z') {
        // Wrap around to 'a' if above 'z'
        newChar = 'a' + (newChar - 'z' - 1);
      }
    }

    printf("%c", newChar);
  }
  printf("\n");
}

/* Decryption function. */
void decrypt(){

  do{
    /* Get Message and remove the spaces. */
    printf("Please type your message: ");

    fgets(message_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(message_raw); i++){

      /* Checks for number-only inputs and prints a more specific error message */
      if(isdigit(message_raw[i])){
        choice[0] = 'y';
        continue;
      }

      if(!(isalpha(message_raw[i]))) {
        continue;
      }

      message[j++] = message_raw[i];
    }

    /* Length checking. */
    if(strlen(message) < 1 & choice[0] == 'y') {
      printf("ERROR: This is not an accepted input.\n"
             "This program does not output numbers in an encrypted string.\n"
             "Maybe you have typed your key here instead?\n");
    }
    else if(strlen(message) < 1) {
      printf("ERROR: Message too short.\n");
    }
    else if(strlen(message) > MAX_SZ) {
      printf("ERROR: Message too long.\n");
    }
  } while(strlen(message) < 1 | strlen(message) > MAX_SZ);

  if(choice[0] == 'y') {
    printf("There is a number in your input. This may not be a valid message.\n"
           "The program will continue as normal, ignoring the numeric part of your input,\n"
           "however this may cause your message to be decrypted incorrectly.\n");
  }
  do {
    /* Get Key and remove the spaces. */
    printf("Please type your key: ");

    fgets(key_raw, MAX_SZ, stdin);
    for(i = 0, j = 0; i < strlen(key_raw); i++){

      if(isdigit(key_raw[i])) {
        digitToChar(&key_raw[i], key);
      }

      if(!(isalpha(key_raw[i]))) {
        continue;
      }
      key[j++] = key_raw[i];
    }

    /* Length checking. */
    if(strlen(key) < 1)
      printf("ERROR: Key too short.\n");
    if(strlen(key) > MAX_SZ)
      printf("ERROR: Key too long.\n");
  } while((strlen(key) < 1) | (strlen(key) > MAX_SZ));

  /* Decryption algorithm. */
  /* The distance that the key is from 'a' is subtracted from the encrypted message, undoing the encryption.
    1 is subtracted due to the key not being the first row of the Tabula Recta. */

  printf("Your decrypted message is: ");

  for(i = 0, j = 0; i < strlen(message); i++, j++) {
    // Reset key index when reaching the end of the key
    if(!key[j]){
      j = 0;
    }

    // Decrypt the message using the Vigenère cipher logic
    int shift = key[j] - 'a';  // Shift amount from key character

    // Encrypt the message using the Vigenère cipher logic
    if (key[j] >= 'A' && key[j] <= 'Z') {
      shift = key[j] - 'A';  // Shift amount from key character
    }

    int newChar = message[i] - shift - 1;  // Apply shift

    // Handle wrap-around for decryption, considering both uppercase and lowercase
    if (isupper(message[i])) {
      if (newChar < 'A') {
        // Wrap around to 'Z' if the result is less than 'A'
        newChar = 'Z' - ('A' - newChar - 1);
      } else if (newChar > 'Z') {
        // Wrap around to 'A' if the result is greater than 'Z'
        newChar = 'A' + (newChar - 'Z' - 1);
      }
    } else if (islower(message[i])) {
      // For lowercase letters
      if (newChar < 'a') {
        // Wrap around to 'z' if below 'a'
        newChar = 'z' - ('a' - newChar - 1);
      }
      else if (newChar > 'z') {
        // Wrap around to 'a' if above 'z'
        newChar = 'a' + (newChar - 'z' - 1);
      }
    }

    printf("%c", newChar);
  }
  printf("\n");
}

/* Main function. Allows user to pick from options (E)ncrypt, (D)ecrypt, or Show (T)able. */
int main(){

  do{
    printf("Show (T)able, (E)ncrypt message, or (D)ecrypt message?: ");
    fgets(choice, MAX_SZ, stdin);

  }
  /* This could probably be replaced/enhanced with the lower() function. */
  while((*choice != 'T') & (*choice != 'E') & (*choice != 'D') & (*choice != 't') & (*choice != 'e') & (*choice != 'd'));

  if((*choice == 'T') | (*choice == 't'))
    table();

  else if((*choice == 'E') | (*choice == 'e'))
    encrypt();

  else if((*choice == 'D') | (*choice == 'd'))
    decrypt();

  return 0;
}
