//head
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;

const double pi = acos(-1);

#define rep(i, a, n) for (int i = a; i <= n; i++)
#define per(i, n, a) for (int i = n; i >= a; i--)
#define Rep(i, u) for (int i = head[u]; i; i = next[i])
#define clr(a) memset(a, 0, sizeof a)
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

ld eps = 1e-9;
ll INF = 1000000007;
ll mo(ll a, ll pp) {if (a >= 0 && a < pp) return a; a %= pp; if (a < 0) a += pp; return a;}
ll powmod(ll a, ll b, ll pp) {ll ans = 1; for (; b; b >>= 1, a = mo(a * a, pp)) if (b & 1) ans = mo(ans * a, pp); return ans;}
ll lowbit(ll x) {return x & -x;}
ll read()
{
    ll ans = 0;
    char last = ' ', ch = getchar();
    while (ch < '0' || ch > '9') last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
    if (last == '-') ans = -ans;
    return ans;
}
//head

struct node
{
    int wx, wy, sx, sy;
};

node que[910000];
int x[100][100];
bool flag[31][31][31][31];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m, _;

int main()
{
    n = read();
    m = read();
    _ = read();
    rep(i, 1, n)
    {
        rep(j, 1, m)
        {
            x[i][j] = read();
        }
    }
    while (_--)
    {
        int wx = read(), wy = read(), sx = read(), sy = read(), tx = read(), ty = read();
        int H = 0;
        int T = 0;
        que[0] = (node){wx, wy, sx, sy};
        int now = 1;
        int HH = 0;
        int TT = 0;
        int ans = -1;
        memset(flag, 0, sizeof(flag));
        while (H <= T)
        {
            for (int i = 0; i < 4; i++)
            {
                node temp = que[H];
                int xx = temp.wx + dx[i];
                int yy = temp.wy + dy[i];
                if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && x[xx][yy] == 1)
                {
                    //printf("X%d %d %d %d %d %d\n", H, i, temp.wx, temp.wy, xx, yy);
                    node TT;
                    if (xx == temp.sx && yy == temp.sy)
                    {
                        TT = (node){xx, yy, temp.wx, temp.wy};
                    }
                    else
                    {
                        TT = (node){xx, yy, temp.sx, temp.sy};
                    }
                    if (TT.sx == tx && TT.sy == ty)
                    {
                        ans = now;
                        break;
                    }
                    if (flag[TT.wx][TT.wy][TT.sx][TT.sy] == false)
                    {
                        //printf("%d %d %d %d\n", TT.wx, TT.wy, TT.sx, TT.sy);
                        flag[TT.wx][TT.wy][TT.sx][TT.sy] = true;
                        T++;
                        que[T] = TT;
                    }
                }
                if (ans != -1)
                {
                    break;
                }
            }
            if (ans != -1)
            {
                break;
            }
            HH++;
            if (HH > TT)
            {
                TT = T;
                now++;
            }
            H++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
