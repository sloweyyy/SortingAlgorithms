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
void SelectionSort(int arr[][500], int m, int n) {
    int minIndex;
    for (int i = 0; i < m * n - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < m * n; j++) {
            if (arr[j / n][j % n] < arr[minIndex / n][minIndex % n]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {

    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/SelectionSort/InputData/Matrix/intmatrandata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int m, n;
        int arr[500][500];
        if (NhapFile(arr, m, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, m, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/SelectionSort/OutputData/Matrix/output";
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

