#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Line.h"
#include "Driver.h"


using namespace std;

class Company{
 private:
  string nome;
  vector<Line> linhas;
  vector<Driver> condutores;
 public:
  Company();
  Company(Company &obj);
  Company(string nome, string fichCondutores, string fichLinhas);
  // metodos get
  string getNome() const;
  vector<Driver> getCondutores() const;
  vector<Line> getLinhas() const;
  // metodos set
  void setNome(string nome);
  void setCondutores(vector<Driver> condutores);
  void setLinhas(vector<Line> linhas);
  // outros metodos
  void addCondutor(Driver condutor);
  Driver findCondutor(int id);
  void removeCondutor(int id);
};
