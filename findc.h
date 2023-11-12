#include <stdio.h>
#include <stdlib.h>
void help(){
    printf("Usage: findc [OPTION]... PATTERN [FILE]...\n");
    printf("Search for PATTERN in each FILE.\n");
    printf("Example: -h\n");
    printf("         -f [filename]\n");
    printf("         -c [character]\n");
}
int readFile(int inputC, char* filename){
    int charCounter = 0;
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        printf("Error: file not found");
        return 1;
    }
    while(!feof(fp))
    {
        int c = fgetc(fp);
        if(c == inputC)
        {
            charCounter++;
        }
    }
    printf("Amount of times character appears: ");
    printf(charCounter);
    fclose(fp);
    return 0;
}
int readInput(int inputC){
    int charCounter = 0;
    int c;
    while((c = getchar()) != EOF)
    {
        if(c == inputC)
        {
            charCounter++;
        }
    }
    printf("Amount of times character appears: ");
    printf(charCounter);
    return 0;
}