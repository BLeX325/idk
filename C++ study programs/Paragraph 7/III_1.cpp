#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int main()
{
    string str, word, tmp; // иниц. строку, слово и пустую строку
    int k = 0; // счётчик появления искомого слова в строке
    cout << "Vvedite text" << endl;
    getline(cin, str);
    for (int i = 0; str[i]; i++) // замена всех букв в строке на нижний регистр
    {
        str[i] = tolower(str[i]);
    }
    int pos_dot, pos_com;
    while ( str.find(".") != string::npos) // пока в строке присутствует точка
    {
        pos_dot = str.find("."); // присваеваем переменной позицию точки в тексте
        str.replace(pos_dot, 1, " "); // заменяем точку на пробел, для считывания слов слитных с точкой
    }
    while ( str.find(",") != string::npos) // пока есть запятая
    {
        pos_com = str.find(","); // pos_com = possition_comma, comma - запятая
        str.replace(pos_com, 1, " ");
    }
    cout << "Vvedite slovo" << endl;
    getline(cin,word);
    for (int i = 0; word[i]; i++) // замена всех букв вслове на нижний регистр
    {
        word[i] = tolower(word[i]);
    }
    istringstream ist(str); // превращаем строку в поток
    while ( ist >> tmp ) // читаем из потока символы, разделителем служит пробел, и кладём их в пустую строку tmp пока не закончится
        if ( tmp == word ) // проверяем является ли прочитанное слово искомым
            ++k; // считаем количество совпадений
 cout << "Dannoe slovo vstretilos " << k << " raz." << endl;
}
© 2020 GitHub, Inc.
