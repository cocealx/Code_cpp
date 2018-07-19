#include"Time.h"
#include"Date.h"
#include<malloc.h>
Time::Time(int hour, int minute, int second) :_hour(hour), _minute(minute), _second(second)
{
	_d = (Date*)malloc(sizeof(Date));
}
