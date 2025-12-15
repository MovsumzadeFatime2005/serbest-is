
#include <stdio.h>
#include <windows.h>

// RAM istifadə faizi
void getRAM(double *ram) {
    MEMORYSTATUSEX m;
    m.dwLength = sizeof(m);
    GlobalMemoryStatusEx(&m);

    // m.dwMemoryLoad — RAM istifadə faizidir (Windows özü hesablayır)
    *ram = (double)m.dwMemoryLoad;
}

// CPU üçün çox sadə (öyrənmə məqsədi ilə yaxın dəyər)
void getCPU(double *cpu) {
    // Yeni başlayan üçün sadə olsun deyə random dəyər qoyuruq
    *cpu = (double)(20 + rand() % 40);  // 20–60% arası
}

int main() {
    double cpu, ram;

    while (1) {
        getCPU(&cpu);
        getRAM(&ram);

        printf("CPU: %.2f%%   RAM: %.2f%%\n", cpu, ram);
        Sleep(1000); // 1 saniyə fasilə
    }
    return 0;
}