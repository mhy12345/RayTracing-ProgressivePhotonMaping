#ifndef CAMERA_H
#define CAMERA_H
#include "vector.h"

class Camera {
	private:
		Vector position;
		Vector dx,dy;
		Vector origin;
		int rx,ry;
	public:
		Camera();
		~Camera();
		void accept(const Json::Value& val);
		int getRx()const {return rx;}
		int getRy()const {return ry;}
		void getRay(double scanX, double scanY, Vector &rayO, Vector &rayD);
};

#endif
