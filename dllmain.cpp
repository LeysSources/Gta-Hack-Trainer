
#include "pch.h"
#include <iostream>
#include <string>
#include "cheat.h"
#include "menu.h"

using namespace cheat;
int main(HMODULE close) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    bool a = false;
    int sel = 0;
    std::cout << "             GirlSkouts" << std::endl;
    std::cout << "              Features" << std::endl;
    std::cout << "-> God Mode " << std::endl;
    std::cout << "Inf Stamina" << std::endl;
    std::cout << "Super Run" << std::endl;
    std::cout << "Set 5Star" << std::endl;
    std::cout << "Never Wanted" << std::endl;
    std::cout << "Clean Car" << std::endl;
    std::cout << "Rainbow Car" << std::endl;
    std::cout << "Car Full Upgrade" << std::endl;
    std::cout << "Vehicle GodMode" << std::endl;


  
    uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GTA5.exe");
uintptr_t world = 0x25667E8;

bool bWin = false;
    while (!GetAsyncKeyState(VK_END) & 1) {


        if (GetAsyncKeyState(VK_INSERT) & 1){
            bWin = !bWin;
        }
       
        cheat::loadAllFeatures();
        
        if (bWin == false) {
            HWND c = GetConsoleWindow();

            SetWindowLongPtr(c, GWL_STYLE, WS_POPUP);

            ShowWindow(c, SW_NORMAL);

            SetWindowPos(c, HWND_TOPMOST, 100, 200, 300, 400, SWP_DRAWFRAME);
            ShowWindow(c, SW_NORMAL);
            ShowScrollBar(c, SB_BOTH, FALSE);
            system("color 20");
           
            
        } else  {
            HWND c = GetConsoleWindow();
            SetWindowLongPtr(c, GWL_STYLE, WS_POPUP);
            ShowWindow(c, SW_MINIMIZE);
            SetWindowPos(c, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
            ShowWindow(c, SW_MINIMIZE);
           
       }


        intptr_t wanted = mem::offset(moduleBase + 0x02F0C9B, {  });
       
       
        if (GetAsyncKeyState(VK_F1) & 1) {
           
            ((void(*)(int, int, bool)) wanted)(0, 4, false);


       
            
        }
        if (GetAsyncKeyState(VK_F2) & 1) {

            ((void(*)(int)) wanted)(3);




        }


        if (GetAsyncKeyState(VK_PRIOR) & 1) {
            if (sel != 0) {
                sel--;
                a = false;
            }
        }
        if (GetAsyncKeyState(VK_NEXT) & 1) {
            if (sel != 11) {
                sel++;
                a = false;
            }
        }
        if (GetAsyncKeyState(VK_RETURN) & 1) {
          

            cheat::ActivateFeatures(sel);
            cheat::menu(a, sel);
        }
        if (a == false) {
             a = cheat::menu(a, sel);

           
        }


       
       

       
    /*   if (GetAsyncKeyState(VK_F3)) {
            binfAmmo = !binfAmmo;
           
        }
        if (binfAmmo) {
            *(int*)(moduleBase + 0x1D00E04) = 1;
        }
       
       
        
        int rag = *(int*)mem::offset(moduleBase + world, { 0x8,0x10B8 });
        if (noRagdoll) {
            *(int*)mem::offset(moduleBase + world, { 0x8,0x10B8 }) = 1749041185;
        }
        if (GetAsyncKeyState(VK_F8)&1) {
            noRagdoll = !noRagdoll;
        }
        if (GetAsyncKeyState(VK_F9)&1) {
            bExplosiveBullet = !bExplosiveBullet;
        }
        if (bExplosiveBullet) {
         
        }
        else {
        
        }
        
      
        
        //E
       
       
       
        
         if (GetAsyncKeyState(VK_F12)&1) {
            
             
         }

      //  else if (!bCarBoost  && carhp > 0.0) {
            
      //  }
      */



    }
    //
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(close, 0);
  
        




}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, LPTHREAD_START_ROUTINE(main), 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

