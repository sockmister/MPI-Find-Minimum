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

	//randomly generate 3 int.
	//find min sequentially

	//use reduce, mpi_minloc operation

	//print out from root.

	/* shut down MPI */
	MPI_Finalize(); 
	
	
	return 0;
}
