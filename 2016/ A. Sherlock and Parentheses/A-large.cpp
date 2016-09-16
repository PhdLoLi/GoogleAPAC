#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

long maxP(int L, int R) {
  long num = min(L, R);
  if (num == 0) return 0;
  else return (1 + num) * num / 2;
}

int main() {
  ifstream infile("A-large-practice.in");
///  if (!infile.is_open()) cout << "No such file!" << endl;
  string line;
  int num;
  getline(infile, line);
  istringstream(line) >> num;

  for (int i = 1; i <= num; i++) {
    getline(infile, line);
    istringstream iss(line);
    int L;
    iss >> L;
    int R;
    iss >> R;

    cout << "Case #" << i << ": " << maxP(L, R) << endl;
    
  // do something useful with v
  }

  return 1;
}
