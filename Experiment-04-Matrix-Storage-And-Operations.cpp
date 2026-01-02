#include <iostream>
using namespace std;
class matrix
{
  public:
  int i,j,flag,sum=0;
  int a[3][3],upptri[3][3],trans[3][3];
  void accept(int,int);
  void display(int,int);
  void upptriangle(int,int);
  void summ(int,int);
  void transpose(int,int);
};
void matrix::accept(int r,int c)
{
    cout<<"Matrix 1:"<<endl;
    for(i=1;i<=r;i++)
    {
        cout<<"Enter Row "<<i<<":"<<endl;
        for(j=1;j<=c;j++)
        {
            cout<<"Enter Column "<<i<<" element "<<j<<"=";
            cin>>a[i][j];
        }
    }
}
void matrix::display(int r,int c)
{
    cout<<"Matrix 1="<<endl;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrix::upptriangle(int r,int c)
{
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(i>j and a[i][j]!=0)
            {
                flag=1;
            }
        }
    }
    if(flag==1)
    {
        cout<<"It isn't an upper triangle matrix.";
    }
    else
    {
      cout<<"It is an upper triangle matrix.";
    }
}
void matrix::summ(int r,int c)
{
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
           if(i==j)
           {
               sum=a[i][j]+sum;
           }
        }
    }
    cout<<"\nThe summation of the diagonals are: "<<sum;
}
void matrix::transpose(int r,int c)
{
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            trans[j][i]=a[i][j];
        }
    }
    cout<<"\nThe transpose of the matrix is: "<<endl;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cout<<" "<<trans[i][j];
        }
        cout<<endl;
    }
}
int main()
{
    matrix m1;
    int r,c;
    cout<<"Enter value for row: ";
    cin>>r;
    cout<<"Enter value for column: ";
    cin>>c;
    m1.accept(r,c);
    cout<<"Displaying the matrix:"<<endl;
    m1.display(r,c);
    cout<<"Checking if matrix is upper triangle..."<<endl;
    m1.upptriangle(r,c);
    m1.summ(r,c);
    m1.transpose(r,c);
}
