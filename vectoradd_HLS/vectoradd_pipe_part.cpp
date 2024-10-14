//*****************************************************************************
//
//*****************************************************************************
//Design Name: vectoradd
//Purpose:
//    This is a Vitis HLS C++ version of the vector addition example. 
//    Adding vectors A & B
//Reference:
//Revision History: Oct. 1, 2024
//*****************************************************************************

#include <cmath>
#include "vectoradd.h"

void vectoradd(
      vec_a_t a[VEC_A_COLS],
      vec_b_t b[VEC_B_COLS],
      result_t res[VEC_B_COLS]
	  )


{
#pragma HLS array_partition variable=a 
#pragma HLS array_partition variable=b 
#pragma HLS array_partition variable=res

  // Add the elements of the vectors a and b into the result vector res
    Col: for(int j = 0; j < VEC_B_COLS; j++) {
	#pragma HLS PIPELINE
        res[j] = a[j] + b[j];
      }
  
}


