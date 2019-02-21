#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"

using namespace std;

Person::Person()
{
  firstName = "NA";
  lastName = "NA";
  payRate = 0.00;
  hoursWorked = 0.0;
}

void Person::setLastName(string lName)
{
  lastName = lName;
}

string Person::getLastName()
{
  return lastName;
}

void Person::setFirstName(string fName)
{
  firstName = fName;
}

string Person::getFirstName()
{
  return firstName;
}

string Person::fullName()
{
  return firstName + " " + lastName;
}

void Person::setPayRate(float rate)
{
  payRate = rate;
}

float Person::getPayRate()
{
  return payRate;
}

float Person::totalPay()
{
  return getPayRate() * getHoursWorked();
}

void Person::setHoursWorked(float hours)
{
  hoursWorked = hours;
}

float Person::getHoursWorked()
{
  return hoursWorked;
}
