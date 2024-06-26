#include <iostream>
#include <chrono>
#include <vector>

// Fungsi Fibonacci dengan pendekatan rekursif
unsigned long long fib_recursive(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Fungsi Fibonacci dengan pendekatan dynamic programming
unsigned long long fib_dynamic(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    std::vector<unsigned long long> fib(n + 1, 0);
    fib[1] = 1;

    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

// Fungsi untuk mengukur waktu eksekusi
template <typename Func>
double measure_time(Func func, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    return duration.count();
}

int main() {
    // Nilai-nilai n yang akan diuji
    int n_values[] = {10, 25, 30, 40, 50};
    const int num_values = sizeof(n_values) / sizeof(n_values[0]);

    // Tabel hasil waktu eksekusi
    std::cout << "n\tRekursif (µs)\tDynamic Programming (µs)\n";
    for (int i = 0; i < num_values; ++i) {
        int n = n_values[i];

        double time_recursive = measure_time(fib_recursive, n);
        double time_dynamic = measure_time(fib_dynamic, n);

        std::cout << n << "\t" << time_recursive << "\t\t" << time_dynamic << "\n";
    }

    return 0;
}

