#include <iostream>
#include <string>
using namespace std;
class Cargo{
	public:
		float cargo;
		Cargo(float c) :
			cargo(c) {}
};

class Apple : public Cargo {
	public:
		Apple() :
			Cargo(1.5) {}
};

class Kiwi : public Cargo{
	public:
		Kiwi() :
			Cargo(0.5) {}
	
};
class Truck {
public:
		float remaining = 8;
		
public:
    void loadCargo(Cargo cargo)
		{
			remaining -= cargo.cargo; 
		}
		void printInfo()
		{
			cout << remaining << " tons remaining" << endl;
		}
};
int main() {
    Truck truck;
    truck.printInfo();

		truck.loadCargo(Apple());
		truck.printInfo();

		truck.loadCargo(Kiwi());
		truck.printInfo();
}