#include "json_helper.cpp"
#include <fstream>
#include <iostream>

#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;

/**
 * Temporary priority function that turns a string into an
 * integer by adding together the ascii value of all of its
 * characters. So, longest "name" will have highest priority.
 */
int nameToNumber(string name) {
	int total = 0;
	for (int i = 0; i < name.length(); i++) {
		total += (int)name[i];

	}
	return total;
}
int nameToNumber1(string name)
{
	int total = (int)name.length();
	return total;
}
const static double EarthRadiusKm = 6372.8;

inline double DegreeToRadian(double angle) {
	return M_PI * angle / 180.0;
}

class Coordinate {
public:
	Coordinate(double latitude, double longitude) : myLatitude(latitude), myLongitude(longitude) {}

	double Latitude() const {
		return myLatitude;
	}

	double Longitude() const {
		return myLongitude;
	}

private:
	double myLatitude;
	double myLongitude;
};

double HaversineDistance(const Coordinate& p1, const Coordinate& p2) {

	double latRad1 = DegreeToRadian(p1.Latitude());
	double latRad2 = DegreeToRadian(p2.Latitude());
	double lonRad1 = DegreeToRadian(p1.Longitude());
	double lonRad2 = DegreeToRadian(p2.Longitude());

	double diffLa = latRad2 - latRad1;
	double doffLo = lonRad2 - lonRad1;

	double computation = asin(sqrt(sin(diffLa / 2) * sin(diffLa / 2) + cos(latRad1) * cos(latRad2) * sin(doffLo / 2) * sin(doffLo / 2)));
	return 2 * EarthRadiusKm * computation;

}

struct Animal {
	string animal_name;
	long date;
	double latitude;
	double longitude;
	float priority;
	bool validated;
	string version;

	Animal() {
		animal_name = "";
		date = 0;
		latitude = 0.0;
		longitude = 0.0;
		priority = 0.0;
		validated = 0;
		version = "";
	}

	Animal(string name, long _date, double lat, double lon, float pri, bool val, string ver) {
		animal_name = name;
		date = _date;
		latitude = lat;
		longitude = lon;
		priority = pri;
		validated = val;
		version = ver;
	}

	Animal(json j) {
		animal_name = j["animal_name"];
		date = j["date"];
		latitude = j["latitude"];
		longitude = j["longitude"];
		priority = j["priority"];
		validated = j["validated"];
		version = j["version"];
	}
};
class AnimalHelper {
	private:

		Animal** H;       // Pointer to allocate dynamic array
		int Next;     // Next available location
		int MaxSize;  // Max size since were using array
		int HeapSize; // Actual number of items in the array.


	void BubbleUp(int i) {
		int p = Parent(i);
		while (p > 0 && bucket[i].priority > bucket[p].priority) {
			Swap(i, p);
			i = p;
			p = Parent(i);
		}
	}
	void BubbleDown(int i) {
		int c = PickChild(i);

		while (c > 0) {
			if (A[i]->priority < A[c]->priority) {
				Swap(i, c);
				i = c;
				c = PickChild(i);
			}
			else {
				c = -1;
			}
		}
	}
	void Swap(int p, int i) {
		Animal* temp = A[p];
		A[p] = A[i];
		A[i] = temp;
	}
	int Parent(int i) {
		return int(i / 2);
	}

	/**
	* Function LeftChild:
	*      Returns left index of a given index
	*
	* Params:
	*      [int] index - index to calculate child from
	* Returns
	*      [int] index - left child index
	*/
	int LeftChild(int i) {
		return i * 2;
	}
	/**
	 * Function RightChild:
	 *      Returns right index of a given index
	 *
	 * Params:
	 *      [int] index - index to calculate child from
	 * Returns
	 *      [int] index - right child index
	 */
	int RightChild(int i) {
		return i * 2 + 1;
	}

	/**
	* Function PickChild:
	*      Return index of child to swap with or -1 to not swap.
	*
	* Params:
	*      [int] index - index of parent element
	* Returns
	*      [int] index - index to swap with or -1 to not swap
	*/
	int PickChild(int i) {
		if (RightChild(i) >= Next) {    //No right child
			if (LeftChild(i) >= Next) { //No left child
				return -1;
			}
			else { //you have a left no right
				return LeftChild(i);
			}
		}
		else {
			//right child exists
			if (A[RightChild(i)]->priority > A[LeftChild(i)]->priority) {
				return RightChild(i);
			}
			else {
				return LeftChild(i);
			}
		}
	}
public:
	
	AnimalHelper(int size) {
		H = new Animal * [size];
		Next = 1;
		MaxSize = size;
		HeapSize = 0;
	}
	AnimalHelper() {
		H = new Animal * [1];
		Next = 1;
		MaxSize = 0;
		HeapSize = 0;
	}
	void Insert(Animal* x) {
		
		A[Next] = x;
		BubbleUp(Next);
		Next++;
		HeapSize++;
	}
	Animal Extract(ofstream& outfile) {

		if (Empty()) {
			return -1;
		}

		Animal* retval = H[1];
		H[1] = H[--Next];
		HeapSize--;

		if (HeapSize > 1) {
			BubbleDown(1);
		}
		
		return *retval;
	}
	void PrintHeap(Animal* A, ofstream& outfile) {

		outfile << A->animal_name << endl;
		outfile << A->priority << endl << endl;


	}
	void Heapify(Animal* A, int size) {
		int i = size / 2;


		for (int b = i; b >= 1; b--) {
			BubbleDown(b);
		}
	}
};
int main(int argc, char** argv) {

	AnimalHelper A("animals.json");
	JsonHelper J("animals.json");
	AnimalHeap** N;
	N = new AnimalHeapHeap * [size];
	Animal** animals = A.getAnimalPointer(AH);
	for (int i = 0; i < size; i++) {
		N[i] = new AnimalHeapHeap;
	}

	for (int i = 0; i < size; i++)
	{
		N[i]->Insert(animals[i]);
	}


	AH.PrintAnimals();

	return 0;
}
	

