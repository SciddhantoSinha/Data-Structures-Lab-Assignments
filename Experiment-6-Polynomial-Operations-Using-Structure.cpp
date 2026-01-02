#include <iostream>
using namespace std;

struct poly
{
    int coef;
    int expo;
};

int read(struct poly p[])
{
    int i,len;
    cout<<"Enter number of terms of polynomial: ";
    cin>>len;
    for(i=0;i<len;i++)
    {
        cout<<"Enter coefficient "<<i+1<<": ";
        cin>>p[i].coef;
        cout<<"Enter exponent "<<i+1<<": ";
        cin>>p[i].expo;
    }
    return len;
}

void display(struct poly p[10],int len)
{
    int i;
    for(i=0;i<len-1;i++)
    cout<<p[i].coef<<"x^"<<p[i].expo<<" + ";
    cout<<p[i].coef<<"x^"<<p[i].expo;
}

int add(struct poly p1[10],struct poly p2[10],int t1,int t2,struct poly p3[10])
{
    int i,j,k;

    i=0;
    j=0;
    k=0;

    while(i<t1 && j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].coef=p1[i].coef + p2[j].coef;
            p3[k].expo=p1[i].expo;

            i++;
            j++;
            k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coef=p1[i].coef;
            p3[k].expo=p1[i].expo;
            i++;
            k++;
        }
        else
        {
            p3[k].coef=p2[j].coef;
            p3[k].expo=p2[j].expo;
            j++;
            k++;
        }
    }

    while(i<t1)
    {
        p3[k].coef=p1[i].coef;
        p3[k].expo=p1[i].expo;
        i++;
        k++;
    }

    while(j<t2)
    {
        p3[k].coef=p2[j].coef;
        p3[k].expo=p2[j].expo;
        j++;
        k++;
    }

    return(k);
}

void mul(struct poly p1[10],struct poly p2[10],int len1, int len2, struct poly p4[20])
{
    int count=-1;
    for(int i=0;i<len1;i++)
    {
        for (int j=0;j<len2;j++)
        {
            p4[++count].expo=p1[i].expo+p2[j].expo;
            p4[count].coef=p1[i].coef*p2[j].coef;
        }
    }
    for(int i=0;i<=count;i++)
    {
        if(p4[i].expo==0)
            printf("%d ",p4[i].coef);
        else if(p4[i].expo==1)
            printf("%dx ",p4[i].coef);
        else
            printf("%dx^%d ",p4[i].coef,p4[i].expo);
        if(i!=count)
            printf("+ ");
    }
}

int main()
{
    cout<<"For polynomial 1: "<<endl;
    struct poly p1[20];
    int len1 = read(p1);
    display(p1,len1);

    cout<<"\n\nFor polynomial 2: "<<endl;
    struct poly p2[20];
    int len2 = read(p2);
    display(p2,len2);

    cout<<"\n\nSum of polynomials: "<<endl;
    struct poly p3[10];
    int len3 = add(p1,p2,len1,len2,p3);
    display(p3,len3);

    cout<<"\n\nMultiplication of polynomials: "<<endl;
    struct poly p4[10];
    mul(p1,p2,len1,len2,p3);

    return 0;
}
