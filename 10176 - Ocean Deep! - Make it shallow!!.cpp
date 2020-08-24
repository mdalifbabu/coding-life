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

string s;
ll Div, DivB, convert = 0;

ll BtoD(ll N){
	ll i = 1;
	ll D = 0;
	while(N){
		D += (i * (N%10));
		N /= 10;
		i *= 2;
	}
	return D;
}

ll DtoB(ll N){
	string s = "";
	while(N){
		s += ('0' + (N%2));
		N /= 2;
	}

	reverse(all(s));
	ll D = 0;
	for(int i = 0; i < s.size(); i++){
		D *= 10;
		D += (s[i]-'0');
	}
	return D;
}

int main(){FastIO;
	Read(); Write();
   Div = 131071;
   DivB = 11111111111111111;
   bool flag = 0;
   char c;
   while(cin>>c && c != EOF){
   		if(c != '#'){
   			s += c;
   			continue;
   		}
   		convert = 0;
   		for(int i = 0; i < s.size(); i++){
   			if(DivB > convert){
   				convert *= 10;
   				convert += (s[i]-'0');
   				flag = 1;
   			}else{
   				flag = 0;
   				convert = BtoD(convert);
   				convert = (convert%Div);
   				convert = DtoB(convert);
   				i--;
   			}
   		}
   		if(flag){
   			convert = BtoD(convert);
   			convert = (convert%Div);
   		}

   		if(convert)cout<<"NO"<<endl;
   		else cout<<"YES"<<endl;

   		s = "";
   }
    return 0;
}
