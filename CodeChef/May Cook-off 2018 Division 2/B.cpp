//VISHAL ANAND
#include <bits/stdc++.h>
using namespace std;
#define ios std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define TC int t;scanf("%d",&t);while (t-->0)
#define Int long long int
#define ld long double
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
Int min3(Int a, Int b, Int c){return min(a,min(b,c));}
Int max3(Int a, Int b, Int c){return max(a,max(b,c));}
Int nextPowerOf2(Int n);
Int raiseToPow(Int x, Int power);
Int powerMod(Int x, Int y, Int p);
void primeFactors(Int n);
bool isPowerOfTwo (Int x);
void allFactors(Int n);

Int T,N,K;

int main(){
    ios;
    cout.precision(10);
    cout<<fixed;

    cin>>T;
    while(T--){
        cin>>N>>K;
        if(K==1){
            fl(i,0,N)   cout<<"1 ";
            cout<<endl;
            continue;
        }
        if(N==1){
            cout<<K;
            continue;
        }
        Int MM = nextPowerOf2(K);
        MM--;
        Int Xor = MM^K;
        if(MM+1==K) Xor = MM;
        if(N%2==0){
            if(Xor==0){
                cout<<(K-1)<<" "<<"1 ";
                fl(i,0,N-2) cout<<"1 ";
                cout<<endl;
            }
            else{
                cout<<K<<" "<<Xor<<" ";
                fl(i,0,N-2) cout<<"1 ";
                cout<<endl;  
            }
            // if(N==2){
            //     if(Xor==0)  Xor = 1;
            //     cout<<K<<" "<<Xor<<" ";
            //     fl(i,0,N-2) cout<<"1 ";
            //     cout<<endl;
            // }
            // else{
            //     if(Xor==0){
            //         Int num;
            //         fl(i,2,K){
            //             if((1^i)==K){
            //                 num = i;
            //                 break;
            //             }
            //         }
            //         cout<<K<<" "<<K<<" "<<num<<" "<<(K^num)<<" ";
            //         fl(i,0,N-4) cout<<"1 ";
            //         cout<<endl;
            //     }
            //     else{
            //         cout<<K<<" "<<Xor<<" ";
            //         fl(i,0,N-2) cout<<"1 ";
            //         cout<<endl;
            //     }
            // }
        }
        else{
            if(Xor==0){
                cout<<K<<" ";
                fl(i,0,N-1) cout<<"1 ";
                cout<<endl;
            }
            else{
                if(Xor==1){
                    // cout<<K<<" "<<1<<" "<<1<<" ";
                    cout<<K<<" ";
                    bool found = 0;
                    for(int i=1; i<=K; i++){
                        if((1^i)<K && (1^i)>1){
                            cout<<i<<" "<<(1^i)<<" ";
                            found = 1;
                            break;
                        }
                    }
                    fl(i,0,N-3) cout<<"1 ";
                    if(!found)  cout<<"1 1 ";
                    cout<<endl;   
                }
                else{
                    int num = 1;
                    bool found = 0;
                    for(int i=K-1; i>=1; i--){
                        if((Xor^i)<K && (Xor^i)>1){
                            found = 1;
                            num = i;
                            break;
                        }
                    }
                    if(found)
                        cout<<K<<" "<<(Xor^num)<<" "<<num<<" ";
                    else
                        cout<<K<<" "<<1<<" "<<1<<" ";

                    fl(i,0,N-3) cout<<"1 ";
                    cout<<endl;
                }
            }
        }
    }

    #ifndef LOCAL_DEFINE
        cerr<<"\nTime elapsed: "<<1.0*clock()/CLOCKS_PER_SEC<<"s.\n";
    #endif

    return 0;
}

void printDivisors(Int n)
{
    // Note that this loop runs till square root
    for (Int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                printf("%d ", i);
 
            else // Otherwise print both
                printf("%d %d ", i, n/i);
        }
    }
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

Int raiseToPow(Int x, Int y)
{
    Int res = 1;     // Initialize result
  
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res*x;
  
        // n must be even now
        y /= 2; // y = y/2
        x = x*x;  // Change x to x^2
    }
    return res;
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

bool isPowerOfTwo (Int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
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