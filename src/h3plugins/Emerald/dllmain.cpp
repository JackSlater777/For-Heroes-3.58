// dllmain.cpp: ���������� ����� ����� ��� ���������� DLL.
#include "emerald.h"

extern void __stdcall  Emerald(PEvent e);

extern void __stdcall ReallocProhibitionTables(PEvent e);
extern void __stdcall LoadConfigs(PEvent e);



GAMEDATA save;
Patcher * globalPatcher;
PatcherInstance *emerald;

void __stdcall InitData (PEvent e)
{
}


void __stdcall StoreData (PEvent e)
{
	WriteSavegameSection(sizeof(save), (void*)&save, PINSTANCE_MAIN);
}


void __stdcall RestoreData (PEvent e)
{
	ReadSavegameSection(sizeof(save), (void*)&save, PINSTANCE_MAIN);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		//���� ���, ���� �������
		globalPatcher = GetPatcher();
		emerald =  globalPatcher->CreateInstance(PINSTANCE_MAIN);
		ConnectEra();

		//Storing data
		RegisterHandler(InitData, "OnAfterErmInstructions");
		RegisterHandler(StoreData, "OnSavegameWrite");
		RegisterHandler(RestoreData, "OnSavegameRead");



		//������ ��������� ������ ��� ��������		
		RegisterHandler(ReallocProhibitionTables, "OnAfterCreateWindow");


		//RegisterHandler(LoadConfigs, "OnBeforeErmInstructions");
		RegisterHandler(LoadConfigs, "OnAfterCreateWindow");

		//�������� �������
		RegisterHandler(Emerald, "OnAfterWoG");
	}
	return TRUE;
}

