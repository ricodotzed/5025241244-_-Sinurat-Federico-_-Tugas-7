#include <stdio.h>

int fx( int x ) {
    if ( x == 0 )
        return 0;
    return fx( x -1 ) + 2;
}

int main() {
    
    int x;
    printf("Enter Value : ");
    scanf("%d", &x);

    printf("%d", fx(x));
    
    return 0;
}