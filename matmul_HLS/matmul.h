//*****************************************************************************
//
//*****************************************************************************
//Device: All
//Design Name: systolic_mult
//Purpose:
//    This is the Vitis HLS header for the systolic_mult.cpp design.
//Reference:
//Revision History: Oct. 14, 2024
//*****************************************************************************

#ifndef __SYSTOLIC_MULT_H__
#define __SYSTOLIC_MULT_H__

#include <ap_int.h>

// Define matrix dimensions (NxN)
#define MATRIX_SIZE 4

typedef ap_int<16> matrix_t;

// Prototype of the top-level function for C-synthesis
// Matrix A and Matrix B are inputs, Matrix C is the result.
void systolic_array(
    matrix_t A[MATRIX_SIZE][MATRIX_SIZE],
    matrix_t B[MATRIX_SIZE][MATRIX_SIZE],
    matrix_t C[MATRIX_SIZE][MATRIX_SIZE]
);

#endif // __SYSTOLIC_MULT_H__ not defined
