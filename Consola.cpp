#include "Logger.cpp"
#include "direct.h"

#ifndef CONSOLA_CPP
#define CONSOLA_CPP


using namespace std;

class Consola
{
	private:
		string usuario;
		Logger *logger;
		
	public:
		Consola(){}
		Consola(string usua, char* dir)
		{
			fstream Escribir(dir, ios::out | ios::binary | ios::app);
			Escribir.close();
			usuario=usua;
			
			logger = new Logger(usua,dir);
			
			
			
		}
		void cmd()
		{
			Log *log;
			string comando;
			system("cls");
			while(true)
			{
				
				cout<<usuario<<" ";
				cin>>comando;
				int nume=logger->getNumeroLog();
				log= new Log(usuario,comando,nume);
				logger->insertarLog(log);
				logger->setNumeroLog(nume+1);
				if(comando=="listar")
					logger->listar();
				else
					system(comando.c_str());
				if(comando=="exit")
				{
					logger->escribir();
					break;
				}
					
					
				
			}
			
		}
		
		
		
};

#endif
