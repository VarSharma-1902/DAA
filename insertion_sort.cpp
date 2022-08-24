#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> elements;
    int key,i,j,n, ele;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++){
        cin>>ele;
        elements.push_back(ele);
    }
    
    for(j=1;j<n;j++)
    {
        key = elements[j];
        i = j-1;
        while((i>=0)&&(elements[i]<key))
        {
            elements[i+1] = elements[i];
            i = i-1;
        }
        elements[i+1] = key;
    }
   for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }
}