#ifndef CEREAL_H
#define CEREAL_H
#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

const int MAXCHAR = 101;
struct Cereal{
  char name[MAXCHAR];
  int calories;
  int sugar;
  double ratings;
}; 

void loadCereal(ifstream &inFile, Cereal findData[], int &numCereal);
Cereal highRate(Cereal findData[], int numCereal);
Cereal lowRate(Cereal findData[], int numCereal);
Cereal nutricious(Cereal findData[], int numCereal);
Cereal findAvg(Cereal findData[], int numCereal);
void printData(Cereal findData[], int numCereal);
#endif