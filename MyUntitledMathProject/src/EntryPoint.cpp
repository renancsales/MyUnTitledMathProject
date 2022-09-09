#include <iostream>
#include <iomanip>

// Eigen packages
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/Core>

#define MPIR_PRECISION 1
// Arbitrary precision
#if MPIR_PRECISION

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
	const int digits = 30;
	mpfr::mpreal::set_default_prec(mpfr::digits2bits(digits));

	std::cout << "Checking MPReal\n";
	data_type value = 2.0 * mpfr::asin(1.0);
	std::cout << std::setprecision(digits) << "PI = " << value << std::endl << std::endl;

	std::cout << "Checking Eigen\n";
	DenseMatrix A = DenseMatrix::Random(3, 3);
	std::cout << "A = \n";
	std::cout << std::setprecision(digits) << std::scientific << A << std::endl;
	return 0;
}