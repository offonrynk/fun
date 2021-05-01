#include "converter.h"

float Converter::fahrenheit_to_celsius(float const fahrenheit)
{
  return ((fahrenheit - 32) * 5) / 9;
}

float Converter::celsius_to_fahrenheit(float const celsius)
{
  return ((celsius * 9) / 5) + 32;
}

float Converter::miles_to_kilometers(float const miles)
{
  return (0.6214 * miles);
}

float Converter::kilometers_to_miles(float const kilometers)
{
  return (1.609 * kilometers);
}
