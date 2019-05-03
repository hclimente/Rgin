#ifndef CGAMMA_CLASS
#define CGAMMA_CLASS

#include "gin/globals.h"
//#include "utils/CMathHelper.h"

/*
*CGamma Exception Class
*/
class CGammaException {
	private:
		std::string __error_msg;
	public:
		CGammaException(std::string const& error_msg) : __error_msg(error_msg) {
			logging(GIN_ERROR,"CGamma Exception: " + error_msg)
		}

		std::string what() {
			return __error_msg;
		}
};

/*
* CGamma Class: Gamma Distribution class
*/
class CGamma {
	
	private:
		static void __checkParameters(float64 const&, float64 const&);

	public:
		static float64 cdf(float64 const&, float64 const&);
		static float64 logcdf(float64 const&, float64 const&);
		static float64 sf(float64 const&, float64 const&);
		static float64 logsf(float64 const&, float64 const&);
		static float64 pdf(float64 const&, float64 const&);
		static float64 logpdf(float64 const&, float64 const&);
	
};
		
#endif //CGAMMA_CLASS
