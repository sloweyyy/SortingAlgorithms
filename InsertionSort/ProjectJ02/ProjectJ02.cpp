#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

int NhapFile(float arr[], int& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> arr[i];
    fi.close();
    return 1;
}

int XuatFile(float arr[], int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (int i = 0; i < n; i++)
        fo << arr[i] << setw(10);
    fo.close();
    return 1;
}
void InsertionSort(float arr[], int n) {
    for (int k = 1; k < n; k++)
    {
        float x = arr[k];
        int vt;
        for (vt = k - 1; vt >= 0 && arr[vt] > x; vt--)
            arr[vt + 1] = arr[vt];
        arr[vt + 1] = x;
    }
}

int main() {

    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/InsertionSort/InputData/Float/floatdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int n;
        float arr[100000];
        if (NhapFile(arr, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            InsertionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/InsertionSort/OutputData/Float/outdata";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            XuatFile(arr, n, outfile);
            cout << "Doc thanh cong file " << inpfile << endl;
            cout << "Ghi thanh cong file " << outfile << endl;
            cout << "Time: " << fixed << setprecision(6) << time.count() << " seconds" << endl;
        }
        else
            cout << "Khong mo duoc file" << inpfile << "\n";
    }
    return 0;
}

