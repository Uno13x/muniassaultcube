#include <iostream>
#include <windows.h>
using namespace std;


// Create by unoxys


// Variavel da bala
DWORD_PTR muni = 0x084F530;

// Ler e ver valor da bala
int value = 30;
int recebervalor;

int main(int argc, char const *argv[])
{
    // Procurar janela e ver se a janela ta aberta
    HWND window = FindWindowW(NULL, L"AssaultCube"); 
    if (!window) {
        wcout << L"Janela não encontrada" << endl; 
        system("pause");
        exit(0);
    }
    
// procurar processos
DWORD processo;
GetWindowThreadProcessId(window,&processo);

HANDLE handler = OpenProcess(PROCESS_ALL_ACCESS, false, processo);

if(!handler){
   cout<<"Não foi encontrado os processos"<<endl;
   system("pause");
   exit(0);

}  

cout<<"Valor das Balas:"<<endl;
cin>>value;

 while(true){
    if(GetAsyncKeyState(VK_F1)){
        WriteProcessMemory(handler,(LPVOID)muni,&value,4,0);
    } 

    ReadProcessMemory(handler, (LPVOID)muni,&recebervalor, sizeof(int),0);
    cout<<"Quantidade de munição: "<<recebervalor;
    system("cls");
} 
    return 0;
}

