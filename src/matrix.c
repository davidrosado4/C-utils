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
void mat_times_vect(double** A, double *vect, int row, int col, double *sol){
    /*
     Function that perform the multiplication of a  matrix times a vector and store the results in sol.
     Arguments:
        A: The matrix to perform operations.
        vect: The vector to perform operations.
        row: Integer, the number of rows of the matrix.
        col: Integer, the number of columns of the matrix.
        sol: A pointer to which we assign the solution of the operation.
     */
    if(row <= 0 || col<=0 ){
        printf("Wrong dimension. The dimension of the matrix introduced is negative or zero. Take a look\n");
        exit(1);
    }else{
        int i,j;
        
        /* The solution is a vector of dimensions row */
        for(i = 0; i<row; i++){
            sol[i] = 0;
            for(j=0 ; j<col; j++){
                /* vect must be a vector of dimensions col */
                sol[i] += A[i][j]*vect[j];
            }
        }
    }
}
double Euclidian_norm(double* vector, int n){
    /*
     Function that computes the Euclidan norm of a vector.
     Arguments:
        vector: Pointer to the vector for which we want to calculate the norm.
        n: length of the vector.
     Returns:
        The Euclidian norm of the vector.
     */
    int i;
    double square_sum = 0;
    
    for(i = 0; i < n; i++){
        square_sum += vector[i] * vector[i];
    }
    return sqrt(square_sum);
}
void gaussEliminationLS(int m, int n, double **A, double *b, double *x) {
    /*
     Function that solves a linear system Ax=b using Gauss Elimination with partial pivoting.
     The result is stored in x.
     The function recieves a matrix of dimensions m x (n-1) and add the vector b to the last
     column of the matrix, to start the Guassian Elimination process.
     Arguments:
         m: Rows dimensions of the matrix
         n: Columns + 1 dimensions of the matrix.
         A: The matrix of the linear system.
         b: The vector b to solve Ax=b.
         x: A pointer to which we assign the result.
    */
    int i,j,k;
    /* Append the vector to the matrix */
    for(i=0; i<m;i++){
        A[i][n-1] = b[i];
    }
    /* Start Gauss */
    for(i=0; i<m-1; i++) {
        /* Partial Pivoting */
        int max_row = i;
        for(k=i+1; k<m; k++) {
            /*If diagonal element(absolute value) is smaller than any of the terms below it */
            if(fabs(A[i][i]) < fabs(A[k][i])) {
                /*Track the row interchanges */
                max_row = k;
            }
        }
        if(max_row != i) {
            /* Swap the rows */
            for(j=0; j<n; j++) {
                double temp = A[i][j];
                A[i][j] = A[max_row][j];
                A[max_row][j] = temp;
            }
        }
        /* Begin Gauss Elimination */
        for(k=i+1; k<m; k++) {
            double term = A[k][i] / A[i][i];
            for(j=0; j<n; j++) {
                A[k][j] = A[k][j] - term*A[i][j];
            }
        }
    }
    /* Begin Back-substitution */
    for(i=m-1; i>=0; i--) {
        x[i] = A[i][n-1];
        for(j=i+1; j<n-1; j++) {
            x[i] = x[i] - A[i][j]*x[j];
        }
        x[i] = x[i] / A[i][i];
    }
}

