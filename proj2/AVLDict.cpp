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

// Returns true iff the key is found.
 //
 // If the key is found, pred is set to the predecessor.
 // Do not delete the object pointed to by pred, as there will
 // still be a pointer to that object inside the dictionary.
bool AVLDict::find(MazeState * key, MazeState *& pred){
  if(pred = NULL){
    std::cout << "null pred" << std::endl;
  }
  return finder(root, key->getUniqId(), pred, 0);
}

//returns true if the object is found, a recurse function called initially by find
bool AVLDict::finder(node* top, string keyID, MazeState *& pred, int depth) {
  if (top==NULL) {
    if (depth<MAX_STATS) depth_stats[depth]++;
    return false;
  }

  string rID = top->key->getUniqId();
  if (keyID == rID) {
    if (depth<MAX_STATS)
      depth_stats[depth]++;
    pred = top->data; // Found result, put in pred.
    return true;
  }

  record_stats(depth);

  //recursively look through the tree for the key
  if (keyID < rID)
    return finder(top->left, keyID, pred, depth+1);
  else
    return finder(top->right, keyID, pred, depth+1);
}

//code here directly from AVL lab
bool AVLDict::update_height( node * x ) {
  //
  // Recalculates the height of x from the height of its children.
  // Returns true iff the height of x changes.
  //
  if( x == NULL ) return false;
  int m = std::max(height(x->left), height(x->right)) + 1;
  if( x->height != m ) {
    x->height = m;
    return true;
  }
  return false;
}

//code for this function adopted from that provided by AVL lab
void AVLDict::rotate_left( node *& a ) {
  // "rotates" the subtree rooted at a to the left (counter-clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
std::cout << "Rotate Left: " << a->getUniqId() << std::endl;
#endif
// End of "DO NOT CHANGE" Block

  node *temp;

  temp = a->right;
  a->left = temp->left;
  temp->left = a;
  update_height(a);
  update_height(temp);
  a = temp;

  return;
}

//code for this function adopted from that provided by AVL lab
void AVLDict::rotate_right( node *& b ) {
  // "rotates" the subtree rooted at b to the right (clockwise)

// 221 Students:  DO NOT CHANGE OR DELETE THE NEXT FEW LINES!!!
// We will use this code when marking to be able to watch what
// your program is doing, so if you change things, we'll mark it wrong.
#ifdef MARKING_TRACE
cout << "Rotate Right: " << b->getUniqId() << endl;
#endif
// End of "DO NOT CHANGE" Block

  node* temp;

  temp = b->left;
  b->left = temp->right;
  temp->right = b;
  update_height(b);
  update_height(temp);
  b = temp;

  return;
}

//helper function from the avl lab
void AVLDict::doubleRotateLeft( node *& a ) {
  rotate_right(a->right);
  rotate_left(a);
}

//helper function from the avl lab
void AVLDict::doubleRotateRight( node *& a ) {
  rotate_left(a->left);
  rotate_right(a);
}

//helper function from the avl lab
bool AVLDict::contains( MazeState* key, node * root ) {
  //
  // Return true iff the tree contains the given key.
  //
  if ( root == NULL ) {
    return false;
  }

  if ( key < root->key ) {
    return contains( key, root->left );
  }
  else if ( key > root->key ) {
    return contains( key, root->right );
  }
  else
    return true;
}

/* DEFINED IN THE .hpp FILE!!
//helper function from the avl lab
int AVLDict::height( node * x ) {
  //
  // Returns the height of node x or -1 if x is NULL.
  //
  if( x == NULL ) return -1;
  return x->height;
}*/

// helper function from avl lab, slightly changed because the node struct changed
AVLDict::node * AVLDict::createNode( MazeState* key, MazeState* data, node* l, node* r) {
  //
  // Creates a new Node containing key, with 'l' as its left
  // child and 'r' as its right child, with height=0
  //
  // PRE:  key is valid, l points to a Node or is NULL and r
  //       points to a Node or is NULL
  // POST: If there is enough free memory space, a new Node is created
  //	   and its address is returned; otherwise, NULL is returned.

  node* result = new node;
  if (! result) return (node*) NULL;
  result->key = key;
  result->data = data;
  result->height = 0;
  result->left = l;
  result->right = r;
  return result;
}

//this function borrowed and modified from the AVL lab
void AVLDict::insert( node* in, node * top) {
  // BASE CASE
  if( top == NULL ) {
    top = in;
    return;
  }

  string keyID = in->key->getUniqId();
  string rID = top->key->getUniqId();

  // either go to the left, or to the right, but ignore if already in tree
  if( keyID < rID ) {
    insert( in, top->left );
  }
  // if key == root->key then ignore it (do not insert duplicate)
  else if( keyID > rID ) {
    insert( in, top->right );
  }
  // We know: descendant had a child added (in recursive call, above).
  // Now we're "unwinding" the call-stack (returning from the recursive calls,
  // one level at a time, until we get to the original call).
  // Do we have to rebalance at this level?
  if( update_height(top) )
    balanceTree(top);
}


// add a (key, predecessor) pair to the dictionary
//
// Note:  Do not delete the object pointed to by key or pred,
//        since the dictionary will keep a link to the object.
// You may assume that no duplicate MazeState is ever added.
void AVLDict::add(MazeState * key, MazeState * pred) {

  //nothing to insert
  //if(key == NULL)
    //return;

  node* newNode = createNode(key, pred);

  //tree is empty, put the key at the root node (which pred refers to)
  if(root == NULL) {
    root = newNode;
    return;
  }

  string ID = newNode->key->getUniqId();
  string rID = root->key->getUniqId();

  if( ID > rID){
    if(root->right == NULL) {
      root->right = newNode;
    }
    insert(newNode, root->right);
  }
  else if( ID < rID){
    if(root->left == NULL) {
      root->left = newNode;
    }
    insert(newNode, root->left);
  }

  return;

}

//done, taken from my AVL lab with slight modifications
void AVLDict::balanceTree(node * d) {
  if( d == NULL)
    return;

  node* l = d->left;
  node* r = d->right;

  int bf = height(l) - height(r);

  //left side is heavy
  if( bf > 1 ) {
    int ldiff = height(l->left) - height(l->right);
    if( ldiff < 0) // check if right subtree is heavy
      doubleRotateRight(d);
    else
      rotate_right(d);
    return;
  }
  //right side is heavy - do opposite of above
  else if( bf < -1){
    int rdiff = height(r->left) - height(r->right);
    if( rdiff > 0) //check if left subtree is heavy
      doubleRotateLeft(d);
    else
      rotate_left(d);
    return;
  }
  else
    return;
}
#endif
