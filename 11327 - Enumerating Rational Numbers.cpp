#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ll INF = 12158598919;
const int inf = 200000;
const long double EPS = 1e-9;
#define Read()  freopen("D://Input.txt", "r", stdin);
#define Write() freopen("D://Output.txt", "w", stdout);

const int maxn = 200001;
int phi[maxn+10];

void PhiDP(){
    phi[0]  = phi[1] = 0;
    for (int i=2; i<maxn; ++i)
        phi[i] = i - 1;
    for (int i=1; i<maxn; ++i)
        for (int j=i+i; j<maxn; j+=i)
                 phi[j] -= phi[i];
}

int main(){FastIO;
    Read(); Write();
    PhiDP();
    phi[0] = phi[1] = 1;

   ll k;
   while(cin>>k && k){

        ll posp = 0; 
        int num = 0;
        for(int i = 0; i < maxn; i++){
            if(posp + phi[i] >= k){
                num = i;
                break;
            }else{
                posp += (ll)phi[i];
            }
        }

        if(1 == k)
                cout<<0<<"/"<<1<<endl;
        else
        for(int i = 1; i <= num; i++){
            
            posp += (__gcd(i, num) == 1);
            if(posp == k){
                cout<<i<<"/"<<num<<endl;
                break;
            }
        }
   }
    return 0;
}
