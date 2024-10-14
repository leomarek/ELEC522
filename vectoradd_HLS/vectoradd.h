//*****************************************************************************
//
//*****************************************************************************
//Device: All
//Design Name: vectoradd
//Purpose:
//    This is the Vitis HLS header for the vectoradd.cpp design.
//Reference:
//Revision History: Oct. 1, 2024
//*****************************************************************************

#ifndef __VECTORADD_H__
#define __VECTORADD_H__

#include <cmath>
using namespace std;


// Prototype of top level function for Vitis HLS C-synthesis
// Variable a through h are inputs. In C language format, a pointer to 
// variable r is passed in so that r can be written in this function.

#define VEC_A_COLS 8
#define VEC_B_COLS 8

typedef short vec_a_t;
typedef short vec_b_t;
typedef short result_t;

// Prototype of top level function for C-synthesis
void vectoradd(
      vec_a_t a[VEC_A_COLS],
      vec_b_t b[VEC_B_COLS],
      result_t res[VEC_B_COLS]
	  );



#endif // __VECTORADD_H__ not defined