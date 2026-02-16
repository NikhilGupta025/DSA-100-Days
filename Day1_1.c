//Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.
#include<stdio.h>
int main() 
{
    int n,pos,value;
    int a[100];
    scanf("%d", &n);
for(int i=0; i<n; i++) 
{
    scanf("%d", &a[i]);
}
for(int i=0; i<n; i++) 
{
    printf("%d", a[i]);

printf(" "); 
}


printf("\nEnter position: ");
scanf("%d", &pos);
printf("Enter the value to insert: ");
scanf("%d", &value);

for(int i=n; i>pos; i--) 
{
    a[i] = a[i-1];
}

a[pos] = value;
n++;
for(int i=0; i<n; i++) 
{
    printf("%d", a[i]);
    printf(" ");
}
return 0;
}