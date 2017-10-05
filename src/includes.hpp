#ifndef INCLUDES_H
#define INCLUDES_H
#include <png.h>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <random>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;

// Evolution Parameters
#define POP_SIZE		50
#define NUM_EPOCHS		10000
#define MUTATION_RANGE	1

#define PI				3.14159265

// File Parameters
#define BUFFER_SIZE		256

// Data Sets
#define COST_PREF		"res/cost_"
#define C25_			"data/25cities.csv"
#define C25A			"data/25cities_A.csv"
#define C100			"data/100cities.csv"

#define METHOD			2

#endif
