//Lab 3, Setion 1
//Jeremy Love
//10/7/2022

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

const int N = 1024 ;
static float A[N][N] = {0} ;
static float B[N][N] = {0} ;
static float C[N][N] = {0} ;

int main(int argc, char **argv)
{
	std::cout << "N = " << N << "\n" ;
	
	clock_t beginTime = clock() ;
		
	srand((unsigned)time(NULL)) ;
	
	for(int i = 0 ; i < N ; i++)
	 	for(int k = 0 ; k < N ; k++)
			A[i][k] = rand() / (float)RAND_MAX ;
	
	for(int i = 0 ; i < N ; i++)
		for(int k = 0 ; k < N ; k++)
			B[i][k] = rand() / (float)RAND_MAX ;
	
	for(int i = 0 ; i < N ; i++)
		for(int k = 0 ; k < N ; k++)
			for(int m = 0 ; m < N ; m++)
				C[k][m] = A[k][m] * B[i][m] ;

	clock_t endTime = clock() ;
 
	std::cout << "Runtime: " << (float)(endTime - beginTime) / CLOCKS_PER_SEC << " seconds" ;
	
	return 0 ;
}

