#include "pch.h"
#include "cheat.h"
//#include "dllmain.cpp"
#include "offsets.h"
#include <iostream>
uintptr_t moduleBase = (uintptr_t)GetModuleHandle(L"GTA5.exe");
uintptr_t world = 0x25667E8;
bool binfAmmoReload = false;
bool bGod = false;
bool bForeverStam = false;
bool bExplosiveBullet = false;
bool bCarBoost = false;
bool binfAmmo = false;
bool bSprint = false;
bool bHeal = false;
bool b5Star = false;
bool bClean = false;
bool bCarGodMode = false;
bool p = false;
bool invis = false;

// ragdoll 71319633;
// not ragdoll 1749041185
bool noRagdoll = false;
bool bNoWanted = false;




bool cheat::menu(bool a, int sel) {
	bool b0 = false;
	bool b1 = false;
	bool b2 = false;
	bool b3 = false;
	bool b4 = false;
	bool b5 = false;
	bool b6 = false;
	bool b7= false;
	bool b8 = false;
	bool b9 = false;
	bool b10 = false;
	bool b11 = false;



	switch (sel) {

	case 0:


		
		a = true;

		b0 = true;
		break;

	case 1:
		
		a = true;
		b1 = true;
		break;

	case 2:

		a = true;
		b2 = true;
		break;

	case 3:

		a = true;
		b3 = true;
		break;

	case 4:

		a = true;
		b4 = true;
		break;

	case 5:

		a = true;
		b5 = true;
		break;
	case 6:

		a = true;
		b6 = true;
		break;

	case 7:

		a = true;
		b7 = true;
		break;


	case 8:

		a = true;
		b8 = true;
		break;
	case 9:
	
		a = true;
		b9 = true;
		break;
	case 10:
	

		a = true;
		b10 = true;
		break;

	case 11:
	
		a = true;
		b11 = true; 
		break;
	}



	system("CLS");
	std::cout << "             GirlSkouts" << std::endl;
	std::cout << "              Features" << std::endl;
	if (b0) { std::cout << "-> "; }
	std::cout << "God Mode " << std::boolalpha << bGod << std::endl;
	if (b1) { std::cout << "-> "; }
	std::cout << "Inf Stamina " << std::boolalpha << bForeverStam << std::endl;
	if (b2) { std::cout << "-> "; }
	std::cout << "Super Run " << std::boolalpha << bSprint << std::endl;
	if (b3) { std::cout << "-> "; }
	std::cout << "Set 5Star " << std::boolalpha << b5Star << std::endl;
	if (b4) { std::cout << "-> "; }
	std::cout << "Never Wanted " << std::boolalpha << bNoWanted << std::endl;
	if (b5) { std::cout << "-> "; }
	std::cout << "Clean Car " << std::boolalpha << bClean << std::endl;
	if (b6) { std::cout << "-> "; }
	std::cout << "Rainbow Car " << std::endl;
	if (b7) { std::cout << "-> "; }
	std::cout << "Car Full Upgrade " << std::endl;
	if (b8) { std::cout << "-> "; }
	std::cout << "Vehicle GodMode " << std::boolalpha << bCarGodMode << std::endl;
	if (b9) { std::cout << "-> "; }
	std::cout << "Heal Player " << std::endl;
	if (b10) { std::cout << "-> "; }
	std::cout << "Kill Player " << std::endl;
	if (b11) { std::cout << "-> "; }
	std::cout << "Inf Ammo Reload " << std::boolalpha << binfAmmoReload << std::endl;
	return a;
}


void cheat::ActivateFeatures(int sel) {
	switch (sel) {
	case 0:
		godMode();
		break;
	case 1:
		foreverStam();
		break;
	case 2:
		superRun();
		break;
	case 3:
		set5Star();
		break;
	case 4:
		neverWanted();
		break;
	case 5:
		cleanCar();
		break;
	case 6:
		RainbowMode();
		break;
	case 7:
		carMaxUpgrade();
		break;
	case 8:
		vehicleGodMode();
		break;
	case 9:
		healPlayer();
		break;
	case 10:
		killPlayer();
		break;

	case 11:
		infAmmoReload();
		break;

	case 12:
		Invis();
		break;
	}
	

}


void cheat::loadAllFeatures() {
	/*
	infAmmoReload();
	healPlayer();
	killPlayer();
	godMode();
	foreverStam();
	superRun();
	set5Star();
	neverWanted();
	cleanCar();
	boostCar();
	vehicleGodMode();
	*/
	0;
}
//F1
void cheat::infAmmoReload() {
	
	
		binfAmmoReload = !binfAmmoReload;
	
	
	if (binfAmmoReload) {
		mem::Nop((BYTE*)(moduleBase + 0x10383ED), 3);
	}
	else {
		mem::Patch((BYTE*)(moduleBase + 0x10383ED), (BYTE*)"\x89\x5F\x20", 3);

	}
}
//F2
void cheat::healPlayer() {
	
	
		bHeal = !bHeal;

	

	if (bHeal) {

		*(float*)mem::offset(moduleBase + world, { 0x8,0x280 }) = 200.0;
		bHeal = false;

	}
}
//F5
void cheat::killPlayer() {
	

		*(float*)mem::offset(moduleBase + world, { 0x08,0x280 }) = 90.0;

	
}
//INS
void cheat::godMode() {
	
	
		bGod = !bGod;
		//    std::cout << "Entered If";
	
	if (bGod) {
		*(int*)mem::offset(moduleBase + world, { 0x8,0x188 }) = 4196860;
		// std::cout << "Entered God";
	}
	else {
		*(int*)mem::offset(moduleBase + world, { 0x8,0x188 }) = 4194316;
		//   std::cout << "Entered Else";
	}

}
//DEL
void cheat::foreverStam() {
	
		bForeverStam = !bForeverStam;
	
	if (bForeverStam) {
		*(float*)mem::offset(moduleBase + world, { 0x8,0x10C8,0xCF4 }) = 100.0;
	}
}
//F4
void cheat::superRun() {
	

		bSprint = !bSprint;
	
	if (bSprint) {
		*(float*)mem::offset(moduleBase + world, { 0x8,0x10C8,0xCF0 }) = 2.0;
	}
	else {
		*(float*)mem::offset(moduleBase + world, { 0x8,0x10C8,0xCF0 }) = 1.0;
	}
}
//F6
void cheat::set5Star() {

	
		b5Star = !b5Star;
	
	if (b5Star) {
		*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0x10C8,0x888 }) = 5;
	}
}
//F7
void cheat::neverWanted() {
	

		bNoWanted = !bNoWanted;
	
	if (bNoWanted) {
		*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0x10C8,0x888 }) = 0;
	}
}
//F10
void cheat::cleanCar() {
	int safety = *(int*)mem::offset(moduleBase + world, { 0x8,0xD30 });
	
	
		bClean = !bClean;
	
	if (bClean && safety != 0) {
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x9F8 }) = 0.0;
	}
}
//E
void cheat::boostCar() {
	int safety = *(int*)mem::offset(moduleBase + world, { 0x8,0xD30 });
	
	if (GetAsyncKeyState(0x45) && safety != 0) {
		while (GetAsyncKeyState(0x45)) {


			*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0xC5C }) = 200.0;
		}
		p = true;


	}

	if (p && safety != 0) {
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0xC5C }) = 9.8;
		p = false;
	}
}
//F11
void cheat::vehicleGodMode() {
	int safety = *(int*)mem::offset(moduleBase + world, { 0x8,0xD30 });
	

		bCarGodMode = !bCarGodMode;
	
	if (bCarGodMode && safety != 0) {
		//Deformation
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x938,0xF8 }) = 0.0;
		//CollisionMult
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x938,0xF0 }) = 0.0;
		//hp 1
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x280 }) = 1000.0;
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x840 }) = 1000.0;
		*(float*)mem::offset(moduleBase + world, { 0x8,0xD30,0x844 }) = 1000.0;

	}

}

//Printing Stuff (for use in the stone ages ***before i draw gui***)
void cheat::print2Console() {

	if (bGod) {
		std::cout << "\x1b[8A";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[8A";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}

	if (bForeverStam) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}

	if (bSprint) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}
	if (b5Star) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}
	if (bNoWanted) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[14G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[14G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}
	if (bClean) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[11G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}
	if (p) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[10G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}
	if (bCarGodMode) {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[13G";
		std::cout << "\033[1;32;49m True\033[0m";
	}
	else {
		std::cout << "\x1b[1B";
		std::cout << "\x1b[13G";
		std::cout << "\033[1;31;49mFalse\033[0m";
	}


}
void cheat::carMaxUpgrade(){
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x402 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x403 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x404 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x405 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3D6 }) = 3;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3DB }) = 11;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3D7 }) = 6;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3D9 }) = 19;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3DA }) = 24;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3DD }) = 1;
	//*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x20 }) = 1;




}
void cheat::RainbowMode() {

	int r = 0;
	int g = 0;
	int b = 0;
	//UnderGlow
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3A2 }) = r;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3A1 }) = g;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x3A0 }) = b;

	//Paint
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x20,0xA6 }) = r;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x20,0xA5 }) = g;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x20,0xA4 }) = b;

	//Underglow equip
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x402 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x403 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x404 }) = 1;
	*(uint8_t*)mem::offset(moduleBase + world, { 0x8,0xD30,0x48,0x405 }) = 1;

}
void cheat::Invis() {

	invis = !invis;

	if (invis) {
		*(uint8_t*)mem::offset(moduleBase + world, { 0x8, 0x2C }) = 0;
			
	}
	else {
		*(uint8_t*)mem::offset(moduleBase + world, { 0x8, 0x2C }) = 47;


	}




}