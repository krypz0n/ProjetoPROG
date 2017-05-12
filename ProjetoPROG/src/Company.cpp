#include "Company.h"

using namespace std;

Company::Company(){

}

Company::Company(Company &obj){

	this->nome = obj.getNome();
	this->linhas = obj.getLinhas();
	this->condutores = obj.getCondutores();
}

Company::Company(string nome, string fichCondutores, string fichLinhas){

	this->nome = nome;
	ifstream in_stream;

	in_stream.open(fichLinhas.c_str(), ifstream::in);

	int id, freq, time, linhaId = 1;
	string buffer, str;
	vector<string> busStops;
	vector<int> stopTimes;

	while(in_stream >> id){
		in_stream >> freq;
		in_stream >> buffer;
		if(buffer.compare(";") != 0){
			cout << "Couldn't find \";\"";
			return;
		}
		while(in_stream >> buffer != ";"){
			while(in_stream >> buffer != ","){
				str.append(buffer);
				str.append(" ");
			}
			str[str.length()-1] = '\0';
			busStops.push_back(str);
		}
		for(int i = 0; i < (int)busStops.size()-1; i++){
			in_stream >> time;
			stopTimes.push_back(time);
			in_stream >> buffer;
		}
		this->linhas.push_back(Line(linhaId, freq, busStops, stopTimes));
	}

	in_stream.open(fichCondutores.c_str(), ifstream::in);
	int turno, maxSemana, minDescanso;

	while(in_stream >> id){
		in_stream >> buffer;
		if(buffer.compare(";") != 0){
			cout << "Couldn't find \";\"";
			return;
		}
		while(in_stream >> buffer != ";"){
			while(in_stream >> buffer != ","){
				str.append(buffer);
				str.append(" ");
			}
			str[str.length()-1] = '\0';
		}
		in_stream >> turno;
		in_stream >> maxSemana;
		in_stream >> minDescanso;
		this->condutores.push_back(Driver(id, str, turno, maxSemana, minDescanso));
	}
	in_stream.close();
}

////////////////////////////////
// metodos get
///////////////////////////////
string Company::getNome() const{
  return nome;
}
vector<Driver> Company::getCondutores() const{
  return condutores;
}
vector<Line> Company::getLinhas() const{
  return linhas;
}
//////////////////////////////
// metodos set
/////////////////////////////
void Company::setNome(string nome){
	this->nome = nome;
}
void Company::setCondutores(vector<Driver> condutores){
	this->condutores = condutores;
}
void Company::setLinhas(vector<Line> linhas){
	this->linhas = linhas;
}
////////////////////////////
// outros metodos
///////////////////////////
void Company::addCondutor(Driver condutor){
	this->condutores.push_back(condutor);
}
Driver Company::findCondutor(int id){
	int i = 0;

	while((int)this->condutores.at(i).getId() != id && (int)this->condutores.size()-1 != i){
		i++;
	}

	return this->condutores.at(i);
}
void Company::removeCondutor(int id){
	int i = 0;

	while((int)this->condutores.at(i).getId() != id && (int)this->condutores.size()-1 != i){
		i++;
	}

	this->condutores.erase(this->condutores.begin()+i);
}
