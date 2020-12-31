#include <iostream>
#include <chrono>
#include <vector>
#define MAX_ARRAY 10000

int arrays[MAX_ARRAY];

void swapper(int* a, int* b)  
{  
    int temporary = *a;  
    *a = *b;  
    *b = temporary;  
}  

/*  
    * Last Element = pivot
    * left = less than pivot
    * right = more than pivot
*/
int partition (int low, int high)  
{  
    int pivot = arrays[high]; // pivot (last element) 
    int i = (low - 1); // Index of smaller element, starting from position -1.

    
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arrays[j] < pivot)  
        {  
            i++; // increment index of smaller element  
            swapper(&arrays[i], &arrays[j]);  //swap the array between the low and the high (starting from high - 1)
        }  
    }  
    swapper(&arrays[i + 1], &arrays[high]); //positioning the pivot into its position
    return (i + 1); //returning the pivot.
}  


void quicksort(int low, int high)  
{  
    if (low < high)  
    {  
        //pi stands for partition index, so that we can divide the array into two different sections.
        int pi = partition(low, high);  


        quicksort(low, pi - 1);  //before partition
        quicksort(pi + 1, high);  //after partition
    }  
}  

void showArray(int max)  
{  
    int start;  
    for (start = 0; start < max; start++)  
    {
        if (start == max - 1)
        {
            printf("%d\n", arrays[start]);
        }
        else
        {
        printf("%d, ", arrays[start]);
        }
    }
}  

int main()  
{  
    int max;
    int start = 0;
    int low = 0;
    printf ("Enter the amount of data to insert to the array\n");
    scanf ("%d", &max);

    printf ("Enter the data you want to insert\n");
    for (start = 0; start < max; start ++)
    {
        scanf ("%d", &arrays[start]);
    }

    auto t_start = std::chrono::high_resolution_clock::now();//starting the timer

    quicksort (low, max - 1);
    printf("Sorted array:\n");
    showArray (max);
    
    auto t_stop = std::chrono::high_resolution_clock::now();//stopping the timer


    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t_stop - t_start); //subtract the result from the stop and the start.

    printf("Quick Sort Algorithm\n");//giving an information to the user about the program algorithm
    printf("Time taken to sort the array: %d microseconds\n", duration.count());//showing the result to the user.

    return 0;
}  
