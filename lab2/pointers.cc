#include <iostream>

int main() {
  int* p1;
  int* p2;
  int x = 5;
  int y = 15;

  p1 = &x; 	 	// x contains ____; y ____; p1 ____; p2 ____
 
  p2 = &y;	 	// x contains ____; y ____; p1 ____; p2 ____
 
  *p1 = 6; 		// x contains ____; y ____; p1 ____; p2 ____
 
  *p1 = *p2;	// x ____; y ____; p1 ____; p2 ____
 
  p2 = p1; 		// x ____; y ____; p1 ____; p2 ____
 
  *p1 = *p2+10; // x ____; y ____; p1 ____; p2 ____
  
  return 0;
}
