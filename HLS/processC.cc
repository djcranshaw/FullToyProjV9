#include "processC.hh"
void processC(ap_uint<2> bx, ap_uint<2>& bx_o,
              int inmem1[2][16], int inmem2[4][16],
              int outmem[2][16])
{
#pragma HLS inline off
#pragma HLS interface register port=bx_o
#pragma HLS resource variable=inmem1 latency=2
#pragma HLS resource variable=inmem2 latency=2

  for (int i = 0; i < 16; ++i) {
#pragma HLS pipeline II=1 rewind
    // read input memories
    int indata1 = inmem1[bx(0,0)][i];
    int indata2 = inmem2[bx][i];

    // compare data and store the larger one
    bool islarger = indata1 > indata2;
    int outdata = islarger ? indata1 : indata2;

    // write to output memory
    outmem[bx(0,0)][i] = outdata;

    if (i==15) bx_o = bx;
  }
}
