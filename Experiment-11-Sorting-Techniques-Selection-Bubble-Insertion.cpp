#include<iostream>
using namespace std;

class sorting
{
    public:
    int arr[10];

    sorting()
    {
        cout<<"\nEnter the array: ";
        for(int i=0;i<10;i++)
        {
            cout<<"\nEnter element no. "<<i+1<<": ";
            cin>>arr[i];
        }
    }

    void display()
    {
        for(int i=0;i<10;i++)
            cout<<arr[i]<<" ";
    }

    void bubblesort()
    {
        cout<<"\nUnsorted array is: ";
        display();

        int i,j,temp;
        for(i=0;i<9;i++)
            for(j=0;j<9-i;j++)
                if(arr[j]>arr[j+1])
                {
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }

        cout<<"\nSorted array is: ";
        display();
    }

    void insertionsort()
    {
        cout<<"\nUnsorted array is: ";
        display();

        int i,j,key;
        for (i = 1; i < 10; i++)
        {
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j -=1;
            }
            arr[j + 1] = key;
        }

        cout<<"\nSorted array is: ";
        display();
    }

    void selectionsort()
    {
        cout<<"\nUnsorted array is: ";
        display();

        int i, j, min_idx,temp;
        for (i = 0; i < 9; i++)
        {

            min_idx = i;
            for (j = i+1; j < 10; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

            if(min_idx!=i)
            {
                temp=arr[min_idx];
                arr[min_idx]=arr[i];
                arr[i]=temp;
            }
        }

        cout<<"\nSorted array is: ";
        display();
    }
};

int main()
{
    sorting s;
    char c='0';
    cout<<"\nEnter the sorting method you want:\n1. Bubble sort\n2. Insertion sort\n3. Selection sort\n";
    cin>>c;
    switch(c)
    {
        case '1':
        s.bubblesort();
        break;

        case '2':
        s.insertionsort();
        break;

        case '3':
        s.selectionsort();
        break;

        default:
        break;
    }
    return 0;
}
