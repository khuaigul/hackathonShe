#include <bits/stdc++.h>
using namespace std;

struct For_Input
{
	virtual void parse(string row);
};

struct Taxes: For_Input
{
	int Bus_Cost_per_Minute;
	int Away_Aircraft_Stand_Cost_per_Minute;
	int JetBridge_Aircraft_Stand_Cost_per_Minute;
	int Aircraft_Taxiing_Cost_per_Minute;

	void parse(string row);
};

struct Plane_Type: For_Input
{
	string name;
	int Max_Seats;
	int JetBridge_Handling_Time;
	int Away_Handling_Time;

	void parse(string row1, string row2);
};

struct Datatime
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
};

struct Plane: For_Input
{
	char flight_AD;
	Datatime flight_datatime;
	string flight_AL_Synchron_code;
	int flight_number;
	char flight_ID;
	int flight_terminal;
	string flight_AP;
	string flight_AC_Synchron_code;
	int flight_AC_PAX_capacity_total;
	int flight_PAX;
	int Aircraft_Stand;
	Plane_Type plane_type;

	void parse(string row);
};

struct Stand: For_Input
{
	int Aircraft_Stand;
	char JetBridge_on_Arrival;
	char JetBridge_on_Departure;
	int Time_To_Terminal[6];
	int Terminal = 0;
	int Taxiing_Time;

	void parse(string row) { return; }
};

void in(string file, vector<For_Input>& data)
{
	ifstream in_file(file);
	int sz = 0;
	string str;
	while(in_file >> str)
	{
		data.push_back(For_Input());
		data[sz++].parse(str);	
	}	
	sz = 0;
	in_file.close();	
}

int main()
{
	vector <Stand> Stands;
	in("data_set/Aircraft_Stands_Public.csv", Stands);

}