#ifndef _ARRAYQUEUESOLN_CPP
#define _ARRAYQUEUESOLN_CPP

//ArrayQueueSoln.cpp

#include "ArrayQueue.hpp"
#include <cstdlib> //for NULL
#include <cassert>
#include <iostream>
using namespace std;

// 221 STUDENTS:
//
// This skeleton file (along with the .hpp) is
// here to help get you started, but you are
// free to change function signatures, etc.
// as long as ArrayQueue is some subtype
// of BagOfMazeStates
ArrayQueue::ArrayQueue()
{
  // Constructor: initialize member variables
  //              and do any other initialization
  //              needed (if any)
  // TODO: implement constructor
}

void ArrayQueue::add(MazeState *elem)
{
  // TODO: implement add method
  if ((tail+1) % (capacity+1) == head) {
    // queue is full
    ensure_capacity(capacity+1); // ensure_capacity makes grows the array.
  }

  // Your code goes here...
}

MazeState *ArrayQueue::remove()
{
  // TODO: implement remove method
  assert(!is_empty());
  MazeState *temp = array[head];
  head = (head+1) % (capacity+1);
  return temp;
}

bool ArrayQueue::is_empty()
{
  // TODO: implement is_empty method
  return (head==tail);
}

// TODO: implement ensure_capacity (but leave this to last.. just start with lots of capacity!)
void ArrayQueue::ensure_capacity(int n)
{
  if (capacity < n) {
    // Make plenty of room.
    int target_capacity = (n > 2*capacity+1) ? n : (2*capacity+1);

    // TODO: Set the current array aside and make room for the new one.

    // TODO: Copy each element of the old array over.
    // Update front carefully as you go!  Can you just use front++?

    // TODO: Fix front and back and capacity so they correspond to the new array.
    // TODO: Delete the old array.
  }
}


ArrayQueue::~ArrayQueue()
{
  // TODO: implement the destructor
}

#endif
