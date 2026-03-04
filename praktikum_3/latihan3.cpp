#include <iostream>
#include <iomanip>

class RekeningBank {
private:
    double saldo;

public:
    // Constructor untuk mengisi saldo awal
    RekeningBank(double saldoAwal) {
        saldo = saldoAwal;
        std::cout << "Rekening berhasil dibuat." << std::endl;
        std::cout << "Saldo awal: Rp " << std::fixed << std::setprecision(2) << saldo << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    // Method untuk menyetor uang
    void setor(double jumlah) {
        saldo += jumlah;
        std::cout << "Setor: Rp " << std::fixed << std::setprecision(2) << jumlah << std::endl;
        std::cout << "Saldo sekarang: Rp " << saldo << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    // Method untuk menarik uang
    void tarik(double jumlah) {
        if (jumlah > saldo) {
            std::cout << "Penarikan Gagal: Rp " << std::fixed << std::setprecision(2) << jumlah
                      << " melebihi saldo." << std::endl;
            std::cout << "Saldo tetap: Rp " << saldo << std::endl;
        } else {
            saldo -= jumlah;
            std::cout << "Tarik: Rp " << std::fixed << std::setprecision(2) << jumlah << std::endl;
            std::cout << "Sisa saldo: Rp " << saldo << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
    }
};

int main() {
    std::cout << "SIMULASI REKENING BANK" << std::endl;

    // Membuat objek dengan saldo awal 1.000.000
    RekeningBank rekening(1000000.00);

    // Setor uang
    rekening.setor(500000.00);

    // Tarik uang (berhasil)
    rekening.tarik(200000.00);

    // Tarik uang (gagal, melebihi saldo)
    rekening.tarik(2000000.00);

    // Tarik uang (berhasil, tepat habis)
    rekening.tarik(1300000.00);

    return 0;
}
