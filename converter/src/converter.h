/* Copyright (c) 2016, Nkrumah Offonry
 * All rights reserved.
 * Class header for Converter
 * Author: Nkrumah Offonry
 */
#ifndef _CONVERTER_H
#define _CONVERTER_H

class Converter {
public:
  Converter() = default;
  ~Converter() = default;

  float fahrenheit_to_celsius(float const fahrenheit);
  float celsius_to_fahrenheit(float const celsius);
  float miles_to_kilometers(float const mile);
  float kilometers_to_miles(float const km);
};

#endif
