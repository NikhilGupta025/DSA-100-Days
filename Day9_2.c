#include<stdio.h>
void revstr(char *s, int size) {
    int left = 0;
    int right = size - 1;

    while(left<right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}
int main() {
    char s[1000];
    int n;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++) {
    scanf("%c",&s[i]);
    }

int size = n;
revstr(s, size);

printf("Reverse string\n");
for(int i = 0; i<size; i++) {
    printf("%c", s[i]);
}
printf("\n");
return 0;
}