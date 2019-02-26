#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"
#include "person.cpp"

using namespace std;

void readData(string file, Person array[], int aSize);
void writeData(Person array[], int aSize);

int main()
{
  int size = 20;
  Person arr[size];
  string file = "input.txt";

  readData(file, arr, size);
  writeData(arr, size);

  return 0;
}

void readData(string file, Person array[], int aSize)
{
  ifstream readFile;
  Person obj;
  string fName, lName;
  float rate, hours;

  readFile.open(file);

  if(readFile.fail())
  {
    cout << "Error\n";
  }

  for(int i = 0; i < aSize; i++)
  {
    if(readFile >> fName)
    {
      readFile >> lName;
      readFile >> hours;
      readFile >> rate;
      array[i].setFirstName(fName);
      array[i].setLastName(lName);
      array[i].setHoursWorked(hours);
      array[i].setPayRate(rate);
    }
  }

  readFile.close();
}

void writeData(Person array[], int aSize)
{
  ofstream writeFile;
  string name;
  float wage;
  Person obj;
  int counter = 0;

  writeFile.open("output.txt");

  // Counts how many indexes are filled with non default entries
  for(int i = 0; i < aSize; i++)
  {
    if(array[i].getFirstName() != "NA")
    {
      counter++;
    }
  }

  // Writes data stored in the array to a seperate text file
  for(int j = 0; j < counter; j++)
  {
    name = array[j].fullName();
    wage = array[j].totalPay();
    writeFile << name << " " << fixed << setprecision(2) << wage << endl;
  }

  writeFile.close();
}
