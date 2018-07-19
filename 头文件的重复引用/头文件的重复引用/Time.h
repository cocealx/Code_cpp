#pragma
class Date;
class Time
{
	friend class Date;
public:
	Time(int hour, int minute, int second);
	void ReSetDate();
private:
	int _hour;
	int _minute;
	int _second;
	Date _d;
};