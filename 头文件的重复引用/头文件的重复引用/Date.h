class Time;
class Date
{
	friend class Time;
public:
	Date(int year = 2017, int month = 9, int day = 10);
	void ReSetDate();
private:
	int _year;
	int _month;
	int _day;
	Time*_t;
};