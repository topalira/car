#include <iostream>
#include <string>
using namespace std;

class Car
{
protected:
	string body_material;
	string color;
	double weight;
	double price;
public:
	Car(){}
	Car(string bm, string c, double w, double p)
	{
		body_material = bm;
		color = c;
		weight = w;
		price = p;
	}
	void Print()
	{
		cout << "body_material: " << body_material << "\tcolor: " << color << "\tweight: " << weight << "\tprice: " << price << endl;
	}
	virtual string  GetColor() const = 0;
	virtual double  GetSpeed() const = 0;
};

class SportCar : public Car
{
	double maxSpeed;
	string type_engine;
	string type_rim;
	string type_steering;
	int turboCount;
public:
	SportCar(){}
	SportCar(string bm, string c, double w, double p, double ms, string te, string tr, string ts, int tc) : Car(bm, c, w, p)
	{
		maxSpeed = ms;
		type_engine = te;
		type_rim = tr;
		type_steering = ts;
		turboCount = tc;
	}
	void Print()
	{
		cout << "maxSpeed: " << maxSpeed << "\type_engine: " << type_engine << "\type_rim: " << type_rim << "\type_steering: " << type_steering << "\turboCount: " << turboCount << endl;
	}
	virtual string GetColor() const
	{
		return color;
	}
	virtual double  GetSpeed() const
	{
		return maxSpeed;
	}
};

class RetroCar : public Car
{
	double Speed_max;
	string seat_material;
	string type_headlidht;
	string type_dashboard;
	int engineMaxRPM;
public:
	RetroCar() {}
	RetroCar(string bm, string c, double w, double p, double mS, string sm, string th, string td, int eM) : Car(bm, c, w, p)
	{
		Speed_max = mS;
		seat_material = sm;
		type_headlidht = th;
		type_dashboard = td;
		engineMaxRPM = eM;
	}
	void Print()
	{
		cout << "Speed_max: " << Speed_max << "\seat_material: " << seat_material << "\type_headlidht: " << type_headlidht << "\type_dashboard: " << type_dashboard << "\engineMaxRPM: " << engineMaxRPM << endl;
	}
	virtual string GetColor() const
	{
		return color;
	}
	virtual double  GetSpeed() const
	{
		return Speed_max;
	}
};

int main()
{
	Car* car = nullptr;
	int choice = 0;
	cout << "1. sport car" << endl;
	cout << "2. retro car" << endl;
	cout << "your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		car = new SportCar("carbon", "\tred", 1200, 150000, 320, "V8", "sport rims", "sport steering", 2);
		break;
	case 2:
		car = new RetroCar("steel", "\tblack", 1600, 90000, 180, "leather", "round chrome", "analog", 4500);
		break;
	}
	car->Print();
	cout << "Color" << car->GetColor() << endl;
	cout << "Speed" << car->GetSpeed() << endl;
}
