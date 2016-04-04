#include <iostream>

float circle_area(float radius);  // declare function before main()

int main(void) {
  float circle_radius;
  std::cout << "Enter radius:" << std::endl;
  std::cin >> circle_radius;
  std::cout << "Area is: " << circle_area(circle_radius) << std::endl;
  return 0;
}

float circle_area(float radius) {
  return 3.14159 * radius * radius;  // = pi * r^2
}

// File I-O ----------------------------------------

#include <iostream>
#include <string>
#include <fstream>

int main(void) {
  std::ifstream in("infile.txt");       // input file-stream
  std::ofstream out("outfile.txt");     // output file-stream 
  std::string ss;
  // getline() puts next line in ss and discards any newline characters
  while (getline(in, ss))   
    out << ss << std::endl; // add each line to the new file, appending endl 
  std::cout << "End of program" << std::endl;
  return 0;
}

// Towers of Hanoi -------------------------

#include <cstdlib> // for atoi
#include <iostream>
// prototype 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
    return -1;
  }
  int n = atoi(argv[1]);
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}
// put your moveDisks() function here i// WARNING: This code will NOT compile.  
// It contains the code samples from the cs221 lab 1 write-up.

#include <iostream>

float circle_area(float radius);  // declare function before main()

int main(void) {
  float circle_radius;
  std::cout << "Enter radius:" << std::endl;
  std::cin >> circle_radius;
  std::cout << "Area is: " << circle_area(circle_radius) << std::endl;
  return 0;
}

float circle_area(float radius) {
  return 3.14159 * radius * radius;  // = pi * r^2
}

// File I-O ----------------------------------------

#include <iostream>
#include <string>
#include <fstream>

int main(void) {
  std::ifstream in("infile.txt");       // input file-stream
  std::ofstream out("outfile.txt");     // output file-stream 
  std::string ss;
  // getline() puts next line in ss and discards any newline characters
  while (getline(in, ss))   
    out << ss << std::endl; // add each line to the new file, appending endl 
  std::cout << "End of program" << std::endl;
  return 0;
}

// Towers of Hanoi -------------------------

#include <cstdlib> // for atoi
#include <iostream>
// prototype 
void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
    return -1;
  }
  int n = atoi(argv[1]);
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}
// put your moveDisks() function here 
