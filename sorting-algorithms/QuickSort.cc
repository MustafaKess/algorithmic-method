/**
 *  Quick Sort algorithm implementation in C++.
 *
 *   @see https://frh.folk.ntnu.no/algmet/opplegg.html (Norwegian Site)
 *   for the original implementation in Frode Kode™
 *   @file     QuickSort.cc
 *   @author   Frode Haug, Mustafa Kesen
 */


#include <iostream>          //  cout
#include <string>            //  string
#include <cstdlib>           //  (s)rand
using namespace std;


const int n = 20;            //Total number of elements in the array to be sorted.
void change(char & first, char & second);
void display(const string & text, const char arr[],  int left,  int right);
int  partitions(char arr[],  int left, int right);
void quickSort(char arr[],  int left,  int right);

/**
 *  Main function that initializes an array with random letters.
 */

int main() {
    char array[n+1];                //Array to be sorted
    srand(0);                  //Initialize random number generator.
    array[0] = ' ';                // Element for 1-based indexing.
    for (int i = 1; i <= n; i++) //  Randomize letters
        array[i] = static_cast <char> ('A' + (rand() % 26));
    display("\n\nArray Before quicksort:\n", array, 1, n);
    quickSort(array, 1, n);
    display("\n\nArray after quicksort algorithm:\n", array, 1, n);
    cout << "\n\n";
    return 0;
}


/**
 *  Changes the values of two characters by reference.
 *  @param   first  -  Value to be swapped with 'second' (reference passed)
 *  @param   second  - Value to be swapped with 'first' (reference passed)
 */
void change(char & first, char & second) {
    char temp = first;     //temporary variable
    first = second;
    second = temp;
}


/**
 * Displays a part of the array with a message.
 * @param text  - Message to be displayed before the array.
 * @param arr  - Array to be displayed.
 * @param left  - Left index of the array to be displayed.
 * @param right  - Right index of the array to be displayed.
 */
void display(const string & text, const char arr[],
             const int left, const int right) {
    cout << text << "\t";
    for (int i = left;  i <= right;  i++)
        cout << arr[i];
    getchar();                            // Wait for user input
}

/**
 * Partitions the array into two halves based on a pivot element.
 *
 * @param arr  -  Array to be partitioned.
 * @param left -  Left index of the array to be partitioned.
 * @param right -  Right index of the array to be partitioned.
 * @return  -  Index of the pivot element after partitioning.
 */
int partitions(char arr[], const int left, const int right) {
    if (right > left) {
        int i, j;
        char partitionElement = arr[right]; // Initializing partition element
        i = left-1;                //Minus 1 for 1-based indexing.
        j = right;                 //Rightmost index is the partition element.

        while (true) {
            while (arr[++i] < partitionElement) {} //Bigger or equal:
            while (arr[--j] > partitionElement) {} //Less or equal:
            if (i >= j)  break;         //  Condition for breaking the loop.
            change(arr[i], arr[j]);
        }

        change(arr[i], arr[right]);
        return i;     // Return the index of the partition element.
    }
    return 0;        // If no partitioning is needed, return 0.
}


/**
 * Quick Sort algorithm that sorts an array of characters.
 *
 * @param arr -  Array to be sorted.
 * @param left -  Left index of the array to be sorted.
 * @param right -  Right index of the array to be sorted.
 */
void quickSort(char arr[], const int left, const int right)  {
    if (right > left) {
        int index = partitions(arr, left, right);
        quickSort(arr, left, index-1);
        quickSort(arr, index+1, right);

    }
}
