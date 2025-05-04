/**********************************************************
 * Implementation for Independence Test
 * Author: Kyle Bueche
 *
 **********************************************************/

#include "coefficient-matrix.h"

int getInputInteger(char *statement)
{
    int scanf_result = 0;
    char buffer_clear;

    int input = 0;
    printf(statement);
    scanf_result = scanf("%d", &input);
    while (scanf_result <= 0)
    {
        do { buffer_clear = getchar(); }
        while(buffer_clear != '\n' && buffer_clear != EOF);

        printf("\n\nPlease type a valid integer.\n");
        printf(statement);
        scanf_result = scanf("%d", &input);
    }
    do { buffer_clear = getchar(); }
    while(buffer_clear != '\n' && buffer_clear != EOF);
    printf("\n");
    return input;
}

void exitApplication()
{
    printf("Press enter to exit...");
    getchar();
}

int main()
{
    int i = 0;
    int n = 0;
    int trials = 0;

    P0 = vector<int>(3);
    P1 = vector<int>(3);
    P2 = vector<int>(3);
    P3 = vector<int>(3);
    P4 = vector<int>(3);
    P5 = vector<int>(3);
    P6 = vector<int>(3);
    P7 = vector<int>(3);
    coefMat = CoefficientMatrix(8 * 3);
    coefMat.addP0P1minus
    
    /*
    printf("Calculating...\n");
    printf("0%% complete");
    for (i = 0; i < trials; i++)
    {
        if (i % (trials / 1000) == 0)
        {
            printf("\r%.1f%% complete", (100.0 * ((float) i / trials)));
            //fflush(stdout);
        }
    }
    */

    exitApplication();
    return 0;
}
