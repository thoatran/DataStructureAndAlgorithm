#include <iostream>
#include <limits>

using namespace std; 

double findPi(int n) {
	srand(time(NULL));
	int inCircle = 0;
	for(int i = 0; i < n; i++) {
		double x = (double) rand() / (RAND_MAX);
		double y = (double) rand() / (RAND_MAX);
		double d = (double)(x - 0.5)*(x - 0.5) + ( y - 0.5)*(y - 0.5);
		if( d < 0.25){
			inCircle = inCircle + 1;
		}
		//cout << x <<"      " << y << "       " << inCircle << endl;
	}
	return (double) 4 * inCircle / n;
}

int main() 
{ 
	int n = 0;
	cout << "Number of points: ";
	cin >> n;
	cout << "The value of pi: " << endl;
	for(int i = 0; i < 10; i++) {
		double pi = findPi(n); //number opf po
	    cout << pi << endl;
	}
	cout << endl;
	return 0; 
} 