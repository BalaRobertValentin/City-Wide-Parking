#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<fstream>
#include<time.h>
using namespace std;
ofstream gTime("Time.txt", ios_base::app);
ifstream fTime("Time.txt", ios_base::app);
ofstream gPark("Database.txt", ios_base::app);
ifstream fPark("Database.txt", std::ios_base::app);
int ok = 0;
class Park
{
public:
	double totalHours, totalMinutes, totalTime, sumofMoney = 0;
	unsigned int Location, parkingID[6] = { 0 }, numberofVehicles, variable, carNumber, hours, minutes;
	char  name[20], licenseNumber[10], asking;
	void carInformation()
	{
		cout << "\nEnter your name : ";
		cin >> name;
		cout << "\nEnter license Number (DJ06OPE - Example ) : ";
		cin >> licenseNumber;
		cout << "\nEnter the total number of hours of stay ( Between 0 hours and 24 hours ) : ";
		cin >> totalHours;
		if (totalHours == 0)
			cout << "\nEnter the total number of minutes of stay ( Between 15 minutes, 30 minutes and 45 minutes ) : ";
		else
			cout << "\nEnter the total number of minutes of stay ( Between 0 minutes, 15 minutes, 30 minutes and 45 minutes ) : ";
		cin >> totalMinutes;
		totalTime = totalHours * 60 + totalMinutes;
		if (totalTime >= 15 && totalTime <= 60) {
			a.parkLocation();
			cout << "\nYou selected a short term parking\n\n ";
			cout << "\nFor future references your Car ID number is " << numberofVehicles;
		}
		else
			if (totalTime >= 15 && totalTime <= 180) {
				a.parkLocation();
				cout << "\nYou selected a short term parking\n\n ";
				cout << "\nFor future references your Car ID number is " << numberofVehicles;
			}
			else
				if (totalTime >= 180 && totalTime <= 1440) {
					a.parkLocation();
					cout << "\nYou selected a high term parking\n\n ";
					cout << "\nFor future references your Car ID number is " << numberofVehicles;
				}
	}
	void parkLocation()
	{
		const std::time_t now = std::time(nullptr);
		const tm calendar_time = *localtime(addressof(now));
		cout << "\nPlease select the location that you've parked at: ";
		cout << "\n1.  City Center ";
		cout << "\n2.  Hilton Mall ";
		cout << "\n3.  Henri Coanda International Airport ";
		cout << "\n4.  Parliament House ";
		cout << "\n5.  Youth Park \n";
		cin >> Location;
		switch (Location)
		{
		case 1:
		{
			a.availablePark();
			if (calendar_time.tm_hour >= 20 && calendar_time.tm_hour <= 24) { // Parking in the City Center between 8 pm and 12 pm costs double the amount
				cout << "\nBecause you park during busy hours, the parking price is 2x the initial amount. ";
				cout << "\nDo you still want to park here ( Type y/n )";
				cin >> asking;
				if (asking == 'y') {
					if (totalMinutes == 0)
						sumofMoney = totalHours * 16;
					else if (totalMinutes == 15)
						sumofMoney = totalHours * 16 + 4;
					else if (totalMinutes == 30)
						sumofMoney = totalHours * 16 + 8;
					else if (totalMinutes == 45)
						sumofMoney = totalHours * 16 + 12;
					cout << "\nThis parking spot costs 16 euro per hour (double the amount, because you park during busy hours), so your total is " << sumofMoney << " euro";
				}
				else
					exit(0);
			}
			else
			{
				if (totalMinutes == 0)
					sumofMoney = totalHours * 8;
				else if (totalMinutes == 15)
					sumofMoney = totalHours * 8 + 2;
				else if (totalMinutes == 30)
					sumofMoney = totalHours * 8 + 4;
				else if (totalMinutes == 45)
					sumofMoney = totalHours * 8 + 6;
				cout << "\nThis parking spot costs 8 euro per hour, so your total is " << sumofMoney << " euro";
			}
			break;
		}
		case 2:
		{
			a.availablePark();
			if (totalMinutes == 0)
				sumofMoney = totalHours * 4;
			else if (totalMinutes == 15)
				sumofMoney = totalHours * 4 + 1;
			else if (totalMinutes == 30)
				sumofMoney = totalHours * 4 + 2;
			else if (totalMinutes == 45)
				sumofMoney = totalHours * 4 + 3;
			cout << "\nThis parking spot costs 4 euro per hour, so your total is " << sumofMoney << " euro";
			break;
		}
		case 3:
		{
			a.availablePark();
			if (calendar_time.tm_hour >= 15 && calendar_time.tm_hour <= 17){  // Parking at Henri Coanda International Airport between 3 pm and 5 pm costs 1.5x the amount
				cout << "\nBecause you park during busy hours, the parking price is 1.5x the initial amount. ";
				cout << "\nDo you still want to park here ( Type y/n )";
				cin >> asking;
				if (asking == 'y') {
					if (totalMinutes == 0)
						sumofMoney = totalHours * 3;
					else if (totalMinutes == 15)
						sumofMoney = totalHours * 3 + 0.75;
					else if (totalMinutes == 30)
						sumofMoney = totalHours * 2 + 1.5;
					else if (totalMinutes == 45)
						sumofMoney = totalHours * 2 + 2.25;
					cout << "\nThis parking spot costs 3 euro per hour (1.5x the initial amount, because you park during busy hours), so your total is " << sumofMoney << " euro";
				}
				else
					exit(0);
			}
			else
			{
				if (totalMinutes == 0)
					sumofMoney = totalHours * 2;
				else if (totalMinutes == 15)
					sumofMoney = totalHours * 2 + 0.5;
				else if (totalMinutes == 30)
					sumofMoney = totalHours * 2 + 1;
				else if (totalMinutes == 45)
					sumofMoney = totalHours * 2 + 1.5;
				cout << "\nThis parking spot costs 2 euro per hour, so your total is " << sumofMoney << " euro";
			}
			break;
		}
		case 4:
		{
			a.availablePark();
			if (totalMinutes == 0)
				sumofMoney = totalHours * 10;
			else if (totalMinutes == 15)
				sumofMoney = totalHours * 10 + 2.5;
			else if (totalMinutes == 30)
				sumofMoney = totalHours * 10 + 5;
			else if (totalMinutes == 45)
				sumofMoney = totalHours * 10 + 7.5;
			cout << "\nThis parking spot costs 10 euro per hour, so your total is " << sumofMoney << " euro";
			break;
		}
		case 5:
		{
			a.availablePark();
			if (totalMinutes == 0)
				sumofMoney = totalHours * 1;
			else if (totalMinutes == 15)
				sumofMoney = totalHours * 1 + 0.25;
			else if (totalMinutes == 30)
				sumofMoney = totalHours * 1 + 0.5;
			else if (totalMinutes == 45)
				sumofMoney = totalHours * 1 + 0.75;
			cout << "\nThis parking spot costs 1 euro per hour, so your total is " << sumofMoney << " euro";
			break;
		}
		}

	}
	void availablePark()
	{
		if (parkingID[Location] >= 10) {
			cout << "\nThe maximum capacity has been reached, please go to another parking area " << "\n";
			a.parkLocation();
		}
		else {
			srand(time(NULL));
			parkingID[Location]++;
			numberofVehicles = rand();
		}
	}
	void allCars()
	{
		time_t timev;
		time(&timev);
		if (gTime.is_open())
		{
			gTime << numberofVehicles << " " << timev << " " << totalHours << " " << totalMinutes << "\n";
			gTime.close();
		}
		if (gPark.is_open()) {
			gPark << numberofVehicles << " " << name << " " << licenseNumber << " " << totalHours << " " << totalMinutes
				<< " " << sumofMoney << "\n";
			gPark.close();
		}
	}
	void output()
	{
		if (fPark.is_open()) {
			while (!fPark.eof())
			{
				fPark >> numberofVehicles;
				if (variable == numberofVehicles)
					break;
				variable = numberofVehicles;
				fPark >> name;
				fPark >> licenseNumber;
				fPark >> totalHours;
				fPark >> totalMinutes;
				fPark >> sumofMoney;
				cout << "\n\nCarNo " << numberofVehicles << endl;
				cout << "\nThe Driver Name : " << name << endl;
				cout << "\nThe Car License Number : " << licenseNumber << endl;
				cout << "\nThe car has been parked for " << totalHours << " hours and " << totalMinutes << " minutes" << " and the total cost was " << sumofMoney << " euro";
			}
			fPark.close();
		}
	}
	void notifications()
	{
		time_t currentTime;
		time(&currentTime);
		unsigned int time;
		if (fTime.is_open())
		{
			while (!fTime.eof())
			{
				fTime >> carNumber;
				fTime >> time;
				fTime >> hours;
				fTime >> minutes;
				if ((time + hours * 3600.0 + minutes * 60.0 - 600) <= currentTime)
					a.matchingCar();
				
			}
		}
	}
	void matchingCar()
	{
		if (fPark.is_open())
		{
			while (!fPark.eof())
			{
				fPark >> numberofVehicles;
				if (numberofVehicles == carNumber)
				{
					fPark >> name;
					fPark >> licenseNumber;
					fPark >> totalHours;
					fPark >> totalMinutes;
					fPark >> sumofMoney;
					cout << "\nCarNo " << numberofVehicles << endl;
					cout << "\nThe Driver Name : " << name << endl;
					cout << "\nThe Car License Number : " << licenseNumber << endl;
					cout << "\nThe car has been parked for " << totalHours << " hours and " << totalMinutes << " minutes" << " and the total cost was " << sumofMoney << " euro\n";
					cout << "\nYour parking is about to expire in 10 minutes or it was aleardy expired, if you wish to extend the duration of the parking ( Type y/n )";
					cin >> asking;
					if (asking == 'y')
						a.parkLocation();
					else {
						ok = 1;
						break;
					}
				}
			}
		}
	}
}a;

class Menu {
public:
	void EntryMenu() {
		int command;
		while (1) {
			cout << "\n\n\n\n\t\t\t\t---Welcome to Valentin Parking Lot ---";
			cout << "\n1.  Park a Car";
			cout << "\n2.  Show every car parked in Valentin Parking lot";
			cout << "\n3.  Notifications";
			cout << "\n4.  Exit Program\n";
			cout << "\nPlease select a category\n";
			cin >> command;
			switch (command)
			{
			case 1:
			{
				a.carInformation();
				a.allCars();
				break;
			}
			case 2:
			{
				a.output();
				break;
			}
			case 3:
			{
				a.notifications();
				if(ok == 0)
				cout << "\nNo car found in the Database has a expired parking spot ";
				break;
			}
			case 4:
			{
				exit(0);
				break;
			}
			default:
			{
				cout << "\nInvalid input";
				cout << "\nPress Enter to continue";
				break;
			}
			}



		}
	}
}b;

int main()
{
	b.EntryMenu();
}