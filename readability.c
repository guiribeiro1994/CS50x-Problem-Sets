// Readability problem set cs50 wk2 2020.
// This program uses the Coleman-Liau index to output what (U.S.) grade level
// is needed to understand a text input by the user.
// Compile as: clang readability.c -o readability -lcs50

// Header files go here.
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Function prototypes go here.
int isWord(int a, int b);
int isSentence(string a, int b);
float cli(float a, float b, float c);



// Program start.
int main()
{
  // Gets user input.
  string text = get_string("Text: ");

  // Calculates size of string.
  int n = strlen(text), pchar = 0, cchar = 0, i;

  // Variables foe letters, words, and sentences.
  float l = 0, w = 0, s = 0, result;

  // Counts number of letters, words, and sentences in text.
  for (i = 0; i < (n + 1); i++) {
    if (isalpha(text[i]) != 0) {
      l++;
    }
    if (isspace(text[i]) != 0) {
      cchar = 1;
    }
    if (isWord(pchar, cchar) == 1) {
      w++;
    }
    pchar = cchar;
    cchar = 0;
    if (isSentence(text, i) == 1) {
      cchar = 1;
      s++;
    }
  }

  // Prints totals for user.
  printf("\nLetters:%0.0f  Words:%0.0f  Sentences:%0.0f\n", l, w, s);

  // Calculate Coleman-Liau index.
  result = cli(l, w, s);

  // Print results.
  if (result < 1) {
    printf("Before Grade 1\n");
  }
  else if (result >= 16) {
    printf("Grade 16+\n");
  }
  else {
    printf("Grade %0.0f\n", roundf(result));
  }

  return 0;
}
// Program end.



// isWord Function Definition.
int isWord(int a, int b) {
  if (a == 0 && b == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

// isSentence Function Definition.
int isSentence(string a, int b) {
  if ((a[b] == 33) || (a[b] == 46) || (a[b] == 63)) {
    return 1;
  }
  else {
    return 0;
  }
}

// Coleman-Liau index (cli) Function Definition.
float cli(float a, float b, float c) {
  float result, L, S;

  L = (a / b) * 100;
  S = (c / b) * 100;

  result = 0.0588 * L - 0.296 * S - 15.8;

  return result;
}
