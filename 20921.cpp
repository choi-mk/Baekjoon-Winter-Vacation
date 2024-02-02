#include <iostream>
using namespace std;

int main() {
    int n, k, changed_num=0;
    int original[4245], changed[4245]; 
    scanf("%d %d", &n, &k);
    
    for (int i=0; i<n; i++)
        original[i] = i + 1;

    for (int i=n-1; i>0; i--) {
        if (k >= i) {
            k -= i;
            original[i] = -1;
            changed[changed_num++] = i+1;
        }
    }

    for (int i=0; i<n; i++) {
        if (original[i] >= 0)
            changed[changed_num++] = original[i];
        printf("%d ", changed[i]);
    }
    printf("\n");

    return 0;
}