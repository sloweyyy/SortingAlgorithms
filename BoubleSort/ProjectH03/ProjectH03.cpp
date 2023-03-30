#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct phanso
{
    int tu;
    int mau;
};
typedef struct phanso PHANSO;

int SoSanh(PHANSO x, PHANSO y)
{
    float a = (float)x.tu / x.mau;
    float b = (float)y.tu / y.mau;
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}


int NhapFile(PHANSO arr[], int& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    for (int i = 0; i < n; i++)
        fi >> arr[i].tu >> arr[i].mau;
    fi.close();
    return 1;
}

int XuatFile(PHANSO arr[], int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (int i = 0; i < n; i++)
        fo << setw(5) << arr[i].tu << setw(5) << arr[i].mau << endl;
    fo.close();
    return 1;
}
void BoubleSort(PHANSO arr[], int n) {
    for (int i = n - 1; i >= 1; i--)
        for (int j = 0; j <= i - 1; j++)
            if (SoSanh(arr[j],arr[j+1])==1)
                swap(arr[j], arr[j + 1]);
}

int main() {

    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/BoubleSort/InputData/Fraction/phansodata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int n;
        PHANSO arr[100000];
        if (NhapFile(arr, n, inpfile) == 1)
        {
            BoubleSort(arr, n);
            string outfile = "D:/Uni/UIT_Together/BoubleSort/OutputData/Fraction/output";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            XuatFile(arr, n, outfile);
            cout << "Doc thanh cong file " << inpfile << endl;
            cout << "Ghi thanh cong file " << outfile << endl;
        }
        else
            cout << "Khong mo duoc file" << inpfile << "\n";
    }
    return 0;
}

