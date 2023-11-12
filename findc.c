#include <stdio.h>
#include <stdlib.h>
#include "findc.h"
int main(int argc, char** argv)
{
    // Define ASCII value for 'C'
    int inputC = 67;

    // Check if arguments are valid
    if(argc < 2)
    {
        printf("Usage: findc -c <char> -f <file>");
        return 1;
    }

    // options for getopt
    int option;
    while((option = getopt(argc, argv, "hc:f:")) != -1)
    {
        switch(option)
        {
            case 'h':
                help();
                return 0;
            case 'c':
                inputC = atoi(optarg);
                break;
            case 'f':
                readFile(inputC, optarg);
                break;
            case '?':
                readInput(inputC);
                return 1;
        }
    }
    return 0;
}