//
// Created by hclimente on 22/07/2017.
//

#ifndef GIN_GRID_H
#define GIN_GRID_H

#include "gin/feature_selection/scones.h"
#include "gin/stats/univariate_association.h"
#include "gin/globals.h"

class Grid {

public:

	Grid(MatrixXd const&, VectorXd const&, SparseMatrixXd* const&, uint const&);
	Grid(MatrixXd const&, VectorXd const&, SparseMatrixXd* const&, uint const&, VectorXd const&, VectorXd const&);

	void search();

	// getters
	std::map<double, std::map<double, VectorXd>> grid() { return __grid; }
	VectorXd selected(double const&, double const&);
	std::vector<VectorXd> selected(VectorXd const &etas, VectorXd const &lambdas);

	MatrixXd X() { return __X; }
	VectorXd y() { return __y; }
	VectorXd c() { return __c; }
	VectorXd etas() { return __etas; }
	VectorXd lambdas() { return __lambdas; }

private:

	MatrixXd __X;
	VectorXd __y;
	SparseMatrixXd* __W;
	VectorXd __c;
	VectorXd __etas;
	VectorXd __lambdas;

	std::map<double, std::map<double, VectorXd>> __grid;

	void __initGrid();
	void __computeUnivariate(uint const&);

	};

#endif //GIN_GRID_H
