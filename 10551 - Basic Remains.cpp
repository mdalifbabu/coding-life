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

ll CP[11][11];
int b; ll convert = 0, DC, Mod, Div; string n, p;

void DPP(){
	for(int i = 2; i < 11; i++){
		CP[i][0] = 1;
		for(int j = 1; j < 11; j++){
			CP[i][j] = CP[i][j-1] * i;
		}
	}
}

ll BtoD(ll N){
	int i = 0;
	ll D = 0;
	while(N){
		D += (CP[b][i] * (N%10));
		N /= 10;
		i++;
	}
	return D;
}

ll DtoB(ll N){
	string s = "";
	while(N){
		s += ('0' + (N%b));
		N /= b;
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
    DPP();

    while(true){
	    cin>>b>>n>>p;
	    if(b == 0)break;
	    
	    Div = 0;
	    convert = 0;
	    for(int i = 0; i < p.size(); i++){
			Div *= 10;
			Div += (p[i]-'0');
		}
	    DC = BtoD(Div);
	    bool flag;
	    for(int i = 0; i < n.size(); i++){
	    	if(convert < Div){
	    		convert *= 10;
	    		convert += (n[i] - '0');
	    		flag = 1;
	    	}else{
	    		convert = BtoD(convert);
	    		convert = (convert % DC);
	    		convert = DtoB(convert);
	    		i--;
	    		flag = 0;
	    	}
	    }
	    if(flag){
	    	convert = BtoD(convert);
	    	convert = (convert % DC);
	    	convert = DtoB(convert);
	    	cout<<convert<<endl;
	    }
	    else cout<<convert<<endl;
	}
   
    return 0;
}
