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

#define IPADDRESS(a,b,c,d)    (a << UPPER32 | b << UPPER16 | c << UPPER8 | d)
#define IPADDRESS_CLASS_A(ip) (((ip & 0xff000000) >> UPPER32) & 0xff)
#define IPADDRESS_CLASS_B(ip) ((ip & 0xff0000) >> UPPER16)
#define IPADDRESS_CLASS_C(ip) ((ip & 0xff00) >> UPPER8)
#define IPADDRESS_CLASS_D(ip) (ipaddr & 0xff)

#define IPADDRESS_FORMAT       "%d.%d.%d.%d"
#define EXTRACT_IPADDR(ip)     IPADDRESS_CLASS_A(ip), IPADDRESS_CLASS_B(ip), IPADDRESS_CLASS_C(ip), IPADDRESS_CLASS_D(ip)

int main(void)
{
    int ipaddr = IPADDRESS(192,168,0,1); //192 168 000 001
    printf("ip address: " IPADDRESS_FORMAT "\n", EXTRACT_IPADDR(ipaddr));
    return 0;
}