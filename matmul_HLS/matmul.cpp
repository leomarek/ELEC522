//*****************************************************************************
//
//*****************************************************************************
//Design Name: Matrix Multiplication using Systolic Array
//Purpose:
//   - This is the source file for the systolic array matrix multiplication
//
//Reference:
//Revision History: Oct. 14 2024
//*****************************************************************************

#include <hls_stream.h>
#include <ap_int.h>

#define N 4 // Matrix size (N x N)

// Function to multiply two matrices using systolic array architecture
void systolic_array(ap_int<16> A[N][N], ap_int<16> B[N][N], ap_int<16> C[N][N]) {

    #pragma HLS ARRAY_PARTITION variable=A complete dim=2
    #pragma HLS ARRAY_PARTITION variable=B complete dim=1
    #pragma HLS ARRAY_PARTITION variable=C complete dim=0

    ap_int<16> buffer_A[N][N];
    ap_int<16> buffer_B[N][N];
    ap_int<16> buffer_C[N][N] = {0};

    // Initialize buffers
    #pragma HLS PIPELINE II=1
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            #pragma HLS UNROLL
            buffer_A[i][j] = A[i][j];
            buffer_B[i][j] = B[i][j];
            buffer_C[i][j] = 0;
        }
    }

    // Perform systolic multiplication
    for (int t = 0; t < 2*N - 1; t++) {
        #pragma HLS PIPELINE II=1

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i + j == t) {
                    buffer_C[i][j] += buffer_A[i][t-i] * buffer_B[t-i][j];
                }
            }
        }
    }

    // Output result
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = buffer_C[i][j];
        }
    }
}
