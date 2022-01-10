#include "iostream"
 #include "algorithm"
 #include "cmath"
 #include "vector"
 #include "set"
 #include "map"
 #include "cstdio"
 #include "utility"
 #include "stdlib.h"
 #include "queue"
 #define ll long long
 #define tt "\n"
 #define loop(n) for(int i = 0 ; i < n; i++)
 #define Fast ios_base::sync_with_stdio(NULL),cin.tie(NULL),cout.tie(NULL);
 #define pb push_back
 #define in insert
 #define ff first
 #define ss second
 #define all(v) v.begin(),v.end()
 const ll MOD = 1000000000+7;
 using namespace std;
 struct SEV{
     vector < ll > sev;
     void SEV1(ll n)
     {
        vector < bool > prime(n+1 , true);
         for (int p = 2; p * p <= n; p++)
         {
             if (prime[p])
             {
                 for (int i = p * p; i <= n; i += p)
                     prime[i] = false;
             }
         }
         for (int p = 2; p <= n; p++)
             if (prime[p])
                 sev.pb(p);
     }
 };
 struct POWER{
     ll fastPower(ll a, ll b){
         if(b == 0)
             return 1;
         ll value = fastPower(a,b/2);
         if(b%2 == 0)
             return value * value;
         else
             return value * value * a;
     }
     ll fastPowerMod(ll x , ll y , ll mod){
         if(y == 0)
             return 1 % mod;
         ll u = fastPowerMod(x, y / 2, mod);
         u = u * u % mod;
         if(y & 1)
             u = u * x % mod;
         return u;
     }
 };
 template <typename T>
 class CQueue{
 private:
     ll size = 0 , capacity = 6;
     T *ele = new T [capacity];
     ll front = -1 , rear = -1;
     void encureCapacity(){
         ll k = capacity / 2 + capacity;
         T *temp = new T [k];
         for(ll i = front ; i <= rear; i++)
             temp[i] = ele[i];
         ele = temp;
         capacity = k;
     }
 public:
     CQueue(){
         front = -1;
         rear = -1;
     }
     bool isFull(){
         if((rear+1) % capacity == front)
             return true;
         return false;
     }
     bool isEmpty(){
         if(rear == front && front == -1)
             return true;
         return false;
     }
     void enqueue(T data){
         if(isEmpty())
         {
             ele[++front] = data;
             rear++;
             return;
         }
         if(isFull())
             encureCapacity();
         ele[(rear + 1) % capacity] = data;
         rear = (rear + 1) % capacity;
         size++;
     }
     T dequeue(){
         if(isEmpty())
         {
             cout << "The queue is Empty There is no data\n";
             return NULL;
         }
         T data = ele[front];
         front++;
         return data;
     }
     ll getSize(){
         return size;
     }
     string toString(){
         string s = "[";
         for(ll i = front; i <= rear; i++){
             string d = to_string(ele[i]);
             s+=d+", ";
         }
         s[s.length() - 1] = s[s.length() - 2] = 0;
         return s +"]";
     }
 };
 int main(){
     Fast
     CQueue<ll> q;
     q.enqueue(1);
     q.enqueue(3);
     q.enqueue(6);
     cout << q.toString() << tt;
 }
