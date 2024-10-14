//*****************************************************************************
//
//*****************************************************************************
//Design Name: matrixmult
//Purpose:
//    This is a Vitis HLS C++ version of the systolic matrix multiplication example.
//    Multiplying matrices A & B
//Reference:
//Revision History: Oct. 1, 2024
//*************************************
****************************************

#include <cmath>
#include "matmul.h"

void matrixmult(
						mat_a_t a[MAT_A_ROWS][MAT_A_COLS],
						mat_b_t b[MAT_B_ROWS][MAT_B_COLS],
						result_t res[MAT_A_ROWS][MAT_B_COLS]
			)


{

		// Multiply the elements of the matrices a and b into the result matrix res
				Row: for(int i = 0; i < MAT_A_ROWS; i++) {
								Col: for(int j = 0; j < MAT_B_COLS; j++) {
												#pragma HLS PIPELINE
												res[i][j] = 0;
												Product: for(int k = 0; k < MAT_A_COLS; k++) {
																res[i][j] += a[i][k] * b[k][j];
												}
								}
				}

}
```
