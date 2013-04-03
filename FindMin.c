/*
 ============================================================================
 Name        : FindMin.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Find minimum of all prcesses, where each process contains 10 int.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mpi.h"

int main(int argc, char* argv[]){
	int  my_rank; /* rank of process */
	int  p;       /* number of processes */
	MPI_Status status ;   /* return status for receive */

	/* start up MPI */
	MPI_Init(&argc, &argv);
	
	/* find out process rank */
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); 
	
	/* find out number of processes */
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	//randomly generate 10 int.
    int arr[10];
    srand(time(NULL) + my_rank);
    int i;
    for(i = 0; i < 10; ++i){
    	arr[i] = rand() % 1000;
    }

 	//find min sequentially
 	int min = arr[0];
 	for(i = 0; i < 10; ++i){
 		if(arr[i] < min){
 			min = arr[i];
 		}
 	}
 	printf("I am rank %d and found %d to be my minimum value.\n", my_rank, min);

	//use reduce, mpi_minloc operation
	struct{
		int val;
		int rank;
	} in, out;
	in.val = min;
	in.rank = my_rank;
	MPI_Reduce(&in, &out, 1, MPI_2INT, MPI_MINLOC, 0, MPI_COMM_WORLD ); 

	//print out from root.
	if(my_rank == 0){
		printf("min value: %d from rank: %d\n", out.val, out.rank);
	}

	/* shut down MPI */
	MPI_Finalize(); 
	
	
	return 0;
}
