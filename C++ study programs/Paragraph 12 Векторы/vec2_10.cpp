#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // подключаем русский язык в консоли
    vector <int> iVec; // объявляем объект типа "vector" для хранения последовательности целых чисел
    int x, n; // целочисленные переменные для промежуточного хранения значения эл-тов векторов и изначального макс. числа эл-то для цикла
    cout << "n = ";
    cin >> n;
    for(int i = 0; i < n; i++) // цикл ввода эл-тов в вектор iVec
    {
        cout << "Введите элемент с номером " << i << endl;
        cin >> x;
        iVec.push_back(x); // добавление эл-та в конец вектора с помощью функции "push_back"
    }
    cout << endl;
    int zam = 0; // целочисленная переменная для хранения значения нового элемента
    cout << "Введите значение нового элемента: ";
    cin >> zam;
    cout << endl;
    for(vector <int>::iterator it = iVec.begin() - 1; it != iVec.end() - 1; ++it) // цикл вставки перед каждым чётным числом нового элемента
    {
        if ((*(it+1))%2 == 0) // если значение следующего элемента вектора на месте it+1 чётно, то:
        {
            it = iVec.insert(it+1, zam);
            // при помощи функции "insert" вставляем новый элемент "zam" перед чётным элементом стоящем на месте it+1
        }
    }
    cout << endl;
    for(vector <int>::iterator it = iVec.begin(); it != iVec.end(); ++it) // цикл вывода изменённого вектора на экран
    {
        cout << *it << " ";
    }
    return 0;
}
