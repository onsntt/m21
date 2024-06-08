#include <iostream>
#include <vector>
enum room_type
{
    living = 1,
    children = 2,
    bedroom = 3,
    kitchen = 4,
    bathroom = 5
};

struct room
{
    double area;
    room_type type;
};
struct store
{
    double height;
    std::vector<room> rooms;
};

enum building_type
{
    house = 1,
    garage = 2,
    barn = 3,
    bath = 4
};

struct building
{
    bool has_chimney;
    building_type type;
    double area;
    std::vector<store> stores;
};

struct plot
{
    int number;
    double area;
    std::vector<building> buildings;
};

struct village
{
    std::vector<plot> plots;
};

std::string bType(building_type x)
{
    std::string str;
    switch(x)
      {
      case 1:
          str = "House";
          break;

      case 2:
          str = "Garage";
          break;

      case 3:
          str = "Barn";
          break;

      case 4:
          str = "Bath";
          break;
      }
    return str;



}
std::string rType(room_type x)
{
    std::string str;
    switch (x)
    {
    case 1:
        str = "Living room";
        break;

    case 2:
        str = "Children room";
        break;

    case 3:
        str = "Bedroom";
        break;

    case 4:
        str = "Kitchen";
        break;

    case 5:
        str = "Bathroom";
        break;    
    }
    return str;
}

int main()
{
    int plotCount = rand()%100 + 10;
    
    
    village v;
    for (int i = 0; i < plotCount; i++)
    {
        plot p;
        p.number = i + 1;
        p.area = rand()%5 + 11;
        int buildingCount = rand()%4 +1;
       
        for (int j = 0; j < buildingCount; j++)
        {
            building b;
            b.type = building_type(rand()%4 + 1);
            
            b.area = rand()%100 + 80;
            int storeCount;
            if (b.type == house || b.type == bath) 
            {
                b.has_chimney = rand()%2;
            } else
                b.has_chimney = 0;
                    if (b.type == house)
                {
                    storeCount = rand() % 3 + 1;
            }
            else
            {
                storeCount = 1;
            }
            
            for (int l = 0; l < storeCount; l++)
            {
                store s;
                s.height = rand()%11 + 250;
                int roomCount;
                if(b.type == house) 
                  {
                      roomCount = rand() % 3 + 2;
                  }
                else
                  {
                    roomCount = 0;
                  } 

                for (int w = 0; w < roomCount; w++)
                {
                    room r;
                    r.area = rand()%10 + 12;
                    r.type = room_type(rand()%5 + 1);
                    s.rooms.push_back(r);
                }
                b.stores.push_back(s);
            }
            p.buildings.push_back(b);
        }
        v.plots.push_back(p);
    }
    for (int i = 0; i < plotCount; i++)
    {
        std::cout << "\nPlot number - " << v.plots[i].number << "\n";
        std::cout << "Plot " << v.plots[i].number << " area is " << v.plots[i].area << "\n";
        std::cout << "There are " << v.plots[i].buildings.size() << " buildings on this plot\n";

        for (int j = 0; j < v.plots[i].buildings.size(); j++)
        {
             
             std::cout << "\tBuilding " << bType(v.plots[i].buildings[j].type) << "\n";
             std::cout << "\t" << bType(v.plots[i].buildings[j].type) << " area is " << v.plots[i].buildings[j].area << "\n";
             std::cout << "\tThis building has " <<  v.plots[i].buildings[j].stores.size() << " stores \n";
             if (v.plots[i].buildings[j].has_chimney == 1) std::cout << "\t There is a chimney in this building \n";
                 for (int l = 0; l < v.plots[i].buildings[j].stores.size(); l++)
                 {
                     std::cout << "\t" << "\t Store " << l + 1 << " has " << v.plots[i].buildings[j].stores[l].rooms.size() << " rooms.\n";
                     std::cout << "\t" << "\t The height of this store is " << v.plots[i].buildings[j].stores[l].height << " \n";
                     for (int w = 0; w < v.plots[i].buildings[j].stores[l].rooms.size(); w++)
                     {
                         std::cout << "\t"<< "\t"<< "\t" << "Room " << w + 1 << " is a " << rType(v.plots[i].buildings[j].stores[l].rooms[w].type) << "\n";
                         std::cout << "\t" << "\t" << "\t" << rType(v.plots[i].buildings[j].stores[l].rooms[w].type) << " area is " << v.plots[i].buildings[j].stores[l].rooms[w].area << "\n";
                     }
                 }
        }
    }
    
}