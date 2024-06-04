#include <iostream>
#include <vector>

struct room
{
    bool roomExist = 0;
    enum roomType
    {
        none,
        bedroom,
        kitchen,
        bathroom,
        childrenroom,
        livingroom
    };
    double roomSize;
};

struct houseFloor
{
    int floorNumber;
    int roomCount;
    double floorHeight = 2.5;
    enum floorType
    {
        none,
        first,
        second,
        third
    };
    enum rooms
    {
        room1,
        room2,
        room3,
        room4
    };
};

struct house
{
    bool houseExist = 0;
    int floorCount;
    double houseSize;
    houseFloor firstFloor;
    houseFloor secondFloor;
    houseFloor thirdFloor;
    bool furnace = 0;
};

struct outbuilding
{
    bool obExist = 0;
    enum outbuildingType
    {
        none,
        bathhouse,
        garage,
        barn
    };

    double outbuildingSize;
};

struct bathhouse
{
    bool furnace = 0;
};

struct plot
{
    int number;
    house house1;
    outbuilding ob1;
    outbuilding ob2;
    outbuilding ob3;
};

struct town
{
  std::string name = "sometown";
  int plotCount = 0;

};










   



int main() {

room r1;





}