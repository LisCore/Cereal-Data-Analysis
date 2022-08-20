#include "cereal.h"

const int NUM = 30;
int main() {
  ifstream inFile;
  Cereal findData[NUM];
  Cereal highestRating, lowestRating, mostNutricious;
  Cereal average;
  int numCereal = 0;
  inFile.open("cereal.txt");
  if (!inFile) {
    cout << "Error, could not open file." << endl;
    exit(0);
  }
  
  loadCereal(inFile, findData, numCereal);
  highestRating = highRate(findData, numCereal);
  lowestRating = lowRate(findData, numCereal);
  mostNutricious = nutricious(findData, numCereal);
  average = findAvg(findData, numCereal);
  printData(findData, numCereal);

  cout << "The highest rating cereal is '" << highestRating.name << "' with " << highestRating.ratings << "%!" << endl;
  cout << "The lowest rating cereal is '" << lowestRating.name << "' with " << lowestRating.ratings << "%!" << endl;
  cout << "The healthiest option of cereal is '" << mostNutricious.name << "',\nwith " << mostNutricious.calories << " calories and " << mostNutricious.sugar << " grams of sugar!" << endl;
  cout << "Average number of calories in a cereal box is " << average.calories << " calories per serving!" << endl;
  return 0;
}