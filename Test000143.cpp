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

int T[26][2] = { 2, 1,
                2, 2,
                2, 3,
                3, 1,
                3, 2,
                3, 3,
                4, 1,
                4, 2,
                4, 3,
                5, 1,
                5, 2,
                5, 3,
                6, 1,
                6, 2,
                6, 3,
                7, 1,
                7, 2,
                7, 3,
                7, 4,
                8, 1,
                8, 2,
                8, 3,
                9, 1,
                9, 2,
                9, 3,
                9, 4 };
int x[100];

int main()
{
    rep(i, 1, 9)
    {
        x[read()] = i;
    }
    char st[200];
    scanf("%s", st);
    int pre = -1;
    rep(i, 0, strlen(st) - 1)
    {
        int ch = T[st[i] - 97][0];
        int len = T[st[i] - 97][1];
        if (x[ch] == pre)
        {
            printf("#");
        }
        rep(j, 1, len)
        {
            printf("%d", x[ch]);
        }
        pre = x[ch];
    }
    printf("\n");
    return 0;
}
