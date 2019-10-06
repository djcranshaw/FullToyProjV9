open_project -reset processBDir
set_top processB
add_files processB.cc -cflags "-std=c++11"
add_files -tb processB_tb.cc -cflags "-std=c++11"
open_solution -reset "solution1"
set_part {xcvu7p-flvb2104-1-e} -tool vivado
create_clock -period 4 -name default
csim_design -compiler gcc
csynth_design
cosim_design
export_design -rtl verilog -format ip_catalog
