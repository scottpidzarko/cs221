//codetree.h - library that implements a CodeTree

//freq is array of integer representations of each character within a string
//The index is an ascii character, and at that index is the # of occurences of that ascii character within the input file

class CodeTree{
private:
	int freq[256];
	int heap[];
	void printChar(int ch);
	void buildPriorityQ(void);
public:
	CodeTree(int freqin[]);
	~CodeTree();
	void printTree( void );
	void printCode( void );
};
