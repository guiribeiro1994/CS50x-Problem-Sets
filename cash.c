// Cash problem set cs50 wk1 2020.
// This program is a greedy algorithm that asks users for an amount of change
// as a positive float, and returns the minimmal number of coins required to
// make that change. I have modified the original problem set parameters so that
// the program also states how many of each coin is required.
// Compile as: clang cash.c -o cash -lcs50

// Header files go here.
#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function prototypes go here.
int getsChange();
int countCoins(int a);



// Program start.
int main()
{
  // Gets user input.
  float change = getsChange();

  // Counts out coins.
  int q = 0, d = 0, n = 0, p = 0;
  while (change != 0) {
    if (countCoins(change) / 25 == 1) {
      q++;
      change -= 25;
    } else if (countCoins(change) / 10 == 1) {
      d++;
      change -= 10;
    } else if (countCoins(change) / 5 == 1) {
      n++;
      change -= 5;
    } else if (countCoins(change) / 1 == 1) {
      p++;
      change -= 1;
    }
  }
  printf("\nQuarters:%d  Dimes:%d  Nickesl:%d  Pennies:%d\n", q, d, n, p);
  printf("Total number of coins needed: %d\n\n", q + d + n + p);
  return 0;
}
// Program end.



// getsChange function definition.
int getsChange ()
{
  // Asks user for change amount.
  float amount = get_float("Change owed: $");

  // Checks change is a positive amount.
  if (amount <= 0) {
    do {
      printf("Change must be positive and greater than 0.\n");
      amount = get_float("Change owed: $");
    } while(amount <= 0);
  }

  // Converts amount into cents.
  int change = round(amount * 100);

  // Returns the amount.
  return change;
}


// countCoins function definition.
int countCoins (int a)
{
  int i;
  // Checks quarters.
  if (a % 25 == 0) {
    i = 25;
    return i;
  }

  // Checks dimes.
  else if (a % 10 == 0) {
    i = 10;
    return i;
  }

  //Checks nickels.
  else if (a % 5 == 0) {
    i = 5;
    return i;
  }

  // Checks pennies.
  else if (a % 1 == 0) {
    i = 1;
    return i;
  }

  return 0;
}
