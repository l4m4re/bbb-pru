#BBB-PRU

This is an example program to figure out how to program the PRU units in the Beagle Bone Black.



**DEPRECATION NOTICE:** The code in [this repo](https://github.com/outer-space-sounds/beaglebone-pruio/) is more up-to-date and probably more useful.

## 3rd party tools that are needed.

The vendors/am335x_pru_package directory includes a driver and assembler that can be used to generate and load binaries to be ran on the PRUs. The vendors/install.sh script takes care of compiling and installing it.

The vendors/pru_2.0.0B2 directory should contain the C compiler for generating binaries to run in the PRU. However TI's licence prevents redistribution of it so you have to manually download it from [here](http://software-dl.ti.com/codegen/non-esd/downloads/beta.htm) and run the installer script. This will generate a pru_2.0.0B2 directory which you'll have to move into vendors/pru_2.0.0B2. vendors/install.sh copies some files from here to system-wide directories for convenience.

## Writing PRU assembly code.

Look at the app-assembler example.

## Writing PRU C code

Look at the app-c example.

## ADC example 

I have adjusted the adc example to fit my needs, namely to sample two channels
as fast as possible. With the current code, I get a sampling rate just shy of
1600 kS/s (or 800 kS/s per channel), which is pretty close to the theoretical
maximum of about 1.6 MS/s in continous mode for two channels. 

See: [stack
overflow](https://stackoverflow.com/questions/31076486/frequency-sampling-limit-for-beaglebone-adc)

"The ADC subsystem in the AM335x CPU is clocked at 24 MHz and needs 15 cycles
for a sample (14 in continous mode). This leads to a maximum sample rate of
1.6 (1.74) MSamples/s. See SRM, chapter 12 for details."

In addition to the clock cycles needed for the ad conversion, the sequencer
which processes the programmable adc steps also has an "idle" step, which
cannot be disabled. It appears this takes two clock cycles, which brings the
total number of clock cycles needed for two channels at max speed to 30.

I added a calc_samplerate.py script to the apps/adc directory, in which I
attempted to sort this out. 

## Links:

http://www.embeddedrelated.com/showarticle/586.php   
http://www.embeddedrelated.com/showarticle/603.php   
https://github.com/texane/pru_sdk   
https://github.com/BeaglePilot/PRUSS-C   
https://github.com/beagleboard/am335x_pru_package   
https://github.com/VegetableAvenger/BBBIOlib
http://processors.wiki.ti.com/index.php/PRU_Assembly_Instructions   
http://processors.wiki.ti.com/index.php/PRU_Assembly_Reference_Guide   
[AM335x SitaraTM Processors Technical Reference Manual](http://www.ti.com/lit/ug/spruh73k/spruh73k.pdf)   


## Objectives

1. How to compile and run assembly code for the PRU?  [DONE]
2. How to communicate between a host application (linux app) and the code running in the PRU? Interrupt based, please. [DONE]
3. How to do all of this stuff in C instead of assembly?  [DONE]
4. How to use GPIOs? [DONE]
5. ADCs? 
5. Hardware Timers?

## License

GPLv3
