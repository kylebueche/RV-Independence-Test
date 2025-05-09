/**********************************************************
 * Implementation for Independence Test
 * Author: Kyle Bueche
 *
 **********************************************************/

#include <iostream>
#include <type_traits>
#include "coefficient-matrix.h"

int getInputInteger(char *statement)
{

    int input = 0;
    std::cout << statement;
    while (!(std::cin >> input))
    {
        std::cout << "\n\nPlease type a valid integer: ";
        std::cin.clear();
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return input;
}

void exitApplication()
{
    char c;
    std::cout << ("Press enter to exit...");
    std::cin >> c;
}

int main()
{
    int n = 0;

    std::vector<std::vector<int>> P0toP7 = std::vector<std::vector<int>>(8);
    std::vector<int> P0 = std::vector<int>(n);
    std::vector<int> P1 = std::vector<int>(n);
    std::vector<int> P2 = std::vector<int>(n);
    std::vector<int> P3 = std::vector<int>(n);
    std::vector<int> P4 = std::vector<int>(n);
    std::vector<int> P5 = std::vector<int>(n);
    std::vector<int> P6 = std::vector<int>(n);
    std::vector<int> P7 = std::vector<int>(n);
    P0toP7[0] = P0;
    P0toP7[1] = P1;
    P0toP7[2] = P2;
    P0toP7[3] = P3;
    P0toP7[4] = P4;
    P0toP7[5] = P5;
    P0toP7[6] = P6;
    P0toP7[7] = P7;

    CoefficientMatrix coefMat = CoefficientMatrix(8 * n);
    coefMat.printCoefficients();
    
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
