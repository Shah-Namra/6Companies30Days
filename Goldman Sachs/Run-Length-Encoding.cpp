#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
  //Your code here 
    int count = 1;
    stringstream result;
    int n = src.length();

    for (int i = 0; i<n;i++) {
        if (i+1<n && src[i] == src[i + 1]) 
            count++;
         else {
            result << src[i] << count;
            count = 1;
        }
    }

    return result.str();
}     
 
