#ifndef __isingmodel_hpp__   
#define __isingmodel_hpp__

#include<armadillo>
#include<random>
using namespace arma;
using namespace std;

class Ising
{
private:
 double E_;
 double M_;
 double E_sum;
 double M_sum;
 double Eavg; // Mean Energy
 double Mavg; // Mean Magnetization
 double E_sqr; 
 double M_sqr;
 double E2_; // Mean Energy^2
 double M2_; // Mean Magnetization^2
 double cv_;
 double chi_;


public:
 double kb = 1.; // Boltzmann Constant
 int J_ = 1; // Association Energy Constant
 int L_;  // Length of Spin Configuration
 mat S_; // Spin Configuration
 vec Tvec_; // Temperature Vector
 int tsize_;
 double beta_; // Inverse Temperature
 vec bvec_; // Inverse Temperature Vector
 int mc_cycles_; // Number of MCMC cycles
 double norm_; // Normalizing Factor For Averages
 vec boltz_ = vec(17).fill(0.);  // Delta Energy Values
 int i_flip; // Row Flip Index
 int j_flip; // Column Flip Index
 

 // Constructor 
 Ising(int L_in, vec Tvec_in, int cycles_in);

 // Delta Energy Values
 void dE_values();

 // Initial Spin Configuration
 void start_config();

 // Periodic Boundary Condition
 int Periodic(int i, int L);

 // Energy Around The Original Spin
 int E_spin_orig(int i, int j);

 // Energy Around The Flipped Spin
 int E_spin_flip(int i, int j);

 // Energy Difference
 int dE(int i, int j);

 // Probability Ratio for Energy Shift of 1 Spin Change
 double p(int dE);

//  // 1 Spin Change
//  void flip();

 // Calculate Total Energy For A Given Spin Configuration
 int E(mat S);

 // Calculate Total Magnetization For A Given Spin Configuration
 int M(mat S);

 // Specific Heat Capacity
 double Cv();

 // Magnetic Susceptibility
 double Chi();

 // Metropolis Rule
 void metropolis();

 // Monte Carlo
 void monte_carlo();

 // Temperature Monte Carlo plots
 void mc_temp();

 // Export
 void filesave(int i);

 // Print out
 void print();

};

#endif