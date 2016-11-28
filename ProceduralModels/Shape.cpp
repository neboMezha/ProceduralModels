#include "Shape.h"
#include<fstream>

void Shape::addLoc(vec3 newLoc)
{
	locations.push_back(newLoc);
}

void Shape::addUv(vec2 newUV)
{
	uvs.push_back(newUV);
}

void Shape::addNorm(vec3 newNorm)
{
	normals.push_back(newNorm);
}

void Shape::addFace(Face newFace)
{
	faces.push_back(newFace);
}

bool Shape::writeObj(string filename)
{
	if (locations.size() == 0 || uvs.size() == 0 || normals.size() == 0 || faces.size() == 0) //fails if empty
		return false;

	std::ofstream myFile(filename);
	if (myFile.is_open()) {
		
		for (int i = 0; i < locations.size(); i++) {
			myFile << "v " << locations[i].x << " " << locations[i].y << " " << locations[i].z << " \n";
		}
		for (int i = 0; i < uvs.size(); i++) {
			myFile << "vt " << uvs[i].x << " " << uvs[i].y << " \n";
		}
		for (int i = 0; i < normals.size(); i++) {
			myFile << "vn " << normals[i].x << " " << normals[i].y << " " << normals[i].z << " \n";
		}
		for (int i = 0; i < faces.size(); i++) { 
			myFile << "f " << faces[i].d[0] << "/" << faces[i].d[1] << "/" << faces[i].d[2] << " " << faces[i].d[3] << "/" << faces[i].d[4] << "/" << faces[i].d[5] << " " << faces[i].d[6] << "/" << faces[i].d[7] << "/" << faces[i].d[8] << " \n";
		}
		


		myFile.close();
		return true;
	}
	else { //file isn't open
		return false;
	}
}
