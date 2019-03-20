#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "person.h"

using namespace std;

Person::Person(string firstName, string lastName, float payRate, float hoursWorked)
{
  setFirstName(firstName);
  setLastName(lastName);
  setPayRate(payRate);
  setHoursWorked(hoursWorked);
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
