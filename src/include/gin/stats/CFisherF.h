#ifndef CFISHERF_CLASS
#define CFISHERF_CLASS

#include "gin/globals.h"
#include "gin/utils/CMathHelper.h"

/*
*CFisherF Exception Class
*/
class CFisherFException {
	private:
		std::string __error_msg;
	public:
		CFisherFException(std::string const& error_msg) : __error_msg(error_msg) {
			logging(GIN_ERROR,"CFisherF Exception: " + error_msg)
		}

		std::string what() {
			return __error_msg;
		}
};

/*
* CFisherF Class: FisherF Distribution class
*/
class CFisherF {
	
	private:
		static void __checkParameters(float64 const&, int const&, int const&);

	public:
		static float64 cdf(float64 const&, int const&, int const&);
		static float64 logcdf(float64 const&, int const&, int const&);
		static float64 pdf(float64 const&, int const&, int const&);
		static float64 ppf(float64 const&, int const&, int const&);
		static float64 logpdf(float64 const&, int const&, int const&);
		static float64 sf(float64 const&, int const&, int const&);
		static float64 isf(float64 const&, int const&, int const&);
		static float64 logsf(float64 const&, int const&, int const&);

};
	

#endif //CFISHERF_CLASS
