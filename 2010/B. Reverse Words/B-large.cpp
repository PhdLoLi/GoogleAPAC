#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void reverseWords(string &s) {
  int len = 0;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == ' ') {
      cout << " " << s.substr(i + 1, len); 
      len = 0;
    } else len++;
  }
  cout << " " << s.substr(0, len); 
}

int main() {
  ifstream infile("B-large-practice.in");
  string line;
  int num;
  getline(infile, line);
  istringstream(line) >> num;

  for (int i = 1; i <= num; i++) {
    getline(infile, line);
    cout << "Case #" << i << ":"; 
    reverseWords(line);
    cout << endl;
  }

  return 0;
}
