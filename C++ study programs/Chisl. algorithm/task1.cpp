#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double Interpol (double* x, double* F_x, int N, double t) // функция подсчёта интерполяционного многочлена Лагранжа
{
    double Sum = 0; // переменная для подсчёта суммы произведений значений функции на базисный полином
    for (int i = 0; i < N; i++) // цикл подсчёта инт. многочлена 
    {
        double P = 1; // Базисный полином
        for (int j = 0; j < N; j++) // подсчёт базисного полинома
        {
            if (!(j == i)){ // если j не равно i то продолжаем умножение
            P *= (t - x[j])/(x[i]-x[j]); // Базисный полином
            }
        }
    Sum += (P* F_x[i]);
    }
return Sum;
}

int main(){
int n;
cout << "Vvedite chislo tochek:";
cin >> n;
double *x = new double [n]; // переменная для x
double *y = new double [n]; // переменная для значения функции от x
for (int i = 0; i < n; i++)  // цикл ввода значений x
{
    cout << endl <<  "x["<< i+1 <<"]   = ";
    cin >> x[i];
    y [i] = cosh(x[i]);
    cout << "f(x)["<< i+1 <<"]= "<< y[i] << endl;
}
cout << setprecision(10);
double x0;
cout << endl << "Vvedite x - neobhodimyu vicheslit:";
cin >> x0;
cout << endl << "Rezultat:" << endl << Interpol (x,y,n,x0);
return 0;
}
