#include <fstream>
#include <stack>
using namespace std;

int main()
{
    stack<int> t, t1;
    int i, x, y;
    ifstream in("1inp.txt");
    ofstream out("1outp.txt");
    in >> x;
    in >> y;
    while (in >> i) // считываем данные из файла в стек
    {
        t.push(i);
    }
    in.close();
    while (!t.empty()) // пока первый стек не пуст
    {
        // запоминаем значение верхнего жлемента из первого стека
        i = t.top();
        t1.push(i); // помещаем это значение во второй стек
        if (i == x) // есди это значение равно x, то
        {
            t1.push(y); // во второй стек записываем значение y
        }
        t.pop(); // удаляем верхний элемент из перового стека
    }
    // выводим содержимое второго стека в выходной файл
    while (!t1.empty())
    {
        out << t1.top() << " ";
        t1.pop();
    }
    out.close();
    return 0;
}
