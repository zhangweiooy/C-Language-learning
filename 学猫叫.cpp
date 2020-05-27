#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int flag[105] = { 0 };
	int n, m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	vector<int>map[105];
	while (m--)
	{
		int tem1, tem2;
		scanf("%d%d", &tem1, &tem2);
		map[tem1].push_back(tem2);
		map[tem2].push_back(tem1);
	}
	flag[s] = 1;
	int temp[105];
	while (t--)
	{
		for (int i = 0; i < n; i++)
			temp[i] = 0;
		for(int i=0;i<n;i++)
			if (flag[i] > 0)
			{
				for (int j = 0; j < map[i].size(); j++)
					temp[map[i][j]] += flag[i];
			}
		for (int i = 0; i < n; i++)
		{
			flag[i] = temp[i];
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += flag[i];
	printf("%d\n", sum);
	return 0;
}

