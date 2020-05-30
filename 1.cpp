#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<cmath>
using namespace std;
//输入
//4
//1 6 2 3
//4 32 3 4
//2 1 1 2
//1 2147483647 1 4

//输出
//5
//8
//0
//31
typedef long long ll;
int main()
{
	int num;
	cin >> num;
	vector<int> res;
	ll n; ll m; int w2; int w3;
	for (int i = 0; i < num; i++)
	{
		cin >> n >> m >> w2 >> w3;
		if (n >= m)
		{
			res.push_back(0);
			continue;
		}
		double k2 = double(w2) / 2;
		double k3 = double(w3) / 3;
		int cnt = 0;
		if (k2 < k3)
		{
			while (n < m)
			{
				n = n * 2;
				cnt+=w2;
			}
			int tmp = cnt;
			cnt = cnt - w2-w2;
			n = n / 4;
			if (n * 3 >= m)
				cnt+=w3;
			res.push_back(max(tmp, cnt));
		}
		else
		{
			while (n < m)
			{
				n = n * 3;
				cnt+=w3;
			}
			int tmp = cnt;
			n = n / 3;
			cnt=cnt-w3;
			if (n * 2 >= m)
				cnt += w2;
			res.push_back(max(tmp, cnt));
		}
	}
	for (int i = 0; i < res.size()-1; i++)
	{
		cout << res[i] << endl;
	}
	cout << res.back();
	return 0;
}
