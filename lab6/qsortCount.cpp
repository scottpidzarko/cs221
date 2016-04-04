#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps(0);
int predcomps(0);

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {

	//input parameters are wrong if true
	if (a >= b) return;

	// else ... continue sorting
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
	if (x[i] < x[a])
		swap(x[++m], x[i]);
		::comps++;
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

//Question 3
int qc(int n){

	if (n <= 1){
		return 0;
	}

	int tempcount = 0;

	int p = randint(0,n); // pivot

	int i;

	// in-place partition:
	for (i = 1; i <= n; i++) {
		tempcount += n-1 + qc(i-1) + qc(n-i);
	}

	return tempcount / n;
}

//Question 4
float c(int n) {
  if (n <= 1) return 0;
  float sum = 0.0;
  for (int m=1; m <= n; m++)
    sum += n-1 + c(m-1) + c(n-m);
  return sum / n;
}

//Array size - no bigger than 20 when we get to Q4
#define NN 15

int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}

	quicksort(0, NN-1);

  //list x on terminal
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

  std::cout << std::endl;
  std::cout << "Predicted Comparison for NN: " << qc(NN) << std::endl;
  std::cout << "Average Comparisons for NN: " << c(NN) << std::endl;
  std::cout << "Actual Comparisons for NN:  " << ::comps << std::endl;


	delete[] x;
	return 0;
}

