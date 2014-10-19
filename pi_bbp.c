/*
 * calculates Bailey-Borwein-Plouffe series for pi
 * to the nth iteration
 *
 */
#include <stdio.h>

double pi_bbp (int n)
{
	// intitalize all denominators with n = 0
	double front = 1.;
	double firstTerm = 1.;
	double secondTerm = 4.;
	double thirdTerm = 5.;
	double fourthTerm = 6.;

	// start pi count at n = 0
	double Pi = 0.;
	Pi += 1. /front * ( 4. /firstTerm - 2. /secondTerm - 1. /thirdTerm - 1. /fourthTerm ); 

	// implement front = 16^n,  *Term = 8n + c.  from n=1 to n=n-1
	for (int i = 0; i < n; i++)
	{
		front *= 16.;
		firstTerm += 8.;
		secondTerm += 8.;
		thirdTerm += 8.;
		fourthTerm += 8.;

		// add each itteration to pi count
		Pi += 1. /front * ( 4. /firstTerm - 2. /secondTerm - 1. /thirdTerm - 1. /fourthTerm ); 
	}
 
	return Pi;
}
