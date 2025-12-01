//friends pairing- for every element, either they will be selected alone, or be paired with one other (any one from the provided).
#include<iostream>
using namespace std;

#define u unsigned long long

u friends(int n)
{
    if(n==0 or n==1) return 1;
    if(n==2) return 2;
    return friends(n-1)+(n-1)*friends(n-2);
}
int main()
{
    cout<<friends(4)<<'\n';
    return 0;
}

