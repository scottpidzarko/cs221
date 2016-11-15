#ifndef NODE_H
#define NODE_H
struct Node {
	int frequency;
	int character; //all the nodes except leaves will not have a character
				   //character being -1 indicates that the node does not contain any valid character data.
	Node* right;
	Node* left;
};
#endif /* NODE_H */
