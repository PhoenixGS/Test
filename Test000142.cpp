#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

string s1;
int f[1000005][30];

int main()
{
    long long n;
    scanf("%lld",&n);
    cin>>s1;
    int len1=s1.length();
    int _;
    scanf("%d",&_);
    s1='@'+s1;
	memset(f,0,sizeof(f));
	for (int i=1; i<=len1; i++)
    {
		for (int j=0; j<26; j++)
            f[i][j]=f[i-1][j];
		f[i][s1[i]-65]++;
    }
    while (_--)
    {
        long long X; char s2[5];
        scanf("%lld ",&X);
        scanf("%s",s2);
        long long ans=0;
        long long A=(X * (X - 1) / 2) / len1;
        long long B=((X % len1) * ((X - 1) % len1)) / 2 % len1;
        long long C=(X * (X+1) / 2) / len1;
        long long D=((X % len1) *((X+1) % len1) / 2) % len1;
        printf("%lld %lld %lld %lld %lld %lld\n", (long long)len1, A, B, C, D, (X * (X+1) / 2) / len1);
        long long Y;
        if (D>=B)
        {
            Y=C-A;
        }
        else
        {
            Y=C-1-A;
        }
        if (B == 0)
        {
            B=len1;
            A--;
        }
        if (D == 0)
        {
            D=len1;
            C--;
        }
        printf("%d %d %d %d %d\n", A, B, C, D, Y);
        ans=Y*(f[len1][s2[0]-65]);
        if (D < B) ans+=f[len1][s2[0]-65]-f[B][s2[0]-65]+f[D][s2[0]-65];
        else ans+=f[D][s2[0]-65]-f[B][s2[0]-65];
        cout<<ans<<endl;
    }
}
