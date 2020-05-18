#include <cstring>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <stack>
using namespace std;

const int maxf = 0, minf = 1, size = 100; // определили константы
typedef struct _t // объявили тип элемента стека
{
    int data[size];
    int cur;
}
st;
void init(st* s) // функция инициализации стека
{
    for(int i = 0; i < size; i++)
        s -> data[i] = 0;
    s -> cur = -1;
}
int empty(st *s)// функция проверки пустоты стека
{
    return s -> cur == -1;
}
void push(st *s,int i) // функция заталкивания элемента в стек
{
    s -> data[++(s -> cur)] = i;
}

int pop(st *s) // функция извлечения элемента из стека
{
    return empty(s)?0:s -> data[(s -> cur)--];
}

int main()
{
ifstream input("stqu_file.txt"); // объявили входной поток из файла
const int l=100;
char e[l];
char buf[l];
st s;
init(&s);
// объявляем переменные и инициализируем стек
input.getline(e,l,'\n'); // ввели строку из файла
int i,j,len = strlen(e); // определили длину введенной строки
for(i = 0; i < len; i++)
{
    if(e[i]=='M')
    {
        push(&s,maxf); continue;
    }
    if(e[i]=='m')
        {
            push(&s,minf);
            continue;
        }
    if(isdigit(e[i])) // заталкиваем в стек коды операций и числа
        {
            j=0;
            while(isdigit(e[i]))buf[j++]=e[i++];
            buf[j]=' ';
            push(&s,atoi(buf));
        }
    if(e[i]==')')
        {
            int b = pop(&s);
            int a = pop(&s);
            int func = pop(&s);
            if(func == maxf)
                {
                    push(&s,a>b?a:b);
                }
            else push(&s,a<b?a:b);
        }
// если попадается закрывающая скобка, вытаскиваем из стека два числа и код
// операции, производим операцию и закидываем результат обратно в стек
}
cout << e << endl << pop(&s) << endl; //выводим строку исходного выражения и результат
cin.get(); // задерживает закрытие окна вывода до нажатия Enter
return 0;
}
