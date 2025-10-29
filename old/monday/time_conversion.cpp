/*
hackerrank problem (easy)
time conversion
convert 12 hour clock's time  
to a military 24 hour format

*/

#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the timeConversion function below.
 */
string timeConversion(string s) {
    string outstring;
    if(s[8]=='A')
    {
        outstring = s.substr(0,s.length()-2);
        if(s[0]=='1' and s[1]=='2')
        {
            outstring[0]='0';
            outstring[1]='0';
            //cout<<" size "<<outstring.size()<<endl;
        }
        return outstring;
    }
    else if(s[8]=='P')
    {
        int h=stoi(s.substr(0,2));
        h+=12;
        //cout<<" hour "<<h<<endl;
        outstring = to_string(h) + s.substr(2,s.size()-4) ;
        if(s[0]=='1' and s[1]=='2')
        {
            outstring[0]='1';
            outstring[1]='2';
        }
    }
    return outstring;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
