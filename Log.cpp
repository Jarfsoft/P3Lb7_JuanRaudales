#include <iostream>
#include <fstream>
#include<string.h> 

#ifndef LOG_CPP
#define LOG_CPP


using namespace std;

class Log
{
	private:
		char usuario[50];
		char comando[50];
		int numeroLog;
		
		
	public:
		Log(){}
		Log(string usua, string cmd, int num)
		{
			setNombre(usua);
			setComando(cmd);
			numeroLog=num;
		}
		void setNumeroLog(int num)
		{
			numeroLog=num;
		}
		int getNumeroLog()
		{
			return numeroLog;
		}
		void imprimir()
		{
			cout<<"num: "<<numeroLog<<", usuario: "<<usuario<<", cmd: "<<comando<<endl;
		}	
		void setNombre(string usua)
        {
        	const char *ptrUsua = usua.data();
            int numeroCaracteres = usua.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(usuario, ptrUsua, numeroCaracteres);
            usuario[numeroCaracteres] = '\0';
         }
         void setComando(string cmd)
        {
        	const char *ptrCmd = cmd.data();
            int numeroCaracteres = cmd.size();
            numeroCaracteres = numeroCaracteres < 50 ? numeroCaracteres:49;
            strncpy(comando, ptrCmd, numeroCaracteres);
            comando[numeroCaracteres] = '\0';
         }
		
		
};

#endif
