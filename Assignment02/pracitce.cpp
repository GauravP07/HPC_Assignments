#include <stdio.h>
#include <omp.h>

int main() {
    int n = 10;
    int i;

    #pragma omp parallel for schedule(dynamic, 2)
    for (i = 0; i < n; i++) {
            printf("Iteration %d: Thread %d\n", i, omp_get_thread_num());
    }

    return 0;
}

