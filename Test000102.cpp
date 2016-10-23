#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<algorithm>
#define inf 1000000000
#define ll long long
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,K;
double ave;
int a[15][15];
int s[15][15];
double t[15][15][15][15][15];
double dfs(int a,int b,int c,int d,int k)
{
	double &res=t[a][b][c][d][k];
	if(res!=-1)return res;
	if(k==0)
	{
		res=s[b][d]+s[a-1][c-1]-s[a-1][d]-s[b][c-1];
		res=(res-ave)*(res-ave);
        printf("X%d %d %d %d %d %f\n", a, c, b, d, k, res);
		return res;
	}
	res=1e9;
	for(int i=a+1;i<=b;i++)
		for(int j=0;j<k;j++)
			res=min(res,dfs(a,i-1,c,d,j)+dfs(i,b,c,d,k-j-1));
	for(int i=c+1;i<=d;i++)
		for(int j=0;j<k;j++)
			res=min(res,dfs(a,b,c,i-1,j)+dfs(a,b,i,d,k-j-1));
    printf("%d %d %d %d %d %f\n", a, c, b, d, k, res);
	return res;
}
int main()
{
	n=read();m=read();K=read();
	for(int a=0;a<=10;a++)
		for(int b=0;b<=10;b++)
			for(int c=0;c<=10;c++)
				for(int d=0;d<=10;d++)
					for(int l=0;l<=10;l++)
						t[a][b][c][d][l]=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j],
	ave=(double)s[n][m]/K;
	dfs(1,n,1,m,K-1);
	printf("%.2lf\n",sqrt(t[1][n][1][m][K-1]/K));
	printf("%f\n", ave);
	printf("%d\n", s[n][m]);
	return 0;	
}
