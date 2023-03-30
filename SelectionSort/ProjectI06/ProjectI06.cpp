#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <chrono>

using namespace std;

struct node
{
    int info;
    struct node* pNext;
    struct node* pPrev;
};

typedef struct node NODE;

struct list
{
    NODE* pHead;
    NODE* pTail;
};

typedef struct list LIST;

void Init(LIST& l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

int IsEmpty(LIST l)
{
    if (l.pHead == NULL)
        return 1;
    return 0;
}

NODE* GetNode(int x)
{
    NODE* p = new NODE;
    if (p == NULL)
        return NULL;
    p->info = x;
    p->pNext = NULL;
    p->pPrev = NULL;
    return p;
}

void AddTail(LIST& l, NODE* p)
{
    if (l.pHead == NULL)
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p;
        p->pPrev = l.pTail;
        l.pTail = p;
    }
}

int NhapFile(LIST& l, string filename)
{
    ifstream fi(filename);
    if (!fi.is_open())
        return 0;
    int n;
    fi >> n;
    Init(l);
    int x;
    for (int i = 1; i <= n; i++)
    {
        fi >> x;
        NODE* p = GetNode(x);
        if (p != NULL)
            AddTail(l, p);
    }
    fi.close();
    return 1;
}

int DemNode(LIST l)
{
    int dem = 0;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        dem++;
        p = p->pNext;
    }
    return dem;
}

int XuatFile(LIST l, string filename)
{
    ofstream fo(filename);
    if (!fo.is_open())
        return 0;
    fo << setw(5) << DemNode(l) << endl;
    NODE* p = l.pHead;
    while (p != NULL)
    {
        fo << setw(5) << p->info;
        p = p->pNext;
        if (p != NULL)
            fo << " ";
    }
    fo.close();
    return 1;
}

void SelectionSort(LIST& l)
{
    NODE* p = l.pHead;
    while (p != NULL)
    {
		NODE* q = p->pNext;
		NODE* min = p;
        while (q != NULL)
        {
			if (q->info < min->info)
				min = q;
			q = q->pNext;
		}
        if (min != p)
        {
			int temp = p->info;
			p->info = min->info;
			min->info = temp;
		}
		p = p->pNext;
	}
}

int main()
{
    LIST l;
    for (int i = 1; i <= 13; i++)
    {
        string inpfile = "D:/Uni/UIT_Together/SelectionSort/InputData/Int/intdata";
        if (i < 10)
            inpfile += '0';
        inpfile += to_string(i);
        inpfile += ".inp";
        if (NhapFile(l, inpfile) == 1)
        {
            auto start = chrono::high_resolution_clock::now();
            SelectionSort(l);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> time = end - start;
            string outfile = "D:/Uni/UIT_Together/SelectionSort/OutputData/Int06/intdata";
            if (i < 10)
                outfile += '0';
            outfile += to_string(i);
            outfile += ".out";
            XuatFile(l, outfile);
            cout << "\n" << inpfile;
            cout << "\n" << outfile;
            cout << "Time: " << fixed << setprecision(6) << time.count() << " seconds" << endl;
        }
        else
            cout << "\n Khong mo duoc file" << inpfile << "\n";
    }
    cout << "\n\n\n";
    return 0;
}