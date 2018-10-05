#include "stdio.h"
#include "stdbool.h"
#include "time.h"
#include "stdlib.h"
#include "heapsort.h"

#define ARRAY_LEN (500000)
#define N_RUNS (100)

static int array[ARRAY_LEN];

static void randomize(int seed) {
    srand(seed);
    for (int i = 0; i < ARRAY_LEN; ++i) {
        array[i] = i;
    }
    for (int i = 0; i < ARRAY_LEN; ++i) {
        int j = random() % ARRAY_LEN;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

static bool is_sorted(int *array, size_t array_len) {
    for (int i = 0; i < array_len - 1; ++i) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    for (int seed = 0; seed < N_RUNS; ++seed) {
        randomize(seed);
        printf("Seed %d: ", seed);
        for (int i = 0; i < 10; ++i) {
            printf("%d, ", array[i]);
        }
        printf("-> ");
        simple_heapsort(array, ARRAY_LEN);
        for (int i = 0; i < 10; ++i) {
            printf("%d, ", array[i]);
        }
        printf("\n");
        if (!is_sorted(array, ARRAY_LEN)) {
            printf("Failed\n");
            exit(1);
        }
    }
}

