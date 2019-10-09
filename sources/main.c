#include <stdio.h> 
#include <stdlib.h> 
#include "../includes/malloc.h"
#include <unistd.h>

#define M (1024 * 1024)

void print(char *s) {
    write(1, s, strlen(s));
}

int main() 
{
//     int i;
//     char *addr;

//     i = 0;
//     while (i < 1024) {
//         addr= (char *)ft_malloc(1024);
//         addr[0] = 42;
//         ft_free(addr);
//         i++;
//     }
//     return 0;
    // ------------------------------
    // char *addr;

    // addr = ft_malloc(16);
    // ft_free(NULL);
    // ft_free((void *)addr + 5);
    // if (ft_realloc((void *)addr + 5, 10) == NULL) print("Bonjours\n");
    //-----------------------------------
  
    // char *malloc1 = (char *)ft_malloc(131);
    // ft_free(malloc1);
    // char *malloc2 = (char *)ft_malloc(4096*2);
    // char *malloc3 = (char *)ft_malloc(1000);
    // ft_free(malloc2);
    // ft_free(malloc3);
    // char *malloc4 = (char *)ft_malloc(200);
    // ft_free(malloc4);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // ft_free(malloc1);
    // show_alloc_mem();


    // char *malloc1 = (char *)ft_malloc(4);
    // malloc1 = (char *)ft_realloc(malloc1, 4096*3);
    // printf("%s", malloc1);
    // char *malloc2 = ft_calloc(2, 4096);
    // ft_free(malloc2);
    // ------------------------------------
    // int i;
    // char *addr;

    // i = 0;
    // while (i < 1024)
    // {
    //     addr = (char *)ft_malloc(1024);
    //     addr[0] = 42;
    //     ft_free(addr);
    //     i++;
    // }
    // ------------------------------------
    // char *addr1;
    // char *addr2;
    // char *addr3;

    // addr1 = (char *)ft_malloc(16*M);
    // strcpy(addr1, "Bonjours\n");
    // print(addr1);
    // addr2 = (char *)ft_malloc(16*M);
    // addr3 = (char *)ft_realloc(addr1, 128*M);
    // addr3[127*M] = 42;
    // print(addr3);
    // // ---------------------------------------
    char *addr1 = (char *)ft_malloc(10);
    char *addr3 = (char *)ft_malloc(504);
    char *addr4 = (char *)ft_malloc(3024);
    char *addr5 = (char *)ft_malloc(1024);
    char *addr6 = (char *)ft_malloc(1024);
    char *addr7 = (char *)ft_malloc(1024*32);
    char *addr8 = (char *)ft_malloc(1024*1024);
    char *addr9 = (char *)ft_malloc(1024*1024*16);
    char *addr10 = (char *)ft_malloc(1024*1024*128);
    char *addr11 = (char *)ft_malloc(1024*1024*128);
    char *addr12 = (char *)ft_malloc(1024*1024*128);
    char *addr13 = (char *)ft_malloc(1024*1024*128);
    char *addr14 = (char *)ft_malloc(1024*1024*128);
    char *addr15 = (char *)ft_malloc(1024*1024*128);
    ft_free(addr1);
    ft_free(addr3);
    ft_free(addr4);
    // ft_free(addr5);
    // ft_free(addr6);
    // ft_free(addr7);
    // ft_free(addr8);
    // ft_free(addr9);
    // ft_free(addr10);
    // ft_free(addr11);
    ft_free(addr12);
    ft_free(addr13);
    ft_free(addr14);
    ft_free(addr15);
    show_alloc_mem();
    return 0; 
} 