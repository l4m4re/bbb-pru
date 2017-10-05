/* Beaglebone Pru IO 
 * 
 * Copyright (C) 2015 Rafael Vega <rvega@elsoftwarehamuerto.org> 
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PINS_H
#define PINS_H

#include <string.h>

#define BEAGLEBONE_PRUIO_MAX_ADC_CHANNELS 14
#define BEAGLEBONE_PRUIO_MAX_GPIO_CHANNELS 118

// These defines map the beagle bone's pin names to the AM335X's 
// gpio numbers. GPIO numbers can be used like:
//    
//    int gpioModule = P9_11 >> 5;
//    int gpioPin = P9_11 % 32;

// #define P8_03 38 // emmc2
// #define P8_04 39 // emmc2
// #define P8_05 34 // emmc2
// #define P8_06 35 // emmc2
#define P8_07 66 
#define P8_08 67 
#define P8_09 69 
#define P8_10 68 
#define P8_11 45 
#define P8_12 44 
#define P8_13 23 
#define P8_14 26 
#define P8_15 47 
#define P8_16 46 
#define P8_17 27 
#define P8_18 65 
#define P8_19 22 
// #define P8_20 63 // emmc2
// #define P8_21 62 // emmc2
// #define P8_22 37 // emmc2
// #define P8_23 36 // emmc2
// #define P8_24 33 // emmc2
// #define P8_25 32 // emmc2
#define P8_26 61 
#define P8_27 86 // hdmi, mux_control
#define P8_28 88 // hdmi, mux_control
#define P8_29 87 // hdmi, mux_control
#define P8_30 89 // hdmi
#define P8_31 10 // hdmi
#define P8_32 11 // hdmi
#define P8_33 9  // hdmi
#define P8_34 81 // hdmi
#define P8_35 8  // hdmi
#define P8_36 80 // hdmi
#define P8_37 78 // hdmi
#define P8_38 79 // hdmi
#define P8_39 76 // hdmi
#define P8_40 77 // hdmi
#define P8_41 74 // hdmi
#define P8_42 75 // hdmi
#define P8_43 72 // hdmi
#define P8_44 73 // hdmi
#define P8_45 70 // hdmi
#define P8_46 71 // hdmi

// #define P9_11  30  // uart 4
#define P9_12  60 
// #define P9_13  31  // uart 4
#define P9_14  50 
#define P9_15  48 
#define P9_16  51 
// #define P9_17  5  // i2c1
// #define P9_18  4  // i2c1
// #define P9_19  13 // i2c2
// #define P9_20  12 // i2c2
#define P9_21  3 
#define P9_22  2 
#define P9_23  49 
#define P9_24  15
// #define P9_25  117 // mcasp0
#define P9_26  14 
#define P9_27  115 
// #define P9_28  113 // mcasp0
// #define P9_29  111 // mcasp0
#define P9_30  112 // previous mux_control
// #define P9_31  110 // mcasp0
#define P9_41A 20 
// #define P9_41B 116 // low levels on output, ok input
#define P9_42A 7   // previous mux_control
// #define P9_42B 114 // mcasp0

static inline int beaglebone_pruio_get_gpio_number(char* pin_name){
   if(strcmp(pin_name, "P8_07") == 0){
      return P8_07;
   }
   else if(strcmp(pin_name, "P8_08") == 0){
      return P8_08;
   }
   else if(strcmp(pin_name, "P8_09") == 0){
      return P8_09;
   }
   else if(strcmp(pin_name, "P8_10") == 0){
      return P8_10;
   }
   else if(strcmp(pin_name, "P8_11") == 0){
      return P8_11;
   }
   else if(strcmp(pin_name, "P8_12") == 0){
      return P8_12;
   }
   else if(strcmp(pin_name, "P8_13") == 0){
      return P8_13;
   }
   else if(strcmp(pin_name, "P8_14") == 0){
      return P8_14;
   }
   else if(strcmp(pin_name, "P8_15") == 0){
      return P8_15;
   }
   else if(strcmp(pin_name, "P8_16") == 0){
      return P8_16;
   }
   else if(strcmp(pin_name, "P8_17") == 0){
      return P8_17;
   }
   else if(strcmp(pin_name, "P8_18") == 0){
      return P8_18;
   }
   else if(strcmp(pin_name, "P8_19") == 0){
      return P8_19;
   }
   else if(strcmp(pin_name, "P8_26") == 0){
      return P8_26;
   }
   else if(strcmp(pin_name, "P8_27") == 0){
      return P8_27;
   }
   else if(strcmp(pin_name, "P8_28") == 0){
      return P8_28;
   }
   else if(strcmp(pin_name, "P8_29") == 0){
      return P8_29;
   }
   else if(strcmp(pin_name, "P8_30") == 0){
      return P8_30;
   }
   else if(strcmp(pin_name, "P8_31") == 0){
      return P8_31;
   }
   else if(strcmp(pin_name, "P8_32") == 0){
      return P8_32;
   }
   else if(strcmp(pin_name, "P8_33") == 0){
      return P8_33;
   }
   else if(strcmp(pin_name, "P8_34") == 0){
      return P8_34;
   }
   else if(strcmp(pin_name, "P8_35") == 0){
      return P8_35;
   }
   else if(strcmp(pin_name, "P8_36") == 0){
      return P8_36;
   }
   else if(strcmp(pin_name, "P8_37") == 0){
      return P8_37;
   }
   else if(strcmp(pin_name, "P8_38") == 0){
      return P8_38;
   }
   else if(strcmp(pin_name, "P8_39") == 0){
      return P8_39;
   }
   else if(strcmp(pin_name, "P8_40") == 0){
      return P8_40;
   }
   else if(strcmp(pin_name, "P8_41") == 0){
      return P8_41;
   }
   else if(strcmp(pin_name, "P8_42") == 0){
      return P8_42;
   }
   else if(strcmp(pin_name, "P8_43") == 0){
      return P8_43;
   }
   else if(strcmp(pin_name, "P8_44") == 0){
      return P8_44;
   }
   else if(strcmp(pin_name, "P8_45") == 0){
      return P8_45;
   }
   else if(strcmp(pin_name, "P8_46") == 0){
      return P8_46;
   }

   // else if(strcmp(pin_name, "P9_11") == 0){
   //    return P9_11;
   // }
   else if(strcmp(pin_name, "P9_12") == 0){
      return P9_12;
   }
   // else if(strcmp(pin_name, "P9_13") == 0){
   //    return P9_13;
   // }
   else if(strcmp(pin_name, "P9_14") == 0){
      return P9_14;
   }
   else if(strcmp(pin_name, "P9_15") == 0){
      return P9_15;
   }
   else if(strcmp(pin_name, "P9_16") == 0){
      return P9_16;
   }
   // else if(strcmp(pin_name, "P9_17") == 0){
   //    return P9_17;
   // }
   // else if(strcmp(pin_name, "P9_18") == 0){
   //    return P9_18;
   // }
   else if(strcmp(pin_name, "P9_21") == 0){
      return P9_21;
   }
   else if(strcmp(pin_name, "P9_22") == 0){
      return P9_22;
   }
   else if(strcmp(pin_name, "P9_23") == 0){
      return P9_23;
   }
   else if(strcmp(pin_name, "P9_24") == 0){
      return P9_24;
   }
   else if(strcmp(pin_name, "P9_26") == 0){
      return P9_26;
   }
   else if(strcmp(pin_name, "P9_27") == 0){
      return P9_27;
   }
   else if(strcmp(pin_name, "P9_30") == 0){
      return P9_30;
   }
   else if(strcmp(pin_name, "P9_41A") == 0){
      return P9_41A;
   }
   else if(strcmp(pin_name, "P9_42A") == 0){
      return P9_42A;
   }
   return -1;
}

#endif //PINS_H
