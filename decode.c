#include<stdio.h>
#include <stdint.h>
#include "decode.h"
/**
 * @brief Extract 4 bytes from buffer and convert them from Little Endian to Big Endian
 * 
 * @param buffer 
 * @param start 
 * @param end 
 * @return uint32_t 
 */

uint32_t extractBytes4(uint8_t* buffer, int start, int end){
    uint8_t number[4] ={0,0,0,0};

    for(int c=0;c<4;c++){
        number[c]=buffer[c+start];
    }

    //return littleToBig4(number);
    return littleToBig(number, 4);
}

uint32_t extractBytes2(uint8_t* buffer, int start){
    uint8_t number[2] ={0,0};

    for(int c=0;c<2;c++){
        number[c]=buffer[c+start];
    }

    return littleToBig(number,2 );
}

/**
 * @brief Generic version of changing little to big endian
 * 
 * @param buffer An array of uint8 
 * @param size The size of the uint8 array
 * @return uint32_t 
 */
uint32_t littleToBig(uint8_t * buffer, int size){
    int shift = (size-1) * 8;

    uint32_t result = 0;

    for(int c =(size-1); c >=0;c--){
        uint8_t shift = (c * 8); //How many bits to shift
        result += (uint32_t) buffer[c] << shift;
    }

    return result;
}


