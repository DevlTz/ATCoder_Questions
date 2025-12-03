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
    for (int n = 1000; n <= 15000; n += 1000) {
        
        // Gerar vetor aleatório
        vector<int> A(n);
        for(int i=0; i<n; ++i) A[i] = dis(gen);

        // --- Medir Ineficiente ---
        auto start = high_resolution_clock::now();
        
        // Chama a função que importamos do arquivo ineficiente.cpp 
        volatile int ret1 = solve_inefficient(n, A); 
        
        auto stop = high_resolution_clock::now();
        auto duration_inefficient = duration_cast<milliseconds>(stop - start);

        // --- Medir Eficiente ---
        start = high_resolution_clock::now();
        
        // Chama a função que importamos do arquivo eficiente.cpp
        volatile int ret2 = solve_efficient(n, A);
        
        stop = high_resolution_clock::now();
        auto duration_efficient = duration_cast<milliseconds>(stop - start);

        // Saída para o gráfico
        cout << n << " " 
             << duration_inefficient.count() << " " 
             << duration_efficient.count() << endl;
             
        cerr << "N = " << n << " processado." << endl;
    }

    return 0;
}