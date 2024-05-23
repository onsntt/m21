#include <iostream>

//  знак & после указания ТИПА ПЕРЕМЕННОЙ говорит о том, что тут мы создаем ССЫЛКУ на переменную этого типа

int main(){
int x = 42;

int& ref = x; // переменная ref типа "ссылка на int" равна значению целочисленной переменной х. Знак & после int говорит о том, речь идет именно о ссылке на int 
              // ref является псевдонимом х 
std::cout << ref << "\n"; 

// теперь ссылка на переменнную типа std::string

std::string str1 = "Vata kakaya-to";
std::string& str2 = str1;
std::cout << str2 << " " << str1.size() << "\n"; // выведет Vata kakaya-to 14

str1.clear();

std::cout << str2 << " " << str1.size() << "\n"; // выведет  0


}