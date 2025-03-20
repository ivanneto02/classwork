#include <iostream>
using namespace std;

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
   double inverseMilesPerGallon = 1.0/milesPerGallon;
   
   return drivenMiles*inverseMilesPerGallon*dollarsPerGallon;
}



int main() {
   double milesPerGallon, dollarsPerGallon;
   
   cin >> milesPerGallon >> dollarsPerGallon;
   
   cout << DrivingCost(10, milesPerGallon, dollarsPerGallon) << " ";
   cout << DrivingCost(50, milesPerGallon, dollarsPerGallon) << " ";
   cout << DrivingCost(400, milesPerGallon, dollarsPerGallon) << endl;

   return 0;
}