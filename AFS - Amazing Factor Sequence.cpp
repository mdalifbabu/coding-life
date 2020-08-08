#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;
const long double EPS = 1e-9;
#define Read()  freopen("D://Input.txt", "r", stdin);
#define Write() freopen("D://Output.txt", "w", stdout);



ll a[1000009];


int main(){FastIO;
    //Read(); Write();
    
    for(int i = 2; i <= 1000000; i++){
    	a[i] = 1;
    }
    a[0] = a[1] = 0;

    for(int i = 2; i <= 1000000; i++){
    	for(int j = i+i; j <= 1000000 ; j += i){
    		a[j] += i;
    	}
    }

    for(int i = 3; i <= 1000000; i++){
    	a[i] += a[i-1];
    }

    int t;
    cin>>t;

    while(t--){
    	int n;
    	cin>>n;
    	cout<<a[n]<<endl;
    }
    
    return 0;
}
