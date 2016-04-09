#ifndef _LINEARHASHDICT_CPP
#define _LINEARHASHDICT_CPP

//LinearHashDict.cpp
#include "LinearHashDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of the dictionary ADT as a hash table with linear probing
//

const int LinearHashDict::primes[] = {53, 97, 193, 389, 769, 1543, 3079,
      6151, 12289, 24593, 49157, 98317, 196613, 393241, 786433, 1572869,
      3145739, 6291469, 12582917, 25165843, 50331653, 100663319,
      201326611, 402653189, 805306457, 1610612741, -1};
// List of good primes for hash table sizes from
// http://planetmath.org/goodhashtableprimes
// The -1 at the end is to guarantee an immediate crash if we run off
// the end of the array.

const int LinearHashDict::notprimes[] = {100, 300, 1000, 3000, 10000,
      30000, 100000, 300000, 1000000, 3000000, 10000000, 30000000,
      100000000, 300000000, 1000000000, -1};
// List of bad sizes for the hash table and this hash function...

LinearHashDict::LinearHashDict() {
  size_index = 0;
  size = primes[size_index];
  //size = notprimes[size_index];
  table = new bucket[size](); // Parentheses force initialization to 0
  number = 0;

  // Initialize the array of counters for probe statistics
  probes_stats = new int[MAX_STATS]();
}

LinearHashDict::~LinearHashDict() {
  // Delete all table entries...
  for (int i=0; i<size; i++) {
    if (table[i].key!=NULL) {
      delete table[i].key;
      // Don't delete data here, to avoid double deletions.
    }
  }
  // Delete the table itself
  delete [] table;

  // It's not good style to put this into a destructor,
  // but it's convenient for this assignment...
  cout << "Probe Statistics for find():\n";
  for (int i=0; i<MAX_STATS-1; i++)
    cout << i << ": " << probes_stats[i] << endl;
  cout << "More: " << probes_stats[MAX_STATS-1] << endl;
  delete [] probes_stats;
}

// 221 Students:  DO NOT CHANGE THIS FUNCTION
// You need to call this function from your find (or from a helper function).
// Pass in the number of probes that you needed for that call to find.
// The number of probes should be the total number of buckets that you
// look at:  e.g., on an unsuccessful call to find, you should include
// the empty bucket at the end.
void LinearHashDict::record_stats(int probes) {
  if (probes> MAX_STATS-1) probes = MAX_STATS-1;
  probes_stats[probes]++;
}

int LinearHashDict::hash(string keyID) {
  //std::cout << "in hash" << std::endl;
  int h=0;
  for (int i=keyID.length()-1; i>=0; i--) {
    h = (keyID[i] + 31*h) % size;
  }
// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Hashing " << keyID << " to " << h << std::endl;
#endif
// End of "DO NOT CHANGE" Block
  return h;
}

void LinearHashDict::rehash() {
  //std::cout << "in rehash" << std::endl;
// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// And leave this at the beginning of the rehash() function.
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "*** REHASHING " << size;
#endif
// End of "DO NOT CHANGE" Block

  // Keep a pointer to the old table.
  // Get a bigger table
  // Rehash all the data over
  // No need to delete the data, as all copied into new table.

  int old_size = size;
  size_index++;
  size = primes[size_index]; //muh Invariant
  bucket *old_table = table;
  table = new bucket[size]();
  number = 0;

  for(int k = 0; k < old_size; k++){
    if (old_table[k].key != NULL){
      add(old_table[k].key, old_table[k].data);
    }
  }

  //memory leaks are bad kids
  delete[] old_table;

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// And leave this at the end of the rehash() function.
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << " to " << size << " ***\n";
#endif
// End of "DO NOT CHANGE" Block
  return;
}

bool LinearHashDict::find(MazeState *key, MazeState *&pred) {
  //std::cout << "in find" << std::endl;

  // Returns true iff the key is found, puts the key in pred

  string keyID = key->getUniqId();
  int hashKey = hash(keyID);
  int probes = 1, position = 0; // set the probes to be one for the first iteration of the loop
  int target;
  //std::cout << "Hashkey: " << hashKey << " probes: " << probes << " position: " << position << " size: " << size << std::endl;
  while(position < size) {
    //std::cout << "in find loop" << std::endl;
    //std:: cout << position << " " << size << std::endl;
    target = (hashKey + position) % size;
    bucket tempbucket = table[target];
    string tempID;

    //If the key is null we have to give it a blank UniqID or otherwise segmentation faults happen
    if(tempbucket.key != NULL){
      tempID = tempbucket.key->getUniqId();
    }
    else{
      tempID = "";
    }

    //It's a match
    if(tempID == keyID) {
      pred = table[target].data;
      return true;
    }
    //no match
    else {
      position++;
    }
    //a null key indicates an unsuccessful probe
    //for some reason I need to return false here for the probes to count correctly
    if(tempbucket.key == NULL){
      record_stats(probes);
      return false;
    }

    probes++;
  }
  return false;
}

// You may assume that no duplicate MazeState is ever added.
void LinearHashDict::add(MazeState *key, MazeState *pred) {

  //std::cout << "in add" << std::endl;

  // Rehash if adding one more element pushes load factor over 3/4
  if (4*(number+1) > 3*size) rehash();

  string keyID = key->getUniqId();
  int hashKey = hash(keyID);
  int position = 0;
  int target;

  while(position < size) {
    target = (hashKey + position) % size;

    if(table[target].key == NULL) {
        table[target].key = key;
        table[target].data = pred;
        number++;
        return;
    } else {
      position++;
    }
  }

}

#endif
