#include "cereal.h"

void loadCereal(ifstream &inFile, Cereal findData[], int &numCereal) {
  inFile.ignore(200, '\n');
  inFile.getline(findData[numCereal].name, 101, ';');
  while (!inFile.eof()) {
    inFile >> findData[numCereal].calories; 
    inFile.ignore(5, ';');
    inFile >> findData[numCereal].sugar;
    inFile.ignore(5, ';');
    inFile >> findData[numCereal].ratings;
    inFile.ignore(5, '\n');
    numCereal++;
    inFile.getline(findData[numCereal].name, 101, ';');
  }
}
Cereal highRate(Cereal findData[], int numCereal) {
  Cereal highestRating;
  highestRating.ratings = findData[1].ratings;
  for (int i = 0; i < numCereal; i++) {
    if (highestRating.ratings < findData[i].ratings) {
      highestRating = findData[i];
    }
  }
  return highestRating;
}
Cereal lowRate(Cereal findData[], int numCereal) {
  Cereal lowestRating;
  lowestRating.ratings = findData[1].ratings;
  for (int i = 0; i < numCereal; i++) {
    if (lowestRating.ratings > findData[i].ratings) {
      lowestRating = findData[i];
    }
  }
  return lowestRating;
}
Cereal nutricious(Cereal findData[], int numCereal) {
  Cereal mostNutricious;
  mostNutricious.calories = findData[1].calories;
  mostNutricious.sugar = findData[1].sugar;
  for (int i = 0; i < numCereal; i++) {
    if (mostNutricious.sugar > findData[i].sugar 
      && mostNutricious.calories > findData[i].calories) {
      mostNutricious = findData[i];  
    }
  }
  return mostNutricious;
} 
Cereal findAvg(Cereal findData[], int numCereal) {
  Cereal avg;
  for (int i = 0; i < numCereal; i++) {
    avg.calories += findData[i].calories;  
  }
  avg.calories /= numCereal;
  return avg;
}

void printData(Cereal findData[], int numCereal) {
  cout << left;
  cout << setw(35) << "Name of Cereal:";
  cout << left;
  cout << setw(10) << "Calories:" ; 
  cout << left;
  cout << setw(10) << "Sugar:";
  cout << left;
  cout << "Ratings:" << endl << endl;
  cout << fixed << setprecision(2);
  for (int i = 0; i < numCereal; i++) {
    cout << left;
    cout << setw(35) << findData[i].name;
    cout << left;
    cout << setw(10) << findData[i].calories; 
    cout << left;
    cout << setw(10) << findData[i].sugar;
    cout << left;
    cout << findData[i].ratings << "%" << endl;
  }
  for (int i = 0; i < 62; i++) {
    cout << "_";
  }
  cout << endl;
}