#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    map<string, int> Map;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        string st;
        cin >> st;
        sort(st.begin(), st.end());
        printf("%d\n", Map[st]);
        Map[st]++;
    }
    return 0;
}
