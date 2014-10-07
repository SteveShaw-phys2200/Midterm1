/*
 * calculates Bailey-Borwein-Plouffe series for pi
 * to the nth iteration
 *
 */
#include <stdio.h>
#include <math.h>

double pi_bbp (int n)
{
	// initialize Pi count, BBP(0)
	// pow doesnt handle 0 well
	double Pi = 4 - .5 - .2 - .16666666666666666;
	
	if (n == 0)
	{
		return Pi;
	}
	
	// BBP(1)
	Pi += 1. / 16. * ( 4. /(8.+1.) - 2. /(8.+4.) - 1./(8.+5) - 1./(8.+6.));
	
	if (n == 1)
	{
		return Pi;
	}
	
	// adding each term in the series to the sum Pi from 1 to nth iteration
	// im actually doing n+1 itterations for n > 1 ...oops ill fix later
	for (int i = 2; i <= n; i++)
	{	
		// BBP series implimentation 
		Pi += 1. / pow(16.,(double)i) * ( 4. /(8.*(double)i+1.) - 2. /(8.*(double)i+4.) - 1./(8.*(double)i+5) - 1./(8.*(double)i+6.));
	}
	
	return Pi;
}
