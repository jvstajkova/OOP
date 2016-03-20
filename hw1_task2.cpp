#include<iostream>
#include<string>
#include<cmath>
const int maxSize = 20;
using namespace std;
struct Planet
{
	string name;
	double distance;
	double diameter;
	double mass;

	void read(string n, double dist, double diam, double m);
	void print();
	double seconds();
	Planet maxDiameter(int n, Planet planets[]);
	Planet minMass(int n, Planet planets[]);
};

void Planet::read(string n, double dist, double diam, double m)
{
	cout << "Name: ";
	cin >> n ;
	cout << "Distance in kilometers: ";
	cin >> dist;
	cout << "Diameter: ";
	cin >> diam;
	cout << "Mass: ";
	cin >> m;
	name = n;
	distance = dist;
	diameter = diam;
	mass = m;
	cout << endl;
}

void Planet::print()
{
	cout << "Planet(name:" << name << ", distance: "<< distance <<", diameter: "<<diameter << ", mass: " << mass <<")"<< endl;
	cout << endl;
}

double Planet::seconds()
{
	double time, distance1;
	double speed = 299792;
	double speed1 = speed * 1000;
	distance1 = distance * 1000;
	time = distance1 / speed1;
	return time;
}
 Planet maxDiameter(int n, Planet planets[maxSize])
{
	int d = 0;
	double maxDiam = *planets.diameter();
	for (int i = 1; i < n; i++)
	{
		if (planets[i].diameter() > maxDiam)
			d = i;
	}
	return planets[d];
}
Planet minMass(int n, Planet planets[])
{
	int m = 0;
	double minM = planets[0].mass();
	for (int i = 1; i < n; i++)
	{
		if (planets[i].mass() < minM)
			m = i;
	}
	return planets[m];
}


int main()
{
	Planet planet;
	planet.read("Jupiter", 816081455, 142984, 500000);
	planet.print();
	cout << "Distance from the sun to the planet(in seconds)= " << planet.seconds() << endl;
	cout << endl;

	int n;
	//double maxDiameter = planets[0].diameter();
	//double minMass = planets[0].mass();
	do
	{
		cout << "n= ";
		cin >> n;
		cout << endl;
	} while (n < 1 || n>maxSize);

	Planet planets[maxSize];
	for (int i = 1; i <= n; i++)
	{
		string name;
		double distance, mass, diameter;
		planets[i].read(name, distance, mass, diameter);
	}
		/*
		cout << "The planet with the smallest mass: " << endl;
		minMass(n, planets).print();
		cout << "The planet with the biggest diameter: " << endl;
		maxDiameter(n, planets).print();
		cout << endl;
		cout << endl;
		}
		cout << endl;
		*/
	

		for (int i = 1; i <= n; i++)
		{
			cout << "Planets: " << endl;
			planets[i].print();
			cout << endl;
		}
		cout << endl;   
//намиране на най-голям диаметър и най-малка маса
/*	for (int j = 0; j < n; j++)
	{
		if (maxDiameter > planets[j].diameter())
			maxDiameter = planets[j].diameter();
		if (minMass < planets[j].mass())
			minMass = planets[j].mass;
	}

	cout << "The largest diameter is: " << maxDiameter << endl;
	cout << "The smallest mass is: " << minMass << endl;
	*/
	system("pause");
	return 0;
}