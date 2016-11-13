//codetree.h - library that implements a CodeTree
//

//freq is array of integer representations of each character within a string
//freq[0] is the first character, freq[1] is the second character, and so on
public void CodeTree::CodeTree(int[] freq){
	//create
}
public void CodeTree::CodeTree~{
}
public void CodeTree::printTree(void){
}
public void CodeTree::printCode(void){
}
private void heapfiy(){
}
private void swapDown(){

}
private void swapUp(){
}
private void deleteMin(){
}
private void insert(){
}

private void printChar( int ch ) {
    if( ch < 16 ) {
        std::cout << "x0" << std::hex << ch;
    } else if( ch < 32 || ch > 126 ) {
        std::cout << "x" << std::hex << ch;
    } else {
        std::cout << "\"" << (char)ch << "\"";
    }
}







