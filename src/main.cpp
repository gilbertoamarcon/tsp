#include "includes.hpp"
#include "sol.hpp"

int main(int argc, char **argv){

	srand(clock());

	// Loading and printing dataset
	Dataset dataset;
	dataset.load_dataset(C15_);
	dataset.print_dataset();
	dataset.print_distances();

	// Initializing sols
	vector<Sol> sols;
	for(int i = 0; i < POP_SIZE; i++){
		Sol sol(&dataset);
		sols.push_back(sol);
		sols.at(i).print_solution();
	}

	// For each Epoch
	for(int e = 0; e < NUM_EPOCHS; e++){

		// Error evaluation
		for(auto &sol : sols)
			sol.eval();

		// All sols evaluated, mutation and selection
		sort(sols.begin(),sols.end());

		// Error printing
		// for(auto &sol : sols)
		// 	printf("%09.3f ", sol.cost);
		// printf("\n");

		// Erasing the worst sols
		sols.erase(sols.begin()+NUM_PARENTS,sols.end());

		// Reproducing the best sols
		for(int i = 0; i < POP_SIZE-NUM_PARENTS; i++){

			// Parent selection
			Sol sol(&sols.at(rand()%NUM_PARENTS));

			// Mutation
			sol.mutate(MUTATION_RANGE);

			// Inserting into population
			sols.insert(sols.end(), sol);

		}

	}

	return 0;
}

