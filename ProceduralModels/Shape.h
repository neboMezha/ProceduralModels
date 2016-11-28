#pragma once
#include <vector>
#include <string>
#include<fstream>
using std::vector;
using std::string;

//add glm and stuff
#include "glm/glm.hpp"
using glm::vec3;
using glm::vec2;
using glm::mat3;

//struct Obj {
//	vec3 v;
//	vec2 vt;
//	vec3 vn;
//	vec3 f;
//};
struct Vertex {
	int loc, uv, norm;
};
struct Face {
	//vec2 uv;
	//vec3 locs, norms;
	int d[9];
};

class Shape {
public:
	vector<vec3> locations;
	vector<vec2> uvs;
	vector<vec3> normals;
	vector<Face> faces;

	void addLoc(vec3 newLoc);
	void addUv(vec2 newUV);
	void addNorm(vec3 newNorm);
	void addFace(Face newFace);

	bool writeObj(string filename);

};

