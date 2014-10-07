/*
 * Midterm 1 main prog. contains anwsers to all questions in one program 
 * line of ***'s marks different sections
 *
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include "pi_funs.h"

int main(void)
{
	// intillize begin and end times for 2 functions
	clock_t startLib, finishLib, startBBP, finishBBP;
	double time_elapsed_lib, time_elapsed_bbp;
	
	// n_l is the # of terms in the leibniz series
	int n_l = 100000;
	double Pi;
	
	// N_l is number of iterations so Leibniz error better than 10^-6 on last itteration [(N_l -1)*n]
	int N_l = 12;
	
	// M_l is # of iterations so t = 5 - 10 seconds
	int M_l = 50;
	
	for(int i = 0; i < N_l; i++, n_l += 100000)
	{
		// on last itteration
 		if (i == N_l - 1)
		{
			// begin time for Leibniz function
			startLib = clock();
			printf("Leibniz testing...\nN is: %d\n",M_l);
			
			for(int j = 0; j < M_l; j++)
			{
				Pi = pi_leibniz(n_l);
			}

			// end time of Leibniz
			finishLib = clock();
			time_elapsed_lib = (double)(finishLib - startLib) /CLOCKS_PER_SEC;
			printf("\nLeibniz took %f sec\n\n", time_elapsed_lib);			
		}
		
		// regular 1st for loop
		else
		{	
			Pi = pi_leibniz(n_l);
			printf("%8d   %20.15f   %20.15f\n", n_l, Pi, fabs(Pi - M_PI));
		}
	}
	
/*************************************************************************/
				// Bailey-Borwein-Plouffe section //

	double pi = 0.;

	// n_b is # of iterations so BBP error better than 10^-6 on last iteration
	int n_b = 5;
	
	// M_b is # of iterations so t = 5 - 10 seconds
	int M_b = 2000000;
	
	for(int i = 0; i < n_b; i++)
	{
		// on last itteration
 		if (i == n_b - 1)
		{
			// begin time for BBP function
			startBBP = clock();
			printf("BBP testing...\nN is: %d\n", M_b);
			
			for(int j = 0; j < M_b; j++)
			{
				pi = pi_bbp(i);
			}

			// end time of BBP
			finishBBP = clock();
			time_elapsed_bbp = (double)(finishBBP - startBBP) /CLOCKS_PER_SEC;
			printf("\nBBP took %f sec\n\n", time_elapsed_bbp);			
		}
		
		// regular 1st for loop
		else
		{			
			pi = pi_bbp(i);
			printf("%8d   %20.15f   %20.15f\n", i, pi, fabs(pi - M_PI));
		}
	}

/**************************************************************************/
					// comparison section //

	// ratio of time per itteration of Leibniz vs BBP
	double Tlb = (time_elapsed_lib /(double)M_l) /(time_elapsed_bbp /(double)M_b);
	printf("timeLeibniz / timeBBP: %20.15f\n\n", Tlb);

	return 0;
}
