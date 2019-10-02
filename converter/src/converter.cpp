/* Copyright (c) 2016, Nkrumah Offonry
 * All rights reserved.
 * Cpp file for program header
 * Author: Nkrumah Offonry
 */

#include "converter.h"
#include <iostream>

converter::converter()
{
}

converter::~converter()
{
}


float converter::fahrenheit_to_celsius(float fahrenheit)
{
  celsius = ((fahrenheit - 32) * 5) / 9;
  std::cout << "The temperature in Fahrenheit is: " << celsius << std::endl;
}

float converter::celsius_to_fahrenheit(float celsius)
{
  fahrenheit = ((celsius * 9) / 5) + 32;
  std::cout << "The temperature in Celsius is: " << fahrenheit << std::endl;
}

float converter::miles_to_kilometers(float miles)
{
  kilometers = (0.6214 * miles);
  std::cout << "The distance in kilometers is: " << kilometers << std::endl;
}

float converter::kilometers_to_miles(float kilometers)
{
  miles = (1.609 * kilometers);
  std::cout << "The distance in kilometers is: " << miles << std::endl;
}
