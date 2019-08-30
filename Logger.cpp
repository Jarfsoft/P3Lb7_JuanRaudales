#include "Log.cpp"
#include <vector>

#ifndef LOGGER_CPP
#define LOGGER_CPP


using namespace std;

class Logger
{
	private:
		string usuario;
		char* nombreArchivo;
		int numeroLog;
		vector<Log*> loggs;
		
	public:
		Logger(string usua, char*nomArch)
		{
			nombreArchivo=nomArch;
			string linea;
			ifstream Leer(nomArch, ios::in | ios::binary);
			usuario=usua;
			Log t;
			Leer.seekg(0,ios::beg);
			getline(Leer,linea);
			Leer.seekg(0,ios::beg);
			if(linea.size()>0)
			{
				Leer.read(reinterpret_cast<char *>(&t),sizeof(t));
				while(!Leer.eof())
				{
					
					Log *temp = new Log();
					*temp=t;;
					loggs.push_back(temp);
					Leer.read(reinterpret_cast<char *>(&t),sizeof(t));
				}
				
			}
			if(loggs.size()!=0)
			{
				int ubica=loggs.size()-1;
				numeroLog=loggs.at(ubica)->getNumeroLog()+1;
			}else
				numeroLog=0;
			Leer.close();
			
		}
		void setNumeroLog(int n)
		{
			numeroLog=n;
		}
		int getNumeroLog()
		{
			return numeroLog;
		}
		void insertarLog(Log* lo)
		{
			loggs.push_back(lo);
		}
		void listar()
		{
			for(int x=0;x<loggs.size();x++)
			{
				loggs.at(x)->imprimir();
			}
		}
		void escribir()
		{
			fstream Escribir(nombreArchivo, ios::out | ios::binary);
			Escribir.seekp(0,ios::end);
			Log t;
			for(int x=0;x<loggs.size();x++)
			{
				t=*loggs.at(x);
				Escribir.write(reinterpret_cast<char*>(&t),sizeof(t));
			}
			Escribir.close();
			
		}
		
		
};

#endif
