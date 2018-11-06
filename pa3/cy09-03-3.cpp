#include<iostream>
#include<fstream>
#include<map>
#include<stdio.h>
using namespace std;

const int NMAX = 100005;

int main()
{
    int n,i,id,a,ido,ao,idx,ax;
    cin >> n;
    map<int,int> m;												// key: 实力; value: id
    m[1000000000] = 1;
    map<int,int>::iterator it;
    for (i=1; i<=n; i++)
    {
        cin >> id >> a;
        it = m.lower_bound(a);									// m中第一个key>=a的iterator, 如果没有则返回m.end()
        if (it==m.end()) {
            // a是m中最大的key
            it--;
            cout << id << " " << it->second << endl;
            m[a] = id;
        }
        else if (it->first==a) {
            // m的keyset已经有a
            cout << id << " " << it->second << endl;
            if (id < it->second)
                m[a] = id;
        }
        else {
            // m的keyset中不存在a且存在比a大的数
            if (it==m.begin())									// 比a还大的key是keyset中的最小值
            {
                cout << id << " " << it->second << endl;
            }
            else
            {
                ao = it->first;
                ido = it->second;
                ax = (--it)->first;
                idx = it->second;
                if (abs(ao-a) < abs(ax-a))
                {
                    cout << id << " " << ido << endl;
                }
                else if (abs(ao-a) > abs(ax-a))
                {
                    cout << id << " " << idx << endl;
                }
                else
                {
                    if (ido < idx)
                    {
                        cout << id << " " << ido << endl;
                    }
                    else
                    {
                        cout << id << " " << idx << endl;
                    }
                }
            }
            m[a] = id;
        }
    }
    return 0;
}

