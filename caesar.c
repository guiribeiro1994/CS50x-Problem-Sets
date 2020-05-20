// Caesar problem set cs50 wk2 2020.
// This program encrypts messages using Caesar’s cipher.
// Compile as: clang caesar.c -o caesar -lcs50

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
int main(int argc, char *argv[])
{
  // Checks at least (and only) one Command-Line Argument was used.
  if (checksCLA(argc) == 0) {
    // Checks that Command-Line Argument key used is a digit.
    if (validatesKEY(argv[1]) == 0) {
      // Gets user input text.
      string plaintext = get_string("plaintext: ");

      // Encodes user input and prints coded output.
      codeSHIFT(plaintext, argv[1]);

      return 0;
    }
  }
  return 1;
}
// Program end.



// checksCLA (Command-Line Arguments) function definition.
int checksCLA(int a) {
  if (a != 2) {
    printf("Usage: ./caesar key\n");
    return 1;
  }
  return 0;
}

// validatesKEY function definition.
int validatesKEY(string a) {
  int n = strlen(a), i;
  char b[n];
  strcpy(b, a);

  for (i = 0; i < n; i++) {
    if (isdigit(b[i]) == 0) {
      printf("Usage: ./caesar key\n");
      return 1;
    }
  }
  return 0;
}

// codeSHIFT function definition.
string codeSHIFT(string a, string b) {
  int n = strlen(a), i, k = atoi(b);
  char c[n];
  k = k % 26;

  for (i = 0; i < n; i++) {
    if (isupper(a[i]) != 0) {
      if ((a[i] + k) > 90) {
        c[i] = 65 + (k - (90 - a[i]) - 1);
      }
      else {
        c[i] = a[i] + k;
      }
    }
    else if (islower(a[i]) != 0) {
      if ((a[i] + k) > 122) {
        c[i] = 97 + (k - (122 - a[i]) - 1);
      }
      else {
        c[i] = a[i] + k;
      }
    }
    else if (ispunct(a[i]) != 0 || isspace(a[i]) != 0) {
      c[i] = a[i];
    }
  }
  printf("ciphertext: %s\n", c);
  return 0;
}
