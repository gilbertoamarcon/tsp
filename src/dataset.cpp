#include "dataset.hpp"

Dataset::Dataset(){
	this->distances = NULL;
}

double Dataset::compute_distance(pair<double,double> &c_a, pair<double,double> &c_b){
	return sqrt(pow(c_a.first - c_b.first, 2) + pow(c_a.second - c_b.second, 2));
}

void Dataset::compute_distances(){
	distances = new double[cities.size()*cities.size()];
	for(int i = 0; i < cities.size(); i++)
		for(int j = 0; j < cities.size(); j++)
			distances[i*cities.size()+j] = compute_distance(cities.at(i), cities.at(j));
}

int Dataset::load_dataset(char *filename){

	FILE *file;	
	char fileBuffer[BUFFER_SIZE]; 

	file 	= fopen(filename,"r");
	if(file == NULL)
		return 1;

	// File Header
	if(fgets(fileBuffer, BUFFER_SIZE, file) == NULL){
		printf("Error: Wrong file type.\n");
		return 1;
	}
	int int_file_len = atoi(fileBuffer);

	// File Header
	for(int i = 0; i < int_file_len; i++){
		if(fgets(fileBuffer, BUFFER_SIZE, file) == NULL){
			printf("Error: Wrong file type.\n");
			return 1;
		}
		int aux = 0;
		double x = atof(fileBuffer+aux);
		while(fileBuffer[aux++] != ',');
		double y = atof(fileBuffer+aux);
		cities.push_back(pair<double,double>(x,y));
	}
	compute_distances();
	printf("%d cities loaded.\n", cities.size());

	return 0;
}

void Dataset::print_city(pair<double,double> &c){
	printf("%9.3f %9.3f\n", c.first, c.second);
}

void Dataset::print_dataset(){
	printf("---\n");
	printf("Dataset: \n");
	for(auto &c : cities)
		print_city(c);
	printf("---\n");
}

pair<double,double> Dataset::get_location(int city_index){
	return cities.at(city_index);
}

void Dataset::print_distances(){
	printf("---\n");
	printf("Distances: \n");
	for(int i = 0; i < cities.size(); i++){
		for(int j = 0; j < cities.size(); j++)
			printf("%9.2f ", distances[i*cities.size()+j]);
		printf("\n");
	}
	printf("---\n");
}

double Dataset::get_dist(int city_a, int city_b){
	return distances[city_a*cities.size()+city_b];
}

int Dataset::size(){
	return cities.size();
}