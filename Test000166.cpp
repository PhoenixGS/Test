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

char T[2000], P[2000];
int f[2000];

void getFail(char* P, int* f)
{
    int m = strlen(P);
    f[0] = 0;
    f[1] = 0;
    rep(i, 1, m - 1)
    {
        int j = f[i];
        while (j && P[i] != P[j])
        {
            j = f[j];
        }
        f[i + 1] = P[i] == P[j] ? j + 1 : 0;
    }
}

void find(char* T, char* P, int* f)
{
    int n = strlen(T);
    int m = strlen(P);
    getFail(P, f);
    int j = 0;
    rep(i, 0, n - 1)
    {
        while (j && P[j] != T[i])
        {
            j = f[j];
        }
        if (P[j] == T[i])
        {
            j++;
        }
        if (j == m)
        {
            printf("%d\n", i - m + 1);
        }
    }
}

int main()
{
    scanf("%s", T);
    scanf("%s", P);
    find(T, P, f); 
    return 0;
}
