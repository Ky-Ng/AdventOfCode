#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]){
    cout << "Hello Day 1 " << endl;
    cout << "===========================" << endl;
    
    ifstream reader("day1.in");
    string line;
    int maxCalorie1 = -1, maxCalorie2 = -1, maxCalorie3 = -1;
    int calorieCounter = 0;

    while(getline(reader, line)){
        if(line.length() > 0){
            cout << "Adding " << line << endl;
            calorieCounter += stoi(line);
            cout << "Calorie Counter is " << calorieCounter << endl;
        }
        else {
            cout << "Hit a new line" << endl;
            if(calorieCounter > maxCalorie1) {
                maxCalorie3 = maxCalorie2;
                maxCalorie2 = maxCalorie1;
                maxCalorie1 = calorieCounter;
            }
            else if (calorieCounter > maxCalorie2){
                maxCalorie3 = maxCalorie2;
                maxCalorie2 = calorieCounter;
            }
             else if (calorieCounter > maxCalorie3){
                maxCalorie3 = calorieCounter;
            }
            calorieCounter = 0;
        }
    }

    cout << "Max Calorie 1: " << maxCalorie1 << endl;
    cout << "Max Calorie 2: " << maxCalorie2 << endl;
    cout << "Max Calorie 3: " << maxCalorie3 << endl;
    cout << "Sum is " << maxCalorie1 + maxCalorie2 + maxCalorie3 << endl;
    return 0;
}

// clang++ -std=c++11 -g -Wall day1.cpp -o day1