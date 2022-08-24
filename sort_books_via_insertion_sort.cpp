#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Book{
    string title, author_name;
    int access_num;
    float price;

    public:
    friend istream& operator>>(istream& in, Book& b){
        in >> b.title >> b.author_name >> b.access_num >> b.price;
        return in;
    }
    friend ostream& operator<<(ostream& out, Book& b){
        out << b.title << b.author_name << b.access_num << b.price;
        return out;
    }
    bool operator>(Book& b){
        return(access_num>b.access_num);
    }
    bool operator<(Book& b){
        return(access_num<b.access_num);
    }
};

int main()
{
    vector<Book> elements;
    Book ele, key;
    int i,j,n;
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
        while((i>=0)&&(elements[i]>key))
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