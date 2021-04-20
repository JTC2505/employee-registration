/*
Carnet: 1990 - 20 - 4006
Nombre: Julio Estuardo Teleguario
Seccion: A
Fecha: 17/04/2021
*/
#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include <limits>
#include <cstdio>

using namespace std;

//Variables globales o publicas
//Definicion de variables de captura de informacion
string nameEmployee;
string lastNameEmployee;
int birthYear; 
int age;
int hiringYear;
int workingYears;
float baseSalary;
float bonus;
float incentive;
int codeDepartament;
string TMPnameEmployee;
//Obtener tiempo local
time_t t = time(NULL);
tm * tPtr = localtime( & t);
int actualYear = (tPtr -> tm_year) + 1900;

//funcion para calcular anios en base a un anio inicial y el anio actual
int calculateYears(int year, int actualYear) {
	return actualYear - year;
}
//funcion para calculo de bonus
float calculateBonus(float salary, int departament) {
	if (departament == 2) {
		return salary * 0.05;
	} else if (departament == 3) {
		return salary * 0.01;
	} else {
		return salary * 0.02;
	}
}
//funcion para calculo de incentivo
float calculateIncentive(int year) {
	if (year >= 2) {
		return 250;
	} else if (year >= 5) {
		return 500;
	} else if (year >= 10) {
		return 1000;
	} else {
		return 0;
	}
}
//funcion que devuelve en departamento en texto
string departamentIntToString(int departament) {
	switch (departament) {
		case 1:
			return "Operaciones";
			break;
		case 2:
			return "Administrativo";
			break;
		case 3:
			return "RRHH";
			break;
		case 4:
			return "Mantenimiento";
			break;
	}
}

//Procedimiento para ingreso de informacion
void dataEntryProcedure() {
	system("cls");
	//Definicion del puntero que almacena la informacion en el archivo de texto	
	ofstream createRecord("registroEmpleados.txt", ios::app);
	//Ingreso de informacion
	cout<<"Nombre: ";
	cin>>nameEmployee;
	cout<<"Apellido: ";
	cin>>lastNameEmployee;
	cout<<"Anio de nacimiento: ";
	cin>>birthYear;
	cout<<"Anio de contratacion: ";
	cin>>hiringYear;
	cout<<"Sueldo base: ";
	cin>>baseSalary;
	do {
		cout<<"Ingrese el número correspondiente al departamento: "<<endl<<"\t 1. Operaciones"<<endl<<"\t 2. Administracion"<<endl<<"\t 3. RRHH"<<endl<<"\t 4. Mantenimiento"<<endl;
		cin>>codeDepartament;
		if (codeDepartament >= 5 || codeDepartament <= 0) {
			cout<<"No es un departamento valido, ingrese otro";
			system("pause");
		}
	} while (codeDepartament > 5 && codeDepartament < 0);
	//Calculos para completar informacion
	age = calculateYears(birthYear, actualYear);
	workingYears = calculateYears(hiringYear, actualYear);
	bonus = calculateBonus(baseSalary, codeDepartament);
	incentive = calculateIncentive(workingYears);
	//Imprimir informacion en txt
	createRecord<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
	createRecord.close();
}

void dataDisplayProcedure() {
	int showOption1, showOption2, minValue, maxValue;
	string findParameter1, findParameter2;
	float findParameter3, findParameter4;
	do {
		ifstream watchInventary("registroEmpleados.txt");
		ifstream searchDepartament("registroEmpleados.txt");
		system("cls");
		cout<<"\t Visualizacion de Datos"<<endl<<endl;
		cout<<"1. Todos los empleados"<<endl;
		cout<<"2. Por nombre"<<endl;
		cout<<"3. Por departamento"<<endl;
		cout<<"4. Por sueldo"<<endl;
		cout<<"5. Por anios de antiguedad"<<endl;
		cout<<"6. Regresar al menu principal"<<endl;
		cin>>showOption1;
		switch (showOption1) {
			case 1:
				system("cls");
				while (searchDepartament != NULL) {
					searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
					if (nameEmployee != TMPnameEmployee) {
						cout<<"------------------------------------------------------"<<endl;
						cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
						cout<<"	Anio de nacimiento: "<<birthYear<<endl;
						cout<<"	Edad: "<<age<<" anios"<<endl;
						cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
						cout<<"	Salario: Q"<<baseSalary<<endl;
						cout<<"	Bonus: Q"<<bonus<<endl;
						cout<<"	Anio contratacion: "<<hiringYear<<endl;
						cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
						cout<<"	Incentivo: Q"<<incentive<<endl;
					}
					TMPnameEmployee = nameEmployee;
				}
				system("pause");
				searchDepartament.close();
				break;
			case 2:
				system("cls");
				cout<<"Ingrese el nombre y apellido del empleado"<<endl;
				cout<<"Nombre: ";
				cin>>findParameter1;
				cout<<"Apellido: ";
				cin>>findParameter2;
				while (searchDepartament != NULL) {
					searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
					if (nameEmployee + " " + lastNameEmployee  == findParameter1 + " " + findParameter2 && nameEmployee != TMPnameEmployee) {
						cout<<"Coincidencias de busqueda: "<<endl;
						cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
						cout<<"	Anio de nacimiento: "<<birthYear<<endl;
						cout<<"	Edad: "<<age<<" anios"<<endl;
						cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
						cout<<"	Salario: Q"<<baseSalary<<endl;
						cout<<"	Bonus: Q"<<bonus<<endl;
						cout<<"	Anio contratacion: "<<hiringYear<<endl;
						cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
						cout<<"	Incentivo: Q"<<incentive<<endl;
					}
					TMPnameEmployee = nameEmployee;
				}
				system("pause");
				searchDepartament.close();
				break;
			case 3:
				system("cls");
				cout<<"Ingrese el departamento del empleado"<<endl;
				cout<<"Nombre del departamento: ";
				cin>>findParameter1;
				cout<<"Coincidencias de busqueda: "<<endl;
				while (searchDepartament != NULL) {
					searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
					if (departamentIntToString(codeDepartament)  == findParameter1 && nameEmployee != TMPnameEmployee) {
						cout<<"------------------------------------------------------------"<<endl;
						cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
						cout<<"	Anio de nacimiento: "<<birthYear<<endl;
						cout<<"	Edad: "<<age<<" anios"<<endl;
						cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
						cout<<"	Salario: Q"<<baseSalary<<endl;
						cout<<"	Bonus: Q"<<bonus<<endl;
						cout<<"	Anio contratacion: "<<hiringYear<<endl;
						cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
						cout<<"	Incentivo: Q"<<incentive<<endl;
					}
					TMPnameEmployee = nameEmployee;
				}
				system("pause");
				searchDepartament.close();
				break;
			case 4:
				do{
					ifstream watchInventary("registroEmpleados.txt");
					ifstream searchDepartament("registroEmpleados.txt");
					system("cls");
					cout<<"\t Busqueda por Sueldo"<<endl<<endl;
					cout<<"1. Cantidad"<<endl;
					cout<<"2. Rango"<<endl;
					cout<<"3. Regresar"<<endl;
					cin>>showOption2;
					switch (showOption2) {
						case 1:
							system("cls");
							cout<<"Ingrese la cantidad"<<endl;
							cin>>findParameter3;
							cout<<"Coincidencias de busqueda: "<<endl;
							while (searchDepartament != NULL) {
								searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
								if (baseSalary == findParameter3 && nameEmployee != TMPnameEmployee) {
									cout<<"------------------------------------------------------------"<<endl;
									cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
									cout<<"	Anio de nacimiento: "<<birthYear<<endl;
									cout<<"	Edad: "<<age<<" anios"<<endl;
									cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
									cout<<"	Salario: Q"<<baseSalary<<endl;
									cout<<"	Bonus: Q"<<bonus<<endl;
									cout<<"	Anio contratacion: "<<hiringYear<<endl;
									cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
									cout<<"	Incentivo: Q"<<incentive<<endl;
								}
								TMPnameEmployee = nameEmployee;
							}
							system("pause");
							break;
						case 2:
							system("cls");
							cout<<"Ingrese la cantidad minima"<<endl;
							cin>>findParameter3;
							cout<<"Ingrese la cantidad maxima"<<endl;
							cin>>findParameter4;
							cout<<"Coincidencias de busqueda: "<<endl;
							while (searchDepartament != NULL) {
								searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
								if (baseSalary >= findParameter3 && baseSalary <= findParameter4 && nameEmployee != TMPnameEmployee) {
									cout<<"------------------------------------------------------------"<<endl;
									cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
									cout<<"	Anio de nacimiento: "<<birthYear<<endl;
									cout<<"	Edad: "<<age<<" anios"<<endl;
									cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
									cout<<"	Salario: Q"<<baseSalary<<endl;
									cout<<"	Bonus: Q"<<bonus<<endl;
									cout<<"	Anio contratacion: "<<hiringYear<<endl;
									cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
									cout<<"	Incentivo: Q"<<incentive<<endl;
								}
								TMPnameEmployee = nameEmployee;
							}
							system("pause");
							break;
						case 3:
							break;
						default:
							cout<<"option no existente"<<endl;
							system("pause");
							break;
					}
				searchDepartament.close();
				}while(showOption2 != 3);
				
				break;
			case 5:
				do{
					ifstream watchInventary("registroEmpleados.txt");
					ifstream searchDepartament("registroEmpleados.txt");
					system("cls");
					cout<<"\t Busqueda por antiguedad"<<endl<<endl;
					cout<<"1. Cantidad"<<endl;
					cout<<"2. Rango"<<endl;
					cout<<"3. Regresar"<<endl;
					cin>>showOption2;
					switch (showOption2) {
						case 1:
							system("cls");
							cout<<"Ingrese la cantidad"<<endl;
							cin>>findParameter3;
							cout<<"Coincidencias de busqueda: "<<endl;
							while (searchDepartament != NULL) {
								searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
								if (workingYears == findParameter3 && nameEmployee != TMPnameEmployee) {
									cout<<"------------------------------------------------------------"<<endl;
									cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
									cout<<"	Anio de nacimiento: "<<birthYear<<endl;
									cout<<"	Edad: "<<age<<" anios"<<endl;
									cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
									cout<<"	Salario: Q"<<baseSalary<<endl;
									cout<<"	Bonus: Q"<<bonus<<endl;
									cout<<"	Anio contratacion: "<<hiringYear<<endl;
									cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
									cout<<"	Incentivo: Q"<<incentive<<endl;
								}
								TMPnameEmployee = nameEmployee;
							}
							system("pause");
							break;
						case 2:
							system("cls");
							cout<<"Ingrese la cantidad minima"<<endl;
							cin>>findParameter3;
							cout<<"Ingrese la cantidad maxima"<<endl;
							cin>>findParameter4;
							cout<<"Coincidencias de busqueda: "<<endl;
							while (searchDepartament != NULL) {
								searchDepartament>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
								if (workingYears >= findParameter3 && workingYears <= findParameter4 && nameEmployee != TMPnameEmployee) {
									cout<<"------------------------------------------------------------"<<endl;
									cout<<"	Nombre Completo: "<<nameEmployee<<" "<<lastNameEmployee<<endl;
									cout<<"	Anio de nacimiento: "<<birthYear<<endl;
									cout<<"	Edad: "<<age<<" anios"<<endl;
									cout<<"	Departamento: "<<departamentIntToString(codeDepartament)<<endl;
									cout<<"	Salario: Q"<<baseSalary<<endl;
									cout<<"	Bonus: Q"<<bonus<<endl;
									cout<<"	Anio contratacion: "<<hiringYear<<endl;
									cout<<"	Anios trabajando: "<<workingYears<<" anios"<<endl;
									cout<<"	Incentivo: Q"<<incentive<<endl;
								}
								TMPnameEmployee = nameEmployee;
							}
							system("pause");
							break;
						case 3:
							break;
						default:
							cout<<"option no existente"<<endl;
							system("pause");
							break;
					}
				searchDepartament.close();
				}while(showOption2 != 3);
				break;
			case 6:
				break;
			default:
				cout<<"option no existente"<<endl;
				system("pause");
				break;
		}
	} while (showOption1 != 6);
} //Fin de procedimiento

void dataModifyProcedure() {
	string findName, findLastName; 
	int newValue;
	int newValueHiringYear;
	int option;
	float newValueSalary;
	system("cls");
	ifstream modifyInventary("registroEmpleados.txt");
	//Escritura el archivo temporal
	ofstream saveTemporaly("temporal.txt");
	cout<<"Modificar"<<endl;
	cout<<"Ingrese nombre y apellido empleado a modificar: "<<endl;
	cout<<"Nombre: ";
	cin>>findName;
	cout<<"Apellido: ";
	cin>>findLastName;
	while (modifyInventary != NULL) {
		//Lectura del archivo original:
		modifyInventary>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
		if (nameEmployee + " " + lastNameEmployee  == findName + " " + findLastName && nameEmployee != TMPnameEmployee) {
			do {
				cout<<"Coincidencias de busqueda con"<<nameEmployee<<" "<<lastNameEmployee<<", que desa modificar?: "<<endl;
				cout<<"	1. Anio de nacimiento: "<<birthYear<<endl;
				cout<<"	2. Departamento: "<<departamentIntToString(codeDepartament)<<endl;
				cout<<"	3. Salario: Q"<<baseSalary<<endl;
				cout<<"	4. Anio contratacion: "<<hiringYear<<endl;
				cin>>option;
				switch (option) {
					case 1:
						cout<<"Ingrese nuevo anio de nacimiento: "<<endl;
						cin>>newValue;
						age = calculateYears(newValue, actualYear);
						saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<newValue<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
						option = 5;
						break;
					case 2:
						cout<<"Ingrese nuevo codigo Departamento: "<<endl;
						cin>>newValue;
						saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<newValue<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
						option = 5;
						break;
					case 3:
						cout<<"Ingrese nuevo salario"<<endl;
						cin>>newValueSalary;
						bonus = calculateBonus(newValueSalary, codeDepartament);
						saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<newValueSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
						option = 5;
						break;
					case 4:
						cout<<"Ingrese anio contratacion"<<endl;
						cin>>newValue;
						workingYears = calculateYears(newValue, actualYear);
						incentive = calculateIncentive(workingYears);
						saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<newValue<<" "<<workingYears<<" "<<incentive<<endl;
						option = 5;
						break;
					case 5:
						break;
					default:
						cout<<"option no disponible"<<endl;
						break;
				}
			} while (option != 5);
		} else if (nameEmployee != TMPnameEmployee) {
			saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
		}

		TMPnameEmployee = nameEmployee;
	}
	system("pause");
	modifyInventary.close();
	saveTemporaly.close();
	remove("registroEmpleados.txt");
	rename("temporal.txt", "registroEmpleados.txt");
}

void dataDeleteProcedure() {
	string findName, findLastName;
	system("cls");
	ifstream inventoryDelete("registroEmpleados.txt");
	//Escritura el archivo temporal
	ofstream saveTemporaly("temporal.txt");
	cout<<"Eliminar"<<endl;
	cout<<"Ingrese nombre y apellido empleado a eliminar: "<<endl;
	cout<<"Nombre: ";
	cin>>findName;
	cout<<"Apellido: ";
	cin>>findLastName;
	while (inventoryDelete != NULL) {
		//Lectura del archivo original:
		inventoryDelete>>nameEmployee>>lastNameEmployee>>birthYear>>age>>codeDepartament>>baseSalary>>bonus>>hiringYear>>workingYears>>incentive;
		if (nameEmployee + " " + lastNameEmployee  != findName + " " + findLastName && nameEmployee != TMPnameEmployee) {
			saveTemporaly<<nameEmployee<<" "<<lastNameEmployee<<" "<<birthYear<<" "<<age<<" "<<codeDepartament<<" "<<baseSalary<<" "<<bonus<<" "<<hiringYear<<" "<<workingYears<<" "<<incentive<<endl;
		}
		TMPnameEmployee = nameEmployee;
  	}
	cout<<endl<<"El empleado: "<<findName<<" "<<findLastName<<" ha sido eliminado"<<endl;
	system("pause");
	inventoryDelete.close();
	saveTemporaly.close();
	remove("registroEmpleados.txt");
	rename("temporal.txt", "registroEmpleados.txt");
}

main() {
	//Configuracion de consola de español
	int option;
	do {
		system("cls");
		cout<<"\t \tPryecto Modulo 2"<<endl;;
		cout<<"\t \t    Informacion Empleados"<<endl;
		cout<<"1. Ingreso de informacion"<<endl;
		cout<<"2. Visualizacion de informacion"<<endl;
		cout<<"3. Modificacion de informacion"<<endl;
		cout<<"4. Eliminacion de informacion"<<endl;
		cout<<"5. Salir"<<endl;
		cin>>option;
		switch (option) {
			case 1:
				dataEntryProcedure();
				break;
			case 2:
				dataDisplayProcedure();
				break;
			case 3:
				dataModifyProcedure();
				break;
			case 4:
				dataDeleteProcedure();
				break;
			case 5:
				cout<<endl<<"Gracias por utilizar nuestro servicio de registros";
				break;
			default:
				cout<<endl<<"Opcion no valida, ingrese otra"<<endl;
				system("pause");
				break;
		}
	} while (option != 5);
}
