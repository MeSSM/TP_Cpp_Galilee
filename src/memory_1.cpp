#include <iostream>
#include "Distance.hpp"
#include "inheritance.hpp"
using namespace std;





int main(int argc, char** argv) {
	Distance_wrapper d1 = Distance_wrapper(new Distance_meter(1));
	Distance_wrapper d2 = Distance_wrapper(new Distance_leagues(3));
	 
	cout << d1 << " vs "  << d2 << " => " << (d1 < d2) << " | " << (d1 == d2) << (d1 > d2) << endl;
	return 0;
}

