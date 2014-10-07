/*
 * Function to calculate Pi using leibniz series
 *
 */

#include <stdio.h>

double pi_leibniz (int n)
{
	// initialize Pi count and Denominator in series
	double Pi = 0.;
	double Den = 1.;

	// increasing Denominator by 2 each iteration
	for (int i = 0; i < n; i++, Den += 2.)
	{	
		// Numerator has limited scope so it resets to 1
		// unless the iteration is odd		
		double Num = 1.;
		if (i % 2)
		{
			Num = -1.;
		}

		// add this iteration to Pi count		
		Pi += Num / Den;
	}
	
	// Pi count actually represents pi / 4
	return Pi * 4;
}
		
