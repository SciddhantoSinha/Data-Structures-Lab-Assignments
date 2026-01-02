#include<iostream>
using namespace std;
class searching
 {
    public:
    int arr[10],x,ind;
    bool found;

    searching()
    {
        cout<<"\nEnter the array: ";
        for(int i=0;i<10;i++)
        {
            cout<<"\nEnter element no. "<<i+1<<": ";
            cin>>arr[i];
        }

        cout<<"\nEnter the element to be searched: ";
        cin>>x;

        found=false;
    }

    void display()
    {
        cout<<"\nArray is: ";
        for(int i=0;i<10;i++)
            cout<<arr[i]<<" ";
    }

    int sequentialsearch()
    {

        for(int i=0;i<10;i++)
            if(arr[i]==x)
            {
                found=true;
                ind=i;
                break;
            }

        if(found)
        {
            cout<<"\nElement "<<x<<" has been found at index "<<ind+1;
            return ind;
        }
        else
        {
            cout<<"\nElement has not been found in the array";
            return -1;
        }
    }

    void bubblesort()
    {
        int i,j,temp;
        for(i=0;i<9;i++)
            for(j=0;j<9-i;j++)
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
    }

    int binarysearch(int l, int r)
    {
        if (r >= l) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == x)
            {
                ind=mid;
                cout<<"\nElement has been found at index "<<ind+1;
                return mid;
            }

            if (arr[mid] > x)
                return binarysearch(l, mid - 1);

            return binarysearch(mid + 1, r);
        }

        cout<<"\nElement has not been found in the array";
        return -1;
    }

};

int main()
{
    searching s;
    char c='0';
    cout<<"\nEnter the searching method you want:\n1. Binary search\n2. Sequential search\n";
    cin>>c;
    switch(c)
    {
        case '1':
        s.display();
        s.bubblesort();
        cout<<"\nAfter sorting: ";
        s.display();
        s.binarysearch(0,9);
        break;

        case '2':
        s.display();
        s.sequentialsearch();
        break;

        default:
        break;
    }
    return 0;
}
