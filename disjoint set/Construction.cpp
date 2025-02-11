#include <iostream>
#include <vector>

using namespace std;

class DisjointUnion
{
private:
    struct data
    {
        int root;
        int rank;
    };

    data *arr = nullptr;
    int size;

public:
    DisjointUnion(int n)
    {
        arr = (data *)malloc(sizeof(data) * n);
        size = n;
        for (int i = 0; i < n; i++)
        {
            arr[i].root = -1;
            arr[i].rank = 0;
        }
    }

    int find(int i)
    {
        if (arr[i].root < 0)
        {
            return i;
        }

        arr[i].root = find(arr[i].root);
        return arr[i].root;
    }

    void Union(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        if (arr[x].rank < arr[y].rank)
        {
            arr[x].root = y;
        }
        else if (arr[x].rank > arr[y].rank)
        {
            arr[y].root = x;
        }
        else
        {
            arr[y].root = x;
            arr[x].rank++;
        }

        return;
    }
};

int main()
{
    DisjointUnion *dj = new DisjointUnion(10);
    cout << dj->find(2) << "\n";
    cout << dj->find(6) << "\n";
    cout << dj->find(9) << "\n";
    cout << dj->find(7) << "\n";
    dj->Union(2, 7);
    dj->Union(6, 9);
    dj->Union(9, 7);
    cout << dj->find(2) << "\n";
    cout << dj->find(6) << "\n";
    cout << dj->find(9) << "\n";
    cout << dj->find(7) << "\n";
}