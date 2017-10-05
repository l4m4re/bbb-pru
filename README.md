##BBB-PRU

These are some example programs to figure out how to program the PRU units in the Beagle Bone (Black/Green).

Forked from [rvega/bbb-pru](https://github.com/rvega/bbb-pru)

The original code is no longer maintained and suggests [this
repo](https://github.com/outer-space-sounds/beaglebone-pruio/) is more
up-to-date and probably more useful. However, that one is also not actively
maintainedi, the ADC inputs are sampled at 1500 samples per second and it
includes things I don't need. I pulled in the library, though and intend to
adapt it for my needs. Also pulled in the device-tree overlay.


## 3rd party tools that are needed.

The following packages need to be installed:

    am335x-pru-package
    ti-pru-cgt-installer

## Writing PRU assembly code.

Look at the app-assembler example.

## Writing PRU C code

Look at the app-c example.

## ADC example 

I have adjusted the adc example to fit my needs, namely to sample two channels
as fast as possible. With the current code, I get a sampling rate of 1600 kS/s
(or 800 kS/s per channel), the theoretical maximum in continous mode for two
channels. 

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

## License

GPLv3
