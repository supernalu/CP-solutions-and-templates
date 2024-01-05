#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1e5 + 10;

int n, D, W, M;


/*
class Rational {

    long long nominator;
    long long denominator;

public:

    Rational(long long nominator = 0, long long denominator = 1) : nominator(nominator), denominator(denominator) {
        long long gcd = __gcd(nominator, denominator);
        nominator /= gcd;
        denominator /= gcd;
    }

    Rational operator+(Rational const& rhs) {
        long long newDenominator = denominator * rhs.denominator;
        long long newNominator = nominator * rhs.denominator + rhs.nominator * denominator;
        return Rational{newNominator, newDenominator};
    }

    Rational operator-(Rational const& rhs) {
        long long newDenominator = denominator * rhs.denominator;
        long long newNominator = nominator * rhs.denominator - rhs.nominator * denominator;
        return Rational{newNominator, newDenominator};
    }

    Rational operator*(Rational const& rhs) {
        long long newDenominator = denominator * rhs.denominator;
        long long newNominator = nominator * rhs.nominator;
        return Rational{newNominator, newDenominator};
    }

    Rational operator/(Rational const& rhs) {
        long long newDenominator = denominator * rhs.nominator;
        long long newNominator = nominator * rhs.denominator;
        return Rational{newNominator, newDenominator};
    }

    Rational& operator+=(Rational const& rhs) {
        return *this = *this + rhs;
    }

    Rational& operator-=(Rational const& rhs) {
        return *this = *this - rhs;
    }

    Rational& operator*=(Rational const& rhs) {
        return *this = *this * rhs;
    }

    Rational& operator/=(Rational const& rhs) {
        return *this = *this / rhs;
    }

    bool operator==(Rational const& rhs) {
        return nominator == rhs.nominator && denominator == rhs.denominator;
    }

    bool operator<(Rational const& rhs) {
        return nominator * rhs.denominator < rhs.nominator * denominator;
    }

    operator double() const {
        return static_cast<double>(nominator) / static_cast<double>(denominator);
    }

    friend ostream& operator<<(ostream& os, Rational const& rhs) {
        os << rhs.nominator << '/' << rhs.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Rational& rhs) {
        is >> rhs.nominator >> rhs.denominator;
        return is;
    }
};
*/

struct larry {
    int x;
    int d;
    int w;
    int m;
    Rational v;

    larry() {}

    larry(int x, int d, int w, int m) : x(x), d(d), w(w), m(m), v(Rational(w, m)){}

    /*
    larry(int k, int l, int h, int n)
    {
        x = k; 
        d = l;
        w = h;
        m = n;
    }
    */
};

larry arr[MAXN];

void readInput()
{
    cin >> n >> D >> W >> M;

    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d;

        cin >> a >> b >> c >> d;

        arr[i] = {a, b, c, d};
    }


}

int main()
{
     readInput();

    Rational V = {W, M};

    Rational beg = {-D, 1};

    int res = 1;
    
    //cout << beg << '\n';

    for (int i = 1; i < n; i++)
    {
        Rational a = V;
        Rational b = beg;
        Rational c = arr[i].v;
        Rational d = Rational{arr[i].x};

        Rational t = ((d-b)/(a-c));

    

        Rational e = arr[i+1].v;
        Rational f = Rational{arr[i+1].x-arr[i+1].d};

        if (a*t < e*t + f || a*t == e*t + f)
            res++;


    }

    cout << res;
    
    //Rational a{3, 2};
    //Rational b{10, 3};
    //cout << a + b << endl;
    //cout << (double) (a + b) << endl;

}