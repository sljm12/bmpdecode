#include<stdio.h>
#include "decode.h"

int main(){
    uint8_t buffer[54];

    FILE* f = fopen("image.bmp","rb");
    if(f==NULL){
        printf("Failed to open file");
        return -1;
    }

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
    /*
    int len =0;
    int counter = 0;
    uint8_t row_buffer[1280];
    while(1){
        
        len = fread(row_buffer, 1 ,sizeof(row_buffer), f);
        printf("%d\n", len);
        if(len < 1280){
            break;
        }
        if(len != 0){
            counter++;
        }
    }
    printf("Counter %d\n", counter);

    printf("%d\n", row_buffer[0]);
    printf("%d\n", row_buffer[1]);
    printf("%d\n", row_buffer[2]);
    printf("%d\n", row_buffer[3]);
    */
    fclose(f);
    return 0;
}