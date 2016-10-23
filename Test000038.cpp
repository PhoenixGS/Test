#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
char p[2000000];
char s[2000000];
int next[2000000];

int find(int x, char ch)
{
	if (p[x + 1] == ch)
	{
		return x + 1;
	}
	if (x == 0)
	{
		return 0;
	}
	return find(next[x], ch);
}

int main()
{
	scanf("%s", p + 1);
	scanf("%s", s + 1);
	n = strlen(p + 1);
	m = strlen(s + 1);
	next[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		next[i] = find(next[i - 1], p[i]);
	}
	int t = 0;
	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		t = find(t, s[i]);
		if (t == n)
		{
			ans++;
			t = next[t];
		}
	}
	cout << ans << endl;
	return 0;
}
