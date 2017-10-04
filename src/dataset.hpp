#ifndef __DATASET_HPP__
#define __DATASET_HPP__
#include "includes.hpp"

class Dataset{

	private:

		double *distances;
		vector<pair<double,double>> cities;

		double compute_distance(pair<double,double> &c_a, pair<double,double> &c_b);

		void compute_distances();

	public:

		// Constructors
		Dataset();

		int load_dataset(char *filename);

		void print_city(pair<double,double> &c);

		void print_dataset();

		void print_distances();

		pair<double,double> get_location(int city_index);

		double get_dist(int city_a, int city_b);

		int size();
};


#endif
