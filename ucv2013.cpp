#include <iostream>
using namespace std;
long long Bmode(int x, int p, int m)
{
	long long tempo;
	if (p == 0)
		return 1;
	if (p % 2 == 0)
	{
		tempo = Bmode(x, p / 2, m);
		return (tempo*tempo) % m;

	}

	else
		return (Bmode(x, p - 1, m)*(x%m)) % m;
}
int main()
{
	int t, n,l;
	long long m;
	while (1)
	{
		cin >> n;
		cin >> l;
		if (n == 0 && l == 0)
			break;
		m = 0;
		for (int i = 1; i <= l; i++)
		{
			m = (m + Bmode(n, i, 1000000007)) % 1000000007;
		}
		cout <<  m << endl;
	}
}
