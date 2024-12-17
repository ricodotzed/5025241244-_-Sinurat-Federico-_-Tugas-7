#include <stdio.h>
#include <string.h>

void subsets_of_size(char *letters, int n, char *subset, int slenght, int start) {
    if (n == 0) {
        printf("{");
        for (int i = 0; i < slenght; i++) {
            printf("%c", subset[i]);
            if (i < slenght - 1) printf(", ");
        }
        printf("}\n");
        return;
    }

    int len = strlen(letters);
    for (int i = start; i < len; i++) {
        subset[slenght] = letters[i]; 
        subsets_of_size(letters, n - 1, subset, slenght + 1, i + 1);
    }
}


void one(char *letters) {
    printf("One-element subsets:\n");
    char subset[2] = {0}; 
    subsets_of_size(letters, 1, subset, 0, 0);
}


void two(char *letters) {
    printf("\nTwo-element subsets:\n");
    char subset[3] = {0}; 
    subsets_of_size(letters, 2, subset, 0, 0);
}

void three(char *letters) {
    printf("\nThree-element subsets:\n");
    char subset[4] = {0}; 
    subsets_of_size(letters, 3, subset, 0, 0);
}

int main() {
    
    char letters[101];
    scanf("%s", letters);
    
    one(letters);
    two(letters);
    three(letters);
    
    return 0;
}