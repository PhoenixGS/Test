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

int x[2000];
int F[2000];

int main()
{
    string st;
    cin >> st;
    int len = st.length();
    st = '#' + st;
    rep(i, 1, len)
    {
        x[i] = st[i] - 48;
    }
    int t = x[1] % 2;
    int T = 0;
    rep(i, 2, len)
    {
        if (x[i] % 2 != (i + t + 1) % 2)
        {
            F[i] = 1;
            if (T == 0)
            {
                if (x[i] == 9)
                {
                    T = -1;
                }
                if (x[i] == 0)
                {
                    T = 1;
                }
            }
        }
        //cout << i << " " << F[i] << endl;
    }
    if (T == -1 || T == 0)
    {
        bool FF = false;
        rep(i, 1, len)
        {
            if (F[i] == 1)
            {
                if (FF == false || x[i] == 9)
                {
                    printf("%d", x[i] - 1);
                    FF = true;
                }
                else
                {
                    printf("%d", x[i] + 1);
                }
            }
            else
            {
                printf("%d", x[i]);
            }
        }
    }
    if (T == 0)
    {
        printf(" ");
    }
    if (T == 1 || T == 0)
    {
        bool FF = false;
        rep(i, 1, len)
        {
            if (F[i] == 1)
            {
                if (FF == false || x[i] == 0)
                {
                    printf("%d", x[i] + 1);
                    FF = true;
                }
                else
                {
                    printf("%d", x[i] - 1);
                }
            }
            else
            {
                printf("%d", x[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
