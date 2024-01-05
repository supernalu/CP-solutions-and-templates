#include <bits/stdc++.h> 
using namespace std;
int t, p;

vector<vector<int>> preproc;

void reku(int k, int left, vector<int> v)
{
    k = min(k, left);
    if (left == 0) {
        preproc.emplace_back(v);
        return;
    }

    for (int i = k; i >= 1; --i) {
        v.push_back(i);
        reku(i, left - i, v);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    reku(41, 41, {});

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        long long p;
        cin >> p;
        
        vector<int> res{};
        for (auto& vec : preproc) {
          long long curr = 1;
          for (auto x : vec) {
              curr *= x;
          }
          if (curr == p) {
              if (res.empty() || res.size() > vec.size()) {
                  res = vec;
              }
          }
        }
        cout << "Case #" << T << ": " << (res.empty() ? -1 : (int)res.size()) << ' ';
        for (auto i : res)
            cout << i << ' ';
        cout << '\n';
    }

    

   

}