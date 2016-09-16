#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;

const long long MODM = 1000000007;
const int N = 100000 +10;

long long ans, m, n, x, y;
long long cnt[N];

int nowtd, tdnum;

long long pow(long long a, long long x, long long m)
{
	if (x == 0) return 1 % m;
	long long result = pow(a, x / 2, m);
	result = (result * result) % m;
	if (x % 2 == 1) result = (result * a) % m;
	return result;
}

long long f(long long x, long long n, long long m)
{
	long long result = n / m;
	if (n % m >= x) result++;
	if (x == 0) result--;
	return result % MODM;
}

int main()
{
  ifstream infile("b-large-practice.in");
///  if (!infile.is_open()) cout << "no such file!" << endl;
  string line;
  int tdnum;
  getline(infile, line);
  istringstream(line) >> tdnum;

	for (nowtd = 1; nowtd <= tdnum; nowtd++)
	{
		ans = 0;
		memset(cnt, 0, sizeof(cnt));
    getline(infile, line);
    istringstream iss(line);

		iss >> x >> y >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int j = pow(i, y, m);
			cnt[j] += f(i, n, m);
			cnt[j] %= MODM;
		}
		for (int i = 0; i < m; i++)
		{
			int j = pow(i, x, m);
			if (j == 0) j = m;
			ans += f(i, n, m) * cnt[m - j];
			ans %= MODM;
			if ((pow(i, x, m) + pow(i, y, m)) % m == 0) ans = ((ans + MODM - f(i, n, m)) % MODM + MODM) % MODM;
		}
		cout << "Case #" << nowtd << ": " << ans << endl;
	}
	return 0;
}
