/*
 Author: David Rosado Rodríguez
 email: rosadodav4@gmail.com
 License: MIT 2023
 */
#include <stdio.h>
#include <math.h>


void matrix_mult(double** A, double** B, int n, int m, int p, int q, double** C){
    /*
     Function that given two matrix A and B, of dimensions nxm and pxq, perform the multiplication AxB to store it in C.
     Notice that the matrix C must have dimensions nxq.
     Arguments:
        A: Matrix of double stored with dynamic memory.
        B: Matrix of double stored with dynamic memory.
        n,m: Integers, dimension of A.
        p,q: Integers, dimension of B.
     */
    
    /* Check if dimensions fit*/
    if( m != p){
        printf("Wrong dimensions for matrix multiplication\n");
        exit(1);
    }else{
        /* Perform matrix multiplication */
        for (i = 0; i < n; i++) {
            for (j = 0; j < q; j++) {
                C[i][j] = 0;
                for (k = 0; k < m; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }
}
