#include<stdio.h>
#include <stdint.h>

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

    return littleToBig2(number);
}

/**
 * @brief Generic version of changing little to big endian
 * 
 * @param buffer 
 * @param size 
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

/**
 * @brief Convert 4 bytes from little to big endian
 * 
 * @param vals 
 * @return uint32_t 
 */
uint32_t littleToBig4(uint8_t vals[4]){
    uint32_t results = (uint32_t) 0;
    results += (uint32_t)vals[3] << 24;
    results +=(uint32_t)vals[2] << 16;
    results += (uint32_t)vals[1] << 8;
    results += vals[0];
    return results;
}

uint32_t littleToBig2(uint8_t vals[2]){
    uint32_t results = (uint32_t) 0;
    results += (uint32_t)vals[1] << 8;
    results += vals[0];
    return results;
}

void main(){
    uint8_t buffer[54];

    FILE* f = fopen("image.bmp","rb");
    size_t size_read = fread(buffer, 1 ,sizeof(buffer), f);
    printf("Size Read %d\n", size_read);
    int width = extractBytes4(buffer,18,21);
    int bpp = extractBytes2(buffer,28);
    printf("LTB %d\n", extractBytes4(buffer,2,5));
    printf("Width %d\n", extractBytes4(buffer,18,21));
    printf("Height %d\n", extractBytes4(buffer,22,25));
    printf("Data Offset %d\n", extractBytes4(buffer,10,25));
    printf("Bits Per Pixel %d\n", extractBytes2(buffer,28));
    printf("\n");

    int widthBuffer = width * bpp/8;
    printf("Width Buffer %d\n", widthBuffer);

    int len =0;
    int counter = 0;
    uint8_t row_buffer[1280];
    do{
        len = fread(row_buffer, 1 ,sizeof(row_buffer), f);
        printf("%d\n", len);
        counter++;
    }while(len==1280);
    printf("Counter %d\n", counter);

    printf("%d\n", row_buffer[0]);
    printf("%d\n", row_buffer[1]);
    printf("%d\n", row_buffer[2]);
    printf("%d\n", row_buffer[3]);
    fclose(f);
}