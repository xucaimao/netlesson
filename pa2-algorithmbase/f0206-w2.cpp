#include <iostream> 
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#define rep(i,m,n) for(i=m;i<=n;i++)
#define rsp(it,s) for(set<int>::iterator it=s.begin();it!=s.end();it++)
const int inf_int = 2e9;
const long long inf_ll = 2e18;
#define inf_add 0x3f3f3f3f
#define mod 1000000007
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1.0)
#define pii pair<int,int>
#define Lson L, mid, rt<<1
#define Rson mid+1, R, rt<<1|1
const int maxn=5e2+10;
using namespace std;

int main()
{
   char map[300][200];
   char s[10];
   int n,l,f,x;
   freopen("f0206.in","r",stdin);
  while(1)
  {
   memset(map,' ',sizeof(map));//初始化
   x=1;
   cin>>n;
   getchar();
   gets(s);
   if(n==0) return 0;
   l=strlen(s);
   for(int i=0;i<l;i++)    //不同的数字用不同的存储方法，将相应的字符存入map二维字符数组中
   {
      f=s[i]-'0';       
      if(f==0)
      {
            for(int j=x+1;j<x+n+1;j++)
            map[1][j]=map[2*n+3][j]='-';
            for(int j=2;j<2*n+3;j++)
            {
                if(j!=2+n)
                map[j][x]=map[j][x+n+1]='|';
            }
         x=x+3+n;   
      }
      else if(f==1)
      {
           for(int j=2;j<2*n+3;j++)
           {
             if(j!=2+n)
             map[j][x+n+1]='|';
           }
        x=x+3+n;     
      }
      else if(f==2)
      {
             for(int j=2;j<=n+1;j++)
             map[j][x+n+1]='|';
             for(int j=3+n;j<2*n+3;j++)
             map[j][x]='|';
             for(int j=x+1;j<x+n+1;j++)
             map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
             x=x+3+n;  
       } 
       else if(f==3)
       {
             for(int j=x+1;j<x+n+1;j++)
             map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
             for(int j=2;j<2*n+3;j++)
             {
             if(j!=2+n)
             map[j][x+n+1]='|';
             }
              x=x+3+n; 
       }
       else if(f==4)
       {
           for(int j=x+1;j<=x+n;j++)
             map[2+n][j]='-';
             for(int j=2;j<2*n+3;j++)
             {
             if(j!=2+n)
             map[j][x+n+1]='|';
             }
             for(int j=2;j<=n+1;j++)
             map[j][x]='|';
              x=x+3+n;
       }
       else if(f==5)
       {
           for(int j=x+1;j<x+n+1;j++)
            map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
            for(int j=2;j<=1+n;j++)
            map[j][x]='|';
            for(int j=3+n;j<2*n+3;j++)
            map[j][x+n+1]='|';
             x=x+3+n;
       }
       else if(f==6)
       {
          for(int j=2;j<2*n+3;j++)
           {
             if(j!=2+n)
             map[j][x]='|';
           }
          for(int j=3+n;j<2*n+3;j++)
            map[j][x+n+1]='|';
           for(int j=x+1;j<x+n+1;j++)
            map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
             x=x+3+n;
       }
       else if(f==7)
       {

            for(int j=x+1;j<x+n+1;j++)
            map[1][j]='-';
           for(int j=2;j<2*n+3;j++)
           {
             if(j!=2+n)
             map[j][x+n+1]='|';
           }
           x=x+3+n;  
       }
       else if(f==8)
       {
            for(int j=2;j<2*n+3;j++)
            {
                if(j!=2+n)
                map[j][x]=map[j][x+n+1]='|';
            }
             for(int j=x+1;j<x+n+1;j++)
            map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
             x=x+3+n;
       }
       else if(f==9)
       {
            for(int j=2;j<=n+1;j++)
             map[j][x]='|';
           for(int j=2;j<2*n+3;j++)
           {
             if(j!=2+n)
             map[j][x+n+1]='|';
           }
            for(int j=x+1;j<x+n+1;j++)
            map[1][j]=map[2+n][j]=map[2*n+3][j]='-';
             x=x+3+n;
       }
   }
   for(int i=1;i<=2*n+3;i++)  //输出
   {
      for(int j=1;j<=x;j++)
      printf("%c",map[i][j]);
      printf("\n");
   }
   cout<<endl;
  }
   return 0;
}