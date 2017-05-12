#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Line{
 private:
  unsigned int id;
  vector<string> busStopList;
  vector<int> timesList;
 public:
  Line(unsigned int id, vector<string> busStopList, vector<int> timesList);
  // metodos get
  unsigned int getId() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;
  // set methods
  void setId(unsigned int id);
  void setBusStops(vector<string> busStopList);
  void setTimings(vector<int> timesList);
  // other methods
};
