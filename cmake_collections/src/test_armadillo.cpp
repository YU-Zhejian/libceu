// From <http://arma.sourceforge.net/docs.html#example_prog>

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	cout << "Version: " << arma::arma_version::as_string() << endl;
	mat A(4, 5, fill::randu);
	mat B(4, 5, fill::randu);

	cout << A * B.t() << endl;
	return 0;
}
