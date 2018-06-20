//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define Int long long int
#define fl(i,x,y) for(int i=x; i<y; i++)
#define vi vector<Int>
#define vvi vector< vi >
#define si set<Int>
#define msi multiset<Int>
#define si_d set<Int, greater<Int> >
#define mii map<Int,Int>
#define pb push_back
#define msi_it  multiset<Int> :: iterator
#define si_it set<Int> :: iterator
#define sort(v) sort(v.begin(),v.end());
#define F first
#define S second
#define foreach(i,a) for(__typeof((a).begin()) i = (a).begin(); i != (a).end(); ++i)
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
Int MOD = 1000000007;

template <typename T>T gcd(T x,T y){return y==0?x:gcd(y,x%y);}
template <typename T>T lcm(const T &a,const T &b){return (a*b)/gcd(a,b);}

Int min(Int a, Int b){return (a<b?a:b);}
Int max(Int a, Int b){return (a>b?a:b);}
Int nextPowerOf2(Int n);
Int raiseToPow(Int x, Int power);
Int powerMod(Int x, Int y, Int p);
void primeFactors(Int n);

int main(){
	ios;
	cout.precision(10);
	cout<<fixed;

    int t;
    cin>>t;
    while(t--){
        Int p,q,N,b1,b2,s1,s2,Pow,same;
        cin>>p>>q>>N>>b1>>b2>>s1>>s2;
        Pow = raiseToPow(2,N);
        same = Pow;
        int arr[Pow][N], ones, twos;
        bool isOne;
        fl(i,0,N){
            isOne = true;
            ones = twos = 0;
            same /= 2;
            fl(j,0,Pow){
                if(isOne){
                    arr[j][i] = 1;
                    ones++;
                    if(ones==same){
                        isOne = false;
                        ones = twos = 0;
                    }
                }
                else{
                    arr[j][i] = 2;
                    twos++;
                    if(twos==same){
                        isOne = true;
                        ones = twos = 0;
                    }
                }
            }
        }
        // fl(i,0,N){
        //     fl(j,0,Pow){
        //         cout<<arr[j][i]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans = 0;
        fl(i,0,Pow){
            int S1 = 0,S2 = 0,B1 = 0,B2 = 0,P = 0,Q = 0;
            bool yes = true;
            if(arr[i][0]==1)    S1++,B1++,P++;
            else    S2++,B2++,Q++;
            if(N==1){
                if(S1>s1 || S2>s2 || B1>b1 || B2>b2 || P>p || Q>q){
                    yes = false;
                }
            }
            fl(j,1,N){
                if(arr[i][j]==arr[i][j-1]){
                    if(arr[i][j]==1){
                        S1++;
                        P++;
                    }
                    else{
                        S2++;
                        Q++;
                    }
                }
                else{
                    if(arr[i][j]==1){
                        B1++;
                        P++;
                        S1 = 1;
                        S2 = 0;
                    }
                    else{
                        B2++;
                        Q++;
                        S1 = 0;
                        S2 = 1;
                    }
                }
                if(S1>s1 || S2>s2 || B1>b1 || B2>b2 || P>p || Q>q){
                    yes = false;
                    break;
                }
            }
            if(yes) ans++ , ans %= MOD;
        }
        cout<<ans<<endl;
    }

	#ifndef LOCAL_DEFINE
		cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
	#endif

	return 0;
}

Int nextPowerOf2(Int n)
{
  Int count = 0;
 
  /* First n in the below condition is for the case where n is 0*/
  if (n && !(n&(n-1)))
    return n;
 
  while( n != 0)
  {
    n  >>= 1;
    count += 1;
  }
 
  return 1 << count;
}

Int raiseToPow(Int x, Int power)
{
    Int result;
    Int i;
    result =1;
    for (i=1; i<=power;i++)
    {
        result = result*x;
    }
    return(result);
}

Int powerMod(Int x, Int y, Int p)
{
    Int res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

// A function to print all prime factors of a given number n
void primeFactors(Int n)
{
    // Print the number of 2s that divide n
    while (n%2 == 0)
    {
        printf("%d ", 2);
        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip 
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            printf("%d ", i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n 
    // is a prime number greater than 2
    if (n > 2)
        printf ("%d ", n);
}