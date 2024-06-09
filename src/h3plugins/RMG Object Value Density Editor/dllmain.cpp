// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"

Patcher* globalPatcher;
PatcherInstance* _PI;

_LHF_(RMG_ObjGen_AfterObjListCreation)
{
    H3RmgRandomMapGenerator* rmg = reinterpret_cast<H3RmgRandomMapGenerator*>(c->esi);
    auto& objectGens = rmg->objectGenerators;

    constexpr const char* attrNames[2] = { "value","density" };
    bool success = false;
    //constexpr const char* pathName = "Runtime\\debug_rmg.ini";
    //int counter{};
    for (auto& objGen : objectGens)
    {
        int objectType = objGen->type;
        int objectSubtype = objGen->subtype;
        //if (objectType)
        //if (objectSubtype)
        //{
            for (size_t i = 0; i < 2; i++)
            {
                sprintf(h3_TextBuffer, "rmg.objectValueDensityEditor.%d.%d.%s", objectType, objectSubtype, attrNames[i]);
                // Ищем тип и подтип в json
                int attrValue = EraJS::readInt(h3_TextBuffer, success);
                // Если найдены тип и подтип, заменяем параметр объекта
                if (success) {
                    *reinterpret_cast<int*>(reinterpret_cast<int>(objGen) + 12 + i * 4) = attrValue;
                    //H3Messagebox(Era::IntToStr(attrValue).c_str());
                }
                // Если подтип не найден, ищем по типу
                else {
                    sprintf(h3_TextBuffer, "rmg.objectValueDensityEditor.%d.%s", objectType, attrNames[i]);
                    // Ищем тип в json
                    int attrValue = EraJS::readInt(h3_TextBuffer, success);
                    // Если найден, заменяем параметр объекта
                    if (success) {
                        *reinterpret_cast<int*>(reinterpret_cast<int>(objGen) + 12 + i * 4) = attrValue;
                        //H3Messagebox(Era::IntToStr(attrValue).c_str());
                    }
                }
            }
        //}
        //Era::WriteStrToIni("type", Era::IntToStr(objGen->type).c_str(), Era::IntToStr(counter).c_str(), pathName);
        //Era::WriteStrToIni("subtype", Era::IntToStr(objGen->subtype).c_str(), Era::IntToStr(counter).c_str(), pathName);
        //Era::WriteStrToIni("value", Era::IntToStr(objGen->value).c_str(), Era::IntToStr(counter).c_str(), pathName);
        //Era::WriteStrToIni("density", Era::IntToStr(objGen->density).c_str(), Era::IntToStr(counter).c_str(), pathName);
        //counter++;
    }
    //Era::SaveIni(pathName);

    return EXEC_DEFAULT;
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
            _PI = globalPatcher->CreateInstance("rmg_editor.plugin");
            _PI->WriteLoHook(0x5381EC, RMG_ObjGen_AfterObjListCreation);
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
