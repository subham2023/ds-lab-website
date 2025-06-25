#include <stdio.h>
#include <string.h>

int main() {
    char name[100] = "SUBHAM KUMAR";
    char pattern[100] = "KUMAR";
    int found = 0;
    int n = strlen(name);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (name[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Pattern found in the name.\n");
    else
        printf("Pattern not found in the name.\n");
    return 0;
} 