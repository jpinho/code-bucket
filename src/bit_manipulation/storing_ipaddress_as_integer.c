//
//  storing_ipaddress_as_integer.c
//  mycodingsolutions
//
//  Created by JP on 13/02/14.
//  Copyright (c) 2014 CodeBox. All rights reserved.
//

#include <stdio.h>

/**
 * The problem:
 *
 *    1 9 2 . 1 6 8 . 0 0 0 . 0 0 1
 *
 * How to store this in an int (32 bits)?
 *
 * Hum, let's see: 2^8 = 0-255 (stores values from 0 to 255)
 *
 *  2^(8 + 8 + 8 + 8) = 2^32 = sizeof(int) = 4 => nice!
 *
 * We can store for numbers from 0 to 255 in it, great!
 *
 *
 * Draft of solution:
 *
 * int ipaddress = 0; //0x00000000
 *
 * ipaddress = (192 << 32 - 8*1) || (168 << 32 - 8*2) || (0 << 32 - 8*3) || 1;
 *
 * classA_part = ipaddress & 0xff000000
 * classB_part = ipaddress & 0xff0000
 * classC_part = ipaddress & 0xff00
 * classD_part = ipaddress & 0xff
 *
 * Let's implement shall we?!
 */
#define UPPER32 24
#define UPPER16 16
#define UPPER8  8

int main(void)
{
    int ipaddr = 192 << UPPER32 | 168 << UPPER16 | 0 << UPPER8 | 1; //192 168 000 001
    
    printf("ip address: %d.%d.%d.%d\n",
           ((ipaddr & 0xff000000) >> UPPER32) & 0xff,
           (ipaddr & 0xff0000) >> UPPER16,
           (ipaddr & 0xff00) >> UPPER8,
           (ipaddr & 0xff)
           );
    
    return 0;
}


