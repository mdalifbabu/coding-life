#include <bits/stdc++.h>

#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define vi(a)           vector<a>
#define pii(a, b)       pair<a, b>
#define MP              make_pair
#define db              double
#define ll              long long
#define eps             1e-9
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define MOD             100007
#define MAX             INT_MAX
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define auto(x, a)      for(auto x: a)
#define PRINT_CASE      printf("Case %d: ",z)
#define CASE_PRINT      cout<<"Case "<<z<<":"<<endl;
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long
#define vprint(v)       auto(x, v)cout<<x<<" ";cout<<endl;

using namespace std;

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

/*-----------------------GCD && LCM------------------*/
//ll lcm(ll a, ll b) {  return a * (b / __gcd(a, b)); }
/*------------------------------------------------*/

/*-----------------------IO------------------*/
void fileIO()
{
    #ifndef ONLINE_JUDGE
        freopen("D://Input.txt","r",stdin);
        freopen("D://Output.txt","w",stdout);
    #else
      // Read("immetric.in");
      // Write("immetric.out");
    #endif
}
/*------------------------------------------------*/

/*---------------------Prime Sieve--------------------------*//*
ll _sieve_size;bitset<100000100>bs;vi(ll) primes;

void sieve(ll upperbound) {_sieve_size = upperbound +1;bs.set();bs[0] = bs[1] = 0;
    for(ll i = 2; i < _sieve_size; i++)if(bs[i]){
        for(ll j = i*i; j <= _sieve_size; j += i)bs[j] = 0; primes.pb((int)i);
    }
}

bool isPrime(ll N) {if(N <= _sieve_size)return bs[N];for(int i = 0; i < (int)SZ(primes); i++)
    if(N % primes[i] == 0)return false; return true;
}
/*------------------------------------------------*/

int main()
{
    //CIN;
    //fileIO();  int start_s = clock();

    int n;
    sf(n);

    TEST_CASE(n){
        ll a, b, And = 0, Or = 0, orA = 0, orB = 1, i = 0, mod1, mod2;
        sffl(a, b);

        while(a || b){
            mod1 = a % 2, mod2 = b % 2;
            a /= 2, b /= 2;

            //cout<<mod1<<" "<<mod2<<" "<<orB<<endl;

            orA += orB;

            if(mod1 == mod2){
                And += mod1 * orB;
            }

            if(mod1 || mod2){
                Or += orB;
            }

            if(!mod1 && mod2){
                Or = orA;
                And = 0;
            }

            i++;
            orB *= 2;
        }

        PRINT_CASE;
        pf("%lld %lld\n", Or, And);
    }

    //int end_s=clock();
    //printf("\nTime :: %.2lf\n", (double)(end_s-start_s)/CLOCKS_PER_SEC);
    return 0;
}
