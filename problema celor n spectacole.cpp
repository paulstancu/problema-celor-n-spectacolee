#include <fstream>

using namespace std;

ifstream fin("spectacole.in");
ofstream fout("spectacole.out");

float start, stop, G[100][2];
int k, n, m=1, nr[100];

void citire()
{
    fin>>start>>stop;
    fin>>n;
    for(int i=1; i<=n;i++)
    {
        for(int j=1;j<=2;j++)
        {
            fin>>G[i][j];
        }
        nr[i]=i;
    }
    fin>>k;
    fin.close();
}

void sortare()
{
    int aux, schimb;
    do
    {
        schimb=0;
        for(int i=1;i<n;i++)
            if(G[nr[i]][2]>G[nr[i+1]][2])
            {
                aux=nr[i];
                nr[i]=nr[i+1];
                nr[i+1]=aux;
                schimb=1;
            }
    }
    while (schimb);
}

void compensate(int n, int k)
{
    int ora, mint, a;
    for(int i=1;i<=n;i++)
    {
        a=G[nr[i]][2]*100;
        ora=a/100;
        mint=a%100+k;
        if(mint>=60)
        {
            ora++;
            mint=mint-60;
        }
        a=(ora*100+mint)/(float)100;
        G[nr[i]][2]=a;
    }
}

int rezolvare()
{
    int ultim=0;
    for(int i=1;i<=n;i++)
    {
        if(G[nr[i]][1]>start && G[nr[i]][2]<stop)
        {
            if(G[nr[i]][1]>=G[nr[ultim]][2])
            {
                m++;
                ultim=i;
            }
        }
    }
}

int main()
{
    citire();
    sortare();
    compensate(n, k);
    rezolvare();
    fout<<m;
    fout.close();
    return 0;
}
