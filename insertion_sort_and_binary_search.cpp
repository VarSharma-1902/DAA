#include<iostream>
#include<vector>
using namespace std;
int binary_search_pos(int *elements, int low, int high, int s)
{
	int mid;
    if(high <= low){
        if(s > elements[low])
            return low+1;
        else
            return low;
    }
    mid = (low+high)/2;
    if(s==elements[mid])
        return mid+1;
    if(s>elements[mid])
        return binary_search_pos(elements,mid+1,high,s);
    return binary_search_pos(elements,low,mid-1,s);
}

int main()
{

   vector<int> elements(20,0);
    int key,i,j,n,pos;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>elements[i];
   for(j=1;j<n;++j)
    {
    pos = binary_search_pos(elements.data(), 0, j-1, elements[j]);
    i = j-1;
    cout << "element = " << elements[j] << " pos = " << pos << endl;
   key = elements[j];
   while(i>=pos)
    {	
        elements[i+1] = elements[i];
        i--;
     }
  elements[i+1]= key;
  
}

   for(i=0;i<n;i++)
    {
        cout<<elements[i]<<" ";
    }
}