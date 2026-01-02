#include <iostream>
using namespace std;

class Str
{
public:
    string s,scp,scp1;
    int i,cnt,flag;
    Str(void);
    void Frequency(void);
    void Delete(void);
    void CharDelete(void);
    void Palindrome(void);
};

Str :: Str()
{
    cout<<"\nEnter a string:";
    cin>>s;
}

void Str :: Frequency()
{
    char c;
    cnt = 0;
    cout<<"\nEnter character whose frequency you want to find: ";
    cin>>c;
    for (i=0;s[i]!='\0';i++)
    {
        if(s[i]==c)
            cnt++;
    }
    cout<<c<<" occurs "<<cnt<<" time(s) in the string.";
}

void Str :: Delete()
{
    int n1,n2;
    scp = s;
    cout<<"\n\nEnter two positions which you would like to delete: ";
    cin>>n1>>n2;
    scp.erase(n1,1);
    scp.erase(n2-1,1);
    cout<<"New string: "<<scp;
}

void Str :: CharDelete()
{
    char c;
    scp1 = s;
    cout<<"\n\nEnter character which you would like to delete: ";
    cin>>c;
    for (i=0;scp1[i]!='\0';i++)
    {
        if(scp1[i]==c)
            scp1.erase(i,1);
    }
    cout << "New string: " << scp1;
}

void Str :: Palindrome()
{
    flag = 0;
    for (i=0;s[i]!='\0';i++)
    {
        if(s[i] != s[s.length()-i-1])
            flag = 1;
    }
    if (flag == 1)
        cout<<"\nString is not a palindrome.";
    else
        cout<<"\nString is a palindrome.";
}

int main()
{
    Str s1;
    int j=1;
    char ch;
    while(j==1)
    {
        cout<<"\n\nSelect your choice:\n1.Frequency\n2.Delete\n3.CharDelete\n4.Palindrome\nOr any key to exit:";
        cin>>ch;
        switch(ch)
        {

            case '1':
                s1.Frequency();
                break;
            case '2':
                s1.Delete();
                break;
            case '3':
                s1.CharDelete();
                break;
            case '4':
                s1.Palindrome();
                break;
            default:
                j=0;
                break;
        }
    }
    return 0; //EXIT_SUCCESS
}
