#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

long long ss[1000005];
long long b[1000005];
char p[1000005];
char s[1000005];
int n, m;
long long T;
long long pp = 1637281495;

long long mo(long long a)
{
	if (a >= 0 && a < pp)
	{
		return a;
	}
	a %= pp;
	if (a < 0)
	{
		a += pp;
	}
	return a;
}

long long find(int l, int r)
{
	return mo(ss[r] - ss[l - 1] * b[r - l + 1]);
}

int main()
{
	scanf("%s", s + 1);
	scanf("%s", p + 1);
	n = strlen(p + 1);
	m = strlen(s + 1);
	long long stand = 0;
	T = 1;
	for (int i = 1; i <= m; i++)
	{
		T = T * 31 % 1637281495;
		stand = (stand * 31 + s[i]) % 1637281495;
//		cout << stand << endl;
	}
	b[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		b[i] = mo(b[i - 1] * 31);
	}
	ss[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		ss[i] = (ss[i - 1] * 31 + p[i]) % 1637281495;
//		cout << ss[i] << endl;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (find(i, i + m - 1) == stand)
		{
			ans++;
		}
//		cout << find(i, i + m - 1) << endl;
	}
	printf("%d\n", ans);
	return 0;
}
