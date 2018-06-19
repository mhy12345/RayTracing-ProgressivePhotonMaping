#ifndef COLOR_H
#define COLOR_H
#include "json/json.h"

class Color
{
	private:
		double r,g,b;
	public:
		Color();
		Color(double r,double g,double b);
		friend Color operator +(const Color& a,const Color &b);
		void accept(const Json::Value& val);
		double getR()const {return r;}
		double getG()const {return g;}
		double getB()const {return b;}
};

#endif
