/* Copyright (c) 2016, Nkrumah Offonry
 * All rights reserved.
 *
 * This program performs convertions from
 * 1. Fahrenheit to Celsius
 * 2. Celsius to Fahrenheit
 * 3. Miles to Kilometers
 * 4. Kilometers to Miles
 *
 * Takes in Letter as input, the the value to be converted, does the conversion
 * and outputs result(s)
 * Main file for the converter
 * Author: Nkrumah Offonry
 */

#include "converter.h"
#include <iostream>

using namespace std;

float celsius, fahrenheit, kilometers, miles;

int main() {
  char c;
  int flag = 1; // flag initialized to 1
  converter converterobj;

  while (flag) {
    cout << "'F' for Fahrenheit to Celsius Conversion\n";
    cout << "'C' for Celsius to Fahrenheit Conversion\n";
    cout << "'M' for Miles to Kilometers Conversion\n";
    cout << "'K' for Kilometers to Miles Conversion\n";
    cout << "Enter the letter corresponding to the type of conversion:-\n";

    cin >> c;

    switch (c) {
    case 'C':
    case 'c':
      cout << "Please enter temperature in celsius:-\n";
      cin >> fahrenheit;
      converterobj.celsius_to_fahrenheit(celsius);
      break;

    case 'F':
    case 'f':
      cout << "Please enter temperature in fahrenheit:-\n";
      cin >> fahrenheit;
      converterobj.fahrenheit_to_celsius(fahrenheit);
      break;

    case 'M':
    case 'm':
      cout << "Please enter distance in miles:-\n";
      cin >> miles;
      converterobj.miles_to_kilometers(miles);
      break;

    case 'K':
    case 'k':
      cout << "Please enter distance in kilometers:-\n";
      cin >> kilometers;
      converterobj.kilometers_to_miles(kilometers);
      break;

    default:
      cout << "Error!!!\n"; // Outputs Error if wrong value or letter is given
                            // as input
    }

    cout << "To end program press 0\n";
    cout << "To continue program press 1\n";

    cin >> flag;
  }

  return 0;
}
