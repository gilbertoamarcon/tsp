#include "sol.hpp"

void Sol::randomize(){
	vector<int> aux_vec;
	for(int i = 0; i < dataset->size(); i++)
		aux_vec.push_back(i);
	for(int i = 0; i < dataset->size(); i++){
		int choice = rand()%aux_vec.size();
		cities[i] = aux_vec.at(choice);
		aux_vec.erase(aux_vec.begin()+choice);
	}
}

void Sol::mutate(int range){
	for(int i = 0; i < range; i++){
		int index_a = rand()%dataset->size();
		int index_b = rand()%dataset->size();
		int aux = cities[index_a];
		cities[index_a] = cities[index_b];
		cities[index_b] = aux;
	}
}

double Sol::eval(){
	cost = 0.0;
	for(int i = 0; i < dataset->size()-1; i++)
		cost += dataset->get_dist(cities[i], cities[i+1]);
	return cost;
}

Sol::Sol(Dataset *dataset){
	this->dataset = dataset;
	this->cities = new int[dataset->size()];
	randomize();
	eval();
}

Sol::Sol(Sol *sol, int mutation_range){
	this->dataset	= sol->dataset;
	this->cost		= sol->cost;
	this->cities	= new int[dataset->size()];
	for(int i = 0; i < dataset->size(); i++)
		this->cities[i] = sol->cities[i];
	mutate(mutation_range);
	eval();
}

void Sol::print_solution(){
	printf("[%09.3f]: ", cost);
	for(int i = 0; i < dataset->size(); i++)
		printf("%0*d ", (int)((dataset->size()==0)?1:1+log((double)(dataset->size()))/log(10)), cities[i]);
	printf("\n");
}