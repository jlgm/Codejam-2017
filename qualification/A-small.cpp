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
typedef bitset<22> bt;

template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }

string in;
int K;

unordered_map<bt, int> mark;

int main() {

    int t; scanf("%d\n", &t);
    fr(caso,1,t+1) {
        cin >> in;
        scanf("%d", &K);

        bt s, t;
        int k = in.size();

        printf("Case #%d: ", caso);

        fr(i,0,k) {
            (in[i]=='+') ? s.set(i) : s.set(i,0);
            t[i] = 1;
        }

        queue<pair<bt,int> > q;
        q.push(mp(s,0));

        while(!q.empty()) {
            pair<bt,int> cur = q.front();
            q.pop();
            bt tmp = cur.X; int h = cur.Y;
            mark[tmp] = 1;

            if (tmp == t) {
                printf("%d\n", h);
                goto next;
            }

            fr(i,0,k-K+1) {
                fr(j,i,i+K) {
                    if (tmp.test(j)) {tmp.set(j,0);}
                    else tmp.set(j);
                }
                if (mark[tmp] != 1) q.push(mp(tmp,h+1));
                tmp = cur.X;
            }
        }
        puts("IMPOSSIBLE");
        next: ;
        mark.clear();
    }

    return 0;
}
