/* Copyright (c) 2016, Nkrumah Offonry 
 * All rights reserved.
 *
 * This program performs convertions from
 * 1. Fahrenheit to Celsius
 * 2. Celsius to Fahrenheit
 * 3. Miles to Kilometers
 * 4. Kilometers to Miles
 *
 * Author: Nkrumah Offonry
 */

#include <iostream>

using namespace std;

float celsius, fahrenheit, mile, km;

float celcius_to_fahrenheit(float celsius);
float fahrenheit_to_celcius(float fahrenheit);
float mile_to_kilometer(float mile);
float kilometer_to_mile(float km);

int main()
{
    char f;
    int flag = 1;
    while(flag)
    {
    	cout<<"Please choose a value to be converted :";
    	cout<<"'C' for Celcius to Fahrenheit Conversion\n";
    	cout<<"'F' for Fahrenheit to Celcius Conversion\n";
    	cout<<"'M' for Miles to Kilometers Conversion\n";
    	cout<<"'K' for Kilometers to Miles Conversion\n";
    	cout<<" enter the letter corresponding to the type of conversion\n";
    	cin>>f;
    	switch(f)

		{
       		  case  'C':
       		  case  'c':
         		cout << "Enter Celsius temperature: ";
           		cin >> celsius;
            		cout << "Fahrenheit = " << celcius_to_fahrenheit(celsius)<<"\n" ;
           	 break;

       		 case'F':
        	 case'f':
           		cout << "Enter Fahrenheit temperature: ";
           		cin >> fahrenheit;
           		cout << " Celcius= " << fahrenheit_to_celcius(fahrenheit)<<"\n" ;
           	 break;

       		 case 'M':
       		 case 'm':
            		cout << "Enter mile : ";
            		cin >> mile;
            		cout << "km = " << mile_to_kilometer(mile)<<"\n" ;
            	break;

	        case 'K':
        	case 'k':
            	       cout << "Enter km : ";
           	       cin >> km;
            	       cout << "Mile = " << kilometer_to_mile(km)<<"\n" ;
	       break ;

        default:
         cout << "Input invalid\n";
        }

                cout<< "\nEnd Program press 0, Program restart press 1 : ";
		cin>>flag;
	}
	return 0;
	cout<< "Bye.\n";
    }



float celcius_to_fahrenheit(float celsius)
{
    fahrenheit = (5.0/9.0) * (celsius + 32.0);
    return fahrenheit;

}
float fahrenheit_to_celcius(float fahrenheit)
{
    celsius = (fahrenheit-32)/(9.0/5.0);
    return celsius;

}
float mile_to_kilometer(float mile)
{
     float  constant = 1.6093;
     km=mile*constant;
     return km;

}
float kilometer_to_mile(float km)
{
    float constant = 1.6093;
    mile=km/constant;
    return mile;

}
