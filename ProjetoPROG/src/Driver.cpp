#include "Driver.h"

Driver::Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime){

  // INITIALISATION CODE GOES IN HERE
	this->id = id;
	this->name = name;
	this->maxHours = maxHours;        // maximum duration of a shift
	this->maxWeekWorkingTime = maxWeekWorkingTime;  // maximum number of hours of work in a week
	this->minRestTime = minRestTime;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

// set methods

void Driver::setId(unsigned int id){
  this->id = id;
}
void Driver::setName(string name){
  this->name = name;
}
void Driver::setShiftMaxDuration(unsigned int maxHours){
  this->maxHours = maxHours;
}
void Driver::setMaxWeekWorkingTime(unsigned int maxWeekWorkingTime){
  this->maxWeekWorkingTime = maxWeekWorkingTime;
}
void Driver::setMinRestTime(unsigned int minRestTime){
  this->minRestTime = minRestTime;
}
void Driver::setShifts(vector<Shift> shifts){
  this->shifts = shifts;
}
