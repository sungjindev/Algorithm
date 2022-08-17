#include <iostream>
#include <string>
using namespace std;

int main(void) {
    string id;
    getline(cin, id);
    id += "??!";
    cout << id;
    
    return 0;
}