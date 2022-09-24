#include "enum.hpp"

class Distance{
	private:
		const double _value;
		const distance_t _unit;
		
	public:
		Distance(double, distance_t);
		Distance convert_to(distance_t const) const;
		bool operator==(Distance const &);  
		bool operator!=(Distance const &);  
		bool operator<=(Distance const &);  
		bool operator>=(Distance const &);  
		bool operator<(Distance const &);  
		bool operator>(Distance const &);  
		friend std::ostream& operator<<(std::ostream&, Distance const&);
		~Distance();
};


std::ostream& operator<<(std::ostream& out, Distance const & d);
