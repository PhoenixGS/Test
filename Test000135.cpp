//head
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <set>

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

multiset<int> Sx, Sy;
multiset<int>::iterator it, it2;
long long ans;

int main()
{
    int _ = read();
    while (_--)
    {
        int kk = read(), x = read();
        if (! kk)
        {
            if (Sy.size() == 0)
            {
                Sx.insert(x);
            }
            else
            {
                it = Sy.lower_bound(x);
                if (it == Sy.begin())
                {
                    ans = mo(ans + abs(*it - x), 1000000);
                    Sy.erase(it);
                }
                else
                {
                    it2 = it;
                    it2--;
                    if (it == Sy.end())
                    {
                        ans = mo(ans + abs(*it2 - x), 1000000);
                        Sy.erase(it2);
                    }
                    else
                    {
                        if (abs(*it2 - x) <= abs(*it - x))
                        {
                            ans = mo(ans + abs(*it2 - x), 1000000);
                            Sy.erase(it2);
                        }
                        else
                        {
                            ans = mo(ans + abs(*it - x), 1000000);
                            Sy.erase(it);
                        }
                    }
                }
            }
        }
        else
        {
            if (Sx.size() == 0)
            {
                Sy.insert(x);
            }
            else
            {
                it = Sx.lower_bound(x);
                if (it == Sx.begin())
                {
                    ans = mo(ans + abs(*it - x), 1000000);
                    Sx.erase(it);
                }
                else
                {
                    it2 = it;
                    it2--;
                    if (it == Sx.end())
                    {
                        ans = mo(ans + abs(*it2 - x), 1000000);
                        Sx.erase(it2);
                    }
                    else
                    {
                        if (abs(*it2 - x) <= abs(*it - x))
                        {
                            ans = mo(ans + abs(*it2 - x), 1000000);
                            Sx.erase(it2);
                        }
                        else
                        {
                            ans = mo(ans + abs(*it - x), 1000000);
                            Sx.erase(it);
                        }
                    }
                }
            }
        }
    }
    cout << mo(ans, 1000000) << endl;
    return 0;
}
