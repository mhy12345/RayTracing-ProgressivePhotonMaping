#ifndef RAYTRACING_H
#define RAYTRACING_H

#include <vector>
#include "../core/light.h"
#include "../core/camera.h"
#include "../core/object.h"
#include "../core/color.h"
#include "../display/paintboard.h"
#include "json/json.h"

class RayTracing{
	private:
		Camera *camera;
		std::vector<Light*> lights;
		std::vector<Object*> objects;
		Color *bg_color;
		Color **board;
		PaintBoard* paint_board;
		int max_depth;
		int shade_quality;
		int spec_power;
	public:
		RayTracing();
		~RayTracing();
		virtual void accept(const Json::Value& val);
		Color calcReflection(const Object& obj, int depth, unsigned& hash);
		Color calcDiffusion(const Object& obj);

		const Object* findCollidedObject(const Vector &rayO,const Vector& rayD);
		const Light* findCollidedLight(const Vector& rayO,const Vector& rayD);
		Color rayTrace(const Vector& rayO, const Vector& rayD, int depth, unsigned& hash);
		void run();
		void registerPaintBoard(PaintBoard* pb) ;
		void update();
};

#endif
