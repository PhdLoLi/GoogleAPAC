#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

int powerMod(int a, int b, int c) {
  int ans = 1;
  a = a % c;
  while (b > 0) {
    if(b % 2 == 1)
    ans = (ans * a) % c;
    b = b / 2;
    a = (a * a) % c;
  }
  return ans % c;
}

int gymSecret(int A, int B, int N, int K) {
  int sum = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j) continue;
      int power_i = powerMod(i, A, K);
      int power_j = powerMod(j, B, K);
      if ((power_i + power_j) % K == 0) {
 //       cout << "i, j " << i << "," << j << "power " << power_i << " " << power_j << endl;
        sum++;
      }
    }
  }
  return sum;
}

int main() {
  ifstream infile("B-small-practice.in");
///  if (!infile.is_open()) cout << "No such file!" << endl;
  string line;
  int num;
  getline(infile, line);
  istringstream(line) >> num;

  for (int i = 1; i <= num; i++) {
    getline(infile, line);
    istringstream iss(line);
    int A;
    iss >> A;
    int B;
    iss >> B;
    int N;
    iss >> N;
    int K;
    iss >> K;
//    cout << A << " " << B << " " << N << " " << " " << K << endl;
    cout << "Case #" << i << ": " << gymSecret(A, B, N, K) << endl;
    
  // do something useful with v
  }

  return 1;
}
