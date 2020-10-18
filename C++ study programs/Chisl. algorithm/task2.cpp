#include <iostream>
using namespace std;

double Interpol (double* x, double* F_x, int N, double t){
double Sum = 0;
for (int i = 0; i < N; i++){
double Proiz= 1;
for (int j = 0; j < N; j++){
if (!(j == i)){
Proiz *= (t - x[j])/(x[i]-x[j]);
}
}
Sum += (Proiz* F_x[i]);
}
return Sum;
}

int main(){
int n;
cout << "Vvedite chislo tochek:";
cin >> n;
double *x = new double [n];
double *y = new double [n];
for (int i = 0; i < n; i++) {
cout << "Vvedite x["<< i+1 <<"]:"<< endl;
cin >> x [i];
cout << "Vvedite f(x)["<< i+1 <<"]:"<< endl;
cin >> y [i];
}
double x0;
cout << "Vvedite x - neobhodimyu vicheslit:"<< endl;
cin >> x0;
cout << "Itog:" << endl << Interpol (x,y,n,x0);
cin >> x0;
return 0;
}
