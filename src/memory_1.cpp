#include <iostream>
#include "Distance.hpp"
#include "inheritance.hpp"
using namespace std;





int main(int argc, char** argv) {
	Distance_wrapper d1(new Distance_meter(1));
	Distance_wrapper d2(new Distance_leagues(3));
	Distance_wrapper d3(nullptr);
	 
	cout << d1 << " vs "  << d2 << " => " << (d1 < d2) << " | " << (d1 == d2) << (d1 > d2) << endl;
	
	cout << d3 << endl;
	return 0;
}

