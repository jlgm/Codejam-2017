#pragma comment(linker, "/STACK:16777216")
#include <bits/stdc++.h>

using namespace std;

#define ms(ar,a) memset(ar, a, sizeof(ar))
#define fr(i,j,k) for (int (i) = (j); (i) < (k); (i)++)
#define rf(i,j,k) for (int (i) = (j); (i) >= (k); (i)--)
#define db(x) cout << (#x) << " = " << x << endl;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

typedef long long ll;
typedef pair<int, int> pii;

string in;
ll n;

bool tyde(string s) {
    int k = s.size();
    fr(i,1,k) {
        if (s[i-1] > s[i]) return false;
    }
    return true;
}

string fix(string s) {
    int k = s.size();
    bool fnd = 0;
    fr(i,0,k-1) {
        if (fnd) {
            s[i] = '9';
            continue;
        }
        if (s[i] > s[i+1]) s[i] = s[i]-1, fnd = 1;
    }
    s[k-1] = '9';
    return s;
}

int main() {

    int t; scanf("%d", &t);
    fr(caso,0,t) {
        cin >> in;
        while(!tyde(in)) {
            in = fix(in);
            sscanf(in.c_str(), "%lld", &n);
            in = tostr(n);
        }
        printf("Case #%d: %s\n", caso+1, in.c_str());
    }

    return 0;
}
