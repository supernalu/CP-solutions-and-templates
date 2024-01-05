#include <bits/stdc++.h>

using namespace std;
constexpr int LEAVES = 1 << 18;


vector<pair<int, int>> cardsResultTree(2*LEAVES, {0, 0});
vector<int>  beg(2*LEAVES);
vector<pair<int, int>> cards(LEAVES, {1e8, 1e8});

void initiation()
{
    for (int i = LEAVES; i < 2*LEAVES; i++)
    {
        beg[i] = i;
        cardsResultTree[i] = cards[i-LEAVES];
    }
    for (int i = LEAVES-1; i > 0; i--)
    {
        beg[i] = beg[2*i]; 
    
        if (cardsResultTree[2*i].first <= cardsResultTree[beg[2*i+1]].first)
            cardsResultTree[i].first = cardsResultTree[2*i+1].first;
        else if (cardsResultTree[2*i].first <= cardsResultTree[beg[2*i+1]].second)
            cardsResultTree[i].first = cardsResultTree[2*i+1].second;  
        else
            cardsResultTree[i].first = 1e9 + 10;
        
        if (cardsResultTree[2*i].second <= cardsResultTree[beg[2*i+1]].first)
            cardsResultTree[i].second = cardsResultTree[2*i+1].first;
        else if (cardsResultTree[2*i].second <= cardsResultTree[beg[2*i+1]].second)
            cardsResultTree[i].second = cardsResultTree[2*i+1].second;  
        else
            cardsResultTree[i].second = 1e9 + 10;
    }
}

void update(int a, pair<int, int> b)
{
    a += LEAVES;
    cards[a-LEAVES] = b;
    cardsResultTree[a] = b;

    for (int i = a/2; i > 0; i /= 2)
    {
        if (cardsResultTree[2*i].first <= cardsResultTree[beg[2*i+1]].first)
            cardsResultTree[i].first = cardsResultTree[2*i+1].first;
        else if (cardsResultTree[2*i].first <= cardsResultTree[beg[2*i+1]].second)
            cardsResultTree[i].first = cardsResultTree[2*i+1].second;  
        else
            cardsResultTree[i].first = 1e9 + 10;
        
        if (cardsResultTree[2*i].second <= cardsResultTree[beg[2*i+1]].first)
            cardsResultTree[i].second = cardsResultTree[2*i+1].first;
        else if (cardsResultTree[2*i].second <= cardsResultTree[beg[2*i+1]].second)
            cardsResultTree[i].second = cardsResultTree[2*i+1].second;  
        else
            cardsResultTree[i].second = 1e9 + 10;
    }
}

void debug()
{
    for (int i = 1; i <= LEAVES; i *= 2) {
        for (int j = i; j < 2*i; ++j) {
            string a = to_string(cardsResultTree[j].first);
            string b = to_string(cardsResultTree[j].second);
            if (a == "100000000") {
                a = '+';
            }
            if (a == "1000000010") {
                a = '-';
            }
            if (b == "100000000") {
                b = '+';
            }
            if (b == "1000000010") {
                b = '-';
            }
            cout << a << '|' << b << "   ";
        } 
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cards[0] = {0, 0};
    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a, b; cin >> a >> b; 
        if (b < a)
            swap(a, b);

        cards[i] = {a, b};
    }

    initiation();
    //debug();

    int q;
    cin >> q;

    while (q--)
    {
        int a, b; cin >> a >> b;
        pair<int, int> tmp = cards[a], tmp2 = cards[b];

        update(a, tmp2); 
        update(b, tmp); 
        //debug();
        if (cardsResultTree[1].first != 1e9 + 10 || cardsResultTree[1].second != 1e9 + 10)
            cout<< "TAK\n";
        else
            cout << "NIE\n";
    }
}
