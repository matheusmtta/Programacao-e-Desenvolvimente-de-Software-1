#include "pratica2.h"
#include <math.h>

float cauchyPadrao(float x)
	{
		float y;
		y=1/(M_PI*(1+x*x));
		return y;
	}

	float Gumbel(float x, float mi, float beta)
	{
		float y;
		float z;
		z=(x-mi)/beta;
		y=(1/beta)*exp(-(z+exp(-z)));
		return y;
	}

	float Laplace(float x, float mi, float b)
	{
		float t0 = -x+mi;
        float t1 = - fabs(t0) / b;
        float t2 = exp(t1);
        float t3 = 1.0/(2*b);
        float t4 = t3 * t2;
        float y;
        y=t4;
		return y;
	}