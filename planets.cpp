#include <iostream>
#include <string>
using namespace std;

// declare a Planet struct to hold planet data
struct Planet {
  string name; // examples: "Earth", "Venus", "Proxima b"
  int density; // examples: 2901, 40988
};

// print a Planet struct in the form: 
//   Name: name_of_planet, Density: density_of_planet
void printPlanet(const Planet &planet, ostream &out){
  out << "Name: " << planet.name << ", ";
  out << "Density: " << planet.density << endl;
}

int main() {

  // Declare and initialize two planets using the Planet struct
  Planet mars = {"Mars", 3933};
  Planet jupiter = {"Jupiter", 1326};
  Planet jazmin = {"Jazmin", 2006};

  // Print out the planets
  printPlanet(mars,cout);
  printPlanet(jupiter,cout);
  printPlanet(jazmin,cout);

}

