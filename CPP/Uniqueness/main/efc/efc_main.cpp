#include <iostream>
#include <vector>
#include <map>

using namespace std;


int solve_efficient(int N, const vector<int>& A) {
    map<int, int> counts; // Map para contar frequências
    
    // Contagem
    for (int x : A) {
        counts[x]++;
    }
    // Encontrar o maior valor único

    int max_val = -1;
    int ans_idx = -1;

    // Verificação: O(N log N) ou O(N)
        for (int i = 0; i < N; ++i) {
        // Verifica no mapa se a contagem é 1
        if (counts[A[i]] == 1) {
            if (A[i] > max_val) {
                max_val = A[i];
                ans_idx = i + 1;
            }
        }
    }

    return ans_idx;
}

#ifndef BENCHMARK_MODE

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << solve_efficient(N, A) << endl;
    return 0;
}
#endif

