#include<iostream>
#include <sstream>
#include "GenerateModels.h"

int main() {
	std::cout << "Pick a shape :T " << std::endl;
	std::cout << "1: Triangle" << std::endl;
	std::cout << "2: Quad" << std::endl;
	std::cout << "3: Box" << std::endl;
	std::cout << "4: Disc" << std::endl;
	std::cout << "5: Cylinder" << std::endl;
	std::cout << "6: Sphere" << std::endl;
	std::cout << "0: Quit " << std::endl;
	string input;
	std::getline(std::cin, input);
	string name;
	std::cout << "Name of File: ";
	std::getline(std::cin, name);
	if (input == "1") {
		makeTriangle(name+".obj");
	}
	if (input == "2") {
		makeQuad(name + ".obj");
	}
	if (input == "3") {
		makeBox(name + ".obj");
	}
	if (input == "4") {
		string side;
		std::cout << "# of sides: ";
		std::getline(std::cin, side);
		int sides = atoi(side.c_str());
		makeDisc(name + ".obj", sides);
	}
	if (input == "5") {
		string side;
		std::cout << "# of sides: ";
		std::getline(std::cin, side);
		int sides = atoi(side.c_str());
		makeCylinder(name + ".obj", sides);
	}
	if (input == "6") {
		string lat;
		std::cout << "Latitude(Horizontal): ";
		std::getline(std::cin, lat);
		int la = atoi(lat.c_str());

		string lon;
		std::cout << "Longitude(Vertical): ";
		std::getline(std::cin, lon);
		int lo = atoi(lon.c_str());

		makeSphere(name + ".obj", la, lo);
	}
	if (input == "0") {
		return 0;
	}
}