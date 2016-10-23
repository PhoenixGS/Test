#include <cstdio>
#include <iostream>

using namespace std;

int n;
int t[100000];

int main()
{
	t[1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		t[i] = 2 * t[i / 2] + 2 * i;
	}
	cout << t[n] << endl;
	return 0;
}
