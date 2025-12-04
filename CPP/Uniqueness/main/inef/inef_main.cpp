#include <iostream>
#include <vector>

using namespace std;
int solve_inefficient(int N, const vector<int>& A) {
    int max_val = -1;
    int ans_idx = -1;
    // Analise Assintótica : O(N²)
    for (int i = 0; i < N; ++i) {
        int count = 0;
    // Percorre tudo de novo para contar ocorrências
        for (int j = 0; j < N; ++j) {
            if (A[i] == A[j]) {
                count++;
            }
        }
        // Se aparece exatamente uma vez
        if (count == 1) {
            if (A[i] > max_val) {
                max_val = A[i];
                ans_idx = i + 1; // O problema pede índice base    -1
            }
        }
    }
    return ans_idx;
}

#ifndef BENCHMARK_MODE
int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    cout << solve_inefficient(N, A) << endl;
    return 0;
}
#endif