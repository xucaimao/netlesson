#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 1025

int map[MAX][MAX]={0};    //枚举地图各点可清除垃圾数

/*垃圾点*/
struct Point{
    int x, y;    //坐标
    int m;    //垃圾数
}p[21];

int main(){
    int d, n;
    scanf("%d%d", &d, &n);
    for (int i = 0; i < n; i++)//读入垃圾数据
        scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].m);

    int ans = 0, np = 0;
    for (int i = 0; i < n; i++){//处理n组数据
        int sum = 0;
        for (int dx = p[i].x - d; dx <= p[i].x + d; dx++)
            if (dx >= 0 && dx < MAX){//防止越界
                for (int dy = p[i].y - d; dy <= p[i].y + d; dy++){
                    if (dy >= 0 && dy < MAX){//防止越界
                        map[dx][dy] += p[i].m;
                        /*refresh*/
                        if (ans < map[dx][dy])
                        {
                            ans = map[dx][dy];
                            np = 1;
                        }
                        else if (ans == map[dx][dy]) np++;
                    }
                }
            }
    }
    printf("%d %d\n", np, ans);
    
    return 0;
}