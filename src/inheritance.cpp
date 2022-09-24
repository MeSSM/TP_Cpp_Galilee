#include <iostream>
#include "inheritance.hpp"

const double METER_FEET = 3.280839895;
const double METER_LEAGUE = 0.0002071237;
const double METER_NAUTIC_MILES = 0.0005399568;
const double FEET_LEAGUE = 6.31313e-5;
const double FEET_NAUTIC_MILES = 0.0001645788;
const double LEAGUE_NAUTIC_MILES = 2.606928726;


Distance_core::Distance_core(double value) : _value(value){

}

std::ostream& operator<<(std::ostream& os, Distance_core const* distance){
	return distance->_print(os);
}

Distance_wrapper::Distance_wrapper(Distance_core const*const content) : _content(content){
}

bool Distance_wrapper::operator==(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() == other._content->convert_to_meter()->getValue();
}
bool Distance_wrapper::operator!=(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() != other._content->convert_to_meter()->getValue();
}
bool Distance_wrapper::operator<=(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() <= other._content->convert_to_meter()->getValue();
}
bool Distance_wrapper::operator>=(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() >= other._content->convert_to_meter()->getValue();
}
bool Distance_wrapper::operator<(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() < other._content->convert_to_meter()->getValue();
}
bool Distance_wrapper::operator>(Distance_wrapper& other){
	return _content->convert_to_meter()->getValue() > other._content->convert_to_meter()->getValue();
}

Distance_wrapper* Distance_wrapper::convert_to_meter(){
	return new Distance_wrapper(_content->convert_to_meter());
}

Distance_wrapper* Distance_wrapper::convert_to_feet(){
	return new Distance_wrapper(_content->convert_to_feet());
}

Distance_wrapper* Distance_wrapper::convert_to_leagues(){
	return new Distance_wrapper(_content->convert_to_leagues());
}

Distance_wrapper* Distance_wrapper::convert_to_nautic_miles(){
	return new Distance_wrapper(_content->convert_to_nautic_miles());
}

std::ostream& operator<<(std::ostream& os, Distance_wrapper const& distance){
	return os << distance._content;
}


/*                        CLASS Distance_meter                        */
Distance_meter::Distance_meter(double value) : Distance_core(value){
	std::cout << "A distance of "<< _value << " meter was just created" << std::endl;
};
Distance_meter::~Distance_meter(){
	std::cout << "A distance of "<< _value << " meter was just destroyed" << std::endl;
}
std::ostream& Distance_meter::_print(std::ostream& os) const{
	return os <<_value << " meter";
}
Distance_core const* Distance_meter::convert_to_meter() const{
	return new Distance_meter(_value);
}
Distance_core const* Distance_meter::convert_to_feet() const{
	return new Distance_feet(_value*METER_FEET);
}
Distance_core const* Distance_meter::convert_to_leagues() const{
	return new Distance_leagues(_value*METER_LEAGUE);
}
Distance_core const* Distance_meter::convert_to_nautic_miles() const{
	return new Distance_nautic_miles(_value*METER_NAUTIC_MILES);
}
/*                                END                                 */


/*                        CLASS Distance_feet                        */
Distance_feet::Distance_feet(double value) : Distance_core(value){
	std::cout << "A distance of "<< _value << " feet was just created" << std::endl;
};
Distance_feet::~Distance_feet(){
	std::cout << "A distance of "<< _value << " feet was just destroyed" << std::endl;
}
std::ostream& Distance_feet::_print(std::ostream& os) const{
	return os <<_value << " feet";
}
Distance_core const* Distance_feet::convert_to_meter() const{
	return new Distance_meter(_value/METER_FEET);
}
Distance_core const* Distance_feet::convert_to_feet() const{
	return new Distance_feet(_value);
}
Distance_core const* Distance_feet::convert_to_leagues() const{
	return new Distance_leagues(_value*FEET_LEAGUE);
}
Distance_core const* Distance_feet::convert_to_nautic_miles() const{
	return new Distance_nautic_miles(_value*FEET_NAUTIC_MILES);
}
/*                                END                                 */


/*                      CLASS Distance_leagues                        */
Distance_leagues::Distance_leagues(double value) : Distance_core(value){
	std::cout << "A distance of "<< _value << " league was just created" << std::endl;
};
Distance_leagues::~Distance_leagues(){
	std::cout << "A distance of "<< _value << " league was just destroyed" << std::endl;
}
std::ostream& Distance_leagues::_print(std::ostream& os) const{
	return os <<_value << " League";
}
Distance_core const* Distance_leagues::convert_to_meter() const{
	return new Distance_meter(_value/METER_LEAGUE);
}
Distance_core const* Distance_leagues::convert_to_feet() const{
	return new Distance_feet(_value/FEET_LEAGUE);
}
Distance_core const* Distance_leagues::convert_to_leagues() const{
	return new Distance_leagues(_value);
}
Distance_core const* Distance_leagues::convert_to_nautic_miles() const{
	return new Distance_nautic_miles(_value/FEET_NAUTIC_MILES);
}
/*                                END                                 */


/*                      CLASS Distance_nautic_miles                        */
Distance_nautic_miles::Distance_nautic_miles(double value) : Distance_core(value){
	std::cout << "A distance of "<< _value << " Nautic Miles was just created" << std::endl;
};
Distance_nautic_miles::~Distance_nautic_miles(){
	std::cout << "A distance of "<< _value << " Nautic Miles was just destroyed" << std::endl;
}
std::ostream& Distance_nautic_miles::_print(std::ostream& os) const{
	return os <<_value << " Nautic Miles";
}
Distance_core const* Distance_nautic_miles::convert_to_meter() const{
	return new Distance_meter(_value/METER_NAUTIC_MILES);
}
Distance_core const* Distance_nautic_miles::convert_to_feet() const{
	return new Distance_feet(_value/FEET_NAUTIC_MILES);
}
Distance_core const* Distance_nautic_miles::convert_to_leagues() const{
	return new Distance_leagues(_value);
}
Distance_core const* Distance_nautic_miles::convert_to_nautic_miles() const{
	return new Distance_nautic_miles(_value);
}
/*                                END                                 */

