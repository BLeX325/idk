#include <iostream>
#include <cmath>
using namespace std;

double Func (double x)
{
    return exp(-1*x)*cos(x);
}

double Tr (double x, double h)
{
    return (fabs(Func(x)+Func(x+h)))*(h)/2;
}

double Int_Tr (double a, double b, int n)
{
    double h = (b-a)/(n) ;
    double Sum = 0;
    for (int i = 0; i < n; i++)
    {
        Sum += Tr (a+i*h, h);
    }
    return Sum;
}

int Poisk (double eps = 1e-2)
{
    int n = 1;
    for (; (1.0/(3*n*n*n)) > (eps / 2); n++){};
    return n;
}

double Runge (double a = 0, double n = 4, double eps = 1e-2)
{
    double b = Poisk ();
    double rez = Int_Tr(a,b,n);
    double Sled = Int_Tr(a,b,2*n);
    while ((fabs(rez - Sled))/3>= eps / 2)
    {
        rez = Sled;
        n = n*2;
        Sled = Int_Tr(a,b,2*n);
    }
    return rez;
}

int main(){
int n;
cout <<Poisk()<< endl<< Runge();
cin >> n;
return 0;
}
