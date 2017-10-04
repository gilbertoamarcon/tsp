#include "includes.hpp"
#include "sol.hpp"

int main(int argc, char **argv){

	srand(clock());

	// Loading and printing dataset
	Dataset dataset;
	dataset.load_dataset(C15_);
	// dataset.print_dataset();
	// dataset.print_distances();

	// Initializing sols
	vector<Sol> sols;
	for(int i = 0; i < POP_SIZE; i++){
		Sol sol(&dataset);
		// sol.print_solution();
		sols.push_back(sol);
	}

	// For each Epoch
	for(int e = 0; e < NUM_EPOCHS; e++){

		// Soring
		sort(sols.begin(),sols.end());

		// Error printing
		for(auto &sol : sols)
			printf("%05.0f ", sol.cost);
		printf("\n");

		vector<Sol> aux;

		if(METHOD == 0)
			aux.push_back(sols.at(0));
		if(METHOD == 1)
			for(int i = 0; i < POP_SIZE/2; i++)
				aux.push_back(sols.at(i));
		if(METHOD == 2)
			for(int i = 0; i < POP_SIZE; i++){
				int sel = (int)(POP_SIZE*(1-sqrt(1-pow((double)rand()/INT_MAX,2))));
				// printf("%d,", sel);
				aux.push_back(Sol(&sols.at(sel), MUTATION_RANGE));
			}

		// Erasing the population sols
		sols.erase(sols.begin(),sols.end());

		// Pushing back aux
		for(auto &p : aux)
			sols.push_back(p);

		// Creating offspring
		if(METHOD == 0)
			for(int i = 0; i < POP_SIZE-1; i++)
				sols.push_back(Sol(&aux.at(0), MUTATION_RANGE));
		if(METHOD == 1)
			for(int i = 0; i < POP_SIZE/2; i++)
				sols.push_back(Sol(&aux.at(i), MUTATION_RANGE));

	}

	return 0;
}

