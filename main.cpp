#include<iostream>
#include<math.h>

class plan{
	private:
		int 		k,
				rang;

		double  	e,
				h,
				x0,
	       			y0,
	       			h_opt,
	public:
		plan		( double x0, double y0, double h, double e );
		double dabs	( double var );
		double f	( double t, double x, double y );
		double g	( double t, double x, double y );
		double fopt_st	( double e );
};

plan::plan ( double x0, double y0, double h, double e ):
	x0( xo ),
	y0( y0 ),
	h( h ),
	e( e )
{}

double plan::	dabs 	( double var ){ return var < 0 ? -var : var; }

double plan::	f 	( double t, double x, double y){
	return 2*x - y + t*t - 2*( sin( t ) + 1 ) + cos ( t );
}

double plna::	g 	( double t ,double x, double y ){
	return x + 2*y - sin( t ) - 2*t + 2*t - 1;
}

double plan::	fopt_st	( double e ){
	h *= 2;
	double	t = 0,
		x1, y1,
		xm, ym,
		xh, yh;
	do{
		h /= 2;
		x1 = xh , y1 = yh; 	// the steps that should be done whan while : true
					// first step is just empty one
		x1 = x0 + h * f ( t, x0, y0 );
		y1 = y0 + h * g ( t, x0, y0 );

		xm = x0 + h/2 * f ( t, x0, y0 );
		ym = y0 + h/2 * g ( t, x0, y0 );

		xh = xm + h/2 * f ( t + h/2, xm, ym );
		yh = ym + h/2 * g ( t + h/2, xm ,ym );
	} while( debs ( xh - x1 ) + debs ( yh - y1 ) < e );
	return h;
}


