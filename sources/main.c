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
    int i;
    char *addr;

    i = 0;
    while (i < 1024) {
        addr= (char *)malloc(1024);
        addr[0] = 42;
        free(addr);
        i++;
    }
    // show_alloc_mem();
    return 0;
    // ------------------------------
    // char *addr;

    // addr = malloc(16);
    // free(NULL);
    // free((void *)addr + 5);
    // if (realloc((void *)addr + 5, 10) == NULL) print("Bonjours\n");
    //-----------------------------------
  
    // char *malloc1 = (char *)malloc(131);
    // free(malloc1);
    // char *malloc2 = (char *)malloc(4096*2);
    // char *malloc3 = (char *)malloc(1000);
    // free(malloc2);
    // free(malloc3);
    // char *malloc4 = (char *)malloc(200);
    // free(malloc4);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // free(malloc1);
    // show_alloc_mem();


    // char *malloc1 = (char *)malloc(4);
    // malloc1 = (char *)ft_realloc(malloc1, 4096*3);
    // printf("%s", malloc1);
    // char *malloc2 = calloc(2, 4096);
    // free(malloc2);
    // ------------------------------------
    // int i;
    // char *addr;

    // i = 0;
    // while (i < 1024)
    // {
    //     addr = (char *)malloc(1024);
    //     addr[0] = 42;
    //     free(addr);
    //     i++;
    // }
    // ------------------------------------
    // char *addr1;
    // char *addr2;
    // char *addr3;

    // addr1 = (char *)malloc(16*M);
    // strcpy(addr1, "Bonjours\n");
    // print(addr1);
    // addr2 = (char *)malloc(16*M);
    // addr3 = (char *)realloc(addr1, 128*M);
    // addr3[127*M] = 42;
    // print(addr3);
    // // ---------------------------------------
    // char *addr1 = (char *)malloc(10);
    // char *addr3 = (char *)malloc(504);
    // char *addr4 = (char *)malloc(3024);
    // char *addr5 = (char *)malloc(1024);
    // char *addr6 = (char *)malloc(1024);
    // char *addr7 = (char *)malloc(1024*32);
    // char *addr8 = (char *)malloc(1024*1024);
    // char *addr9 = (char *)malloc(1024*1024*16);
    // char *addr10 = (char *)malloc(1024*1024*128);
    // char *addr11 = (char *)malloc(1024*1024*128);
    // char *addr12 = (char *)malloc(1024*1024*128);
    // char *addr13 = (char *)malloc(1024*1024*128);
    // char *addr14 = (char *)malloc(1024*1024*128);
    // char *addr15 = (char *)malloc(1024*1024*128);
    // show_alloc_mem();
    // free(addr1);
    // free(addr3);
    // free(addr4);
    // free(addr5);
    // free(addr6);
    // free(addr7);
    // free(addr8);
    // free(addr9);
    // free(addr10);
    // free(addr11);
    // free(addr12);
    // free(addr13);
    // free(addr14);
    // free(addr15);
    // show_alloc_mem();
    return 0; 
} 