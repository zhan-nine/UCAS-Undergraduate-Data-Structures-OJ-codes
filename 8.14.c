//from Xuzhiyuan
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMB 100
#define MAX_BUF 100

int emb[MAX_EMB][MAX_EMB];

void process_input() {
    char buf[MAX_BUF];
    
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        int a[MAX_BUF] = {0};
        int n = 0;
        char *token = strtok(buf, " ");
        
        while (token != NULL) {
            a[n++] = atoi(token);
            token = strtok(NULL, " ");
        }
        
        int size = a[0];
        for (int i = 1; i < n; i++) {
            emb[size][++emb[size][0]] = a[i];
        }
    }
}

void merge_blocks() {
    for (int b = 0; b < 20; b++) {
        for (int i = 1; i <= emb[b][0]; i++) {
            for (int j = 1; j <= emb[b][0]; j++) {
                if (emb[b][i] + (1 << b) == emb[b][j] && (emb[b][i] % (1 << (b + 1))) == 0) {
                    int temp[MAX_BUF] = {0};
                    for (int k = 1; k <= emb[b][0]; k++) {
                        if (k != i && k != j) {
                            temp[++temp[0]] = emb[b][k];
                        }
                    }
                    emb[b + 1][++emb[b + 1][0]] = emb[b][i];
                    for (int k = 0; k < MAX_BUF; k++) {
                        emb[b][k] = temp[k];
                    }
                    b--;
                    goto next_iteration;
                }
            }
        }
        next_iteration:;
    }
}

void sort_blocks() {
    for (int i = 0; i < 20; i++) {
        if (emb[i][0] != 0) {
            for (int t1 = 1; t1 <= emb[i][0]; t1++) {
                for (int t2 = 1; t2 < emb[i][0]; t2++) {
                    if (emb[i][t2] > emb[i][t2 + 1]) {
                        int temp = emb[i][t2];
                        emb[i][t2] = emb[i][t2 + 1];
                        emb[i][t2 + 1] = temp;
                    }
                }
            }
        }
    }
}

void print_blocks() {
    for (int i = 0; i < 20; i++) {
        if (emb[i][0] != 0) {
            printf("%d", i);
            for (int j = 1; j <= emb[i][0]; j++) {
                printf(" %d", emb[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    process_input();
    merge_blocks();
    sort_blocks();
    print_blocks();
    return 0;
}
