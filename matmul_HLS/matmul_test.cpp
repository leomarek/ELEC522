//*****************************************************************************
//*****************************************************************************
//Device: All
//Design Name: systolic_mult
//Purpose:
//    This is the Vitis HLS C++ test bench for a systolic matrix multiplier.
//Reference:
//Revision History: Oct. 14, 2024
//*****************************************************************************
#include <iostream>
#include "matmul.h"

using namespace std;

int main(int argc, char **argv) {

    matrix_t A[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    matrix_t B[MATRIX_SIZE][MATRIX_SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    matrix_t hw_result[MATRIX_SIZE][MATRIX_SIZE];
    matrix_t sw_result[MATRIX_SIZE][MATRIX_SIZE];

    int err_cnt = 0;

    // Generate the expected result (software)
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            sw_result[i][j] = 0;
            for (int k = 0; k < MATRIX_SIZE; k++) {
                sw_result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

#ifdef HW_COSIM
    // Run the Vitis HLS block
    systolic_array(A, B, hw_result);
#endif

    // Print software result (sw_result) and hardware result (hw_result)
    cout << "Software Result (Expected):" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << sw_result[i][j] << " ";
        }
        cout << endl;
    }

#ifdef HW_COSIM
    cout << "Hardware Result:" << endl;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            cout << hw_result[i][j] << " ";
        }
        cout << endl;
    }

    // Check HW result against SW result
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            if (hw_result[i][j] != sw_result[i][j]) {
                err_cnt++;
                cout << "Mismatch at (" << i << "," << j << "): "
                     << "HW=" << hw_result[i][j] << " SW=" << sw_result[i][j] << endl;
            }
        }
    }

    if (err_cnt)
        cout << "ERROR: " << err_cnt << " mismatches detected!" << endl;
    else
        cout << "Test passed." << endl;
#endif

    return err_cnt;
}
