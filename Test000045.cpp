#include <cstdio>
#include <cstring>

bool flag[300000];
int head1[300000];
int vet1[300000];
int next1[300000];
int head2[300000];
int vet2[300000];
int next2[300000];
int headX[300000];
int vetX[300000];
int nextX[300000];
int que[300000];
int x[300000];
int y[300000];
int flagg[300000];
int Que[300000];
int Ans[300000];
int edgenum1;
int edgenum2;
int edgenumX;
int ans;
int ss, tt;

void add(int u, int v)
{
	edgenum1++;
	vet1[edgenum1] = v;
	next1[edgenum1] = head1[u];
	head1[u] = edgenum1;
}

void add2(int u, int v)
{
	edgenum2++;
	vet2[edgenum2] = v;
	next2[edgenum2] = head2[u];
	head2[u] = edgenum2;
}

void addX(int u, int v)
{
	edgenumX++;
	vetX[edgenumX] = v;
	nextX[edgenumX] = headX[u];
	headX[u] = edgenumX;
//	printf("%d %dX\n", u, headX[u]);
}


void bfs(int S)
{
	int headd = 0;
	int taill = 0;
	que[headd] = S;
	while (headd <= taill)
	{
		int now = head1[que[headd]];
		while (now)
		{
			if (flag[vet1[now]] == false)
			{
				flag[vet1[now]] = true;
				taill++;
				que[taill] = vet1[now];
			}
			now = next1[now];
		}
		headd++;
	}
}

int bfsX()
{
	int Head = 0;
	int Tail = 0;
	Que[Head] = ss;
	Ans[Head] = 0;
	while (Head <= Tail)
	{
		int now = headX[Que[Head]];
		while (now)
		{
			if (flagg[vetX[now]] == false)
			{
				flagg[vetX[now]] = true;
				Tail++;
				Que[Tail] = vetX[now];
				Ans[Tail] = Ans[Head] + 1;
				if (Que[Tail] == tt)
				{
					return Ans[Tail];
				}
			}
			now = nextX[now];
		}
		Head++;
	}
	return 1000000000;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	edgenum1 = 0;
	edgenum2 = 0;
	edgenumX = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		add(y[i], x[i]);
//		printf("XXX%d %d\n", x[i], y[i]);
	}
	scanf("%d%d", &ss, &tt);
	memset(flag, 0, sizeof(flag));
	flag[tt] = true;
	bfs(tt);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d %d\n", i, flag[i]);
//	}
	edgenum2 = 0;
	for (int i = 1; i <= m; i++)
	{
		add2(x[i], y[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		int ffflag = true;
		int now = head2[i];
		while (now)
		{
			if (flag[vet2[now]] == false)
			{
				ffflag = false;
				break;
			}
			now = next2[now];
		}
		if (ffflag == true)
		{
			int now = head1[i];
			while (now)
			{
				addX(vet1[now], i);
				now = next1[now];
			}
		}
	}
	memset(flagg, 0, sizeof(flagg));
	ans = bfsX();
	if (ans == 1000000000) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}
