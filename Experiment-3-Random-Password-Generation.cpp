#include <iostream>
using namespace std;
class password
{
public:
    int passno = 0;

    char passchar[7] = {'1', '3', 'a', 's', 't', 'i'};
    char genpass(void);
};
char password ::genpass()
{

    char pc[4];
    for (int x = 0; x < 6; x++)
    {

        for (int z = 0; z < 6; z++)

        {

            for (int j = 0; j < 6; j++)
            {

                for (int k = 0; k < 6; k++)
                {
                    pc[0] = passchar[x];
                    pc[1] = passchar[z];

                    pc[2] = passchar[j];
                    pc[3] = passchar[k];
                    if (pc[x] == pc[z] || pc[x] == pc[j] || pc[x] == pc[k] || pc[z] == pc[j] || pc[k] == pc[z] || pc[j] == pc[k])
                    {
                        continue;
                    }
                    else
                    {
                        cout << pc[0] << pc[1] << pc[2] << pc[3] << endl;
                        passno++;
                    }
                }
            }
        }
    }
    cout
        << passno;
    return 0;
}

int main()
{

    password p1;
    p1.genpass();
    // cout<<p1.passchar[2];
    return 0;
}
