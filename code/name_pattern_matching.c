#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char pattern[100];
    printf("Enter the name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0; // Remove trailing newline
    printf("Enter the pattern to search: ");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = 0; // Remove trailing newline
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