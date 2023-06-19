//
// Created by yuzj on 4/14/22.
// From <https://eigen.tuxfamily.org/dox/GettingStarted.html>

#include <iostream>
// FIXME: Include dir issues
#include <eigen3/Eigen/Dense>
// #include <Eigen/Dense>

using Eigen::MatrixXd;


int main()
{
	std::cout << "Eigen version: " << EIGEN_WORLD_VERSION << "." << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION
			  << std::endl;
	MatrixXd m(2, 2);
	m(0, 0) = 3;
	m(1, 0) = 2.5;
	m(0, 1) = -1;
	m(1, 1) = m(1, 0) + m(0, 1);
	std::cout << m << std::endl;
}
