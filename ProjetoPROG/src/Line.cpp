#include "Line.h"


Line::Line(unsigned int id, vector<string> busStopList, vector<int> timesList){

  // INITIALISATION CODE GOES IN HERE
  this->id = id;
  this->busStopList = busStopList;
  this->timesList = timesList;
}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}
////////////////
// set methods
////////////////

void Line::setId(unsigned int id){
	this->id = id;
}
void Line::setBusStops(vector<string> busStopList){
	this->busStopList = busStopList;
}
void Line::setTimings(vector<int> timesList){
	this->timesList = timesList;
}
