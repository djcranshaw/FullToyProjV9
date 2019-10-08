# FullToyProjV9

Toy hls/vivado project with similar structure to real hybrid

### To checkout and build the project, and open it for the first time

Do the following (this could be automated someday, or at least put into a bash script)
N.B. This will open the vivado GUI

* git clone https://github.com/djcranshaw/FullToyProjV9
* cd FullToyProjV9/sourceFiles/processA
* unzip xilinx_com_hls_processA_1_0.zip
* cd ../processB
* unzip xilinx_com_hls_processB_1_0.zip
* cd ../processC
* unzip xilinx_com_hls_processC_1_0.zip
* cd ../../
* vivado -source generate_project.tcl

### To open the project after it has been built once

N.B. This will open the vivado GUI

* cd FullToyProjV9
* vivado FullToyProjV9/FullToyProjV9.xpr

### To run the behavioral simulation once it's open

Flow -> Run Simulation -> Run Behavioral Simulation

The first time you do this, it takes many minutes, and it may seem that vivado has hanged. Check the tcl console to make sure that a new line is printed every minute or so to make sure that it's still running.

When the waveform prints, everything has been set up correctly if, around 350 ns, the numbers 14,20,34,40,... are found for the first time on the memout_din port.

### To make changes to individual HLS blocks

The HLS blocks that make up the toy project live in the HLS directory. To change them, and have the changes be incorporated into the overall project, the following is needed. For example, lets say you wanted to change something in processA...

* <Change whatever you need to change in processA.cc, processA.hh, processA_tb.cc>
* cd FullToyProjV9/HLS
* vivado_hls -f script_A.tcl

You may want to check the synthesis report at this point, at FullToyProjV9/HLS/processADir/solution1/syn/report/processA_csynth.rpt to make sure your changes didn't break timing, pipelining, or dramatically change resources usage, unless you anticipate that happening.

* cd ../../FullToyProjV9/sourceFiles/processA
* rm -rf *
* cp ../../FullToyProjV9/HLS/processADir/solution1/impl/ip/xilinx_com_hls_processA_1_0.zip .
* unzip xilinx_com_hls_processA_1_0.zip

Next, you need to open the project. If you haven't opened the project yet, follow the instructions for sourcing the generate_project.tcl shown in the first heading of this README. If you have already, you can just open the .xpr file as shown in the second heading of this README.

Once the project is opened, vivado will realize that the HLS ip you've changed is out of date. To fix this, do the following

* In the Sources tab, Right-click on a process you have changed and select "Report IP Status"
* In the IP Status tab, select all the processing blocks you've made changes to, and click "Upgrade Selected"
* Select "Continue with Core Container Disabled"
* If needed, click "Generate"

## To generate a new .tcl file after making changes to the project

* File -> Project -> Write tcl...
* Uncheck everything, including "copy sources to new project"
* Choose a name for the new tcl (probably just keep generate_project.tcl)
* Click OK

