#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

string timeConversion(string s)
{

	string hh = s.substr(0, 2);
	string mm = s.substr(3, 2);
	string ss = s.substr(6, 2);
	string meridian = s.substr(8, 2);

	if (meridian == "AM"){
		if (hh == "12"){
			hh = "00";
		}
	}
	else
	{
		if (hh != "12")
		{
			hh = to_string(((stoi(hh) + 12)));
		}
	}


	string militaryTime = hh + ":" + mm + ":" + ss;
	return militaryTime;
}



int main()
{
	string result = timeConversion("05:01:00PM");
	cout << result << endl;
	
	return 0;
}