#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>


using namespace std;
using namespace std::chrono;
#define BENCHMARK_MODE


#include "../main/efc/efc_main.cpp"
#include "../main/inef/inef_main.cpp"

int main() {
    // Configuração do gerador aleatório
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000000000); // Valores até 10^9 conforme problema

    // Limite menor pois a ineficiente é muito lenta
 for (int n = 1000; n <= 30000; n += 1000) {
        
        long long total_time_inef = 0;
        long long total_time_eff = 0;
        int repeticoes = 5; // Faz a média de 5 execuções

        for(int k=0; k < repeticoes; ++k) {
            // Gera vetor novo a cada repetição para não viciar o cache
            vector<int> A(n);
            for(int i=0; i<n; ++i) A[i] = dis(gen);

            // Medir Ineficiente
            auto start = high_resolution_clock::now();
            volatile int ret1 = solve_inefficient(n, A);
            auto stop = high_resolution_clock::now();
            total_time_inef += duration_cast<milliseconds>(stop - start).count();

            // Medir Eficiente
            start = high_resolution_clock::now();
            volatile int ret2 = solve_efficient(n, A);
            stop = high_resolution_clock::now();
            total_time_eff += duration_cast<milliseconds>(stop - start).count();
        }

        // Tira a média e imprime
        cout << n << " " 
             << (total_time_inef / repeticoes) << " " 
             << (total_time_eff / repeticoes) << endl;
             
        cerr << "N = " << n << " processado (Media de " << repeticoes << " execucoes)." << endl;
    }

    return 0;
}