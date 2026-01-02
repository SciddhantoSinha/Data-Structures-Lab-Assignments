#include <iostream>
using namespace std;

class Matrix
{
public:
    int i,j,min_j,max_i,temp;
    int a[5][5];
    Matrix(int,int);
    void Saddle(int,int);
};
Matrix :: Matrix(int r,int c)
{
    cout<<"Reading elements of matrix: "<<endl;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cout<<"Row "<<i<<" Column "<<j<<": ";
            cin>>a[i][j];
        }
    }
    cout<<"The matrix is: "<<endl;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Matrix :: Saddle(int r, int c)
{
    int small[10],big[10],minj,maxi;
    for(i=1;i<=r;i++)
    {
        small[i]=a[i][1];
        for(j=1;j<=c;j++)
        {
            if(small[i]>a[i][j])
                small[i]=a[i][j];
        }
    }
    for(j=1;j<=c;j++)
    {
        big[j]=a[1][j];
        for(i=1;i<=r;i++)
        {
            if(big[j]<a[i][j])
                big[j]=a[i][j];
        }
    }
    maxi=small[1];
    for(i=1;i<=r;i++)
    {
        if(maxi<small[i])
            maxi=small[i];
    }
    minj=big[1];
    for(j=1;j<=r;j++)
    {
        if(minj>big[j])
            minj=big[j];
    }
    if(maxi==minj)
    {
        cout<<"The saddle point is: "<<maxi;
    }
    else
    {
        cout<<"There is no saddle point.";
    }
}
int main()
{
    int r,c;
    cout<<"Enter number of rows and columns:";
    cin>>r>>c;
    Matrix m1(r,c);
    m1.Saddle(r,c);
    return 0;
}
