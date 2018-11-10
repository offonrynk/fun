/*
 * Copyright (c) 2016, Nkrumah Offonry
 * All rights reserved.
 *
 * This program calculates the balance after each month for a loan
 *
 * 1. Loan with an interest rate of 9% per anum
 *
 * 2. Monthly payments of 162,25€ per month for 48 months
 *
 * 3. Program calculates and shows balance for the first 12 months
 *
 * Author: Nkrumah Offonry
 */

#include <cmath>   //for pow() and sqrt() fncs
#include <iomanip> //for std::setprecision() fnc
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  float balk;         // balance remaining after Kth payment
  float PMT = 165.25; // amount of monthly payment
  int n = 48;         // number of payments
  int k;              // payment number
  float i = 0.0075;   // interest rate p/mnth

  printf("The amount to be paid monthly is %f\n", PMT);
  printf("Interest Rate of %f\n", i);
  printf("And the total number of payments is %d\n", n);

  for (k = 1; k < 13; k++) {
    balk = PMT * ((1 - (pow((1 + i), (k - n)))) / i);
    cout << fixed << showpoint << setprecision(2);
    cout << "The balance remaining after month " << k << " is: " << balk
         << endl;
  }

  return 0;
}
