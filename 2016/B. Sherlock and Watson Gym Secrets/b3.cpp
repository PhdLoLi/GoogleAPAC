#include <cstdio>
#include <cassert>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

typedef long long ll;
int a, b, k;
ll n;

const int kMaxK = 100000;
const int kMod = 1000000007;
int powa[kMaxK];
int powb[kMaxK];
int cnta[kMaxK];
int cntb[kMaxK];
int f[kMaxK + 1];
int g[kMaxK + 1];

int pow(int a, int b) {
    int res = 1 % k, tmp = a;
    while (b) {
        if (b & 1) res = (ll)res * tmp % k;
        b >>= 1;
        tmp = (ll)tmp * tmp % k;
    }
    return res;
}

inline void update(int &des, int src) {
    des += src;
    if (des >= kMod) {
        des -= kMod;
    }
}

int main() {
  ifstream infile("b-large-practice.in");
///  if (!infile.is_open()) cout << "no such file!" << endl;
  string line;
  int num;
  getline(infile, line);
  istringstream(line) >> num;

  for (int i = 1; i <= num; i++) {
    getline(infile, line);
    istringstream iss(line);
    int a, b, k;
    ll n;
    iss >> a >> b >> n >> k;
    cout << a << " " << b << " " << n << " " << " " << k << endl; 

       for (int i = 0; i < k; ++ i) {
            powa[i] = pow(i, a);
            powb[i] = pow(i, b);
        }
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        for (int i = 0; i < k; ++ i) {
            cnta[powa[i]] ++;
            cntb[powb[i]] ++;
        }
        int tmp0 = 0;
        int tmp1 = 0;
        for (int i = 0; i < k; ++ i) {
            tmp0 += cnta[(k - powb[i]) % k];
            tmp1 += cnta[(k - powb[i]) % k];
            if ((powa[i] + powb[i]) % k == 0) {
                -- tmp1;
            }
        }
        assert(tmp1 >= 0);
        int res = 0;
        update(res, (ll)(n / k) % kMod * ((n / k - 1) % kMod) % kMod * tmp0 % kMod);
        assert(res >= 0);
        update(res, (ll)(n / k) % kMod * tmp1 % kMod);
        assert(res >= 0);
        tmp0 = 0;
        for (int i = 1; i <= n % k; ++ i) {
            tmp0 += cnta[(k - powb[i]) % k];
        }
        update(res, (ll)(n / k) % kMod * tmp0 % kMod);
        tmp0 = 0;
        for (int i = 1; i <= n % k; ++ i) {
            tmp0 += cntb[(k - powa[i]) % k];
        }
        update(res, (ll)(n / k) % kMod * tmp0 % kMod);
        memset(cnta, 0, sizeof(cnta));
        for (int i = 1; i <= n % k; ++ i) {
            cnta[powa[i]] ++;
        }
        tmp1 = 0;
        for (int i = 1; i <= n % k; ++ i) {
            tmp1 += cnta[(k - powb[i]) % k];
            if ((powa[i] + powb[i]) % k == 0) {
                -- tmp1;
            }
        }
        assert(tmp1 >= 0);
        update(res, tmp1 % kMod);
        cout << "case #" << i << ": " << res << endl;
    }
    return 0;
}
