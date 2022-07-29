#ifndef BMP_DECODE_H
#define Bmp_DECODE_H
#include <stdint.h>

uint32_t littleToBig(uint8_t * buffer, int size);
uint32_t extractBytes4(uint8_t* buffer, int start, int end);
uint32_t extractBytes2(uint8_t* buffer, int start);


#endif