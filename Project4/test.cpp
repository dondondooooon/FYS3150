#include <iostream>
#include<armadillo>
#include<random>
using namespace arma;
using namespace std;

int main(){
    int L_ = 5;
    int i_flip; int j_flip;

    random_device rando;
	mt19937_64 generate(rando());
	uniform_real_distribution<double> distribution(0.0, 1.0);
	int x = 0;
    for (int i=0; i<2; i++){
        for (int j=0; j<2; j++){
            x += 1;
            cout << x << endl;
        }
        // i_flip = distribution(generate) * L_;
	    // j_flip = distribution(generate) * L_;

        // cout << "I: " << i_flip << " and J: " << j_flip << endl;
    }

    return 0;
}