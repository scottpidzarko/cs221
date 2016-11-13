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
  if( n < 0) 
	std::cout << "Cannot play Towers of Hanoi with a negative number of disks" << std::endl;
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}

//assumes n is the smallest disk
void moveDisks( int n, const char* FROM, const char* VIA, const char* TO){

	//do nothing case
	if( n == 0) return;
	
	//base case - move one disk from some place to another
	if( n == 1){
	
		//print output of a discrete step
		std::cout << "Moved disk from " << FROM << " to " << TO << std::endl;	
	}
	//recursion (n > 1)
	if( n > 1){
		moveDisks( n-1, FROM, TO, VIA);
		moveDisks( 1, FROM,  VIA, TO);
		moveDisks( n-1, VIA, FROM , TO);
	}
}

