#include "processB.hh"
void processB(ap_uint<2> bx, ap_uint<2>& bx_o,
              int inmem[2][16], int outmem[2][16])
{
#pragma HLS inline off
#pragma HLS interface register port=bx_o
//#pragma HLS resource variable=inmem latency=2

  for (int i = 0; i < 16; ++i) {
#pragma HLS pipeline II=1 rewind
    // read input memories
    int indata = inmem[bx(0,0)][i];

    // multiple by 2
    int outdata = indata * 2;

    // write to output
    outmem[bx(0,0)][i] = outdata;

    if (i==15) bx_o = bx;
  }
}
