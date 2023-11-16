#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxPriceArray[1000000] = {0, };
int priceArray[1000000] = {0, };

int main(void) {
	int t=0;
    cin >> t;
    
    for(int i=0; i<t; i++) {
        long long sum=0;
    	int n=0;
        cin >> n;
        for(int j=0; j<n; j++) {
        	int price = 0;
            cin >> price;
            priceArray[j] = price;
        }
        maxPriceArray[n-1] = 0;
        int maxPrice = 0;
        for(int z=n-1; z>0; z--) {
        	if(priceArray[z] > maxPrice) {
                maxPrice = priceArray[z];
                maxPriceArray[z-1] = maxPrice;
            } else {
            	maxPriceArray[z-1] = maxPrice;
            }
        }
        
        for(int z=0; z<n-1; z++) {
        	if(priceArray[z] < maxPriceArray[z]) {
            	sum += (maxPriceArray[z]-priceArray[z]);
            }
        }
        
        cout << "#" << i+1 << " " << sum << "\n"; 
    }
    
    return 0;
}