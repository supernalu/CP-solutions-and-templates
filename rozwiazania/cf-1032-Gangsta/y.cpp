#include <bits/stdc++.h>
using namespace std;
constexpr int LEAVES = (1 << 19);
int t, n;
char s[LEAVES];
int l[2*LEAVES];
int r[2*LEAVES];
long long segSum[2*LEAVES];
int segHowMany[2*LEAVES];
long long pref[LEAVES];
int id[LEAVES];
int invId[LEAVES];
void init() {
    for (int i = LEAVES; i < 2*LEAVES; i++) {
        l[i] = i-LEAVES;
        r[i] = i-LEAVES;
        segSum[i] = 0;
        segHowMany[i] = 0;
    }
    for (int i = LEAVES-1; i > 0; i--) {
        l[i] = l[2*i];
        r[i] = r[2*i+1];
        segSum[i] = 0;
        segHowMany[i] = 0;
    }
}
void update(int v, long long val, int add) {
    v+=LEAVES;
    segSum[v]+=val;
    segHowMany[v]+=add;
    while(v/2>0) {
        v/=2;
        segSum[v]+=val;
        segHowMany[v]+=add;
    }
} 
pair<long long, int> query(int L, int R, int v) {
    if (R < l[v] || r[v] < L)
        return {0, 0};
    if (L <= l[v] && r[v] <= R)
        return {segSum[v], segHowMany[v]};
    pair<long long, int> a=query(L, R, 2*v);
    pair<long long, int> b=query(L, R, 2*v+1);
    return {a.first+b.first,a.second+b.second};
}
long long countHalves() {
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += (i/2)*(n-i+1);
    }
    return res;
}
bool cmp(int a, int b) {
    return pref[a] < pref[b];
}
/*
int binSearch(int L, int R, int k) {
    if (L == R)
        return L;
    int m = (L+R+1)/2;
    if (pref[invId[m]]<k) 
        return binSearch(m, R, k);
    else
        return binSearch(L, m-1, k);
}
    */
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); init();
    cin >> t;
    while (t--) {
        cin >> n >> s+1;
        long long res=countHalves();
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            id[i] = i;
            pref[i] = pref[i-1];
            if(s[i] == '1')
                pref[i]++;
            else
                pref[i]--;
        }
        sort(id, id+n+1, cmp);
        for (int i = 0; i <= n; i++) {
            invId[id[i]] = i;
        }
        update(invId[0], 0, 1);
        for (int i = 1; i <= n; i++) {
            int q = binSearch(1, n, pref[i]);
            pair<long long,int>q1=query(1,q,1), q2=query(q+1,n,1);
            cout << q1.first << ' ' << q1.second << ' '<< q2.first << ' ' << q2.second << '\n';
            cout << q1.second*pref[i]-q1.first+q2.first-q2.second*pref[i] << '\n';
            res += q1.second*pref[i]-q1.first+q2.first-q2.second*pref[i];
            update(invId[i], pref[i], 1);
        }
        cout << res << '\n';
        for (int i = 1; i <= n; i++) {
            update(invId[i], -pref[i], -1);
        }
    }
}