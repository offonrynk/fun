/* Copyright (c) 2016, Nkrumah Offonry 
 * All rights reserved.
 *
 * This program calculates the balance after each month for a loan 
 * 1. Loan with an interest rate of 9% per anum
 * 2. Monthly payments of 162,25¤ per month for 48 months
 * 3. Program calculates and shows balance for the first 3 months 
 *
 * Author: Nkrumah Offonry
 */

#include <stdio.h>              //for printf function
#include <stdlib.h>
#include <iostream>             // for cout and cin functions amongst others
#include <cmath>		//for pow()and sqrt()
#include <iomanip>              // for std::setprecision()
            

using namespace std;

int main() {
	float balk;          // balance remaining after kth payment
	float PMT = 165.25;  // monthly amount paid
	int k;              //payment number
	int n=48;           // total no. of payments
	float i=0.0075;     // interest rate p/month
    
    printf ("Monthly Payment =%f\n",PMT);
    printf ("Interest Rate per Month =%f\n",i);
    printf("Total Number of Payments: %i\n",n);

    k =1;           // first monthly payment
    while ( k<4 ) {

        balk = PMT* ((1- (pow((1+i),(k-n)))) /i);
        cout << fixed << showpoint << setprecision (2);
        cout << "The Balance after the First monthly payment is:" <<balk<< endl;
        break;
   }

    k =2;           // second monthly payment
    while ( k<4 ) {

        balk = PMT* ((1- (pow((1+i),(k-n)))) /i);
        cout << fixed << showpoint << setprecision (2);
        cout << "The Balance after the Second monthly payment is:" <<balk<< endl;
        break;
    }

    k =3;           // third monthly payment
    while ( k<4 ) {

        balk = PMT* ((1- (pow((1+i),(k-n)))) /i);
        cout << fixed << showpoint << setprecision (2);
        cout << "The Balance after the Third monthly payment is:" <<balk<< endl;
        break;
    }

return 0;

}
