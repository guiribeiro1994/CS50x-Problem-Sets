// Card problem set cs50 wk1 2020.
// This program uses Luhn’s Algorithm and other tests to determine if a credit
// card number is valid and who issued it.
// Compile as: clang cash.c -o cash -lcs50

// Header files go here.
#include <cs50.h>
#include <stdio.h>
#include <math.h>

// Function prototypes go here.
int countLength(long a);
int luhnCheck(long a);
void cardComp(int a, int b);



// Program start.
int main()
{
  // Asks user for credit card number.
  long cardnumber = get_long("Please enter credit card number: ");
  int n = countLength(cardnumber), i;

  // Luhn's Algorithm to determine is number is valid.
  if (luhnCheck(cardnumber) % 10 != 0) {
    printf("INVALID CARD NUMBER\n");
  }
  else {
    // Determines the first 2 digits of the card number.
    i = cardnumber / (pow (10, (n - 2)));

    printf("Card number valid. Issuer: ");
    // Checks card issuer.
    cardComp(n, i);
  }

  return 0;
}
// Program end.



// countLength function definition.
int countLength(long a)
{
  int i;
  for (i = 0; a > 0; i++) {
    a /= 10;
  }
  return i;
}

// luhnCheck function definition.
int luhnCheck(long a)
{
  int i, x = 0, y = 0, sum;
  long n;

  n = 10;
  while (n < a) {
    // Finds the second to last digit of the card number.
    i = (a / n) % 10;
    // Multiplies this digit by 2.
    i *= 2;
    // If the resulting multiplication has 2 places, adds those digits together.
    // Example: if i=7, 7*2=14, i=1+4, i=5.
    i = (i / 10) % 10 + (i % 10);
    // Skips every other digit of the card number.
    n *= 100;
    // Transfers, stores and adds each value of i together.
    x += i;
  }

  n = 1;
  while (n < a) {
    // Finds last digit of the card number.
    i = (a / n) % 10;
    // Skips every other digit of the card number.
    n *= 100;
    // Transfers, stores and adds each value of i together.
    y += i;
  }

  sum = x + y;
  return sum;
}

// cardComp function definition.
void cardComp(int a, int b)
{
  // AMEX check.
  if ((a == 15) && (b == 34 || b == 37))
  {
    printf("AMEX\n");
  }
  // MASTERCARD check.
  else if ((a == 16) && (b > 50 && b < 56))
  {
    printf("MASTERCARD\n");
  }
  // VISA check.
  else if ((a == 13 || a == 16) && (b > 39 && b < 50))
  {
    printf("VISA\n");
  }
  // Final check.
  else
  {
    printf("Sorry, card issuer not recognized.\n");
  }
}
