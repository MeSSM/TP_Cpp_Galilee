#include <iostream>

class Distance_core{
	protected:
		const double _value;
		virtual std::ostream& _print(std::ostream& os) const = 0;
		
	public:
		Distance_core(double);
		double getValue() const { return _value;}
		virtual Distance_core const * convert_to_meter() const = 0;
		virtual Distance_core const * convert_to_feet() const = 0;
		virtual Distance_core const * convert_to_leagues() const = 0;
		virtual Distance_core const * convert_to_nautic_miles() const = 0;
		friend std::ostream& operator<<(std::ostream&, Distance_core const*);
		virtual ~Distance_core () {};
};

class Distance_wrapper{
	private:
		const Distance_core* _content;
	
	public:
		Distance_wrapper(Distance_core const * const);
		Distance_wrapper(Distance_wrapper const &) = delete;
		Distance_wrapper convert_to_meter();
		Distance_wrapper convert_to_feet();
		Distance_wrapper convert_to_leagues();
		Distance_wrapper convert_to_nautic_miles();
		bool operator==(Distance_wrapper other);
		bool operator!=(Distance_wrapper other);
		bool operator<=(Distance_wrapper other);
		bool operator>=(Distance_wrapper other);
		bool operator<(Distance_wrapper other);
		bool operator>(Distance_wrapper other);
		friend std::ostream& operator<<(std::ostream&, Distance_wrapper const);
		~Distance_wrapper(){
			delete _content;
		}
};

class Distance_meter : public Distance_core {
	protected:
		std::ostream& _print(std::ostream& os) const;
	public:
		Distance_meter(double value);
		Distance_core const * convert_to_meter() const;
		Distance_core const * convert_to_feet() const;
		Distance_core const * convert_to_leagues() const;
		Distance_core const * convert_to_nautic_miles() const;
		~Distance_meter();
};

class Distance_feet : public Distance_core {
	protected:
		std::ostream& _print(std::ostream& os) const;
	public:
		Distance_feet(double value);
		Distance_core const * convert_to_meter() const;
		Distance_core const * convert_to_feet() const;
		Distance_core const * convert_to_leagues() const;
		Distance_core const * convert_to_nautic_miles() const;
		~Distance_feet();
};

class Distance_leagues : public Distance_core {
	protected:
		std::ostream& _print(std::ostream& os) const;
	public:
		Distance_leagues(double value);
		Distance_core const * convert_to_meter() const;
		Distance_core const * convert_to_feet() const;
		Distance_core const * convert_to_leagues() const;
		Distance_core const * convert_to_nautic_miles() const;
		~Distance_leagues();
};

class Distance_nautic_miles : public Distance_core {
	protected:
		std::ostream& _print(std::ostream& os) const;
	public:
		Distance_nautic_miles(double value);
		Distance_core const * convert_to_meter() const;
		Distance_core const * convert_to_feet() const;
		Distance_core const * convert_to_leagues() const;
		Distance_core const * convert_to_nautic_miles() const;
		~Distance_nautic_miles();
};

