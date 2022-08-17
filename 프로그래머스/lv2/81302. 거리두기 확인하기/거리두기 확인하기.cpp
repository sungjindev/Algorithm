#include <string>
#include <vector>
#include <iostream>
using namespace std;

int vector_to_array(vector<string> v1, char arr[][5]) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            arr[i][j] = v1[i][j];
        }
    }
    return 0;
}

int calc(char arr[][5]) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(arr[i][j] == 'P') {
                if(i+1 <= 4) {
                    if(arr[i+1][j] == 'P')
                        return 0;
                }
                if(i-1 >= 0) {
                    if(arr[i-1][j] == 'P')
                        return 0;
                }
                if(j+1 <= 4) {
                    if(arr[i][j+1] == 'P')
                        return 0;
                }
                if(j-1 >= 0) {
                    if(arr[i][j-1] == 'P')
                        return 0;
                }
                if(i+1<=4 && j+1<=4) {
                    if(arr[i+1][j+1] == 'P') {
                        if(arr[i+1][j] != 'X')
                            return 0;
                        if(arr[i][j+1] != 'X')
                            return 0;
                    }
                }
                if(i-1>=0 && j+1<=4) {
                    if(arr[i-1][j+1] == 'P') {
                        if(arr[i-1][j] != 'X')
                            return 0;
                        if(arr[i][j+1] != 'X')
                            return 0;    
                    }
                }
                if(i-1>=0 && j-1>=0) {
                    if(arr[i-1][j-1] == 'P') {
                        if(arr[i][j-1] != 'X')
                            return 0;
                        if(arr[i-1][j] != 'X')
                            return 0;
                    }
                }
                if(i+1<=4 && j-1>=0) {
                    if(arr[i+1][j-1] == 'P') {
                        if(arr[i][j-1] != 'X')
                            return 0;
                        if(arr[i+1][j] != 'X')
                            return 0;
                    }
                }
                if(i+2<=4) {
                    if(arr[i+2][j] == 'P') {
                        if(arr[i+1][j] != 'X')
                            return 0;
                    }
                }
                if(j+2<=4) {
                    if(arr[i][j+2] == 'P') {
                        if(arr[i][j+1] != 'X')
                            return 0;
                    }
                }
                if(i-2>=0) {
                    if(arr[i-2][j] == 'P') {
                        if(arr[i-1][j] != 'X')
                            return 0;
                    }
                }
                if(j-2>=0) {
                    if(arr[i][j-2] == 'P') {
                        if(arr[i][j-1] != 'X')
                            return 0;
                    }
                }
                
            }
            
        }
    }
    return 1;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0; i<places.size(); i++) {
        char arr[5][5];        
        vector_to_array(places[i], arr);
        answer.push_back(calc(arr));
    }     
    
    return answer;
}