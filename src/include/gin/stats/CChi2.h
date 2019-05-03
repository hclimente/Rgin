#ifndef CCHI2_CLASS
#define CCHI2_CLASS

#include <cmath>
#include <iterator>
#include <set>

#include "Cephes/cephes.h"
#include "gin/globals.h"


/*
*CChi2 Exception Class
*/
class CChi2Exception {
	private:
		std::string __error_msg;
	public:
		CChi2Exception(std::string const& error_msg) : __error_msg(error_msg) {
			logging(GIN_ERROR, "CChi2 Exception: " + error_msg);
		}

		std::string what() {
			return __error_msg;
		}
};

/*
* CChi2 Class: Chi2 Distribution class
*/
class CChi2 {

private:
	static void __checkParameters(float64 const &);

public:
	static float64 cdf(float64 const &, float64 const &);
	static float64 logcdf(float64 const &, float64 const &);
	static float64 pdf(float64 const &, float64 const &);
	static float64 logpdf(float64 const &, float64 const &);
	static float64 sf(float64 const &, float64 const &);
	static float64 isf(float64 const &, float64 const &);
	static float64 logsf(float64 const &, float64 const &);
	static MatrixXd get2DContingencyTable(VectorXd const &, VectorXd const &, bool);
	static double calculateChi2(MatrixXd const &);
	static double calculateChi2Trend(MatrixXd const &, VectorXd const &);

};


#endif //CCHI2_CLASS
