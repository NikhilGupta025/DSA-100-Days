//Implement linear search to find key k in an array. Count and display the number of comparisons performed

#include<stdio.h>
int main() {
    int a[100];
    int n,value;
    int index=0, comp=1;

    scanf("%d",&n);
    printf("Enter the data: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
    }

    for( int i=0; i<n; i++) {
        printf("%d", a[i]);
        printf(" ");
    }
    printf("\nEnter value: ");
    scanf("%d", &value);

    for( int i=0; i<n; i++) {
        if ( a[i] == value)
        {
            printf("Found at index %d", index);
            printf("\nComparisons = %d", comp);
        }
        else {
            printf("Not Found");
            return 0;
        }
        index++;
        comp++;
    }
    
    return 0;
}