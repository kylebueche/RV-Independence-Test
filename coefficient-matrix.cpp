/**********************************************************
 * Implementation for Independence Test
 * Author: Kyle Bueche
 *
 **********************************************************/

// n rows, n columns, initialized to 0
CoefficientMatrix::CoefficientMatrix(int n)
{
    values = std::vector<std::vector<int>>(n);
    for (int i = 0; i < n; i++)
    {
        values[i] = std::vector<int>(n);
        // Initialize row to 0
        for (int j = 0; j < n; j++)
        {
            values[i][j] = 0;
        }
    }
}

void CoefficientMatrix::printCoefficients()
{
    int i, j;
    for (i = 0; i < values.length; i++)
    {
        printf("| ");
        for (j = 0; j < values[i].length; j++)
        {
            printf("%d ", values[i][j]);
        }
        printf("|\n");
    }
}

void CoefficientMatrix::printPolynomial()
{
    bool firstEntry = true;
    int i, j;
    for (i = 0; i < values.length; i++)
    {
        for (j = 0; j < values[i].length; j++)
        {
            if (firstEntry)
            {
                if (values[i][j] != 0)
                {
                    printf("%dx%dx%d", values[i][j], i, j);
                    firstEntry = false;
                }
            }
            else
            {
                if (values[i][j] > 0)
                {
                    printf(" + %dx%dx%d", values[i][j], i, j);
                }
                else if (values[i][j] < 0)
                {
                    printf(" - %dx%dx%d", std::fabs(values[i][j]), i, j);
                }
            }
        }
    }
}

// Input vector must be of size n
int CoefficientMatrix::evaluatePolynomial(std::vector<int> inputs)
{
    answer = 0;
    int i, j;
    for (i = 0; i < values.size(); i++)
    {
        for (j = 0; j < values[i].size(); j++)
        {
            answer += values[i][j] * inputs[i] * inputs[j];
        }
    }
}

void CoefficientMatrix::printEvaluatedPolynomial(std::vector<int> inputs)
{
    printf("%d", evaluatePolynomial);
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

void CoefficientMatrix::polynomialF(vector<int> P0, vector<int> P1, vector<int> P2, vector<int> P3,
                                    vector<int> P4, vector<int> P5, vector<int> P6, vector<int> P7)
{
    polynomialPlusPP(P0, P1);
    polynomialPlusPP(P2, P3);
    polynomialMinusPP(P4, P5);
    polynomialMinusPP(P6, P7);
}
