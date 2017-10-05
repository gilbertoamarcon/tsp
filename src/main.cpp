#include "includes.hpp"
#include "sol.hpp"


int store_hist(vector<double> &costs, char *filename){	

	FILE *file;	
	char fileBuffer[BUFFER_SIZE]; 

	file 	= fopen(filename,"w");
	if(file == NULL){
		printf("Error writing file '%s'.\n",filename);
		return 1;
	}
	
	for(auto &c : costs)
		fprintf(file,"%.6f\n",c);
}

int main(int argc, char **argv){

	int method = atoi(argv[2]);

	vector<double> costs;

	int sol_count = 0;

	srand(clock());

	// Loading and printing dataset
	Dataset dataset;
	dataset.load_dataset(argv[1]);
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
	auto t1 = Clock::now();
	for(int e = 0; e < NUM_EPOCHS; e++){

		// Soring
		sort(sols.begin(),sols.end());

		// Error printing
		costs.push_back(sols.at(0).cost);
		// for(auto &sol : sols)
		// 	printf("%05.0f ", sol.cost);
		// printf("\n");

		vector<Sol> aux;

		if(method == 0)
			aux.push_back(sols.at(0));
		if(method == 1)
			for(int i = 0; i < POP_SIZE/2; i++)
				aux.push_back(sols.at(i));
		if(method == 2)
			for(int i = 0; i < POP_SIZE; i++){
				int sel = (int)(POP_SIZE*(1-sqrt(1-pow((double)rand()/INT_MAX,2))));
				printf("%d,", sel);
				aux.push_back(Sol(&sols.at(sel), MUTATION_RANGE));
			}

		// Erasing the population sols
		sols.erase(sols.begin(),sols.end());

		// Pushing back aux
		for(auto &p : aux)
			sols.push_back(p);

		// Creating offspring
		if(method == 0)
			for(int i = 0; i < POP_SIZE-1; i++)
				sols.push_back(Sol(&aux.at(0), MUTATION_RANGE));
		if(method == 1)
			for(int i = 0; i < POP_SIZE/2; i++)
				sols.push_back(Sol(&aux.at(i), MUTATION_RANGE));

	}
	auto t2 = Clock::now();
	sort(sols.begin(),sols.end());
	double time_ms = 1e-6*(double)(std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count());
	printf("%.3f,%.3f\n", time_ms, sols.at(0).cost);

	store_hist(costs,COST_PREF);

	return 0;
}

