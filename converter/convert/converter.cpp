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
 * Cpp file for program header
 * Author: Nkrumah Offonry
 */

#include "converter.h"
#include <iostream>

using namespace std;

converter::converter() {} /* calling constructor */

float converter::fahrenheit_to_celsius(
    float fahrenheit) { /* fahrenheit to celsius*/
  celsius = ((fahrenheit - 32) * 5) / 9;
  cout << "The temperature in Fahrenheit is:" << celsius << endl;
}

float converter::celsius_to_fahrenheit(
    float celsius) { /* celcius to fahrenheit */
  fahrenheit = ((celsius * 9) / 5) + 32;
  cout << "The temperature in Celsius is:" << fahrenheit << endl;
}

float converter::miles_to_kilometers(float miles) { /* miles to kilometers */
  kilometers = (0.6214 * miles);
  cout << "The distance in kilometers is:" << kilometers << endl;
}

float converter::kilometers_to_miles(
    float kilometers) { /* kilometers to miles*/
  miles = (1.609 * kilometers);
  cout << "The distance in kilometers is:" << miles << endl;
}
