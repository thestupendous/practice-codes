#include<iostream>
//changed
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
void print(ListNode *h)
{
	while(h!=NULL) { cout<<h->val<<' '; h=h->next; }
	cout<<endl;
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * p = l1;
        ListNode * q = l2;
        ListNode * r = new ListNode(0);
		ListNode * i = r;
		int carry = 0, sum;

		int a,b;
		while( p!= NULL and q!=NULL)
		{
			a=p->val;
			b=q->val;
			cout<<"a,b,carry "<<a<<' '<<b<<' '<<carry<<' ';
			sum = a + b + carry;
			if(sum>9){ sum%=10; carry=1; }
			else carry=0;
			r->val = sum;
			r->next = new ListNode(0);
			r=r->next;
			p=p->next;
			q=q->next;
			cout<<" sum,carry: "<<sum<<' '<<carry<<endl;
		}
		if(carry==1)
			r->val = 1;
		return i;
    }
};

void insert(ListNode * &h,int val)
{
	ListNode * n = new ListNode(val);
	if(h==NULL) {
		h=n;
		return ;
	}
	else
	{
		ListNode  * p = h;
		while(p->next != NULL) p=p->next;
		p->next= n;
	}
}

int main()
{
	int n,m,v;
	cin>>n>>m;
	ListNode *p =NULL, *q = NULL, *r=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>v;
		insert(p,v);
	}
	for(int i=0;i<m;i++)
	{
		cin>>v;
		insert(q,v);
	}
	/*
	cout<<"-----------\nprinting\n";
	print(p);
	print(q);
	*/
	cout<<"----------\nans\n";
	Solution sol;
	r = sol.addTwoNumbers(p,q);
	print(r);

	return 0;
}


