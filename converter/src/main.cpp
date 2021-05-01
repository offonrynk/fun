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

int main()
{
  char c;
  int flag = 1;
  float celsius{0.0f}, fahrenheit{0.0f}, kilometers{0.0f}, miles{0.0f};

  Converter converter;

  while (flag) {
    std::cout << "'F' for Fahrenheit to Celsius Conversion\n";
    std::cout << "'C' for Celsius to Fahrenheit Conversion\n";
    std::cout << "'M' for Miles to Kilometers Conversion\n";
    std::cout << "'K' for Kilometers to Miles Conversion\n";
    std::cout << "Enter the letter corresponding to the type of conversion: \n";

    std::cin >> c;

    switch (c) {
      case 'C':
      case 'c':
        std::cout << "Please enter temperature in celsius: \n";
        std::cin >> celsius;
        std::cout << "The temperature in Fahrenheit is: "
                  << converter.celsius_to_fahrenheit(celsius) << std::endl;
        break;

      case 'F':
      case 'f':
        std::cout << "Please enter temperature in fahrenheit: \n";
        std::cin >> fahrenheit;
        std::cout << "The temperature in Celsius is: "
                  << converter.fahrenheit_to_celsius(fahrenheit) << std::endl;
        break;

      case 'M':
      case 'm':
        std::cout << "Please enter distance in miles: \n";
        std::cin >> miles;
        std::cout << "The distance in kilometers is: "
                  << converter.miles_to_kilometers(miles) << std::endl;
        break;

      case 'K':
      case 'k':
        std::cout << "Please enter distance in kilometers: \n";
        std::cin >> kilometers;
        std::cout << "The distance in kilometers is: "
                  << converter.kilometers_to_miles(kilometers) << std::endl;
        break;

      default:
        std::cout << "Error!!! \n";
    }

    std::cout << "To end program press 0 \n";
    std::cout << "To continue program press 1 \n";

    std::cin >> flag;
  }

  return 0;
}
