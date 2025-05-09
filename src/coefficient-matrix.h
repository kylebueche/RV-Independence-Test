/**********************************************************
 * Extra Credit Problem #4 for Prob & Stats HW10
 * Author: Kyle Bueche
 *
 **********************************************************/
#ifndef COEFFICIENT_MATRIX_H
#define COEFFICIENT_MATRIX_H

#include <iostream>
#include <stdbool.h>
#include <vector>

/**************************************************
 * Coefficient Matrix for a polynomial with
 * terms xi * xj for all i, j where i < j
 *
 * No terms of any other form exist
 *
 * i is the current row, j is the current column
 * Thus, the internal representation is an upper
 * triangular matrix without the diagonal entries.
 *
 * The full nxn matrix is still allocated.
 *
 **************************************************/
class CoefficientMatrix
{
    public:
        // n rows, n columns, initialized to 0
        CoefficientMatrix(int n);
        void printCoefficients();
        void printPolynomial();

        // Input vector must be of size n
        int evaluatePolynomial(std::vector<int> inputs);
        void printEvaluatedPolynomial(std::vector<int> inputs);

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
        void polynomialPlusPP(std::vector<int> P1, std::vector<int> P2);
        void polynomialMinusPP(std::vector<int> P1, std::vector<int> P2);

        void polynomialF(std::vector<std::vector<int>> P0toP7);

    private:
        std::vector<std::vector<int>> values;
};

#endif
