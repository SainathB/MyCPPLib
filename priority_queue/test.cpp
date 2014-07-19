
bool compare(int a,int b)
{
	return a<b;
}
#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
 
#define MOD 1000000007
#define llu long long unsigned
#define lld long long
#define ld long
 
 
int scan_d() {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
ld scan_ld() {int ip=getchar_unlocked(),flag=1;ld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
lld scan_lld() {int ip=getchar_unlocked(),flag=1;lld ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
llu scan_llu() {int ip=getchar_unlocked();llu ret=0;for(;ip<'0'||ip>'9';ip=getchar_unlocked());for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return ret;}
 
void print_d(int n) {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<10);}
void print_ld(ld n) {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[11];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void print_lld(lld n) {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
void print_llu(llu n) {int i=21;char output_buffer[21];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<21);}
 
void println_d(int n) {if(n<0){n=-n;putchar_unlocked('-');}int i=10;char output_buffer[11];output_buffer[10]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<11);}
void println_ld(ld n) {if(n<0){n=-n;putchar_unlocked('-');}int i=11;char output_buffer[12];output_buffer[11]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<12);}
void println_lld(lld n) {if(n<0){n=-n;putchar_unlocked('-');}int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}
void println_llu(llu n) {int i=21;char output_buffer[22];output_buffer[21]='\n';do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar_unlocked(output_buffer[i]);}while(++i<22);}

ll left(ll i)
{
	return 2*i+1;
}
ll right( ll i)
{
	return 2*i+2;
}
template<class T>
class PriorityQueue
{
	public:
	vector<T> elements;
	ll size()
	{
		return elements.size();
	}
	
	void heapify(ll x)
	{
		ll le=left(x);
		ll ri=right(x);
		ll lors;
		ll no_el=size();
		if(le<no_el && compare(elements[le],elements[x]))
			lors=le;
		else
			lors=x;
		if(ri<no_el && compare(elements[ri],elements[lors]))
			lors=ri;
		if(lors!=x)
		{
			T temp=elements[lors];
			elements[lors]=elements[x];
			elements[x]=temp;
			heapify(lors);
		}


	}
	void build(vector<T> &x)
	{
		elements=x;
		ll no_el=x.size();
		for(ll i=(no_el-2)/2;i>=0;i--)
		{
			heapify(i);

		}

	}
	T top()
	{
		if(elements.size()>0)
			return elements[0];
	}
	T pop()
	{
		if(elements.size()>0)
		{
			T x=elements[0];
			if(elements.size()>0)
			{
				ll si=elements.size();
				elements[0]=elements[si-1];
				elements.pop_back();
				heapify(0);
			}
			return x;

		}

	}
	bool empty()
	{
		if (elements.size()>0)
			return false;
		else
			return true;
	}

};

int main()
{
	
	int p;
	int n;
	n=scan_d();
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		
		a[i]=scan_d();
	}
	PriorityQueue<int> x;
	x.build(a);
	while(!x.empty())
	{
		println_d(x.pop());
	}
	getchar();
	return 0;
}