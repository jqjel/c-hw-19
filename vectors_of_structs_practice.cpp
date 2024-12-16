#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// declare a Rover struct to hold rover data
struct Rover {
  int type;
  string id;
  double charge;
};

// print a Rover struct in the form: 
//   Type <type> Rover #<id> (<charge>%)
void printRover(const Rover &rover, ostream &output) {
  output << "Type " << rover.type;
  output << " Rover #" << rover.id; 
  output << " (" << rover.charge * 100 << "%)";
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
void loadRovers(vector<Rover> &fleet, istream &input){

  // Create a Rover variable to hold the data that is read in
  Rover rover; 

  // Continue reading data until the end of the file is reached
  while (input >> rover.type >> rover.id >> rover.charge) {
    // Add this rover to the vector
    fleet.push_back(rover);
  }

}

// Driver program to practice with a vector of structs
int main() {

  // Create a vector of "default rovers"
  Rover defaultRover = {1, "0000", 1};
  vector<Rover> fleet(3, defaultRover);

  // Print the values of the fleet to see what they start out as
  cout << "Original values of the rover fleet: " << endl;
  printFleet(fleet,cout);

  // Update the charge of the first rover
  fleet.at(0).charge = 0.45; 

  // Update the id of the second rover
  fleet.at(1).id = "b743";

  // Update the type of the third rover
  fleet.at(2).type = 3;

  // Print the updated values of the fleet
  cout << "Updated values of the rover fleet: " << endl;
  printFleet(fleet,cout);



  // Create an empty vector of rovers
  vector<Rover> new_fleet;

  // Create an input file stream to a file with rover data
  ifstream roversInput("rovers.txt");

  // check if the file was opened; end program if not
  if(!roversInput.is_open()) {
    cout << "ERROR READING ROVERS DATA FILE" << endl;
    return 1;
  }

  // Load a set of rovers from a file into new_fleet
  loadRovers(new_fleet, roversInput);

  // Close the file
  roversInput.close();

  // Print the values of this fleet
  cout << "This is what is in new_fleet: " << endl;
  printFleet(new_fleet,cout);

}