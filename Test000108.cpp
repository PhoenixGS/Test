#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int X[2000000];
int Y[2000000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dis[1005][1005];
int x[1005][1005];
bool flag[1005][1005];

bool check(int T_T)
{
    memset(flag, 0, sizeof(flag));
    int head = 0;
    int tail = 0;
    X[head] = 1;
    Y[head] = 1;
    while (head <= tail)
    {
        for (int k = 0; k < 4; k++)
        {
            int xx = X[head] + dx[k];
            int yy = Y[head] + dy[k];
            if (xx >= 0 && xx <= n && yy >= 0 && yy <= m && dis[xx][yy] >= T_T && ! flag[xx][yy])
            {
                flag[xx][yy] = true;
                tail++;
                X[tail] = xx;
                Y[tail] = yy;
                if (xx == n && yy == m)
                {
                    return true;
                }
            }
        }
        head++;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &x[i][j]);
            dis[i][j] = 1000000000;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i][j] == 1)
            {
                int head = 0;
                int tail = 0;
                X[head] = i;
                Y[head] = j;
                dis[i][j] = 0;
                while (head <= tail)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int xx = X[head] + dx[k];
                        int yy = Y[head] + dy[k];
                        if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dis[xx][yy] > dis[X[head]][Y[head]] + 1)
                        {
                            dis[xx][yy] = dis[X[head]][Y[head]] + 1;
                            tail++;
                            X[tail] = xx;
                            Y[tail] = yy;
                        }
                    }
                    head++;
                }
            }
        }
    }
    int l = 0;
    int r = n * m;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1; 
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
