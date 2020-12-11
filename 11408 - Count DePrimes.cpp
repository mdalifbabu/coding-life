#include <bits/stdc++.h>
using namespace std;

#define eps             1e-9
#define pi              acos(-1)
#define ll              long long
#define pii             pair<int, int>
#define pll             pair<ll, ll>
#define vi              vector<int>
#define vl              vector<ll>
#define all(x)          (x).begin(), (x).end()
#define FastIO          ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define f               first
#define s               second
#define sc              scanf
#define pf              printf
#define pb              push_back
#define mp              make_pair
#define s1(x)           sc("%d", &x)
#define s2(x, y)        sc("%d %d", &x, &y)
#define s3(x, y, z)     sc("%d %d %d", &x, &y, &z)
#define sl1(x)          sc("%lld", &x)
#define sl2(x, y)       sc("%lld %lld", &x, &y)
#define sl3(x, y, z)    sc("%lld %lld %lld", &x, &y, &z)
#define ms(a, v)        memset(a, v, sizeof a)
#define ff(i, e)        for(int i = 0; i < e; i++)
#define fb(i, e)        for(int i = e; i >= 0; i--)
#define fff(i, s, e)    for(int i = s; i < e; i++)
#define ffb(i, s, e)    for(int i = e; i >= s; i--)
#define view(a, s)      ff(_,s)cout<<a[_]<<" ";cout<<endl;
#define print(v)        pf("%d\n", v)
#define ato(i, v)       for(auto i : v)

const ll INF = 2000000000000000000LL;
const int inf = 0x3f3f3f3f;

#define maxn            5000000
#define Write() freopen("D://Output.txt", "w", stdout);
#define Read()  freopen("D://Input.txt", "r", stdin);


/*-----------------------GCD && LCM------------------*/
//ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b , a % b); }
//ll lcm(ll a, ll b) { return a * b/gcd(a, b); }
/*------------------------------------------------*/

/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/
int mark[maxn+9];
void marking(){
    for(int i = 2; i <= maxn; i++){
        if(!mark[i]){
            mark[i] = i;
            for(int j = i+i; j <= maxn; j += i){
                mark[j] += i;
            }
        }
    }
}

int sum[maxn + 9];

int main(){FastIO;
    Read(); Write();
    marking();
    
    fff(i, 2, maxn+1){
        sum[i] += (sum[i-1] + (mark[i] == mark[mark[i]]));
    }

    int a, b;
    while(true){
        s1(a);
        if(!a)break;
        s1(b);
        pf("%d\n", sum[b]-sum[a-1]);
    }

    return 0;
}