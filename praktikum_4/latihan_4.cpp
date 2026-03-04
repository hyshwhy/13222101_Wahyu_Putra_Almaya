  
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

int main() {

    // Inisialisasi Struktur Data
    std::vector<double> sensor;


    // Pengisian Data Awal
  
    sensor.push_back(100.5);
    sensor.push_back(200.0);
    sensor.push_back(150.5);

  
    std::cout << "KALIBRASI DATA SENSOR" << std::endl;


    std::cout << "\n[DATA AWAL SENSOR]" << std::endl;
    for (int i = 0; i < sensor.size(); i++) {
        std::cout << "  Sensor[" << i << "] = " << std::fixed << std::setprecision(2) << sensor[i] << std::endl;
    }


    //Proses Kalibrasi (Batch Processing)
    std::cout << "\n[PROSES KALIBRASI +10%]" << std::endl;
    for (int i = 0; i < sensor.size(); i++) {
        double nilaiLama = sensor[i];
        sensor[i] = sensor[i] * 1.1;
        std::cout << "  Sensor[" << i << "]: " 
                  << std::fixed << std::setprecision(2) << nilaiLama 
                  << " -> " << sensor[i] << std::endl;
    }


    //Penyimpanan ke File Eksternal
    std::ofstream fileOutput("hasil_kalibrasi.txt");

    if (!fileOutput.is_open()) {
        std::cerr << "\n[ERROR] File gagal dibuka!" << std::endl;
        return 1;
    }

    std::cout << "\n[INFO] File 'hasil_kalibrasi.txt' berhasil dibuka." << std::endl;

    //Menulis Hasil ke File
    fileOutput << "=== HASIL KALIBRASI SENSOR ===" << std::endl;
    fileOutput << "Faktor Kalibrasi : x1.1 (+10%)" << std::endl;
    fileOutput << "==============================" << std::endl;

    for (int i = 0; i < sensor.size(); i++) {
        fileOutput << std::fixed << std::setprecision(2) << sensor[i] << std::endl;
    }

    fileOutput.close();

    std::cout << "[INFO] Data berhasil ditulis dan file ditutup." << std::endl;
    std::cout << "\n[HASIL AKHIR KALIBRASI]" << std::endl;
    for (int i = 0; i < sensor.size(); i++) {
        std::cout << "  Sensor[" << i << "] = " << std::fixed << std::setprecision(2) << sensor[i] << std::endl;
    }

    std::cout << "\n[SUKSES] Kalibrasi selesai. Cek file 'hasil_kalibrasi.txt'." << std::endl;
    std::cout << "=======================================" << std::endl;

    return 0;
}
