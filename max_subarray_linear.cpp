#include<iostream>
#include<climits>
#include<algorithm>

using namespace std;

int main(){
    int n, arr[100];
    //read the number of elements
    cin >> n;
    
    //read the elements of the array
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    int max = INT_MIN;
    int startIndex = 1;
    int endIndex = 0;
    int currMax = 0;
    //traverse each element of the array
    for(int i=0; i<n; i++){
        //current maximum will be either the current element or the sum of the current element and the maximum sum so far
        currMax = std::max(arr[i], arr[i]+currMax);
        //if current maximum is greater than the overall max, then set overall max to current max
        //the end index of the subarray will be the point where we find the total max
        if(currMax > max){
            max = currMax;
            endIndex = i+1;
        }
    }
    
    //to find the end index
    startIndex = endIndex;
    int total = max;
    while(startIndex>0 && total>0){
        startIndex --; 
        total -= arr[startIndex];
    }
    
    cout << startIndex+1 << " " << endIndex << " " << max;
    
    return 0;
}