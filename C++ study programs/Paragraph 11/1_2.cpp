#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

ifstream in("input.txt"); // подключаем входной и выходной потоки
ofstream out("output.txt");
// исп. англ. язык в файле для того чтобы избежать ошибок, т.к. с++ не воспринимает UTF-8
// и считает ширину поля в байтах, а для некоторых букв кириллицы нужно более 1 байта
struct mas
{
    string fam, name, secondname;
    int ses[5]; // оценка по 5 предметам
    double key; // средняя оценка
    void print();
};
void mas::print() // вывод данных в выходной поток
{
    out << setw(12) << left << fam << setw(10) << name << setw(15) << secondname;
    for(int i = 0; i < 5; i++)
        out << setw(3) << ses[i];
    out << setw(5) << key << endl;
}
//сортировка массива записей из n элементов методом "пузырька"
void sort(mas *a, int n)
{
    mas temp; //  temp - временная переменная для обмена элементов местами
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (a[j].key < a[j - 1].key) // цикл проходит снизу вверх, начиная с предпоследнего
            {
                temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                // если ключь предпоследнего меньше чем последнего, то меняем их местами
            }
        }
}
}
int main ()
{
    int n = 0, m, i;
    mas stud[20]; // что делает???
    if (!in) // если входной поток не открывается
    {
        cout << "Error with file input.txt\n";
    }
    else
    {
        in >> m; // считываем номер группы
        // считываем данные про всех студентов
        while (in.peek() != EOF ) // пока следующий символ не конец файла
        {
            in >> stud[n].fam; // считывем фамилию, имя, отчество
            in >> stud[n].name;
            in >> stud[n].secondname;
            stud[n].key = 0; // средний балл (ключ) присвоить 0
            for (i = 0; i < 5; i++)
            {
                in >> stud[n].ses[i]; // считываем оценку
                stud[n].key += stud[n].ses[i]; // суммируем оценки
            }
            stud[n].key /= 5; // средний балл (ключь) присвоить сумму оценок делить на кол-во ( средний балл )
            n++;
        }
        sort(stud, n); // вызываем функцию сортировки
        out << m << endl; // выводим номер группы и переходим на след строку
        for (i = 0; i < n; i++)
            stud[i].print(); // выводим отсортированные данные в output.txt
    }
    in.close(); // закрываем потоки ввода/вывода
    out.close();
    return 0;
}
