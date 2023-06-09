/*
 Author: David Rosado Rodríguez
 email: rosadodav4@gmail.com
 License: MIT 2023
 */
#ifndef matrix_h
#define matrix_h

#ifdef __cplusplus
extern "C" {
#endif

/* Matrix multiplication function */
void matrix_mult(double** A, double** B, int n, int m, int p, int q, double** C);

/* Matrix power function */
void power_mat(double** A, int dim, int times);

/* Matrix times a vector */
void mat_times_vect(double** A, double *vect, int row, int col, double *sol);

/* Euclidian norm of a vector*/
double Euclidian_norm(double* vector, int n);

/* Gaussian Elimination */
void gaussEliminationLS(int m, int n, double **A, double *b, double *x);


#endif /* matrix_h */
