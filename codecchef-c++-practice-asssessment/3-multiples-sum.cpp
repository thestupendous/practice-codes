// find sum of all numbers in array that are multiples of 3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    short t,len,num;
    int sum{0};
    cin>>t;
    while(t--) {
        sum=0;
        cin>>len;
        for(short i{0};i<len;i++) {
            cin>>num;
            if(num%3==0) sum+=num;
        }
        cout << sum << '\n';
    }
    return 0;
}

