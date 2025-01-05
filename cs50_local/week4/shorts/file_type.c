#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX 4
void checker(uint8_t buf[MAX]);
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("error: ./file_type filename\n");
        return 1;
    }
    char *file_name = argv[1];
    FILE *ty = fopen(file_name, "r");
    uint8_t buffer[MAX];
    fread(buffer, 1, 4, ty);
    checker(buffer);
    fclose(ty);
    return 0;
}
void checker(uint8_t buf[MAX])
{
    int pdf = 0, txt = 0, png = 0;
    uint8_t pdf_type[] = {37, 80, 68, 70};
    uint8_t txt_type[] = {49, 44, 32, 50};
    uint8_t png_type[] = {137, 80, 78, 71};
    
    for(int i = 0; i < 4;i++)
    {
        if(buf[i] == pdf_type[i])
            pdf++;
        if(buf[i] == txt_type[i])
            txt++;
        if(buf[i] == png_type[i])
            png++;
    }
    if(pdf == 4)
        printf("type is pdf\n");
    else if (txt == 4) 
        printf("type is txt\n");
    else if(png == 4)
        printf("type is png\n");
    else
        printf("type is unkown\n");       

}