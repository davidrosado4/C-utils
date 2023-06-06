/*
 Author: David Rosado Rodríguez
 email: rosadodav4@gmail.com
 License: MIT 2023
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void matrix_mult(double** A, double** B, int n, int m, int p, int q, double** C){
    /*
     Function that given two matrix A and B, of dimensions nxm and pxq, perform the multiplication AxB to store it in C.
     Notice that the matrix C must have dimensions nxq.
     Arguments:
        A: Matrix of doubles stored with dynamic memory.
        B: Matrix of doubles stored with dynamic memory.
        n,m: Integers, dimension of A.
        p,q: Integers, dimension of B.
     */
    
    /* Check if dimensions fit*/
    if( m != p){
        printf("Wrong dimensions for matrix multiplication\n");
        exit(1);
    }else{
        int i,j,k;
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
void power_mat(double** A, int dim, int times){
    /*
     Function that given a square matrix A, of dimensions dimxdim, computes A^{times}.
     The function store the result in the matrix A.
     Arguments:
        A: Matrix of doubles stored with dynamic memory.
        dim: Integer, dimension of A.
        times: Integer, times we want to power the matrix.
     */
    
    /* Check if times is a correct number */
    if (times < 1){
        printf("We can not compute a matrix power a negative or zero number");
        exit(1);
    }else{
        /* Perform the power of the matrix operation */
        int i,j,k;
        double** result,**aux;
        
        /* Allocate memory for matrices to use the previous function */
        /* aux will be used for store A and result to keep storing the matrix multiplication*/
        result = (double **)calloc(dim,sizeof(double *));
        aux = (double **)calloc(dim,sizeof(double *));
        for(i=0 ;i<dim;i++){
            result[i] = (double *)calloc(dim,sizeof(double));
            aux[i] = (double *)calloc(dim,sizeof(double));
        }
        
        /* Store the matrix A in aux*/
        for(i = 0; i<dim;i++){
            for(j=0;j<dim;j++){
                aux[i][j] = A[i][j];
            }
        }
        /* Perform the matrix multiplication*/
        for(k = 1; k<times;k++){
            matrix_mult(A,aux,dim,dim,dim,dim,result);
            for(i = 0; i<dim;i++){
                for(j=0;j<dim;j++){
                    A[i][j] = result[i][j];
                }
            }
        }
        /* Free up memory */
        for(i = 0; i<dim; i++){
            free(result[i]);
            free(aux[i]);
        }
        free(result); free(aux);
    }
}
