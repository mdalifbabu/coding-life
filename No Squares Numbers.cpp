#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 100009;
const long double EPS = 1e-9;
#define Read()  freopen("D://Input.txt", "r", stdin);
#define Write() freopen("D://Output.txt", "w", stdout);

#define MAXN 100009
int mobi[MAXN];
bool pr[MAXN];

void mobius(){
    for(int i = 0; i < MAXN; i++)mobi[i] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!pr[i]){
            mobi[i] *= -1;
            for(int j = i+i; j < MAXN; j += i){
                pr[j] = 1;
                mobi[j] *= (j % (i*i) ? -1:0);
            }
        }
    }
    ///abeer vai ka mobius sieve:)
}

int m[10][MAXN];
void digit(){
	for(int i = 1; i < MAXN; i++){
		int n = i;
		while(mobi[i] && n){
			m[n%10][i] = 1;
			n /= 10;
		}
		for(int j = 0; j < 10; j++)
			m[j][i] += m[j][i-1];
	}
}

int main(){
    FastIO;
   	Read();Write();
   	mobius();
   	digit();

   	int t;
   	cin>>t;

   	while(t--){
   		int a, b, d;
        cin>>a>>b>>d;
        cout<<m[d][b]-m[d][a-1]<<endl;
   	}

    return 0;
}
