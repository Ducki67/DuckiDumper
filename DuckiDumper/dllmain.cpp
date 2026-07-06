// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <string>

#include "memcury.h"
#include "opts.h"

void CreateConsole() {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    SetConsoleTitleA("DuckiDumper - Offset finder | Made by: Ducki67 (@ducki67 on discord)");
}


DWORD WINAPI FinderThread(LPVOID lpParam) {
    CreateConsole();

    std::cout << "[*] Memcury launched... scanning in process...\n";


    uintptr_t BaseAddress = (uintptr_t)GetModuleHandleA(nullptr);
    std::cout << "\n========================================\n";
    std::cout << "\nGenerated/Scanned by: https://github.com/Ducki67/DuckiDumper\n";
    std::cout << "\n========================================\n";
    std::cout << "[+] Fortnite Base Address: 0x" << std::hex << BaseAddress << std::dec << "\n";
    std::cout << "--------------------------------------------------\n\n";

    for (const auto& Config : PatternsToScan) {
        if (Config.bFollowJump) {
            continue;
        }

        std::cout << "[SCANNING] Name: " << Config.Name << " ...\n";

        auto ScanResult = Memcury::Scanner::FindPattern(Config.BytePattern.c_str());

        if (ScanResult.Get() != 0) {
            uintptr_t FinalAddress = ScanResult.Get();
            uintptr_t Offset = FinalAddress - BaseAddress;

            std::cout << "Pattern: " << Config.BytePattern << "\n";
            std::cout << "Offset: 0x" << std::hex << std::uppercase << Offset << std::dec << "\n";
            std::cout << "Name: " << Config.Name << "\n";
            std::cout << "--------------------------------------------------\n";
        }
        else {
            std::cout << "[FAILED] Name: " << Config.Name << "\n";
            std::cout << "Pattern: " << Config.BytePattern << "\n";
            std::cout << "--------------------------------------------------\n";
        }
    }

    std::cout << "\n[+] Every sigle one was scanned! Dumping done.\n";
    std::cout << "\n==============================================\n";
    std::cout << "\n==============================================\n";
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        CreateThread(nullptr, 0, FinderThread, nullptr, 0, nullptr);
    }
    return TRUE;
}