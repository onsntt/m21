#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
// передать значения в функцию можно не только по указателям, но и по ссылкам:

// !!!!! изменен тип поля name - string вместо char
// в цикле применили функцию к массиву из 10 экземпляров структуры hero

struct hero // создали структуру hero, в ней - поля "имя", "здоровье", "броня". С++ позволяет сразу дать значения по умолчанию
{
    std::string name = "unknown";
    int health = 0;
    int armor = 0;
};

void takeDamage(hero &man, int damage) // передаем теперь параметр по ссылке (& после объявления типа)
                                       // переменные - ссылки используются так же, как и просто переменные.
                                       // чтобы добраться к полям придется использовать "через точку" вместо "стрелки"

{
    // обратиться к полю  структуры можно по-разному. В данном случае используем не стрелку ->, а точку.
    man.armor -= damage;
    if (man.armor < 0)
    {
        man.health += man.armor;
        man.armor = 0;
    }

    std::cout << man.name << " took damage " << damage << ". Actual armor = " << man.armor << ", actual healh = " << man.health << ", damage power was " << damage << "\n";
}

void save (std::ofstream& saveFile, hero& man)
{
    int nameLength = man.name.length(); // используем функцию length() для определения длины имени (поля name)
    saveFile.write((char*)&nameLength, sizeof(nameLength)); // пишем в файл значение переменной nameLength, приведенное к типу char. Размер получим через sizeof(nameLength)
    saveFile.write(man.name.c_str(), nameLength); // пишем в файл имя, приведенное к формату с-строки функцией c_str(). Длина имени у нас посчитана и равна nameLength
    saveFile.write((char*)&man.health, sizeof(man.health));
    saveFile.write((char*)&man.armor, sizeof(man.armor));
}

void load(std::ifstream& loadFile, hero& man)
{
    int nameLength;
    loadFile.read((char*)&nameLength, sizeof(nameLength) );
    man.name.resize(nameLength);
    loadFile.read((char*)man.name.c_str(), nameLength );
    loadFile.read((char*)&man.health, sizeof(man.health));
    loadFile.read((char*)&man.armor, sizeof(man.armor));

}

int main()
{
    hero people[10]; // создали массив из 10 экземпляров переменных типа hero

    

    // инициализируем все элементы всех экземпляров
    for (int i = 0; i < 10; i++)
    {
        people[i].name = "Hero #" + std::to_string(i); // внимание!!! привели int к string'у
        people[i].health = (std::rand() % 100) + 100;
        people[i].armor = (std::rand() % 41) + 10;
    }

    std::cout << "initialized:\n";
    for (int i = 0; i < 10; i++)
  {

    std::cout << people[i].name <<" "<< people[i].health << " " <<people[i].armor << "\n";
  }
  
std::ofstream saveFile("save.bin", std::ios::binary);
   for (int i = 0; i < 10; i++)
     {
        save (saveFile, people[i]);
     }
     saveFile.close();
    
std::cout << "saved\n";



for (int i = 0; i < 10; i++)
    {
        takeDamage(people[i], 30); 
    }


for (int i = 0; i < 10; i++)
  {

    std::cout << people[i].name <<" "<< people[i].health << " " <<people[i].armor << "\n";
  }
std::cout << "posle pizduley\n";
std::cout << "let's restore\n";
std::ifstream loadFile ("save.bin", std::ios::binary);
for (int i = 0; i < 10; i++)
  {
    load(loadFile, people[i]);
  }
loadFile.close();
for (int i = 0; i < 10; i++)
  {

    std::cout << people[i].name <<" "<< people[i].health << " " <<people[i].armor << "\n";
  }
  


}