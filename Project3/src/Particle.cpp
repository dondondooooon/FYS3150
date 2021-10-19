#include "Particle.hpp"

// Constructor Defintion
Particle::Particle(double q_in, double m_in, vec r_in, vec v_in, int part_in){
  m_q = q_in; // Charge
  m_m = m_in; // Mass
  m_r = r_in; // Position
  m_v = v_in; // Velocity
  m_part = part_in; // i-th Particle 
}

// Return particle's information
string Particle::info(){
  // For converting arma::vec to string
  ostringstream sr, sv;
  sr << m_r.st();
  sv << m_v.st();

  string info_string = "\nParticle Index: " + to_string(m_part) + " | " +
  "Charge: " + to_string(m_q) + " | " + "Mass: " + to_string(m_m)
  + " |\n" + "\nIni Pos:" + sr.str() + "\nIni Vec:" + sv.str() ;

  return info_string;
}