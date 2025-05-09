/**********************************************************
 * Implementation for Independence Test
 * Author: Kyle Bueche
 *
 **********************************************************/

#include "coefficient-matrix.h"

// n rows, n columns, initialized to 0
CoefficientMatrix::CoefficientMatrix(int n)
{
    values = std::vector<std::vector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        values.push_back(std::vector<int>(n));
        // Initialize row to 0
        for (int j = 0; j < n; j++)
        {
            values[i].push_back(0);
            std::cout << values[i][j];
        }
    }
}

void CoefficientMatrix::printCoefficients()
{
    int i, j;
    for (i = 0; i < values.size(); i++)
    {
        std::cout << "| ";
        for (j = 0; j < values[i].size(); j++)
        {
            std::cout << values[i][j] << " ";
        }
        std::cout << "|\n";
    }
}

void CoefficientMatrix::printPolynomial()
{
    bool firstEntry = true;
    int i, j;
    for (i = 0; i < values.size(); i++)
    {
        for (j = 0; j < values[i].size(); j++)
        {
            if (firstEntry)
            {
                if (values[i][j] != 0)
                {
                    std::cout << values[i][j] << "x" << i << "x" << j;
                    firstEntry = false;
                }
            }
            else
            {
                if (values[i][j] > 0)
                {
                    std::cout << " + " << values[i][j] << "x" << i << "x" << j;
                }
                else if (values[i][j] < 0)
                {
                    std::cout << " - " << values[i][j] << "x" << i << "x" << j;
                }
            }
        }
    }
}

// Input vector must be of size n
int CoefficientMatrix::evaluatePolynomial(std::vector<int> inputs)
{
    int answer = 0;
    int i, j;
    for (i = 0; i < values.size(); i++)
    {
        for (j = 0; j < values[i].size(); j++)
        {
            answer += values[i][j] * inputs[i] * inputs[j];
        }
    }
    return answer;
}

void CoefficientMatrix::printEvaluatedPolynomial(std::vector<int> inputs)
{
    std::cout << evaluatePolynomial(inputs);
}

/******************************************************************************
* For the following, i, j, k, l, m, and n are used as placeholder identifiers
* for individual x variables
*
* Adds or subtracts the value P1 * P2 to or from the current polynomial,
* forming a new polynomial.
*
* P1 * P2 = (xi + xj + ... + xk) * (xl * xm * ... * xn),
* P1 is represented as a vector (i, j, ..., k) internally, and likewise,
* P2 is represented as a vector (l, m, ..., n)
*******************************************************************************/
void CoefficientMatrix::polynomialPlusPP(std::vector<int> P1, std::vector<int> P2)
{
    int i, j;
    for (i = 0; i < P1.size(); i++)
    {
        for (j = 0; j < P1.size(); j++)
        {
            values[P1[i]][P2[j]]++;
        }
    }
}

void CoefficientMatrix::polynomialMinusPP(std::vector<int> P1, std::vector<int> P2)
{
    int i, j;
    for (i = 0; i < P1.size(); i++)
    {
        for (j = 0; j < P1.size(); j++)
        {
            values[P1[i]][P2[j]]--;
        }
    }
}

void CoefficientMatrix::polynomialF(std::vector<std::vector<int>> P0toP7)
{
    polynomialPlusPP(P0toP7[0], P0toP7[1]);
    polynomialPlusPP(P0toP7[2], P0toP7[3]);
    polynomialMinusPP(P0toP7[4], P0toP7[5]);
    polynomialMinusPP(P0toP7[6], P0toP7[7]);
}
