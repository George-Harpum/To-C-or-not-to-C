#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// I know this is super ugly but I wanted to play around with pointers so that was my priority.

typedef struct ArrayPtrAndSize {
    int* ptr;
    int size;
} ptrSize_arr;
ptrSize_arr sieve(int n);


int main() {
    int n = 25;
    ptrSize_arr a = sieve(n);
    int* ptr = a.ptr;
    int size = a.size;
    if (ptr) {
        printf("[%d", ptr[0]);
        for (int i=1;i<size;i++) {
            printf(" %d,", ptr[i]);
        }
        printf("]");
        free(ptr);
    }
    return 0;
}

ptrSize_arr sieve(int n) {
    if (n <= 0) {
        printf("n must be an element of N+");
        ptrSize_arr null_out = {NULL, NULL};
        return null_out;
    }
    int count = 0;
    int *temp = malloc(sizeof(int) * n);
    temp[0] = false;
    temp[1] = false;
    for (int i=2; i<n; i++) {
        temp[i] = true;
    }
    for (int i=2;i*i<n;i++) {
        if (temp[i] == true) {
            for (int j=i*i;j<n;j=j+i) {
                temp[j] = false;
            }
        }
    }
    for (int i=0;i<n;i++) { 
        if (temp[i] == true) {
            count++;
        }
    }
    int *out_arr = malloc(count);
    if (out_arr) {
        int i = 0;
        for (int j=0;j<n;j++) {
            if (temp[j] == true) {
                out_arr[i] = j;
                i++;
            }
        }
    }
    free(temp);
    ptrSize_arr out = {out_arr, count};
    return out;
}
