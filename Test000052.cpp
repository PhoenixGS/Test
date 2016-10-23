#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int In[300];
vector<int> vet[300];
deque<int> que;

//输入一个n个点的有向无环图 输出它的拓扑排序
//vector<int> vet[300] 表示边表信息
//int In[300] 表示每个点的入度
//deque<int> que 表示宽搜队列 入度为0的点入队列

void topsort()
{
	for (int i = 0; i < n; i++)
	{
		if (In[i] == 0)
		{
			que.push_back(i);
		}
	}
    while (! que.empty())
    {
        int u = que.front();
		cout << u << endl; //访问u的顺序即为拓扑序
        que.pop_front();
        for (int j = 0; j < vet[u].size(); j++)
        {
            int v = vet[u][j];
            In[v]--;
            if (In[v] == 0)
            {
                que.push_back(v);
            }
        }
    }
}
