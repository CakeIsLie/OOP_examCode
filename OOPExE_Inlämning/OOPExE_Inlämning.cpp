#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Vehicle //Base class
{
protected:
	string typeOfVehicle;
	string colour;
	string wheeles;
	string RegNum;
	string people;
public:
	virtual void settype(string CarType) {};
	virtual void setgas(string Cargas) {};
	virtual void setlongbus(string Buslong) {};
	virtual void setschool(string BusSchool) {};
	virtual void setbell(string Bikebell) {};
	virtual void setbasket(string Bikebasket) {};
	virtual void setmodel(string Motomodel) {};
	virtual void setside(string Motoside) {};
	virtual void setbackpart(string Trukback) {};
	virtual void setmodelType(string TruckType) {};
	void setcolour(string VehColour) { colour = VehColour; };
	void setwheeles(string VehWheeles) { wheeles = VehWheeles; };
	void setRegNum(string VehRegNum) { RegNum = VehRegNum; };
	void setpeople(string VehPeople) { people = VehPeople; };
	string getVehicleType()
	{
		return typeOfVehicle;
	}
	string getFindRegNr()
	{
		return RegNum;
	}
	string getColour()
	{
		return colour;
	}
	string getWheels() 
	{
		return wheeles;
	}
	string getPeople()
	{
		return people;
	}
	Vehicle(){}
	virtual void printAll()
	{
		cout << "Reg nr: " << RegNum << ", Colour: " << colour << ", Wheels: " << wheeles << ", People: " << people;
	}
};

class Bike : public Vehicle//Subclass
{
public:
	string bell;
	string basket;
	void setbell(string Bikebell) { bell = Bikebell; }
	void setbasket(string Bikebasket) { basket = Bikebasket; }
	Bike(){}
	Bike(string TypeBike) { typeOfVehicle = TypeBike; }
	void printAll()
	{
		Vehicle::printAll();
		cout << ", Bell?: " << bell << ", Basket?: " << basket << " <-Bike\n";
	}
};

class MotorBike : public Vehicle //Subclass
{
public:
	string model;
	string sidecart;
	void setmodel(string Motomodel) { model = Motomodel; }
	void setside(string Motoside) { sidecart = Motoside; }
	MotorBike(){}
	MotorBike(string TypeMotorBike) { typeOfVehicle = TypeMotorBike; }
	void printAll()
	{
		Vehicle::printAll();
		cout << ", Type of Motorcycle: " << model << ", Sidecar?: " << sidecart << " <-Motorcycle\n";
	}
};

class Car : public Vehicle //Subclass
{
public:
	
	string type;
	string gas;
	void settype(string CarType) { type = CarType; }
	void setgas(string Cargas) { gas = Cargas; }
	
	Car(){}
	Car(string TypeCar) { typeOfVehicle = TypeCar; }

	void printAll()
	{
		Vehicle::printAll();
		cout << ", Type of car: " << type << ", The fuel: " << gas << " <-Car\n";
	}
};

class Bus : public Vehicle//Subclass
{
public:
	string longBus;
	string school;
	void setlongbus(string Buslong) { longBus = Buslong; }
	void setschool(string BusSchool) { school = BusSchool; }
	Bus(){}
	Bus(string TypeBus) { typeOfVehicle = TypeBus; }
	void printAll() 
	{
		Vehicle::printAll();
		cout << ", Long or short?: " << longBus << ", Schoolbus?: " << school << " <-Bus\n";
	}
};

class Truck : public Vehicle //Subclass
{
public:
	string backpart;
	string modelType;
	void setbackpart(string Trukback) { backpart = Trukback; }
	void setmodelType(string TruckType) { modelType = TruckType; }
	Truck(){}
	Truck(string TypeTruck) { typeOfVehicle = TypeTruck; }
	void printAll()
	{
		Vehicle::printAll();
		cout << ", The back is attached?: " << backpart << ", Type of truck: " << modelType << " <-Truck\n";
	}
};

class Garage//Class that holds my vector
{
	//varibles only used in Garage
private:
	string testRg, test, coloursear, wheelessear, peoplesear;
	int sear;
public:
vector<Vehicle*> vec;
void AddVehicle(Vehicle* inObj) { vec.push_back(inObj); }
void print(string tyveh)
{
		for (int i = 0; i != vec.size(); i++)
		{
			string tempType = vec[i]->getVehicleType();
			if (!tempType.compare(tyveh))
			{
				vec[i]->printAll();
			} 
		}
}
void printAll()
{
	for (int i = 0; i != vec.size(); i++)
	{
			vec[i]->printAll();
	}
}
void SearchT() 
{
	//You can search for different things
	cout << "Enter what you want to search for:\n";
	cout << "[1] Colour, [2] Wheels, [3] How many can fit, [4] Reg nr\n";
	cin >> sear;
	if (sear == 1) //Search colour
	{
		cout << "Enter Colour: ";
		cin >> coloursear;
		for (int i = 0; i != vec.size(); i++)
		{
			string tempFind = vec[i]->getColour();
			if (!tempFind.compare(coloursear))
			{
				cout << "Vehicle you are looking for: \n";
				vec[i]->printAll();
			}
		}
	}
	else if (sear == 2) //Search wheels
	{
		cout << "Enter how many wheels it should have: ";
		cin >> wheelessear;
		for (int i = 0; i != vec.size(); i++)
		{
			string tempFind2 = vec[i]->getWheels();
			if (!tempFind2.compare(wheelessear))
			{
				cout << "Vehicle you are looking for: \n";
				vec[i]->printAll();
			}
		}
	}
	else if (sear == 3) //Search people
	{
		cout << "Enter how many people should fit: ";
		cin >> peoplesear;
		for (int i = 0; i != vec.size(); i++)
		{
			string tempFind = vec[i]->getPeople();
			if (!tempFind.compare(peoplesear) || peoplesear < vec[i]->getPeople())
			{
				cout << "Vehicle you are looking for: \n";
				vec[i]->printAll();
			}
		}
	}
	else if (sear == 4) //search using reg nr
	{
		cout << "Enter Reg nr: ";
		cin >> testRg;
		for (int i = 0; i != vec.size(); i++)
		{
			string tempFind = vec[i]->getFindRegNr();
			if (!tempFind.compare(testRg))
			{
				cout << "Vehicle you are looking for: \n";
				vec[i]->printAll();
			}
		}
	}
	else { cout << "Invalid input\n"; }
}
void remuVeh()
{
	//remove vehicles using reg nr
		cout << "Enter Reg nr: ";
		cin >> test;
			
		for (int i = 0; i != vec.size(); i++) 
		{
			string tempFind = vec[i]->getFindRegNr();
			if (!tempFind.compare(test))
			{	
				delete vec[i];
				vec.erase(remove(vec.begin(), vec.end(), vec[i]), vec.end());
			}
			cout << "Vehicle removed\n";
			//Have to break the for loop so it wont crash
			break;	
		}
}
void clearAll()
{
	//delete all vehicles
			for (int i = 0; i < vec.size(); i++)
			{
				delete (vec[i]);
			}
			vec.clear();
			cout << "Garage emptied\n";
}
};

int main()
{
	Garage myGarage;
	myGarage.vec;

	int Gag;
	cout << "Before we start\n How many places should the garage have?\n Enter a whole number\n";
	cin >> Gag;
	myGarage.vec.reserve(Gag);
	
	int h;	
	string tempregnr, tempcol, tempTyp, tempGas, tempLong, tempSho, tempbell, tempbask, tempmod, tempside, tempback, tempmodtyp, tempWheel, tempPeop;
		
	do //Use a do while loop so it will run at least once
	{	//My menu
		cout << "*******************************\n";
		cout << "Welcome to the garage, what do you want to do?\n";
		cout << "*******************************\n";
		cout << "*Enter 1 for add vehicle\n" << "*Enter 2 to print vehicle\n";
		cout << "*Enter 3 to print all vehicles\n" << "*Enter 4 to search vehicles\n" << "*Enter 5 to remove a vehicle\n" ;
		cout << "*Enter 6 to empty the garage\n" << "*Enter 7 to exit\n";
		cout << "*******************************\n\n";
		cin >> h;
	 
		switch (h)//Use a switch case so I can choose what I want to do
		{
			Vehicle* objc;
		case 1:
		{
			while (true)
			{
				int add;
				if (myGarage.vec.size() < myGarage.vec.capacity())
				{
					cout << "What vehicle do you want to add?\n";
					cout << "[1] car, [2] bus, [3] bike, [4] motorcycle, [5] truck\n";
					cin >> add;
					if (add == 1)
					{
						//make type of vehicle and only put cars in
						objc = new Car("Car");
						cout << "Enter reg nr, (no blank spaces):\n";
						cin >> tempregnr;
						objc->setRegNum(tempregnr);

						cout << "Enter colour:\n";
						cin >> tempcol;
						objc->setcolour(tempcol);

						cout << "Enter how many wheels it have:\n";
						cin >> tempWheel;
						objc->setwheeles(tempWheel);

						cout << "Enter how many people can fit:\n";
						cin >> tempPeop;
						objc->setpeople(tempPeop);

						cout << "Enter type of car:\n";
						cin >> tempTyp;
						objc->settype(tempTyp);

						cout << "Enter fuel:\n";
						cin >> tempGas;
						objc->setgas(tempGas);

						myGarage.AddVehicle(objc);
						break;

					}
					else if (add == 2)
					{
						//make type of vehicle and only put buses in
						objc = new Bus("Bus");
						cout << "Enter reg nr, (no blank spaces):\n";
						cin >> tempregnr;
						objc->setRegNum(tempregnr);

						cout << "Enter colour:\n";
						cin >> tempcol;
						objc->setcolour(tempcol);

						cout << "Enter how many wheels it have:\n";
						cin >> tempWheel;
						objc->setwheeles(tempWheel);

						cout << "Enter how many people can fit:\n";
						cin >> tempPeop;
						objc->setpeople(tempPeop);

						cout << "Enter if it's a long or short bus:\n";
						cin >> tempLong;
						objc->setlongbus(tempLong);

						cout << "Enter if it's a schoolbus:\n";
						cin >> tempSho;
						objc->setschool(tempSho);

						myGarage.AddVehicle(objc);
						break;

					}
					else if (add == 3)
					{
						//make type of vehicle and only put bikes in
						objc = new Bike("Bike");
						cout << "Enter reg nr, (no blank spaces):\n";
						cin >> tempregnr;
						objc->setRegNum(tempregnr);

						cout << "Enter colour:\n";
						cin >> tempcol;
						objc->setcolour(tempcol);

						cout << "Enter how many wheels it have:\n";
						cin >> tempWheel;
						objc->setwheeles(tempWheel);

						cout << "Enter how many people can fit:\n";
						cin >> tempPeop;
						objc->setpeople(tempPeop);

						cout << "Enter if it has a bell:\n";
						cin >> tempbell;
						objc->setbell(tempbell);

						cout << "Enter if it has a basket:\n";
						cin >> tempbask;
						objc->setbasket(tempbask);

						myGarage.AddVehicle(objc);
						break;

					}
					else if (add == 4)
					{
						//make type of vehicle and only put motorcycles in
						objc = new MotorBike("MotorBike");
						cout << "Enter reg nr, (no blank spaces):\n";
						cin >> tempregnr;
						objc->setRegNum(tempregnr);

						cout << "Enter colour:\n";
						cin >> tempcol;
						objc->setcolour(tempcol);

						cout << "Enter how many wheels it have:\n";
						cin >> tempWheel;
						objc->setwheeles(tempWheel);

						cout << "Enter how many people can fit:\n";
						cin >> tempPeop;
						objc->setpeople(tempPeop);

						cout << "Enter type of motorcycle:\n";
						cin >> tempmod;
						objc->setmodel(tempmod);

						cout << "Enter if it has a sidecar:\n";
						cin >> tempside;
						objc->setside(tempside);

						myGarage.AddVehicle(objc);
						break;

					}
					else if (add == 5)
					{
						//make type of vehicle and only put truks in
						objc = new Truck("Truck");
						cout << "Enter reg nr, (no blank spaces):\n";
						cin >> tempregnr;
						objc->setRegNum(tempregnr);

						cout << "Enter colour:\n";
						cin >> tempcol;
						objc->setcolour(tempcol);

						cout << "Enter how many wheels it have:\n";
						cin >> tempWheel;
						objc->setwheeles(tempWheel);

						cout << "Enter how many people can fit:\n";
						cin >> tempPeop;
						objc->setpeople(tempPeop);

						cout << "Enter if the back is attached:\n";
						cin >> tempback;
						objc->setbackpart(tempback);

						cout << "Enter the type of truck:\n";
						cin >> tempmodtyp;
						objc->setmodelType(tempmodtyp);

						myGarage.AddVehicle(objc);
						break;
					}
					else { cout << "invalid input\n"; }
				}
				else { cout << "Sorry the garage is full\n"; break; }

			}
			break;
		}
		case 2:
		{
			while (true) {
				int te;
				cout << "What do you want to print?\n";
				cout << "[1] cars, [2] buses, [3] bikes, [4] motorcycles, [5] truks\n";
				cin >> te;
				if (te == 1)
				{
					myGarage.print("Car");
					break;
				}
				else if (te == 2)
				{
					myGarage.print("Bus");
					break;
				}
				else if (te == 3)
				{
					myGarage.print("Bike");
					break;
				}
				else if (te == 4)
				{
					myGarage.print("MotorBike");
					break;
				}
				else if (te == 5)
				{
					myGarage.print("Truck");
					break;
				}
				else
				{
					cout << "Invalid input\n";
				}
			}
			break;
		}
		case 3:
		{
			myGarage.printAll();
			break;
		}
		case 4:
		{
			myGarage.SearchT();
			break;
		}
		case 5:
		{
			myGarage.remuVeh();
			break;
		}
		case 6:
		{
			myGarage.clearAll();
			break;
		}
		}
	}while (h < 7 && h > 0);
	return 0;
}