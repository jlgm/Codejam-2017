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

typedef long long ll;
typedef pair<int, int> pii;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

string in;
int k;

char op(char c) {
    if (c == '-') return '+';
    else return '-';
}

int main() {

    int t; scanf("%d", &t);
    fr(caso,1,t+1) {
        cin >> in >> k;
        printf("Case #%d: ", caso);
        
        int len = in.size(), ans = 0;
        fr(i,0,len-k+1) {
            if (in[i]=='-') {
                fr(j,i,i+k) in[j] = op(in[j]);
                ans++;
            }
        }
        fr(i,0,len) if (in[i]=='-') {
            puts("IMPOSSIBLE");
            goto next;
        }

        printf("%d\n", ans);

        next: ;
    }

    return 0;
}
