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

string SD[510], a, b, x = "", y = "", ans, fans = "";

string Sum(string s1, string s2){
    string res;
    int carry = 0;
    for(int i = s1.size()-1, j = s2.size()-1; i >= 0|| j >= 0; i--, j--){
        int num1 = 0, num2 = 0;

        if(i >= 0)num1 = s1[i] - '0';
        else num1 = 0;
        if(j >= 0)num2 = s2[j] - '0';
        else num2 = 0;

        int s = num1 + num2 + carry;
        carry = s/10;
        s %= 10;
        res.push_back(s + '0');
    }
    if(carry>0)res.push_back(carry + '0');
    reverse(res.begin(), res.end());
    return res;
}

string Sub(string s1, string s2){
    string res = "";
    int carry = 0, f = 0;
    for(int i = s1.size()-1, j = s2.size()-1; i >= 0|| j >= 0; i--, j--){
        int num1 = 0, num2 = 0;

        if(i >= 0)num1 = s1[i] - '0';
        else num1 = 0;
        if(j >= 0)num2 = s2[j] - '0';
        else num2 = 0;
		
        num2 += f;
		f = 0;
		if(num1 < num2)num1 += 10, f = 1;
        int s = num1 - num2;
        res.push_back(s + '0');
    }
    string tem = res;
    res = "";

    f = 0;
    for(int i = tem.size()-1; i >= 0; i--){
    	if(tem[i] != '0' && !f)res += tem[i], f = 1;
    	else if(f){
    		res += tem[i];
    	}
    }

    return (res == "" ? "0" : res);
}

bool isSmall(string s1, string s2){
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] == s2[i])continue;
		else if(s1[i] > s2[i])return true;
		else return false;
	}
	return true;
}

int main(){FastIO;
    Read(); Write();
    SD[1] = "1";
    SD[2] = "2";
    for(int i = 3; i < 501; i++){
    	SD[i] = Sum(SD[i-2], SD[i-1]);
    }

    int cas = 0;
    while(cin>>a>>b){
    	x = "", y = "";
    	for(int i = a.size()-1, j = 1; i >= 0; i--, j++){
    		if(a[i] == '1'){
    			x = Sum(x, SD[j]);
    		}
    	}

    	for(int i = b.size()-1, j = 1; i >= 0; i--, j++){
    		if(b[i] == '1'){
    			y = Sum(y, SD[j]);
    		}
    	}
    	
    	ans = Sum(x, y);
    	//cout<<ans<<endl;

    	bool flag = 0;
    	fans = "";
    	for(int i = 500; i > 0; i--){
    		if(ans.size() >= SD[i].size()){
    			if(ans.size() == SD[i].size()){
    				if(isSmall(ans, SD[i])){
    					ans = Sub(ans, SD[i]);
    					fans += '1';
    					flag = 1;
    				}else if(flag)fans += '0';
    			}else if(ans.size() > SD[i].size()){
    				ans = Sub(ans, SD[i]);
    				fans += '1';
    				flag = 1;
    			}else if(flag)fans += '0';
    		}else if(flag)fans += '0';
    	}

    	if(cas)cout<<endl;
    	if(a == b && a == "0")cout<<"0"<<endl;
    	else cout<<fans<<endl;
    	++cas;
    }

    return 0;
}
