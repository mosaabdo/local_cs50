#include <stdio.h>
#include <stdint.h>// for use uint8_t

typedef uint8_t BYTE; // giv me 8bit vlue 

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");   //open surce file in memory src, and read binary mode from argv[1]
    FILE *dst = fopen(argv[2], "wb");   // creat destnation file in memory dst, and write binary mode in argv[2]

    BYTE b; // creat a new var.. named b, have a one bit

    while(fread(&b, sizeof(b), 1, src) != 0) // fread(addres in memory, size of var, count of bit coped in evry time, copy from surce file) 
        fwrite(&b, sizeof(b), 1, dst);      // fwrite(addres in memory, size of var, count of bit coped in evrytime, copy to other file)
    fclose(dst);    // close new copy file
    fclose(src);    // close sorce file
}