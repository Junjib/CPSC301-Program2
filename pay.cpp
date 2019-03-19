// Junji Bressan
// 301 Section 1

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
#include "person.cpp"

using namespace std;

void readData(string file, vector<Person> &employees);
void writeData(vector<Person> &employees);

int main()
{
  vector<Person> employees;
  string file = "input.txt";

  readData(file, employees);
  writeData(employees);

  return 0;
}

void readData(string file, vector<Person> &employees)
{
  ifstream readFile;
  string fName, lName;
  float rate, hours;

  readFile.open(file);

  if(readFile.fail())
  {
    cout << "Error\n";
  }

  while(readFile >> fName)
  {
    readFile >> lName;
    readFile >> hours;
    readFile >> rate;
    employees.emplace_back(fName, lName, rate, hours);
  }
  readFile.close();
}

void writeData(vector<Person> &employees)
{
  ofstream writeFile;
  string name;
  float wage;
  int counter = 0;

  writeFile.open("output.txt");

  for(int i = 0; i < employees.size(); i++)
  {
    name = employees[i].fullName();
    wage = employees[i].totalPay();
    writeFile << name << " " << fixed << setprecision(2) << wage << endl;
  }
  writeFile.close();
}
