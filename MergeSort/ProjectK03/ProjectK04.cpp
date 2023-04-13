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

void Merge(int a[][500], int n, int m, int Left, int Mid, int Right)
{
    int* temp = new int[Right - Left + 1];
    int p = 0;
    int i = Left;		// Left...Mid
    int j = Mid + 1;	// Mid+1...Right
    while (!(i > Mid && j > Right))
    {
        if ((i <= Mid && j <= Right && a[i / m][i % m] < a[j / m][j % m]) || j > Right)
        {
            temp[p++] = a[i / m][i % m];
            i++;
        }
        else
        {
            temp[p++] = a[j / m][j % m];
            j++;
        }
    }
    for (i = 0; i < p; i++)
        a[(Left + i) / m][(Left + i) % m] = temp[i];
    delete[]temp;
}

void MergeSort(int a[][500], int n, int m, int Left, int Right)
{
    if (Left < Right) // Doan can sap xep co nhieu hon 1 phan tu
    {
        int Mid = Left + (Right - Left) / 2;
        MergeSort(a, n, m, Left, Mid);		// Sap xep ben phai
        MergeSort(a, n, m, Mid + 1, Right);	// Sap xep ben phai
        Merge(a, n, m, Left, Mid, Right);		// Tron
    }
}





int main() {

    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/MergeSort/InputData/Matrix/intmatrandata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int m, n;
        int arr[500][500];
        if (NhapFile(arr, n, m, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            int Left = 0, Right = m * n - 1;
            MergeSort(arr, n, m, Left, Right);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/MergeSort/OutputData/Matrix/output";
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

