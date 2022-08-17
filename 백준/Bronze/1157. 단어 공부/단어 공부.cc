#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    int count = 0;
    int max;
    vector<int>::iterator max_it;
    string s1;
    vector<int> v1(26,0);
    getline(cin, s1);
    for(int i=0; i<s1.size(); i++) {
        s1[i] = toupper(s1[i]);
        v1[(int)(s1[i]-'A')]++;
    }
    
    max_it = max_element(v1.begin(), v1.end());

    for(int j: v1) {
        if(*max_it == j)
            count++;
    }
    
    if(count > 1)
        cout << "?";
    else {
        cout << (char)(max_it-v1.begin()+'A');
    }

    return 0;
}
