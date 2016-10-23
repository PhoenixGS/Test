#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

int main(int tot, char **st)
{
	if (tot == 1)
	{
		printf("Please read!!\n");
		return 0;
	}
	st[1][strlen(st[1]) - 4] = '\0';
	string s = "";
	for (int i = 0; i < strlen(st[1]); i++)
		s += st[1][i];
	s = "g++ -o " + s + ".exe " + s + ".cpp -g";
	char sss[10000];
	for (int i = 0; i < s.length(); i++)
		sss[i] = s[i];
	if (system(sss) != 0)
	{
		printf("Compiler error!\n");
		return 0;
	}
	printf("Compiler successful\n");
	freopen("mode", "r", stdin);
	int mode;
	scanf("%d", &mode);
	fclose(stdin);
	if (mode == 0)
	{
	    char ssss[1000];
        //strcat(ssss, "Run.exe ");
        strcat(ssss, "cmd /c start Run.exe ");
        strcat(ssss, st[1]);
        //strcat(ssss, ".exe < input < ENTER");
        strcat(ssss, ".exe");
        //printf("%s\n", ssss);
        system(ssss);
        //double pred = (double)clock() / CLOCKS_PER_SEC;
        //printf("Error : %d   ", system(ssss));
        //double now = (double)clock() / CLOCKS_PER_SEC;
        //printf("Time : %.6fs\n", now - pred);
	}
	if (mode == 1)
    {
	    char ssss[1000];
        strcat(ssss, st[1]);
        strcat(ssss, ".exe < input");
        double pred = (double)clock() / CLOCKS_PER_SEC;
        printf("Error : %d   ", system(ssss));
        double now = (double)clock() / CLOCKS_PER_SEC;
        printf("Time : %.6fs\n", now - pred);
    }
	if (mode == 2)
    {
	    char ssss[1000];
        strcat(ssss, st[1]);
        strcat(ssss, ".exe < input > output");
        double pred = (double)clock() / CLOCKS_PER_SEC;
        printf("Error : %d   ", system(ssss));
        double now = (double)clock() / CLOCKS_PER_SEC;
        printf("Time : %.6fs\n", now - pred);
    }
	return 0;
}
