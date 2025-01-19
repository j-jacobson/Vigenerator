# Vigenerator = Vigenère + Generator
Program to encrypt and decrypt messages, as well as produce tabula recta using Giovan Battista Bellaso's Vigenère cipher.

https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher

main.c is the main program. Compile it by doing:

```
gcc main.c -o vgen
```

You can then run the program by doing:

```
./vgen
```

Run the program, and it will ask you what you want to do:

Show (T)able,

(E)ncrypt message,

or (D)ecrypt message.

The program will ask you for a key, and message (if encrypting/decrypting). If you are generating a table, it will also ask how large of a table you want.
