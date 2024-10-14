//*****************************************************************************
//*****************************************************************************
//Device: All
//Design Name: vectoradd
//Purpose:
//    This is the Vitis HLS C++ test bench for the vectoradd example.
//Reference:
//Revision History: Oct. 1, 2024
//*****************************************************************************
#include <cmath>
#include <iostream>
#include "vectoradd.h"

using namespace std;

int main(int argc, char **argv)
{
   vec_a_t in_vec_a[8] = {1, 2, 3, 4, 5, 6, 7, 8};

   vec_b_t in_vec_b[8] = {9, 10, 11, 12, 13, 14, 15, 16};

   result_t hw_result[8], sw_result[8];


    int err_cnt = 0;

	// Generate the expected result
	// Add the elements into the result r_sw
    // Add the elements of the vectors a and b into the result vector res
    Col: for(int j = 0; j < VEC_B_COLS; j++) {
        sw_result[j] = in_vec_a[j] + in_vec_b[j];
      }


#ifdef HW_COSIM
   // Run the Vitis HLS block
   vectoradd (in_vec_a, in_vec_b, hw_result);
#endif

   // Print result sw_result and hw_result

#ifdef HW_COSIM
         cout << "software = " << sw_result[0] << "," << sw_result[1] << "," << sw_result[2] << "," << sw_result[3] << "," << sw_result[4] << "," << sw_result[5] << "," << sw_result[6] << "," << sw_result[7] << endl;
		 cout << "hardware = " << hw_result[0] << "," << hw_result[1] << "," << hw_result[2] << "," << hw_result[3] << "," << hw_result[4] << "," << hw_result[5] << "," << hw_result[6] << "," << hw_result[7] << endl;
         // Check HW result against SW
         if ((hw_result[0] != sw_result[0]) || (hw_result[1] != sw_result[1]) || (hw_result[2] != sw_result[2]) || (hw_result[3] != sw_result[3]))
		 {
            err_cnt++;
            cout << "*" << endl;
         }
#else
         cout << "software = " << sw_result[0] << "," << sw_result[1] << "," << sw_result[2] << "," << sw_result[3] << "," << sw_result[4] << "," << sw_result[5] << "," << sw_result[6] << "," << sw_result[7] << "," << sw_result[8] << endl;
#endif


#ifdef HW_COSIM
   if (err_cnt)
      cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
   else
      cout << "Test passed." << endl;
#endif
   return err_cnt;
}
