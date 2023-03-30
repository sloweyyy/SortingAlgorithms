#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>
using namespace std;

int NhapFile(int arr[], int& n, string filename)
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

int XuatFile(int arr[], int n, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << n << endl;
    for (int i = 0; i < n; i++)
        fo << arr[i] << setw(5);
    fo.close();
    return 1;
}
void SelectionSort(int arr[], int n) {
    int min, temp;
    for (int i = 0; i < n - 1; i++) {
		min = i;
        for (int j = n - 1; j >= i + 1; j--) {
			if (arr[j] < arr[min])
				min = j;
		}
        swap(arr[i], arr[min]);
	}
}



int main() {

    for (int i = 1; i <= 13; i++)
    {

        string inpfile = "D:/Uni/UIT_Together/SelectionSort/InputData/Int/intdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        int n;
        int arr[100000];
        if (NhapFile(arr, n, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(arr, n);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/SelectionSort/OutputData/Int01/outdata";
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

