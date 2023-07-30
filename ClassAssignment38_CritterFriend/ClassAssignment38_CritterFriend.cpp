#include <iostream>
#include <string>

class Critter {
    //Make following global functions friends of the Critter class
    friend void Peek(const Critter& aCritter);
    friend std::ostream& operator<<(std::ostream& os, const Critter& aCritter);
public:
    Critter(const std::string& name = "");

private:
    std::string m_Name;

};

Critter::Critter(const std::string& name):
    m_Name(name)
{}

void Peek(const Critter& aCritter);
std::ostream& operator<<(std::ostream& os, const Critter& aCritter);

int main()
{
    Critter crit("Pooch");

    std::cout << "Calling Peek() to access crit's private data member, m_Name: \n";
    Peek(crit);

    std::cout << "\nSending crit object to cout with the <<operator: \n";
    std::cout << crit;

    system("pause");
}

//global friend function which can access all of Critter object's members
void Peek(const Critter& aCritter) {
    std::cout << aCritter.m_Name << "\n";
}

//global friend function which can access all Critter object's members
//overloads the << operator so you can send Critter object to cout
std::ostream& operator<<(std::ostream& os, const Critter& aCritter) {
    os << "Critter object - ";
    os << "m_Name: " << aCritter.m_Name<<"\n\n";
    return os;
}