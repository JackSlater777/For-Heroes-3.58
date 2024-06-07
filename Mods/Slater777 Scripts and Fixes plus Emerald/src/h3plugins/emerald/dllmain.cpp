// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include "emerald.h"

Patcher* globalPatcher;
PatcherInstance* _PI;

extern void __stdcall LoadConfigs(PEvent e);
extern void __stdcall Emerald(PEvent e);
extern void __stdcall ReallocProhibitionTables(PEvent e);
extern void __stdcall EmeraldStrings2(PEvent e);

void __stdcall StoreData(PEvent e)
{
	/*
	////Trying to fix
	for (int i = 0; i < NEW_ARTS_AMOUNT; ++i) {
		//memcpy(&save.newtable[i], &no_save.newtable[i], sizeof(ART_RECORD));
		//memcpy(&save.newbtable[i], &no_save.newbtable[i], sizeof(ART_BONUS));

		if (save.newtable[i].name && save.artname[i] != save.newtable[i].name)
			strncpy(save.artname[i], save.newtable[i].name, char_table_size-1);
		if (save.artname[i][0] == 0 || !(save.newtable[i].name)) {
			strncpy(save.artname[i], "{Unnamed Artifact}", char_table_size - 1);
			save.newtable[i].name = save.artname[i];
		}

		if (save.newtable[i].desc && save.artdesc[i] != save.newtable[i].desc)
			strncpy(save.artdesc[i], save.newtable[i].desc, char_table_size-1);
		if (save.artdesc[i][0] == 0 || !(save.newtable[i].desc)) {
			strncpy(save.artdesc[i], "{Undescribed Artifact}", char_table_size - 1);
			save.newtable[i].desc = save.artdesc[i];
		}
	}
	*/
	WriteSavegameSection(sizeof(save), (void*)&save, PINSTANCE_MAIN);
    click_locked = true;
}

void __stdcall RestoreData(PEvent e)
{
	Era::ReadSavegameSection(sizeof(save), (void*)&save, PINSTANCE_MAIN);
	EmeraldStrings2(e);
	click_locked = true;
}

void __stdcall Z_OnAfterCreateWindow(PEvent e) {
    ReallocProhibitionTables(e);
    LoadConfigs(e);
}

void __stdcall Z_OnAfterWog(PEvent e) {
    Emerald(e);
    ReallocProhibitionTables(e);
    EmeraldStrings2(e);
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    static BOOL plugin_On = 0;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (!plugin_On)
        {
            plugin_On = 1;
            Era::ConnectEra();
            globalPatcher = GetPatcher();
            _PI = globalPatcher->CreateInstance(PINSTANCE_MAIN);

            Era::RegisterHandler(StoreData, "OnSavegameWrite");
            Era::RegisterHandler(RestoreData, "OnSavegameRead");
            Era::RegisterHandler(Z_OnAfterCreateWindow, "OnAfterCreateWindow");
            Era::RegisterHandler(Z_OnAfterWog, "OnAfterWoG");
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
