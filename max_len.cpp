#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

int find_startIndex(int arr[], int end, int m){
    int total = m;
    int startIndex=end;
    while(total > 0 && startIndex > 0){
        startIndex--;
        total -= arr[startIndex];
    }
    return startIndex;
}

int findMax(vector<int> arr){
    int max = arr[0];
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>max)
            max = arr[i];
    }
    return max;
}

int findIndex(vector<int> arr, int ele){
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == ele)
            return i;
    }
}

int main(){
    int n, arr[100], length;
    int largestStart, largestEnd;
    int startIndex=0, endIndex=0;
    int overallMax = INT_MIN;
    int currMax=0;
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    vector<int> maximums;
    vector<int> ends;
    for(int i=0; i<n; i++){
        currMax = max(arr[i], arr[i]+currMax);
        if(currMax >= overallMax){
            overallMax = currMax;
            endIndex = i;
            maximums.push_back(overallMax);
            ends.push_back(endIndex);
        }
        
        
    }
    vector<int> starts;
    int start;
    for(int i=0; i<ends.size(); i++){
        start = ends[i];
        int t = maximums[i]-arr[start];
        while(t>0 && start>0){
            start--;
            t -= arr[start]; 
        }
        cout << endl;
        starts.push_back(start);
    }
    vector<int> lengths;
    for(int i =0;i<starts.size();i++){
        lengths.push_back(ends[i]-starts[i]);
    }
    int maxLen = findMax(lengths);
    
    int maxLenIndex = findIndex(lengths, maxLen);
    
    cout << starts[maxLenIndex]+1 << " " << ends[maxLenIndex]+1 << " " << maximums[maxLenIndex];
    return 0;
}