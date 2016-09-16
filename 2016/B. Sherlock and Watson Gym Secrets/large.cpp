#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

typedef long long ll;
const int MaxK = 100000;
const int MaxMod = 1000000007;
vector<ll> modA(MaxK, 0);
vector<ll> modB(MaxK, 0);
vector<ll> htA(MaxK, 0);
vector<ll> htB(MaxK, 0);

ll powerMod(ll a, ll b, ll c) {
  int ans = 1;
  a = a % c;
  while (b) {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b / 2;
    a = (a * a) % c;
  }
  return ans % c;
}

int main() {
	freopen("B-large-practice.in","r",stdin);
//	freopen("results/B-large-practice.out","w",stdout);
  int num;
  cin >> num;

  for (int i = 1; i <= num; i++) {
    ll a, b, n, k;
    cin >> a >> b >> n >> k;

    for (int i = 0; i < k; i++) {
      htA[i] = htB[i] = 0;
    }

    ll ee = 0;
    ll times = n / k;
    int les = n % k;

    for (int i = 0; i < k; i++) {
      modA[i] = powerMod(i, a, k);
      modB[i] = powerMod(i, b, k);
      htA[modA[i]]++;
      htB[modB[i]]++;
      if ((modA[i] + modB[i]) % k == 0) 
        ee++;
    }

    for (int i = 0; i < k; i++) {
      htA[i] *= times;
      htA[i] %= MaxMod;
      htB[i] *= times;
      htB[i] %= MaxMod;
    }

    ee *= times;
    ee %= MaxMod;

    for (int i = 1; i <= les; i++) {
      htA[modA[i]]++;
      htB[modB[i]]++;
      if ((modA[i] + modB[i]) % k == 0) ee++;
    }
    
    ll sum = 0;
    for (int i = 0; i < k; i++) {
      sum += (htA[i] * htB[(k - i) % k]) % MaxMod;
      sum %= MaxMod; 
    }
    sum = (sum - ee + MaxMod) % MaxMod;
    cout << "case #" << i << ": " << sum << endl;
  
    
  // do something useful with v
  }

  return 1;
}
