#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// declare a Rover struct to hold rover data
struct Rover {
  int type;         // either 1, 2, or 3
  string id;        // 4 alphanumeric characters
  double charge;    // % of charge, between 0 and 1
  int capacity;
  bool isSelected;
};

// print a Rover struct in the form: 
//   Type <type> Rover #<id> (<charge>%)
void printRover(const Rover &rover, ostream &output) {
  output << "Type " << rover.type;
  output << " Rover #" << rover.id; 
  output << " (" << (rover.charge * 100) << "%)";
  output << " carrying " << rover.capacity << "kg. ";
}

// print the values of the whole fleet
void printFleet(const vector<Rover> &fleet, ostream &output){

  // traverse the fleet vector
  for (size_t i = 0; i < fleet.size(); ++i) {
    printRover(fleet.at(i),output); // use helper function to print a single rover
    output << endl; // go to a newline after this rover is printed
  }
}

// load the rover data from an input stream
void loadRovers(vector<Rover> &rovers, istream &is){

  // Create a Rover variable to hold the data that is read in
  Rover rover; 
  rover.isSelected = false;
  // Continue reading data until the end of the file is reached
  while (is >> rover.type >> rover.id >> rover.capacity >> rover.charge) {
    // Add this rover to the vector
    rovers.push_back(rover);
  }

}


// TODO: add desirability function here
double desirability(const Rover &rover) {
  if (rover.charge > 0.9) {
    return rover.capacity/0.1;
  }
  return rover.capacity / (1 - rover.charge);
}



// Driver program to select rovers for a mission
int main() {

  // Create an empty vector of rovers
  vector<Rover> fleet;

  // Create an input file stream to a file with rover data
  ifstream roversInput("rover_data.txt");
  
  // check if the file was opened; end program if not
  if(!roversInput.is_open()) {
    cout << "ERROR READING ROVERS DATA FILE" << endl;
    return 1;
  }

  // Load a set of rovers from a file into fleet
  loadRovers(fleet, roversInput);

  // Close the file
  roversInput.close();

  // Print the values of this fleet
  cout << "This is what is in fleet: " << endl;
  printFleet(fleet,cout);

  // ---- Test desirability helper function ---- //

  // Special Case: charge = 1.0 (fully charged)
  Rover testRover = {1, "test", 1.0, 100, false};
  cout << "desirability of test rover: " ;
  cout << desirability(testRover) << endl; // should print 1000

  // General Case: charge <= 0.9
  cout << "desirability of second rover in fleet: " ;
  cout << desirability(fleet.at(1)) << endl; // should print 250
  cout << desirability(fleet.at(4)) << endl;
  printRover(testRover,cout);
}