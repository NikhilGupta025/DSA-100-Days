#include <stdio.h>
int main() {
    int n1,n2;
    scanf("%d %d",&n1,&n2);
     int arr1[n1];
    printf("Enter array 1: ");
    for(int i=0; i<n1; i++) {
        scanf("%d",&arr1[i]);
    }
    int arr2[n2];
    printf("Enter array 2: ");
    for(int j=0; j<n2; j++) {
        scanf("%d", &arr2[j]);
    }
    printf("Intersection : ");
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {
            if(arr1[i] == arr2[j]) {
                printf("%2d",arr1[i]);
                break;
        }
    }
}
    printf("\n");
    return 0;
}