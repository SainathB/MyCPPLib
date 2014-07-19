#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll left(ll i)
{
	return 2*i+1;
}
ll right( ll i)
{
	return 2*i+2;
}
ll parent(ll n)
{
	return (n-1)/2;
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
	void insert(T x)
	{
		elements.push_back(x);
		ll present=elements.size()-1;
		while(parent(present)>=0 && compare(elements[parent(present)],elements[present]))
		{
			T temp=elements[present];
			elements[present]=elements[parent(present)];
			elements[parent(present)]=temp;
			present=parent(present);
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