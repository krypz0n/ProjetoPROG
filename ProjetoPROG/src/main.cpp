#include <iostream>
#include "Bus.h"
#include "Company.h"
#include "Driver.h"
#include "Line.h"
#include "Shift.h"

using namespace std;

int main(){

	int index = 1;
	Company empresa;

	while(index != 0){

		cout << "\n-/- Menu -\\-\n\n";
		cout << "1. Ler e guardar a informação de linhas e condutores armazenada em ficheiros;\n";
		cout << "2. Gerir os condutores: criar, alterar e remover um condutor;\n";
		cout << "3. Gerar e visualizar de modo formatado tabelas com horários de uma paragem;\n";
		cout << "4. Visualizar o trabalho atribuído a um condutor;\n";
		cout << "5. Visualizar a informação de um autocarro;\n";
		cout << "6. Visualizar a informação de uma linha, visualizando de modo formatado a tabela com o seu horário;\n";
		cout << "7. Inquirir sobre quais as linhas que incluem determinada paragem;\n";
		cout << "8. Calcular e visualizar um percurso e tempo de viagem entre duas quaisquer paragens indicadas pelo;\n";
		cout << "9. Listar todos os períodos de autocarros sem condutor atribuído.\n";
		cout << "10. Listar todos os períodos de condutores sem o serviço completo atribuído.\n";
		cout << "11. Efetuar interactivamente a atribuição de serviço a um condutor, permitindo ao utilizador ver as\n";
		cout << "0. Sair;\n";
		cout << "Escolha a funcionalidade pretendida: ";

		cin >> index;
		switch(index){
			case 0:{
				cout << "A sair...";
				return 0;
			}
			case 1:{
				string linhasF, condutoresF;
				cout << "Indique os ficheiros:\n\n";

				cout << "Condutores: ";
				cin >> condutoresF;

				cout << "Linhas: ";
				cin >> linhasF;

				Company emp("Semprarrolar", condutoresF, linhasF);
				empresa = emp;
				break;
			}

			case 2:{
				cout << "\n1. Criar um condutor;\n";
				cout << "2. Alterar um condutor;\n";
				cout << "3. Eliminar um condutor;\n";
				cout << "0. Voltar;\n";

				cin >> index;
				switch(index){
					case 0:{
						break;
					}
					case 1:{
						string buffer, str;
						int turno, maxSemana, minDescanso, id;

						cin >> id;
						cin >> buffer;
						if(buffer.compare(";") != 0){
							cout << "Couldn't find \";\"";
							break;
						}
						while(cin >> buffer != ";"){
							while(cin >> buffer != ","){
								str.append(buffer);
								str.append(" ");
							}
							str[str.length()-1] = '\0';
						}
						cin >> turno;
						cin >> maxSemana;
						cin >> minDescanso;

						empresa.addCondutor(Driver(id, str, turno, maxSemana, minDescanso));
						break;
					}
					case 2:{
						int id;
						cout << "Indique o ID do condutor: ";
						cin >> id;
						Driver condutor = empresa.findCondutor(id);

						cout << "\nEscolha o que pretende alterar:\n\n";
						cout << "1. Nome;\n";
						cout << "2. Duração máx do Turno;\n";
						cout << "3. Nº máx de Horas por Semana;\n";
						cout << "4. Tempo mín de Descanso;\n";
						cout << "0. Voltar;\n";

						cin >> index;
						switch(index){
							case 0:{
								break;
							}
							case 1:{
								string nome;
								cout << "Indique o novo Nome: ";
								getline(cin, nome);
								condutor.setName(nome);
								break;
							}
							case 2:{
								int max;
								cout << "Indique a nova Duração máx do Turno: ";
								cin >> max;
								condutor.setShiftMaxDuration(max);
								break;
							}
							case 3:{
								int max;
								cout << "Indique o novo Nº máx de Horas por Semana: ";
								cin >> max;
								condutor.setMaxWeekWorkingTime(max);
								break;
							}
							case 4:{
								int min;
								cout << "Indique o novo Tempo mín de Descanso: ";
								cin >> min;
								condutor.setMinRestTime(min);
								break;
							}
						}
					}
					case 3:{
						int id;
						cout << "Indique o ID do condutor: ";
						cin >> id;
						empresa.removeCondutor(id);
						break;
					}
				}
				break;
			}
			case 3:{
				string nomeP;
				cout << "Indique o nome da Paragem pretendida: ";
				cin.ignore();
				getline(cin, nomeP);

				vector<int> horario;

				for(unsigned int i = 0; i < empresa.getLinhas().size(); i++){
					Line linha = empresa.getLinhas().at(i);
					for(unsigned int j = 0; j < linha.getBusStops().size(); j++){
						string nome = linha.getBusStops().at(j);
						if(nome.compare(nomeP) == 0){
							int freq = linha.getFreq(), tempo = 800;

							while(tempo <= 2300){
								horario.push_back(tempo);
								tempo += freq;
							}
							cout << "Linha: " + linha.getId() << endl << endl;
							cout << "Sentido: " + linha.getBusStops().at(linha.getBusStops().size()-1) << endl << endl;
							for(unsigned int n = 0; n < horario.size(); n++)
								cout << horario.at(n) + 'h' << endl;

							horario.erase(horario.begin(), horario.end());
							vector<int> horario;

							tempo = 800;
							if(j != 0)
								tempo += linha.getTimings().at(j-1);
							while(tempo <= 2300){
								horario.push_back(tempo);
								tempo += freq;
							}
							cout << endl <<"Sentido: " + linha.getBusStops().at(0) << endl << endl;
							for(unsigned int n = 0; n < horario.size(); n++)
								cout << horario.at(n) + 'h' << endl;
						}
					}
				}
				break;
			}
		}
	}

	return 0;
}
