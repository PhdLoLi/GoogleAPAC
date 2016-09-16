#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  void twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> ht;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      if (ht.find(target - nums[i]) != ht.end()) {
        cout << " " << min(ht[target - nums[i]], i) + 1;
        cout << " " << max(ht[target - nums[i]], i) + 1 << endl;
        return;
      }
      ht[nums[i]] = i;
    }
    //return res;
  }
};

int main() {
  Solution so;
  ifstream infile("A-large-practice.in");
  string line;
  int num;
  getline(infile, line);
  istringstream(line) >> num;

  for (int i = 1; i <= num; i++) {
    int credit;
    getline(infile, line);
    istringstream(line) >> credit;
    
    int v_size;
    getline(infile, line);
    istringstream(line) >> v_size;

    getline(infile, line);
    istringstream iss(line);
    int n;
    vector<int> v;
    while (iss >> n) {
      v.push_back(n);
    }
  
    cout << "Case #" << i << ":"; 
    so.twoSum(v, credit);
    
  // do something useful with v
  }

  return 1;
}
