include <iostream> // пррграмма заменяет символ 1 в некотором слове на символ 2
#include <cstring>
using namespace std;

string replace( string s1, string s2, string str){
while ( str.find(s1) != string::npos) // пока в слове есть заменяемая буква
{
    int pos;
    pos = str.find(s1); // переменная обозначающая позицию заменяемого символа s1
    str.replace(pos, 1, s2); // заменяем в строке str 1 символ позиции pos на символ s2
}
return str;
}

int main() {
tryAgain:
string str;
cout << "Vvedite slovo" << endl;
getline(cin,str);
if ( str.length() < 2 ) // проверка слова на то чтобы в нём было более 1 символа
{
    cout << "Error" << endl << "Slovo dolhzno soderzhat bolee 1 simvola" << endl << endl;
    goto tryAgain;
}
string s1, s2;
cout << "Vvidite zamenyaemiy simvol" << endl;
getline(cin,s1);
cout << "Vvedite simvol na kotoriu zamenit" << endl;
getline(cin,s2);
if ((s1.length() > 1) || (s2.length() > 1)) // проверка букв на то чтобы не было более 1 символа
{
    cout << "Error!" << endl << "Nuzhno vvodit tolko 1 bukvu!" << endl << endl;
    goto tryAgain;
}
cout << replace(s1, s2, str);
return 0;
}
