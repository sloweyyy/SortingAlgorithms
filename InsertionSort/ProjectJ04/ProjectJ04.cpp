#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

int NhapFile(int arr[][500], int& m, int& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> m;
    fi >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            fi >> arr[i][j];
    fi.close();
    return 1;
}

int XuatFile(int arr[][500], int m, int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << m << setw(5) << n << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            fo << arr[i][j] << setw(5);
        fo << endl;
    }

    fo.close();
    return 1;
}
void InsertionSort(int arr[][500], int m, int n) {
    int k, j;
    for (int i = 1; i < m * n; i++) {
        k = arr[i / n][i % n];
        j = i - 1;
        while (j >= 0 && arr[j / n][j % n] > k) {
            arr[(j + 1) / n][(j + 1) % n] = arr[j / n][j % n];
            j--;
        }
        arr[(j + 1) / n][(j + 1) % n] = k;
    }
}

int main() {

    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/InsertionSort/InputData/Matrix/intmatrandata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int m, n;
        int arr[500][500];
        if (NhapFile(arr, m, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, m, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/InsertionSort/OutputData/Matrix/output";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            XuatFile(arr, m, n, outfile);
            cout << "Doc thanh cong file " << inpfile << endl;
            cout << "Ghi thanh cong file " << outfile << endl;
            cout << "Time: " << fixed << setprecision(6) << time.count() << " seconds" << endl;
        }
        else
            cout << "Khong mo duoc file " << inpfile << "\n";
    }
    return 0;
}

