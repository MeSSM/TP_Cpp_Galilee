#include <iostream>
#include "enum.hpp"

std::ostream& operator<<(std::ostream& out, distance_t const & t){
	switch(t){
		case(distance_t::meter):
			out << "Meter";
			break;
		case(distance_t::feet):
			out << "Feet";	
			break;
		case(distance_t::leagues):
			out << "Leagues";
			break;
		case(distance_t::nautic_miles):
			out << "Nautic Miles";
			break;
	};
	return out;
}
