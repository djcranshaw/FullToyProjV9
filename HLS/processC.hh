#pragma once
#include "ap_int.h"
void processC(ap_uint<2> bx, ap_uint<2>& bx_o,
              int inmem1[2][16], int inmem2[4][16],
              int outmem[2][16]);
