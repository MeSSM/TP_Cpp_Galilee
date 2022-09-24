#include <iostream>
#include "Distance.hpp"
#include <map>
#include <string>
#include <sstream>

using namespace std;

map<string, double> convertion_table = {
	{"MeterFeet",  3.280839895},
	{"MeterLeagues", 0.0002071237},
	{"MeterNautic Miles", 0.0002071237},
	{"FeetLeagues", 6.31313e-5},
	{"FeetNautic Miles", 0.0001645788},
	{"LeaguesNautic Miles", 2.606928726},
};


Distance::Distance(double value, distance_t unit) : _value(value), _unit(unit){
	cout << "A distance of " << _value << " " << _unit << " was just created." << endl;
}

Distance Distance::convert_to(distance_t const new_unit) const{
	stringstream ss; 
	ss << _unit;
	ss << new_unit;
	if(convertion_table.find(ss.str()) != convertion_table.end()){
		double coef = convertion_table.at(ss.str());
		return Distance(_value*coef, new_unit);
	}else{
		ss = stringstream();
		ss << new_unit;
		ss << _unit;
		double coef = convertion_table.at(ss.str());
		return Distance(_value/coef, new_unit);
	}
}

bool Distance::operator==(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value == converted._value;
}  

bool Distance::operator!=(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value != converted._value;
}   

bool Distance::operator<=(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value <= converted._value;
}  

bool Distance::operator>=(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value >= converted._value;
}  

bool Distance::operator<(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value < converted._value;
}  

bool Distance::operator>(Distance const & other){
	Distance converted = other.convert_to(_unit);
	return _value > converted._value;
}   

Distance::~Distance(){
	cout << "A distance of " << _value << " " << _unit << " was just destroyed." << endl;
}


std::ostream& operator<<(std::ostream& out, Distance const & d){
	out << d._value << " " << d._unit;
	return out;
}
