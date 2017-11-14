//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题-3 Have Fun with Numbers
//write by xucaimao ;20171108-12:00
/*
重点是要考虑9位数乘2后变成10位
乘法运算的规则，先乘再加进位
注意出现的数字集合要一样，且每个数字的个数也要一样

Yes的满足条件：
输入的数before的所有位数字的计数与乘2以后得到的数after所有位数字的计数相同。

反之，No的满足条件：
1.after位数比before更大
2.after中并不能找到before的所有数字
3.after和before的相同数字的个数不一致
*/
#include<cstdio>
#include<cstring>
const int maxn=25;
char s[maxn];
int st[10]={0};//记录是个数字字符的使用情况
int dt[10]={0};

int main(){
  scanf("%s",s);
  int len=strlen(s);
  int n=0,inc=0;
  for(int i=len-1;i>=0;i--){
    n=s[i]-'0';
    st[n]++;//记录输入数据中使用的字符
    int n1=n*2+inc;//重点
    inc=n1/10;
    n=n1%10;
    s[i]='0'+n;
    dt[n]++;//记录输出数据中使用的字符
  }

  int ok=1;
  if(inc>0) ok=0;//最高位运算后有进位，超出原有整数的位数了
  if(ok){
    for(int i=0;i<10;i++)
    if(st[i]!=dt[i]) {ok=0;break;}
  }
  
  if(ok)printf("Yes\n");
  else printf("No\n");
  if(inc>0)printf("%d",inc);
  printf("%s\n",s);
  return 0;
}