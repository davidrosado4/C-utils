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


#endif /* matrix_h */
