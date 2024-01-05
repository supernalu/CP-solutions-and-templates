#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, k, c;
 set<ll> divi;
 vector<ll> dividors;


set<ll> trial_division1(ll n) {
    set<ll> factorization;
    for (ll d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.insert(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.insert(n);
    return factorization;
}

bool isCoPrime(ll a)
{
    for (auto div : dividors)
    {
        if (a%div == 0)
            return 0;
    }
    return 1;
}

ll findNumberOfCoprime(ll a)
{
    ll m = dividors.size();

    ll res = 0;

    for (ll k = 1; k <= (1 << m)-1; ++k)
    {
        ll tmp = 1;
        ll u = 1;
        ll mnoznik = -1;
        for (int i = 0; i < m; i++)
        {
            //cout << (k& u) << '\n';
            if ((k & u) != 0)
            {
                //cout << dividors[i] << ' ';
                tmp *= dividors[i];
                mnoznik *= -1;
            }
            u *= 2;
        }
        //cout << '\n';
        //cout << tmp << '\n'; 
        res += mnoznik*(a/tmp);
    }

    return a - res;

}

ll binSearch(ll left, ll right, ll szukana)
{
    if (left == right)
        return left;

    ll mid = (left+right)/2;
    bool poss = isCoPrime(mid);
    ll numberofCoprime = findNumberOfCoprime(mid);
    //cout << mid << ' ' <<  numberofCoprime << '\n';

    if (numberofCoprime < szukana)
        return binSearch(mid, right, szukana);
    if (numberofCoprime > szukana || (numberofCoprime == szukana && poss == 0))
        return binSearch(left, mid, szukana);
    if (numberofCoprime == szukana && poss)
        return mid;
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

    cin >> n >> k >> c;
    divi = trial_division1(n);
    for (auto i : divi)
        dividors.push_back(i);

    //cout << findNumberOfCoprime(70);

    /*
    for (int i = 0; i < c; i++)
    {
        cout << binSearch(1, 1e18, k+i) << ' ';
    }
    */
   ll a = binSearch(1, 1e18, k);
   int done = 1;
   cout << a << ' ';

   while (done < c)
   {
        a++;
        if (__gcd(a, n) != 1)
            continue;
        done++;
        cout << a << ' ';
   }
    
}