/**********************************************************
 * Extra Credit Problem #4 for Prob & Stats HW10
 * Author: Kyle Bueche
 *
 **********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/****************************************************************************
 * A polynomial of dimension d is represented as an array of coefficients
 * index 0 is c1, 1 is c2, 2 is c3, and so forth
 *
 * for d = 3,
 * The first perms(d, 0, 0)(d choose 1) coefficients correspond to x^3, y^3, z^3, etc
 * The next perms(d-1, 1, 0)(d choose 2) coefficients correspond to xy^2, xz^2, yx^2, yz^2, zx^2, zy^2, etc,
 * The next perms(d-2, 1, 1)(d choose 3) coefficients correspond to xyz
 *
 * This is always true:
 * The first parameter is the partitioning of d into one slot of d elements, which permutes d times
 * The last parameter is the partitioning of d into d slots, each equaling 1, which permutes 1 time
 * The middle slots will consider all partitions
 * For example,
 * (d-1, 1) is the first class
 * (d-2, 2) is the next
 * (d-3, 3) is the next
 * following (d-i, i) until i > d - i
 * and then,
 * (d-2, 1, 1)
 * (d-3, 2, 1)
 * (d-4, 3, 1)
 * following (d-i, i-1, 1) until i - 1 > d - i and so on.
 *
 * A partition describes a class of arrangements, like (2, 1) is x^2 * y^1
 * The number of permutations of a partition set into d slots, the rest zeroed
 * multiplied by the number of ways to choose a partition of that size in d slots,
 * gives us the number of polynomial arguments that fit the arrangement.
 *
 ***************************************************************************/

typedef struct Tuple
{
    int *values;
    int length;
} Tuple;

// Automatically zeroed
Tuple new_tuple(int length)
{
    Tuple t;
    t.values = malloc(sizeof(int) * length);
    memset(t.values, 0, length);
    t.length = length;
    return t;
}

void free_tuple(const Tuple t)
{
    free(t.values);
}

typedef struct Polynomial
{
    int *coefficients; // Array of size of number of terms
    int length;
    int dimension;
    int *dbuffer; // Array of size dimension
} Polynomial;

long long int factorial(int n)
{
    long long int n_factorial = 1;
    int i;
    for (i = 1; i <= n; i++)
    {
        n_factorial = n_factorial * i;
    }
    return n_factorial;
}

// Assumes integers of max size Tuple length
long long int distinct_permutations(const Tuple t)
{
    long long int denominator = 1;

    Tuple frequency = new_tuple(t.length);
    int v;
    int i = 0;
    for (i = 0; i < t.length; i++)
    {
        v = t.values[i] - 1;
        if (v >= 0 & v < t.length)
        {
            frequency.values[v]++;
        }
    }

    for (i = 0; i < frequency.length; i++)
    {
        denominator *= factorial(frequency.values[i]);
    }

    return (long long int) factorial(t.length) / denominator;
}




void sizeof_partition_k(Polynomial p, int k)
{
    int d = p.dimension;
    // Current partition size
    int index = 0;
    int partition_size = 1;
    int i = 1;
    // Zero memory
    for (index = 0; index < d, index++)
    {
        p.dbuffer[index] = 0;
    }
    for (i = 0; i
    for (index = 0; index < d, index++)
    {
        p.dbuffer[index] = d;

void print_coefficients(Polynomial p)
{
    int i;
    printf("{ ");
    for (i = 0; i < arrayList->list_length; i++)
    {
        printf("c%d = %d", arrayList->data[i]);
        if (i + 1 < arrayList->list_length)
        {
            printf(", ");
        }
    }
    printf(" } ");
}

// Call free_array after
ArrayList new_array(int length)
{
    ArrayList arrayList;
    arrayList.array_length = length;
    arrayList.list_length = 0;
    arrayList.data = malloc(sizeof(int) * length);
    return arrayList;
}

void free_array(ArrayList *arrayList)
{
    free(arrayList->data);
}

// Must be same array_length, always free_array after
ArrayList copy_array(ArrayList *arrayList)
{
    ArrayList newArray = new_array(arrayList->array_length);
    newArray.list_length = arrayList->list_length;
    int i;
    for (i = 0; i < arrayList->list_length; i++)
    {
        newArray.data[i] = arrayList->data[i];
    }
    return newArray;
}


// Returns a random int in the range [i1, i2)
int random2(int i1, int i2)
{
    return rand() % (i2 - i1) + i1;
}

int next_index(ArrayList *arrayList, int index)
{
    return arrayList->data[index] - 1;
}

// Adds an element to the end of the ArrayList if possible
// Returns the index stored at, or -1 if not inserted
int add_element(ArrayList *arrayList, int value)
{
    if (arrayList->list_length < arrayList->array_length)
    {
        arrayList->data[arrayList->list_length] = value;
        arrayList->list_length++;
        return arrayList->list_length - 1;
    }
    else
    {
        return -1;
    }
}

// Removes an element from an ArrayList, and shifts all
// elements at a higher index to the left by 1
// Returns the value removed
int remove_element(ArrayList *arrayList, int index)
{
    int value;
    int i;
    if ((index >= 0) && (index < arrayList->list_length))
    {
        value = arrayList->data[index];
        for (i = index + 1; i < arrayList->list_length; i++)
        {
            arrayList->data[i - 1] = arrayList->data[i];
        }
    }
    arrayList->list_length--;
    return value;
}

// Removes the first occurence of the value from the ArrayList
void remove_value(ArrayList *arrayList, int value)
{
    int i;
    for (i = 0; i < arrayList->list_length; i++)
    {
        if (arrayList->data[i] == value)
        {
            remove_element(arrayList, i);
            break;
        }
    }
}

// Initialize an array List to { 1, ..., array_length }
void initialize_array(ArrayList *arrayList)
{
    int i;
    for (i = 0; i < arrayList->array_length; i++)
    {
        arrayList->data[i] = i + 1;
    }
    arrayList->list_length = arrayList->array_length;
}

void swapElements(ArrayList *arrayList, int i1, int i2)
{
    int placeholder = arrayList->data[i1];
    arrayList->data[i1] = arrayList->data[i2];
    arrayList->data[i2] = placeholder;
}

void permute_array(ArrayList *arrayList)
{
    int i;
    for (i = 0; i + 1 < arrayList->list_length; i++)
    {
        swapElements(arrayList, i, random2(i + 1, arrayList->list_length));
    }
}

// Counts the cycle order from index 0
int cycle_order(ArrayList *arrayList, int value)
{
    int order = 1;
    int initIndex = value - 1;
    int currIndex = initIndex;
    int nextIndex = next_index(arrayList, currIndex);
    while (nextIndex != initIndex)
    {
        currIndex = nextIndex;
        nextIndex = next_index(arrayList, currIndex);
        order++;
    }
    return order;
}

// Removes the cycle at index 0
void remove_cycle(ArrayList *arrayList, ArrayList *reference)
{
    int initIndex = arrayList->data[0] - 1;
    int currIndex = initIndex;
    int nextIndex = next_index(reference, currIndex);
    remove_value(arrayList, reference->data[currIndex]);
    while (nextIndex != initIndex)
    {
        currIndex = nextIndex;
        nextIndex = next_index(reference, currIndex);
        remove_value(arrayList, reference->data[currIndex]);
    }
    //remove_value(arrayList, tempArray.data[currIndex]);
}

// Returns the number of fixed points in the current permutation
int count_fixed_points(ArrayList *arrayList)
{
    int fixed_points = 0;
    int i;
    for (i = 0; i < arrayList->list_length; i++)
    {
        if (next_index(arrayList, i) == i)
        {
            fixed_points++;
        }
    }
    return fixed_points;
}

int count_cycles(ArrayList *arrayList)
{
    int num_cycles = 0;
    ArrayList tempArray = copy_array(arrayList);
    int currIndex = 0;
    int nextIndex = 0;
    int cycleOrder = 0;
    int i;
    while(tempArray.list_length > 0)
    {
        cycleOrder = cycle_order(arrayList, tempArray.data[0]);
        if (cycleOrder == 1)
        {
            remove_element(&tempArray, 0);
        }
        else
        {
            remove_cycle(&tempArray, arrayList);
            num_cycles++;
        }
    }
    free_array(&tempArray);
    return num_cycles;
}

int count_cycles_order_k(ArrayList *arrayList, int k)
{
    int num_cycles_order_k = 0;
    ArrayList tempArray = copy_array(arrayList);
    int currIndex = 0;
    int nextIndex = 0;
    int cycleOrder = 0;
    int i;
    while(tempArray.list_length > 0)
    {
        cycleOrder = cycle_order(arrayList, tempArray.data[0]);
        
        if (cycleOrder == 1)
        {
            remove_element(&tempArray, 0);
        }
        else
        {
            if (cycleOrder == k)
            {
                num_cycles_order_k++;
            }
            remove_cycle(&tempArray, arrayList);
        }
    }
    free_array(&tempArray);
    return num_cycles_order_k;
}

int largest_cycle_order(ArrayList *arrayList)
{
    int cycleOrder = 0;
    int largestCycleOrder = 0;
    ArrayList tempArray = copy_array(arrayList);
    int currIndex = 0;
    int nextIndex = 0;
    int i;
    while(tempArray.list_length > 0)
    {
        cycleOrder = cycle_order(arrayList, tempArray.data[0]);
        if (cycleOrder > largestCycleOrder)
        {
            largestCycleOrder = cycleOrder;
        }
        if (cycleOrder == 1)
        {
            remove_element(&tempArray, 0);
        }
        else
        {
            remove_cycle(&tempArray, arrayList);
        }
    }
    free_array(&tempArray);
    return largestCycleOrder;
}

int get_input_integer(char *statement)
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

int main()
{
    int i = 0;
    int n = 0;
    int trials = 0;
    int fixed_points = 0;
    int cycles_order_1 = 0;
    int cycles_order_2 = 0;
    int cycles_order_3 = 0;
    int cycles_order_4 = 0;
    int cycles_order_5 = 0;
    int cycles_order_6 = 0;
    int largest_cycle_order_sum = 0;
    float E_cycles_order_1 = 0;
    float E_cycles_order_2 = 0;
    float E_cycles_order_3 = 0;
    float E_cycles_order_4 = 0;
    float E_cycles_order_5 = 0;
    float E_cycles_order_6 = 0;
    float P_no_fixed_points = 0;
    float E_largest_cycle_order = 0;
    ArrayList arrayList;


    printf("\n\nWelcome!\n");
    printf("This program generates a random permutation of the elements { 1, ..., n },\n");
    printf("and calculates some interesting statistics.\n\n");
    printf("Let's start by choosing an n!\n");

    n = get_input_integer("Choose n = ");

    printf("Great! now let's choose a number of trials.\n");

    trials = get_input_integer("trials = ");

    arrayList = new_array(n);
    initialize_array(&arrayList);
    printf("Splendid, calculating...\n");
    printf("0%% complete");
    for (i = 0; i < trials; i++)
    {
        if (i % (trials / 1000) == 0)
        {
            printf("\r%.1f%% complete", (100.0 * ((float) i / trials)));
            //fflush(stdout);
        }
        permute_array(&arrayList);
        fixed_points = count_fixed_points(&arrayList);
        cycles_order_1 += fixed_points;
        cycles_order_2 += count_cycles_order_k(&arrayList, 2);
        cycles_order_3 += count_cycles_order_k(&arrayList, 3);
        cycles_order_4 += count_cycles_order_k(&arrayList, 4);
        cycles_order_5 += count_cycles_order_k(&arrayList, 5);
        cycles_order_6 += count_cycles_order_k(&arrayList, 6);
        largest_cycle_order_sum += largest_cycle_order(&arrayList);
        if (fixed_points == 0)
        {
            P_no_fixed_points = P_no_fixed_points + 1.0f;
        }
    }
    E_cycles_order_1 = ((float) cycles_order_1) / ((float) trials);
    E_cycles_order_2 = ((float) cycles_order_2) / ((float) trials);
    E_cycles_order_3 = ((float) cycles_order_3) / ((float) trials);
    E_cycles_order_4 = ((float) cycles_order_4) / ((float) trials);
    E_cycles_order_5 = ((float) cycles_order_5) / ((float) trials);
    E_cycles_order_6 = ((float) cycles_order_6) / ((float) trials);
    E_largest_cycle_order = ((float) largest_cycle_order_sum) / ((float) trials);
    P_no_fixed_points = P_no_fixed_points / ((float) trials);
    printf("\r100%% complete!\n\n");
    printf("Probability that a permutation has no fixed points: %f\n\n", P_no_fixed_points);

    printf("Expected number of cycles of order 1: %f\n", E_cycles_order_1);
    printf("Expected number of cycles of order 2: %f\n", E_cycles_order_2);
    printf("Expected number of cycles of order 3: %f\n", E_cycles_order_3);
    printf("Expected number of cycles of order 4: %f\n", E_cycles_order_4);
    printf("Expected number of cycles of order 5: %f\n", E_cycles_order_5);
    printf("Expected number of cycles of order 6: %f\n\n", E_cycles_order_6);

    printf("Expected order of the largest cycle: %f\n\n", E_largest_cycle_order);
    

    free_array(&arrayList);

    printf("Press enter to exit...");

    getchar();
    return 0;
}
