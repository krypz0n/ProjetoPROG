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
		cout << "Escolha a funcionalidade pretendida: ";

		cin >> index;

		switch(index){
			case 1:{
				Company emp("Semprarrolar", "condutores.txt", "linhas.txt");
				empresa = emp;
				break;
			}

			case 2:{
				cout << "\n1. Criar um condutor;\n";
				cout << "2. Alterar um condutor;\n";
				cout << "3. Eliminar um condutor;\n";

				cin >> index;
				switch(index){
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
						cout << "Escolha o que pretende alterar:\n\n"
						cout << "1. Nome;\n";
						cout << "2. Duração máx do Turno;\n";
						cout << "3. Nº máx de Horas por Semana;\n";
						cout << "4. Tempo mín de Descanso;\n";

						cin >> index;
						switch(index){
							case 1:{
								break;
							}
							case 2:{
								break;
							}
							case 3:{
								break;
							}
							case 4:{
								break;
							}
						}
					}
				}
				break;
			}
		}
	}

	return 0;
}
