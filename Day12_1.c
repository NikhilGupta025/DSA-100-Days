#include<stdio.h>
int main(){
    int n;
    printf("enter the rows of matrix:");
    scanf("%d",&n);
    int m;
    printf("enter the rows of column:");
    scanf("%d",&m);
    int arr[n][m];
    int trans[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        scanf("%d",&arr[i][j]);
    }
}    
   for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        trans[j][i]=arr[i][j];
    }
}  
for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        printf("%d ",trans[i][j]);
    }
    printf("\n");
}
int null=0;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){

        if(arr[i][j]==trans[i][j]){
            null=1;
        }
        else{
            null=0;
        }
    }
}
if(null==1){
    printf("symmetric matrix");
}
else{
    printf("not symmetric");
}
return 0;
}