#ifndef _AVLDICT_CPP
#define _AVLDICT_CPP

//AVLDict.cpp
#include "AVLDict.hpp"
#include <cassert>
#include <cstdlib>//for NULL
#include <iostream>

// An implementation of a dictionary ADT as an AVL tree
//
AVLDict::AVLDict() {
  root = NULL;

  // Initialize array of counters for depth statistics
  depth_stats = new int[MAX_STATS]();
}

void AVLDict::destructor_helper(node * x) {
  if (x == NULL) return; // Nothing to destroy.
  destructor_helper(x->left);
  destructor_helper(x->right);
  delete x->key;
  delete x;
}

AVLDict::~AVLDict() {
  // Clean up the tree.
  // This is most easily done recursively.
  destructor_helper(root);

  // It's not good style to put this into a destructor,
  // but it's convenient for this assignment...
  cout << "Depth Statistics for find():\n";
  for (int i=0; i<MAX_STATS-1; i++)
    cout << i << ": " << depth_stats[i] << endl;
  cout << "More: " << depth_stats[MAX_STATS-1] << endl;
  delete [] depth_stats;
}

// 221 Students:  DO NOT CHANGE THIS FUNCTION
// You need to call this function from your find (or from a helper function).
// Pass in the depth in the tree that the find stopped at.
// E.g., you'd call record_stats(0) if the entire dictionary were
// a NULL tree and you did a find on it.
// You'd call record_stats(1) if the entire dictionary were a single
// node, and you did a find on that dictionary, successful or not.
// (Another way to understand this is the number of nodes on the chain
// from the root to the node where the find succeeded,
// or to a leaf if the find didn't succeed.)
void AVLDict::record_stats(int depth) {
  if (depth > MAX_STATS-1) depth = MAX_STATS-1;
  depth_stats[depth]++;
}




bool AVLDict::find(MazeState *key, MazeState *&pred) {
  // TODO:  Write this function!

}

//return true if the node's height has changed
bool AVLDict::update_height( node * x ) {

  if( node == NULL)
    return false;

  left = node->left;
  right = node->right;

  if(left->height == right->height)
    return false;
  else
    return true;
}

void AVLDict::rotate_left( node *& a ) {
  // "rotates" the subtree rooted at a to the left (counter-clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Rotate Left: " << a->getUniqId() << std::endl;
#endif
// End of "DO NOT CHANGE" Block

  Node *temp;

  temp = a->left;
  a->left = temp->right;
  temp->right = a;
  a = temp;

  //update_height(a);
  //update_height(a->right);

  delete temp;
  return;
}

void AVLDict::rotate_right( node *& b ) {
  // "rotates" the subtree rooted at b to the right (clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
cout << "Rotate Right: " << b->getUniqId() << endl;
#endif
// End of "DO NOT CHANGE" Block

  Node *temp;

  temp = b->right;
  b->right = temp->left;
  temp->left = b;
  b = temp;

//  update_height(b);
//  update_height(b->left);

  delete temp;
  return;
}

// You may assume that no duplicate MazeState is ever added.
void AVLDict::add(MazeState *key, MazeState *pred) {

  if(pred == NULL || key == NULL){
      return;
  }

  Node newNode;
  newNode->key=key;
  newNode->data=pred;



}
void AVLDict::balanceTree(node * d) {
    if( d == NULL)
      return;

  left* = d->left;
  right* = d->right;

  int bf = (left->height - right->height);

  if( bf = 0 )
    return;
  else if( bf = 1 )
    rotate_right(d);
    return
  else if( bf = -1)
    rotate_left(d);
    return;
  else if( bf > 1)
    //double rotate right
    return;
  else if( bf < -1)
    //double rotate left
    return;
  else //something screwed up if we get here
    std::cout << "Something went wrong in AVLDict::balanceTree" << std::endl;
    return;
}
#endif
