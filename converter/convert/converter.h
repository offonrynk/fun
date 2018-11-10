/* Copyright (c) 2016, Nkrumah Offonry
 * All rights reserved.
 * Class header for Converter
 * Author: Nkrumah Offonry
 */

#ifndef _CONVERTER_H
#define _CONVERTER_H

class converter {
public:
  converter(); // Constructor

  // Member functions (Methods)
  float fahrenheit_to_celsius(float fahrenheit);
  float celsius_to_fahrenheit(float celsius);
  float miles_to_kilometers(float mile);
  float kilometers_to_miles(float km);

private:
  float celsius, fahrenheit;
  float kilometers, miles;
};

#endif
