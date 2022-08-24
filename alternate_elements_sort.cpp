#include<iostream>
using namespace std;
int main()
{
    int elements[20],key,i,j,n;
    //cout<<"Enter number of elements";
    cin>>n;
    for(i=0;i<n;i++)
        cin>>elements[i];
    
    for(j=0;j<n;j+=2)
    {
        key = elements[j];
        i = j-2;
        while((i>=0)&&(elements[i]>key))
        {
            elements[i+2] = elements[i];
            i = i-2;
        }
        elements[i+2] = key;
    }
    for(j=1;j<n;j+=2)
    {
        key = elements[j];
        i = j-2;
        while((i>=0)&&(elements[i]>key))
        {
            elements[i+2] = elements[i];
            i = i-2;
        }
        elements[i+2] = key;
    }
   for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }
}