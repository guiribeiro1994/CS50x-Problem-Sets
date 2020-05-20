// Substitution problem set cs50 wk2 2020.
// This program encrypts messages using a substitution cipher.
// Compile as: clang substitution.c -o substitution -lcs50

// Header files go here.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

// Function prototypes go here.
int checksCLA(int a);
int validatesKEY(string a);
string codeSHIFT(string a, string b);



// Program start.
int main(int argc, char *argv[]) {
  // Checks at least (and only) one Command-Line Argument was used.
  if (checksCLA(argc) == 1) {
    // Ends program.
    return 1;
  }
  // Checks that key is 26 unique alphabetical characters.
  if (validatesKEY(argv[1]) == 1) {
    // Ends program.
    return 1;
  }
  // Gets user input text.
  string plaintext = get_string("plaintext: ");
  // Encodes user input and prints coded output.
  printf("ciphertext: %s\n", codeSHIFT(plaintext, argv[1]));
  return 0;
}
// Program end.



// checksCLA (Command-Line Arguments) function definition.
int checksCLA(int a) {
  if (a != 2) {
    printf("Usage: ./substitution key\n");
    return 1;
  }
  return 0;
}

// validatesKEY function definition.
int validatesKEY(string a) {
  int n = strlen(a), i, j;
  char b[n];
  // Checks that 26 characters were used.
  if (n != 26) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }
  // Checks that only alphabetical characters were used.
  for (i = 0; i < n; i++) {
    if (isalpha(a[i]) == 0) {
      printf("Key must contain only aplhabetical characters.\n");
      return 1;
    }
  }
  // Checks that characters are not repeated.
  for (i = 0; i < n; i++) {
    j = i;
    do {
      if (a[i] == b[i - j]) {
        printf("Error: key contains a repeated character.\n");
        return 1;
      }
      if (j == 0) {
        b[i] = a[i];
        break;
      }
      else {
        j -= 1;
      }
    } while (j != n);
  }
  // All checks cleared.
  return 0;
}

// codeSHIFT function definition.
string codeSHIFT(string a, string b) {
  char UPPER[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
  char lower[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

  int n = strlen(a), i, j;

  char *c = NULL;
  c = malloc(n);

  for (i = 0; i < n; i++) {
    // Checks for uppercase letters.
    if (isupper(a[i]) != 0) {
      for (j = 0; j < 26; j++) {
        if (a[i] == UPPER[j]) {
          b[j] = toupper(b[j]);
          c[i] = b[j];
          break;
        }
      }
    }
    // Checks for lowercase letters.
    if (islower(a[i]) != 0) {
      for (j = 0; j < 26; j++) {
        if (a[i] == lower[j]) {
          b[j] = tolower(b[j]);
          c[i] = b[j];
          break;
        }
      }
    }
    // Checks if character is anything other than a letter.
    if (isalpha(a[i]) == 0) {
      c[i] = a[i];
    }
  }
  return c;
  memset(c, 0, n);
}
