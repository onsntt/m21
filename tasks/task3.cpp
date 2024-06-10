#include<iostream>
//#include<vector>
//#include<string>
#include<cmath>


struct dmv
{
    double x;
    double y;
};

void getVec1 (dmv& vec1)
{
    std::cout << "Enter 2D-vector parameters" << std::endl;
    std::cout << "Enter X: ";
    std::cin >> vec1.x;
    std::cout << "Enter Y: ";
    std::cin >> vec1.y;
    std::cout << "2D-vector is {" << vec1.x << ";" << vec1.y << "}" << std::endl;
    
}

void getVec2(dmv& vec2)
{
    std::cout << "Enter second 2D-vector parameters\n";
    std::cout << "Enter X: ";
    std::cin >> vec2.x;
    std::cout << "Enter Y: ";
    std::cin >> vec2.y;
    std::cout << "second 2D-vector is {" << vec2.x << ";" << vec2.y << "}\n";
}

void add(dmv& vec1, dmv& vec2)
{
    std::cout << "add\n";
    getVec1(vec1);
    getVec2(vec2);
    std::cout << "Here is the result of two 2D-vectors adding:\n";
    std::cout << "{" << vec1.x + vec2.x << ";" << vec1.y + vec2.y << "}\n";
}

void subtract(dmv& vec1, dmv& vec2)
{
    getVec1(vec1);
    getVec2(vec2);
    std::cout << "Here is the result of two 2D-vectors subtraction:\n";
    std::cout << "{" << vec1.x - vec2.x << ";" << vec1.y - vec2.y << "}\n";
}

void scale(dmv& vec1)
{
    getVec1(vec1);
    std::cout << "Enter scalar value: ";
    double scalarVal;
    std::cin >> scalarVal;
    std::cout << "Here is the result of 2D-vector multiply by a scalar:" << std::endl;

    std::cout << "{" << vec1.x * scalarVal << ";" << vec1.y * scalarVal << "}" << std::endl;
    
}

void length(dmv& vec1)
{
    getVec1(vec1);
    std::cout << "Here is the length of 2D-vector:\n";
    double vLength = sqrt(std::pow (vec1.x, 2) + std::pow(vec1.y,2));
    std::cout << vLength << "\n";
}

void normalize(dmv& vec1)
{
    getVec1(vec1);
    std::cout << "Here is the rezult of 2D-vector normalizing:\n";
    double vLength = sqrt(std::pow(vec1.x, 2) + std::pow(vec1.y, 2));
    std::cout << "{" << vec1.x / vLength << ";" << vec1.y /vLength << "}\n";
}



    int main(){
       bool more = true;
       dmv vec1;
       dmv vec2;
       while (more)
       {
           std::string action = " ";
          while (action != "add" && action != "subtract" && action != "exit" && action != "length" && action != "normalize" && action != "scalar" )
          {
               std::cout << "Select operation: \n"
                         << "add for two 2D-vectors adding\n"
                         << "subtract for subtraction\n"
                         << "scalar for multiply by a scalar\n"
                         << "length for length\n"
                         << "normalize for normalizing\n"
                         << "exit to quit\n";

               std::cin >> action;
           }

           if (action == "add")
           {
             add(vec1, vec2);
           }
           else if(action == "subtract")
           {
             subtract(vec1, vec2);
           }
           else if (action == "scalar")
           {
            scale(vec1);
           }
           else if (action == "length")
           {
            length(vec1);
           }
           else if (action == "normalize")
           {
            normalize(vec1);
           }

           else if (action == "exit")
           {
               std::cout << "Exit selected.\n";
               more = false;
               return 0;
           }
       }
    }