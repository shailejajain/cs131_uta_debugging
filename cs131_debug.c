#include <stdio.h>
#include <limits.h>
#include <assert.h>

static int find_range(int vals[], int n, int *smallest, int *largest);
/*
 * Returns the distance between the largest value and smallest value
 * in an array, and sets smallest and largest to point at the smallest
 * and largest elements in the array (respectively).  
 *
 * Parameters:
 *  - vals: an array of integers of length n
 *  - n: the length of vals
 *  - smallest: the pointer we'd like to be pointing at the smallest element in the array.
 *  - largest: the pointer we'd like to be pointing at the largest element in the array.
 *
 * Returns:
 *  - The positive distance between the largest and smallest values of vals.
 *  - INT_MAX in the case of an overflow
 * 	- INT_MIN in the case of an underflow.
 */
int find_range(int vals[], int n, int *smallest, int *largest) {
    if (n <= 0) {
        printf("ERROR: The vals array must have a length greater than 0.\n");
        return INT_MIN; 
    }
    *smallest = vals[0];
    *largest = vals[0];
    for (int i = 1 ; i < n; i++) {
        if (*smallest > vals[i]) {
            *smallest = vals[i];
        }
        if (*largest < vals[i]) {
            *largest = vals[i]; 
        }
    }
    return largest - smallest;
}

int main() {
    int test_1[5] = {2, 1, 3, -4, -3};

    int *smallest = test_1; 
    int *largest = test_1;  
    int range; 

    range = find_range(test_1, 5, smallest, largest); 
    printf("Test 1 - Smallest: %d, Largest: %d, Range: %d\n", *smallest, *largest, range);
    assert(*smallest == -4 && *largest == 3 && range == (3 - (-4))); 
    assert(smallest == test_1 + 3 && largest == test_1 + 2);
    printf("You passed the test!\n");
    return 0;
}
