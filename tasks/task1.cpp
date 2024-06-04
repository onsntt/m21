#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <limits>

struct record
{
  std::string name;
  std::string surname;
  double sum;
  std::string date;
};


bool isName(std::string str)
{
    //char xx;
    if ((str[0]) < (char)65 || str[0] > (char)90) 
      {
        std::cout << "First letter must be big one!\n";
        return false;
      }

    for (int i = 0; i < str.length(); i++)
    {
        bool big = true;
        bool small = true;
        bool space = true;
        bool minus = true;
        //xx = str[i];
        if ((str[i] < (char)65 || str[i] > (char)90))    big = false;

        if ((str[i] < (char)97 || str[i] > (char)122))    small = false;

        if (str[i] != (char)32) space = false;

        if (str[i] != (char)45) minus = false;

        if (big == false && small == false && space == false && minus == false) return false; 
      }

return true;
}

bool correctSum(std::string str)
{
    int dotNumber = 0;
    for (int i = 0; i < str.length(); i++)
    {
        bool digit = true;
        bool dot = true;
        
         if ((str[i] < (char)48 || str[i] > (char)57)) digit = false;
         if (str[i] != (char)46) dot = false;
         if (str[i] == (char)46) dotNumber++;
         if((digit == false && dot == false) || dotNumber >1) return false;
    }

    return true;

}   

bool dateOk(std::string str)
{
    if (str.length() != 10 )
    {
        std::cout << "Incorrect date format!\n";
        return false;
    } 
    int dotNumber = 0;
    for (int i = 0; i < str.length(); i++)
    {
        bool digit = true;
        bool dot = true;

        if ((str[i] < (char)48 || str[i] > (char)57)) digit = false;
        if (str[i] != (char)46) dot = false;
        if (str[i] == (char)46) dotNumber++;
        if ((digit == false && dot == false))
        {
            std::cout << "Incorrect symbol in date!\n";
            return false;
        } 
        if (str[2] != (char)46 && str[5] != (char)46)
        {
            std::cout << "Incorrect date format! Where are the dots?\n";
            return false;
        } 

    }

    int day = std::stoi(str.substr(0, 2));
    if (day <= 0)
    {
        std::cout << "There no day less than 1 in mounth!\n";
        return false;
    } 
    int month = std::stoi(str.substr(3, 2));
    if (month < 1 || month > 12)
    {
        std::cout << "There are no month less than 1 in a year!\n";
        return false;
    } 
    int year = std::stoi(str.substr(6, 4));
    int months[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)) months[1] = 28;
    if (day > months[month-1]) 
    {
        std::cout << "There are not so many days in this month!\n";
        return false;
    }    
    return true;
}

void save (std::ofstream& sfile, record& man)
{
    int nameLength = man.name.length(); // используем функцию length() для определения длины имени (поля name)
    sfile.write((char*)&nameLength, sizeof(nameLength)); // пишем в файл значение переменной nameLength, приведенное к типу char. Размер получим через sizeof(nameLength)
    sfile.write(man.name.c_str(), nameLength); // пишем в файл имя, приведенное к формату с-строки функцией c_str(). Длина имени у нас посчитана и равна nameLength
    int surnameLength = man.surname.length();
    sfile.write((char*)&surnameLength, sizeof(surnameLength));
    sfile.write(man.surname.c_str(), surnameLength);
    sfile.write((char*)&man.sum, sizeof(man.sum));
    int dateLength = man.date.length();
    sfile.write((char*)&dateLength, sizeof(dateLength));
    sfile.write(man.date.c_str(), dateLength);
   
}

void review (std::ifstream& rFile, record& man)
{
  

  
  int nameLength;
  rFile.read((char *)&nameLength, sizeof(nameLength));
  man.name.resize(nameLength);
  rFile.read((char *)man.name.c_str(), nameLength);
  int surnameLength;
  rFile.read((char *)&surnameLength, sizeof(surnameLength));
  man.surname.resize(surnameLength);
  rFile.read((char *)man.surname.c_str(), surnameLength);
  rFile.read((char *)&man.sum, sizeof(man.sum));
  int dateLength;
  rFile.read((char *)&dateLength, sizeof(dateLength));
  man.date.resize(dateLength);
  rFile.read((char *)man.date.c_str(), dateLength);
  
  
}

int main() {
bool more = true;
record man;
while (more)
  {
    std::string action =" ";
    while (action != "add" && action != "list" && action != "exit")
      {
        std::cout << "Select operation (Type add for adding new record, list - for reading saved records or exit for exit): \n";
        std::cin >> action;
      }

      if (action == "add")
        {
          std::cout << "Adding new reckord selected.\n";
             std::cout << "Enter name (A-Z, a-z, -, space): ";
               std::string name;
               std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
               getline(std::cin, name);
               if (!isName(name))
                 {
                    std::cout << "Incorrect input. Program will be closed!\n";
                    return 0;
                 }
             std::cout << "Enter surname (A-Z, a-z, -, space): ";
               std::string surname;
               std::getline(std::cin, surname);
               if (!isName(surname))
                 {
                    std::cout << "Incorrect input. Program will be closed!\n";
                    return 0;
                 }
              std::cout << "Enter sum: ";
                std::string sum;
                std::getline(std::cin, sum);
                if (!correctSum(sum))
                 {
                   std::cout << "Incorrect input. Program will be closed!\n";
                   return 0;
                 }
                double realSum = stod(sum);
                realSum = round(realSum * 100) / 100;
             std::cout << "Enter date: ";
               std::string date;
               std::getline(std::cin, date); 
               if (!dateOk(date))
                {
                  std::cout << "Date is not correct. Program will be closed!\n";
                  return 0;
                }

                
                man.name = name;
                man.surname = surname;
                man.sum = realSum;
                man.date = date;   
                //vec.push_back(man);       
                //std::cout << vec.size()<< "\n";
                //record ooo = vec[0];
                //std::cout << ooo.name <<" " << ooo.surname << " "<< ooo.sum << " " << ooo.date << "\n";
                
             
              std::ofstream sfile ("recs.bin", std::ios::binary | std::ios::app);
              save(sfile, man);
              sfile.close();
             




        }

      else if (action == "list")
        {
            std::cout << "Reading records selected.\n";
            std::ifstream rFile("recs.bin", std::ios::binary);
            if (rFile.is_open())
            {
              while (!rFile.eof())
              {
                review(rFile, man);
                if (rFile.eof())
                  break;
                std::cout << man.name << " " << man.surname << " " << man.sum << " " << man.date << "\n";
              }

              rFile.close();
            } 
            else
            {
              std::cout << "There are no datafile, nothing to view!\n";
            }

            
            
        }  

      else if (action == "exit")
        {
            std::cout << "Exit selected.\n";
            more = false;
            return 0;
        }  
    
    
  }    





}