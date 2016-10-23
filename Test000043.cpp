#include <cstdio>
#include <iostream>

using namespace std;

int n, l;
int x[60000];
long long s[60000];
long long f[60000];
long long que[60000];
int head, tail;

long long g(int i)
{
	return s[i] + i;
}

long long h(int i)
{
	return s[i] + i + l + 1;
}

long long up(int j, int k)
{
	return f[j] - f[k] + h(j) * h(j) - h(k) * h(k);
}

long long down(int j, int k)
{
	return 2 * (h(j) - h(k));
}

long long calc(int i, int j)
{
	return f[j] + (g(i) - h(j)) * (g(i) - h(j));
}

int find(int i, int l, int r)
{
	if (l == r)
	{
		return l;
	}
	int mid = (l + r) / 2;
	if (calc(i, que[mid]) >= calc(i, que[mid + 1])) return find(i, mid + 1, r);
	else return find(i, l, mid);
}

/*
bool pd(int k,int j,int i)
{
return ((f[j]-f[k]+h(j)*h(j)-h(k)*h(k)*(2*h(i)-2*h(j)))>=((f[i]-f[j]+h(i)*h(i)-h(j)*h(j))*(2*h(j)-2*h(k))));
}
void add(int x)
{
++tail;
que[tail]=x;
while (tail - head + 1 >= 3 && pd(que[tail-2],que[tail-1],que[tail])) que[tail-1]=que[tail],--tail;
}*/



int main()
{
	scanf("%d%d", &n, &l);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &x[i]);
		s[i] = s[i - 1] + x[i];
	}
	head = 0;
	tail = 0;
	que[head] = 0;
	for (int i = 1; i <= n; i++)
	{
		int anss = find(i, head, tail);
		f[i] = calc(i, anss);
		printf("%d %d\n", anss, f[i]);
		/*add(i);*/
		while (tail - head >= 1 && up(que[tail - 1], que[tail]) * down(que[tail], i) >= up(que[tail], i) * down(que[tail - 1], que[tail]))
		{
			tail--;
		}
		tail++;
		que[tail] = i;
	}
	cout << f[n] << endl;
	return 0;
}
