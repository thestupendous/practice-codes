/*
 * adding two numbers digit by  digit
 * using linked lists. The two linked
 * lists store numbers in reverse order,
 * i.e, first node contains ones digit,
 * second contains tens digit and so on.
 * Result is stored in a third linked list.
 *
 *This code is complete solution to the
 *problem, it works for all kinds of inputs.
*/

 #include<iostream>
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
		if(p==NULL and q==NULL)
		{
			if(carry==1)
				r->val = 1;
			else
			{
				ListNode * x = i;
				while(x->next->next != NULL) x=x->next;
				x->next = NULL;
			}
			return i;
		}
		else if(p==NULL)
		{
			while(q!=NULL)
			{
				b = q->val;
				sum = carry + b;
				if(sum>9) { sum%=10; carry=1; }
				else carry=0;
				r->val = sum;
				r->next = new ListNode(0);
				r=r->next;
				q=q->next;
			}
		}
		else if(q==NULL)
		{
			while(p!=NULL)
			{
				a = p->val;
				sum = carry + a;
				if(sum>9) { sum%=10; carry=1; }
				else carry=0;
				r->val = sum;
				r->next = new ListNode(0);
				r=r->next;
				p=p->next;
			}
		}
		if(carry==1)
			r->val = 1;
		else
		{
			ListNode * x = i;
			while(x->next->next != NULL) x=x->next;
			x->next = NULL;
		}
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
	
	cout<<"-----------\nprinting\n";
	print(p);
	print(q);
	
	cout<<"----------\n";
	Solution sol;
	r = sol.addTwoNumbers(p,q);
	cout<<"----------\nans\n";
	print(r);
	return 0;
}


