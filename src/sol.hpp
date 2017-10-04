#ifndef __SOL_HPP__
#define __SOL_HPP__
#include "includes.hpp"
#include "dataset.hpp"

class Sol{

	private:
		Dataset *dataset;

		// Random Initialization
		void randomize();

		void mutate(int range);

		double eval();

	public:

		int *cities;
		double cost;

		// Constructors
		Sol(Dataset *dataset);
		Sol(Sol *sol, int mutation_range);

		void print_solution();

		bool operator < (const Sol& cities) const{
			return (cost < cities.cost);
		}
};


#endif
