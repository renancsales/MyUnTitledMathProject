#include <iostream>

// Eigen packages
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/Core>

#define QUAD_PRECISION 1
// Check the quad precision
#if QUAD_PRECISION

// Multiple precision libraries
#include <mpreal.h>
#include <unsupported/Eigen/MPRealSupport>

// Set precision (long double - 128 bits)
using data_type = mpfr::mpreal;
using DenseMatrix = Eigen::Matrix<mpfr::mpreal, Eigen::Dynamic, Eigen::Dynamic>;
using Vector = Eigen::Vector<mpfr::mpreal, Eigen::Dynamic>;

using SparseMatrix = Eigen::SparseMatrix<mpfr::mpreal>;

#else
using data_type = double;
using DenseMatrix = Eigen::MatrixXd;
using Vector = Eigen::VectorXd;

using SparseMatrix = Eigen::SparseMatrix<data_type>;

#endif


int main(int argc, char* argv[])
{
	const int digits = 20;
	mpfr::mpreal::set_default_prec(mpfr::digits2bits(digits));

	data_type value = mpfr::sin(0.50);
	std::cout << value << std::endl;
	return 0;
}