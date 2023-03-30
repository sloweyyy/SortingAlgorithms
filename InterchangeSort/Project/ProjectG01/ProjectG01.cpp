#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int NhapFile(long arr[], long& n, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    fi >> n;
    for (long i = 0; i < n; i++)
        fi >> arr[i];
    fi.close();
    return 1;
}

int XuatFile(long arr[], long n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (long i = 0; i < n; i++)
        fo << arr[i] << setw(5);
    fo.close();
    return 1;
}
void interchangeSort(long arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main() {
    
    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/InterchangeSort/InputData/Int/intdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        long n;
        long arr[100000];
        if (NhapFile(arr,n, inpfile) == 1)
        {
            interchangeSort(arr,n);
            string outfile = "D:/Uni/UIT_Together/InterchangeSort/OutputData/Int/outdata";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            XuatFile(arr,n, outfile);
            cout << "Doc thanh cong file " << inpfile << endl;
            cout << "Ghi thanh cong file " << outfile << endl;
        }
        else
            cout << "Khong mo duoc file" << inpfile << "\n";
    }
    return 0;
}

