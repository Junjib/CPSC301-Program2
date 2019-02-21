#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"
#include "person.cpp"

using namespace std;

void readData(string file, Person array[], int aSize);
void display(Person array[], int aSize);

int main()
{
  int size = 20;
  Person arr[size];
  string file = "input.txt";

  readData(file, arr, size);
  display(arr, size);

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
    if(!readFile.eof())
    {
      readFile >> fName;
      readFile >> lName;
      readFile >> hours;
      readFile >> rate;
      array[i].setFirstName(fName);
      array[i].setLastName(lName);
      array[i].setHoursWorked(hours);
      array[i].setPayRate(rate);
    }

  }

}

void display(Person array[], int aSize)
{
  for(int i = 0; i < aSize; i++)
  {
    cout << array[i].getFirstName() << " " << array[i].getLastName() << " ";
    cout << array[i].getHoursWorked() << " " << array[i].getPayRate() << endl;
  }
}
