#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
int main(){  
    freopen("f0206.in","r",stdin);
    int i,j,k;  
    char n1[11]="- -- -----";  
    char n2[11]="|   ||| ||";  
    char n3[11]="|||||  |||";  
    char n4[11]="  ----- --";  
    char n5[11]="| |   | | ";  
    char n6[11]="|| |||||||";  
    char n7[11]="- -- -- --";  
    int s;  
    char n[20];  
    int num;  
    while(1){  
    scanf("%d %s",&s,n);  
    if(s==0)break;  
    int l=strlen(n);  
    for(i=0;i<l;i++)  
    {num=n[i]-'0';  
     printf(" ");  
       for(k=0;k<s;k++)  
           printf("%c",n1[num]);  
    printf("  ");}  
    printf("\n");  
    for(j=0;j<s;j++)  
    {  
    for(i=0;i<l;i++)  
    {num=n[i]-'0';  
     printf("%c",n2[num]);  
       for(k=0;k<s;k++)  
           printf(" ");  
      printf("%c ",n3[num]);  
     }  
      printf("\n");}  
    for(i=0;i<l;i++)  
    {num=n[i]-'0';  
     printf(" ");  
       for(k=0;k<s;k++)  
           printf("%c",n4[num]);  
    printf("  ");}  
    printf("\n");  
    for(j=0;j<s;j++)  
    {  
    for(i=0;i<l;i++)  
    {num=n[i]-'0';  
     printf("%c",n5[num]);  
       for(k=0;k<s;k++)  
           printf(" ");  
      printf("%c ",n6[num]);  
     }  
      printf("\n");}  
    for(i=0;i<l;i++)  
    {num=n[i]-'0';  
     printf(" ");  
       for(k=0;k<s;k++)  
           printf("%c",n7[num]);  
    printf("  ");}  
    printf("\n");  
    printf("\n");  
    }  
    return 0;
  }  