#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
 
 long double fact(int N)
{
    if(N < 0) // если пользователь ввел отрицательное число
        return 0; // возвращаем ноль
    if (N == 0) // если пользователь ввел ноль,
        return 1; // возвращаем факториал от нуля - не удивляетесь, но это 1 =)
    else // Во всех остальных случаях
        return N * fact(N - 1); // делаем рекурсию.
}
 
int main() {
    setlocale(LC_ALL, "Russian"); // подключаем русский язык в консоли
	double E = 0.001, x1;  // Точность
	int k = 0; // переменная для удобного подсчёта степени и факториала производной
	cout << "Vvedite x = "; // просим ввести x
	cin >> x1; // считываем x
	double x = 1, y = x1;// ((-1)^0)/0! = 1 : первый член суммы
	// первый член суммы производных функции = 0, поэтому я беру второй член, который всегда будет равен самому, введённому x
	double sum = 1, sum2 = x1;// При любой точности сумма начинается с первого члена
	for(int i = 1; ; i++)
	{ // Цикл подсчета суммы пока член суммы по модулю больше точности
		x = pow(x1,i*2)/fact(i*2); 
		if (abs(x) > E)
		{
		    sum += x;
		}
		else { break;}
	}
	for(int i = 1; ; i++)
	{ // Цикл подсчета суммы производных пока член суммы по модулю больше точности
	        k = 2*i-1;
		y = pow(x1,k)/fact(k);
		if (abs(y) > E)
		{
		    sum2 += y;
		}
		else { break;}
	}
    cout << setprecision(10);
	cout << "Summa ryada funkcii = " << sum << "\n";
	cout << "Summa ryada proizvodnih ot funkcii = " << sum2 << endl;
	cout << "Posledniy x = " << x << "\n" << "Posledniy y = " << y;
	return 0;
}
