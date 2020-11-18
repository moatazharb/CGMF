/*------------------------------------------------------------------------------
  CGMF-1.0
  Copyright TRIAD/LANL/DOE - see file COPYRIGHT.md
  For any questions about CGMF, please contact us at cgmf-help@lanl.gov
-------------------------------------------------------------------------------*/

/*! @file rngcgm.h

  \brief Class to define the random number generator

*/

#ifndef __RNGCGM_H__
#define __RNGCGM_H__

/*
   rngcgm.h :
        uniform double random number sampling based on <random>
*/

#include <random>
#include <functional>

/*!

 \brief RNG class

 \todo Add complete documentation.
 
 */
class UniformRNG{
  private:
    int seed;
    std::uniform_real_distribution<> dist;
    std::mt19937 gen;
  public:
    UniformRNG (int s) : seed(s) {
      std::uniform_real_distribution<double> dist(0.0,1.0);
      std::mt19937 gen(seed);
    }
    void set_seed (int s) {
      seed = s;
      gen.seed(seed);
    }
    double operator()() { return dist(gen); }
};


std::function< double(void) > rng_cgm {}; 


static void set_rng(std::function<double(void)> rng) {
    rng_cgm = rng;
}


static void set_rng(double (*funcptr) (void)) {
    rng_cgm = funcptr;
}



#endif //__RNGCGM_H__
