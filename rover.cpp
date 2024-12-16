#include <iostream>
#include <string>

using namespace std;

struct Rover {
  int type;
  string id;
  double charge;
};

void printRover(const Rover &rover, ostream &output) {
	output << "Type " << rover.type << " ";
  output << "Rover #" << rover.id << " ";
  output << "(" << rover.charge * 100 << "%)" << endl;
  
}

int main() {
  Rover myRover;
  myRover.type = 1;
  myRover.id = "a238";
  myRover.charge = 0.8;

  // This should print "Type 1 Rover #a238 (80%)"
  printRover(myRover, cout);
  cout << endl; 
}