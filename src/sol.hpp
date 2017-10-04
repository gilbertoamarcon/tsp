#ifndef __SOL_HPP__
#define __SOL_HPP__
#include "includes.hpp"
#include "dataset.hpp"

class Sol{

	private:
		Dataset *dataset;

		// Random Initialization
		void randomize();

	public:

		int *cities;
		double cost;

		// Constructors
		Sol(Dataset *dataset);
		Sol(Sol *sol);

		// Cost evaluation
		double eval();

		void print_solution();

		// Weight mutation
		void mutate(int range);

		bool operator < (const Sol& cities) const{
			return (cost < cities.cost);
		}
};


#endif
