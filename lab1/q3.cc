#include<iostream>
#include<string>
#include<cstdlib>

int fill_array( int arg[], int start, int increment);

int main( int argc, char**argv ){

	int foo[10];

	fill_array(foo, atoi(argv[1]), atoi(argv[2]) );
	
	for( int k = 0; k < 10; k++){
		std::cout << foo[k];
		std::cout << '\n';
	}

	return 0;
}

int fill_array( int arg[], int start, int increment ){

	int j = start;
	
	for( int i = 0; i < 10; i++){
		arg[i] = j;
		j = j + increment;
	}
	
	return 0;

}
