// Mario pyramid blocks problem set cs50 wk1 2020.
// This program asks users for a positive integer 'n' between 1-8 (inclusive),
// and returns a printed block of pyramids of 'n' height.
// Compile as: clang mario.c -o mario -lcs50

// Header files go here.
#include <stdio.h>
#include <cs50.h>

// Function prototypes go here.
int getsHeight();
void pyramidStep(int a, int b);



// Program start.
int main()
{
  // Gets user input.
  int h = getsHeight(), space = h - 1, block = h - space;

  // Prints pyramid.
  for (size_t i = 0; i < h; i++) {
    pyramidStep(space, block);
    space--;
    block++;
  }

  return 0;
}
// Program end.



// getsHeight function definition.
int getsHeight()
{
  // Asks user for desired height.
  int n = get_int("Please input a height between 1-8, inclusively: ");

  // Error message if constraints not met.
  while (n < 1 || n > 8)
  {
      if (n < 1 || n > 8)
      {
          printf("Height must be a number between 1-8, inclusive. Please try again.\n");
          n = get_int("Height: ");
      }
  }
  return n;
}


// pyramidStep function definition
void pyramidStep(int a, int b)
{
  // Left spaces.
  for (size_t i = 0; i < a; i++) {
    printf("%c", 32);
  }

  // Left blocks.
  for (size_t i = 0; i < b; i++) {
    printf("%c", 35);
  }

  // Middle break.
  printf("%c%c", 32, 32);

  // Right blocks.
  for (size_t i = 0; i < b; i++) {
    printf("%c", 35);
  }

  // Right spaces.
  for (size_t i = 0; i < a; i++) {
    printf("%c", 32);
  }

  // Line break.
  printf("\n");
}
