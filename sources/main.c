#include <stdio.h> 
#include <stdlib.h> 
#include "../includes/malloc.h"

int main() 
{ 
  
    // This pointer will hold the 
    // base address of the block created 
    // int* ptr; 
    // int n, i, sum = 0; 
  
    // // Get the number of elements for the array 
    // n = 987654; 
    // printf("Enter number of elements: %d\n", n); 
  
    // // Dynamically allocate memory using malloc() 
    // ptr = (int*)ft_malloc(n * sizeof(int)); 
  
    // // Check if the memory has been successfully 
    // // allocated by malloc or not 
    // if (ptr == NULL) { 
    //     printf("Memory not allocated.\n"); 
    //     exit(0); 
    // } 
    // else { 
    //     // Memory has been successfully allocated 
    //     printf("Memory successfully allocated using malloc.\n"); 
  
    //     // Get the elements of the array 
    //     for (i = 0; i < n; ++i) { 
    //         ptr[i] = i + 1; 
    //     } 
    //     // Print the elements of the array 
    //     printf("The elements of the array are: "); 
    //     for (i = 0; i < n; ++i) { 
    //         // printf("%d, ", ptr[i]); 
    //     } 
    //     printf("%d", ptr[i]);
    // } 
  
    char *titi3 = (char *)ft_malloc(2500);
    // ft_free(titi3);
    char *titi4 = (char *)ft_malloc(2500);
    ft_free(titi4);
    char *titi5 = (char *)ft_malloc(1000);
    ft_free(titi3);
    ft_free(titi5);
    return 0; 
} 