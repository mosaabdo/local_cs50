#include <stdio.h>
#include <stdlib.h>

void selected(void);
void read(void);
void write(char *tx);
void add(char *tx);
void cop(void);

int main(void)
{
    int s = 0;
    selected();

    printf("1] stay\t\t\t2] exit\n>: ");
    scanf("%d", &s);
    
    if(s == 1)
        main();
    else if(s != 1)
        return 0;
}

void selected(void)
{
    printf("1] read file\t2] write file\t3] add to file\t4] copy file\n");
    int s = 0;
    scanf("%d", &s);
    if(s == 1)
        read();
    else if(s == 2)
    {
        printf("add your txt: ");
        char *tx = malloc(sizeof(char));
        if(tx == NULL)
            return;
        scanf("%s", tx);
        write(tx);
        free(tx);
    }
    else if(s == 3)
    {
        printf("add your txt: ");
        char *tx = malloc(sizeof(char));
        if(tx == NULL)
            return;
        scanf("%s", tx);
        add(tx);
        free(tx);
    }
    else if(s == 4)
        cop();
    else   
        return;
}
void read(void)
{
   
    FILE *file = fopen("text.txt", "r");
    char ch;
    while((ch = fgetc(file)) != EOF)
        printf("%c",ch);
    fclose(file);
}
void write(char *tx)
{
    FILE *file = fopen("text.txt", "w");
    fprintf(file, "%s\n", tx);
    fclose(file);

}
void add(char *tx)
{
    FILE *file = fopen("text.txt", "a");
    fprintf(file, "%s\n", tx);
    fclose(file);
}
void cop(void)
{
    FILE *file = fopen("text.txt", "r");
    FILE *fc = fopen("copy.txt", "w");
    char ch;
    while((ch = fgetc(file)) != EOF)
        fputc(ch, fc);
    fclose(file);
    fclose(fc);
}