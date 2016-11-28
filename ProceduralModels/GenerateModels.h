#pragma once
#include "Shape.h"
#include<cmath>
#define M_PI 3.1415926535897

bool makeTriangle(string filename) {
	Shape triangle;

	triangle.addLoc(vec3(0, 0, 0));
	triangle.addLoc(vec3(1, 0, 0));
	triangle.addLoc(vec3(0.5, 1, 0));

	triangle.addUv(vec2(0, 0));
	triangle.addUv(vec2(1, 0));
	triangle.addUv(vec2(0.5, 1));

	triangle.addNorm(vec3(0,0,1));

	Face f = { 1, 1, 1, 2, 2, 1, 3, 3, 1 };

	triangle.addFace(f);

	triangle.writeObj(filename);
	return true;
}

//DONE
bool makeQuad(string filename) {
	Shape quad;

	quad.addLoc(vec3(-1, -1, 0));
	quad.addLoc(vec3(1, -1, 0));
	quad.addLoc(vec3(1, 1, 0));
	quad.addLoc(vec3(-1, 1, 0));

	quad.addUv(vec2(0, 0));
	quad.addUv(vec2(1, 0));
	quad.addUv(vec2(1, 1));
	quad.addUv(vec2(0, 1));

	quad.addNorm(vec3(0, 0, 1));

	Face f1 = { 1, 1, 1, 2, 2, 1, 3, 3, 1 };
	Face f2 = { 1, 1, 1, 3, 3, 1, 4, 4, 1 };

	quad.addFace(f1);
	quad.addFace(f2);

	quad.writeObj(filename);
	return true;
} 

//DONE
bool makeBox(string filename) {
	Shape box;

	box.addLoc(vec3(-1, -1, 1)); //low left
	box.addLoc(vec3(1, -1, 1)); //low right
	box.addLoc(vec3(1, 1, 1)); //high right
	box.addLoc(vec3(-1, 1, 1)); //high left

	box.addLoc(vec3(-1, -1, -1)); //low left
	box.addLoc(vec3(1, -1, -1)); //low right
	box.addLoc(vec3(1, 1, -1)); //high right
	box.addLoc(vec3(-1, 1, -1)); //high left


	box.addUv(vec2(0, 0.66)); //back top left		1
	box.addUv(vec2(0, 0.33)); //back low left		2
	box.addUv(vec2(0.25, 0.66)); //back top right	3
	box.addUv(vec2(0.25, 0.33)); //back low right	4
	box.addUv(vec2(0.5, 0.66)); // left top right	5
	box.addUv(vec2(0.5, 0.33)); //left low right	6
	box.addUv(vec2(0.5, 1)); //top top left			7	
	box.addUv(vec2(0.75, 1)); //top top right		8
	box.addUv(vec2(0.75, 0.66)); //front top right	9
	box.addUv(vec2(0.75, 0.33)); //front low right	10
	box.addUv(vec2(0.5, 0)); //bottom low left		11
	box.addUv(vec2(0.75, 0)); //bottom low right	12
	box.addUv(vec2(1, 0.66)); //right top right		13
	box.addUv(vec2(1, 0.33)); //right low right		14


	box.addNorm(vec3(0, 0, 1)); //front
	box.addNorm(vec3(0, 0, -1)); //back
	box.addNorm(vec3(0, 1, 0)); //top
	box.addNorm(vec3(0, -1, 0)); //bottom
	box.addNorm(vec3(1, 0, 0)); //right
	box.addNorm(vec3(-1, 0, 0)); //left

	Face f1 = { 1, 6, 1, 2, 10, 1, 3, 9, 1 }; //front //done? //yes
	Face f2 = { 1, 6, 1, 3, 9, 1, 4, 5, 1 };

	Face f3 = { 2, 10, 6, 6, 14, 6, 7, 13, 6 };//right //done  
	Face f4 = { 2, 10, 6, 7, 13, 6, 3, 9, 6 };

	Face f5 = { 6, 2, 2, 5, 4, 2, 8, 3, 2 }; //back //done?? //flipped?
	Face f6 = { 6, 2, 2, 8, 3, 2, 7, 1, 2 };

	Face f7 = { 5, 4, 5, 1, 6, 5, 4, 5, 5 }; //left //done??
	Face f8 = { 5, 4, 5, 4, 5, 5, 8, 3, 5 };

	Face f9 = { 4, 5, 4, 3, 9, 4, 7, 8, 4 }; //top //done??
	Face f10 = { 4, 5, 4, 7, 8, 4, 8, 7, 4 };

	Face f11 = { 5, 11, 3, 6, 12, 3, 2, 10, 3 }; //bottom //facing right but texture is shet
	Face f12 = { 5, 11, 3, 2 ,10, 3, 1, 6, 3 };

	box.addFace(f1);
	box.addFace(f2);
	box.addFace(f3);
	box.addFace(f4);
	box.addFace(f5);
	box.addFace(f6);
	box.addFace(f7);
	box.addFace(f8);
	box.addFace(f9);
	box.addFace(f10);
	box.addFace(f11);
	box.addFace(f12);

	box.writeObj(filename);
	return true;
}

bool makeDisc(string filename, int side) {
	Shape disc;
	float sides = side;
	float t = 0.0f;
	float increment = 2 * M_PI / sides;

	disc.addLoc(vec3(0, 0, 0));

	disc.addUv(vec2(0.5,0.5));

	for (int i = 0; i < sides; i++) {
		t = increment*i;
		float angle = i / sides;
		float x = glm::cos(2 * M_PI * angle);
		float y = glm::sin(2 * M_PI * angle);

		disc.addLoc(vec3(cos(t), sin(t), 0));
		disc.addUv(vec2((x+1)/2, (y+1)/2));
		
	}
	disc.addNorm(vec3(0, 0, 1));

	for (int i = 1; i <=sides; i++) {
		Face f;
		if (i == sides) {
			 f= { 1, 1, 1, i + 1, i + 1, 1, 2, 2, 1 };
		}
		else {
		f = { 1, 1, 1, i + 1, i + 1, 1, i + 2, i + 2, 1 };
		}
		disc.addFace(f);
	}
	disc.writeObj(filename);
	return true;
}

//WORKING DON'T TOUCH IT
bool makeCylinder(string filename, int side) {
	Shape cyl;
	float sides = side;
	double t = 0;
	double increment = 2 * 3.14159 / sides;

	cyl.addLoc(vec3(0, 0, 1)); //center top
	cyl.addUv(vec2(0.439, 0.187)); //center top
	cyl.addNorm(vec3(0, 0, 1));

	cyl.addLoc(vec3(0, 0, 0)); //center bottom
	cyl.addUv(vec2(0.813, 0.187)); //center
	cyl.addNorm(vec3(0, 0, -1));

	for (int i = 0; i < sides; i++) {// circles and/or points
		t = increment*i;
		cyl.addLoc(vec3(cos(t), sin(t), 1));//top
		cyl.addLoc(vec3(cos(t), sin(t), 0)); //bottom

		float angle = i / sides;
		float x = glm::cos(-2 * M_PI * angle);
		float y = glm::sin(-2 * M_PI * angle);

		cyl.addUv(vec2(((x + 1) / 2)*0.347f + 0.252f, ((y + 1) / 2)*0.347)); //numbers are sightly off ??
		cyl.addUv(vec2(((x + 1) / 2)*0.347f + 0.626f, ((y + 1) / 2)*0.347));//numbers are sightly off??

		cyl.addNorm(vec3(x,y, 0)); //yes...?
		cyl.addNorm(vec3(x,y, 0)); //yes...?
	}

	for (int i = 0; i <= sides+1; i++) { //adding side UVs
		float spacing = (float)1 / sides;

		cyl.addUv(vec2(spacing*i, 1));
		cyl.addUv(vec2(spacing*i, 0.374));


	}

	for (int i = 6; i <= sides*2 + 4; i+=2) { //+2 makes an open cake??
		Face f1, f2, f3, f4;

		if (i == sides * 2 + 4) { //fix this

			f1 = { 1,1,1,										i - 3,i - 3,1,								 3,3,1 };
			f3 = { 4,i+(int)sides * 2,4,						3,i-1+(int)sides * 2,3,						i - 2,i - 2 + (int)sides * 2,i - 2 }; //side 2 //4 has to connect to last 
			f2 = { i - 3,i - 3 + (int)sides * 2,i - 3,			i - 2,i - 2 + (int)sides * 2,i - 2,			3,i-1+(int)sides * 2,3 }; //side 1 //3 needs to connect to 2nd to last
			f4 = { 2,2,2,										 4,4,2,										i - 2,i - 2,2 };
		}
		else {
			f1 = { 1,1,1,										i - 3,i - 3,1,								i - 1,i - 1,1 };
			f3 = { i,i + (int)sides * 2,i,						i - 1,i - 1 + (int)sides * 2,i - 1,			i - 2,i - 2 + (int)sides * 2,i - 2 }; //side2
			f2 = { i - 3,i - 3 + (int)sides * 2,i - 3,			i - 2,i - 2 + (int)sides * 2,i - 2,			i - 1,i - 1 + (int)sides * 2,i - 1 }; //side1
			f4 = { 2,2,2,										i,i,2,										i - 2,i - 2,2};
		}


		cyl.addFace(f1);
		cyl.addFace(f2);
		cyl.addFace(f3);
		cyl.addFace(f4);

	}

	cyl.writeObj(filename);
	return true;
} 

//DONE
bool makeSphere(string filename, int lat, int lon) {
	Shape ball;

	float subAxis = (float)lon; //longitude
	float subHeight = (float)lat+2; //latitude

	float x, y, z;
	///////////////////////CREATE THE RINGS
	for (int v = 1; v < subHeight; v++) {   //CREATING THE NONE POLES
		float numV = (float)v / subHeight;

		for (int u = 0; u < subAxis; u++) {
			float numU = (float)u / subAxis;

			x = glm::sin(M_PI * numV) * glm::cos(2 * M_PI * numU);
			y = glm::cos(M_PI * numV);
			z = glm::sin(M_PI * numV) * glm::sin(2 * M_PI * numU);

				ball.addLoc(vec3(x, y, z));
				ball.addUv(vec2(numU,numV));
				ball.addNorm(vec3(x, y, z));
		}
	}

	for (int u = 0; u < subAxis; u++) { //CREATING POLE AT 0 HEIGHT
		float v = 0;
		float numV = (float)v / subHeight;
		float numU = (float)u / subAxis;

		x = glm::sin(M_PI * numV) * glm::cos(2 * M_PI * numU);
		y = glm::cos(M_PI * numV);
		z = glm::sin(M_PI * numV) * glm::sin(2 * M_PI * numU);

		if (u == 0) { //////////////////////create the location only ONCE
					ball.addLoc(vec3(x, y, z));
		}
		ball.addUv(vec2(numU, 1));
		ball.addNorm(vec3(x, y, z));
	}
	for (int u = 0; u < subAxis; u++) { //CREATING POLE AT MAX HEIGHT
		float v = subHeight;
		float numV = (float)v / subHeight;
		float numU = (float)u / subAxis;

		x = glm::sin(M_PI * numV) * glm::cos(2 * M_PI * numU);
		y = glm::cos(M_PI * numV);
		z = glm::sin(M_PI * numV) * glm::sin(2 * M_PI * numU);

		if (u == 0) { //////////////////////create the location only ONCE
			ball.addLoc(vec3(x, y, z));
		}
		ball.addUv(vec2(numU, 0));
		ball.addNorm(vec3(x, y, z));
	}


	//adding the last UV points
	for (int u = 0; u < subAxis; u++) { //TOPmost UVs 85-90
		float numU = (float)u / subAxis;
		ball.addUv(vec2(numU, 1));
	}
	for (int v = 1; v < subHeight; v++) { //rightmost UVs
		float numV = (float)v / subHeight;
		ball.addUv(vec2(1, numV));
	}

	///////////////////////////////////////////////////MAKING FACES
	for (int i = 1; i <= subAxis; i++) { //MAKING SOUTH POLE
		Face f1;
		if (i == subAxis) {
			//f1 = { (int)subAxis*((int)subHeight - 1) + 1, (int)subAxis*((int)subHeight - 1) + i,(int)subAxis*((int)subHeight - 1) + i , 1,1,1, i, i, i };
			f1 = { (int)subAxis*((int)subHeight - 1) + 1, (int)subAxis*(int)subHeight + i,(int)subAxis*(int)subHeight + i - (int)subAxis , 1,((int)subAxis*((int)subHeight))+(int)subHeight-1,1, i, i, i };

		}
		else
		f1 = { (int)subAxis*((int)subHeight-1)+1, (int)subAxis*(int)subHeight + i,(int)subAxis*(int)subHeight + i , i + 1, i + 1, i + 1, i, i, i };

		ball.addFace(f1);
	}

	for (int i = 1; i <= (subAxis)*(subHeight-2); i++) { //making the NONE POLEs //since we are doing the bow, start on 2nd row
		Face f1, f2;
		if (i%(int)subAxis == 0) {
			//f1 = { i, i, i,					i - ((int)subAxis - 1),i - ((int)subAxis - 1),i - ((int)subAxis - 1),			i + (int)subAxis, i + (int)subAxis, i + (int)subAxis };
			//f2 = {  i + 1, i + 1, i + 1,	i + (int)subAxis, i + (int)subAxis, i + (int)subAxis,							i - ((int)subAxis - 1),i - ((int)subAxis - 1),i - ((int)subAxis - 1)};

			f1 = { i, i, i,					i - ((int)subAxis - 1),(int)subHeight*(int)subAxis+(int)subHeight-2+(i/(int)subAxis),i - ((int)subAxis - 1),					i + (int)subAxis, i + (int)subAxis, i + (int)subAxis };
			f2 = { i + 1, (int)subHeight*(int)subAxis + (int)subHeight - 2 + (i / (int)subAxis)+1, i + 1,		i + (int)subAxis, i + (int)subAxis, i + (int)subAxis,				i - ((int)subAxis - 1),(int)subHeight*(int)subAxis + (int)subHeight - 2 + (i / (int)subAxis),i - ((int)subAxis - 1) };


		}
		else {
			f1 = { i, i, i, i + 1, i + 1, i + 1, i + (int)subAxis, i + (int)subAxis, i + (int)subAxis };
			f2 = { i + (int)subAxis + 1, i + (int)subAxis + 1, i + (int)subAxis + 1, i + (int)subAxis, i + (int)subAxis, i + (int)subAxis,  i + 1, i + 1, i + 1 };
		}
		ball.addFace(f2);
		ball.addFace(f1);
	
	}

	for (int i = (subAxis)*(subHeight - 2)+1; i <= (subAxis)*(subHeight - 2)+subAxis; i++) { //MAKING NORTH POLE
		Face f1;
		int k = (int)subAxis*2+i - (int)((subAxis)*(subHeight - 2) + 1);

		if (i == (subAxis)*(subHeight - 2) + subAxis) {
			f1 = { (int)subAxis*((int)subHeight - 1) + 2,(int)subAxis*((int)subHeight - 1) + 1 + k,(int)subAxis*((int)subHeight - 1) + k - (int)subAxis +1, i, i, i, ((int)subAxis)*((int)subHeight - 2)+1, ((int)subAxis*((int)subHeight)) + (int)subHeight * 2 - 3,((int)subAxis)*((int)subHeight - 2)+1 };

		}
		else
			f1 = { (int)subAxis*((int)subHeight - 1) + 2,(int)subAxis*((int)subHeight - 1) + 1 + k,(int)subAxis*((int)subHeight - 1) + k - (int)subAxis+1 , i, i, i, i + 1,i + 1, i + 1 };

		ball.addFace(f1);
	}



	ball.writeObj(filename);
	return true;
}
