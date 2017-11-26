#include <cstdio>
#include <cstring>   
   
int n,ind;  
bool row[12],dia1[25],dia2[25];  
int ans[96][10];//ans[92][8]  
int res[96];  
  
void Dfs(int q)  
{     
    if(q>8)  
    {  
        ind++;  
        for(int i=1;i<=8;i++)  
            ans[ind][i]=ans[ind-1][i];  
        return;  
    }  
      
    for(int r=1;r<=8;r++)  
    {  
        if(row[r]&&dia1[r+q]&&dia2[8-q+r])  
        {  
            row[r]=dia1[r+q]=dia2[8-q+r]=false;  
            ans[ind][q]=r;  
            Dfs(q+1);  
            row[r]=dia1[r+q]=dia2[8-q+r]=true;  
        }  
    }  
}  
  
int main()  
{  
   memset(row,true,sizeof(row));  
   memset(dia1,true,sizeof(dia1));  
   memset(dia2,true,sizeof(dia2));  
   ind=1;  
   Dfs(1);  
     
   scanf("%d",&n);  
     
   int i,x;  
   while(n--)  
   {  
        scanf("%d",&x);  
        for(i=1;i<=8;i++)  
            printf("%d",ans[x][i]);  
        printf("\n"); 
   }  
}