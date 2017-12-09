#include <iostream>
#include <stdlib.h>

using namespace std;

void initialize_edges(int num, int** Edges)
{
    const int DIMENSION = num;
    srand((unsigned)time(NULL));
    for(int i = 0; i < DIMENSION; i++)
    {
        for(int j = i; j < DIMENSION; j++)
        {
            if(i == j)
            {
                Edges[i][j] = 0;
            }
            else
            {
                int yes = (int)rand()%2;
                if(yes == 1)
                {
                    Edges[i][j] = 1;
                    Edges[j][i] = 1;
                }
                else
                {
                    Edges[i][j] = 0;
                    Edges[j][i] = 0;
                }
            }
        }
    }
}

void displayMatrice(int** Edges, int NUM)
{
    const int DIMENSION = NUM;
    cout << "Randomly initialized Edge Matrice:" << endl;
    for(int i = 0; i <= DIMENSION; i++)
    {
        if(i == 0)
        {
            cout << "   ";
            for(int j = 0; j < DIMENSION; j++)
            {
                cout << j << " ";
            }
            cout << endl;
            cout << "  ";
            for(int j = 0; j < DIMENSION*2; j++)
            {
                cout << "-";
            }
            cout << endl;
        }
        else
        {
            cout << i-1 << "| ";
            for(int j = 0; j < DIMENSION; j++)
            {
                cout << Edges[i-1][j] << " ";
            }
            cout << endl;
        }
    }
}

void DFS(int* visited, int** Edges, int NUM, int seq = 0)
{
    visited[seq] = 1;

    cout << seq << " ";

    for(int i = 0; i < NUM; i++)
    {
        if (Edges[seq][i] == 1 && visited[i] == 0)
        {
            DFS(visited,Edges,NUM,i);
        }
    }
}

int count_Zero(const int* t,int len)
{
    int count = 0;
    for(int i =0; i < len; i++)
    {
        if(t[i] == 0) count++;
    }
    return count;
}

void bfs_recur(int* visited, int** Edges, int NUM, int seq, const int lay, int lev)
{
    int level = lev + 1;

    const int LEN = NUM;
    int temp[LEN];
    for(int i = 0; i < LEN; i++)
    {
        temp[i] = 0;
    }

    for(int i = 0; i < NUM; i++)
    {
        if(Edges[seq][i] == 1 && visited[i] == 0)
        {
            temp[i] = 1;
        }
    }

    if(level < lay)
    {
        for(int i = 0; i < NUM; i++)
        {
            if(temp[i] == 1)
            {
                bfs_recur(visited, Edges, NUM, i, lay, level);
            }
        }
    }
    else if(level == lay)
    {
        for(int i = 0; i < NUM; i++)
        {
            if(temp[i] == 1)
            {
                visited[i] = 1;
                cout << i << " ";
            }
        }
        return;
    }
    else return;
}

void BFS(int* visited, int** Edges, int NUM, int seq = 0)
{

    visited[seq] = 1;

    const int LEN = NUM;
    int temp[LEN];
    for(int i = 0; i < LEN; i++)
    {
        temp[i] = 0;
    }

    for(int i = 0; i < NUM; i++)
    {
        if(Edges[seq][i] == 1 && visited[i] == 0)
        {
            temp[i] = 1;
        }
    }

    int num_Zero = count_Zero(visited, NUM);
    int layer = 1;
    while(num_Zero > 0)
    {
        for(int i =0; i < NUM; i++)
        {
            if(temp[i] == 1)
            {
                bfs_recur(visited, Edges, NUM, i, layer, 0);
            }
        }
        layer++;
        num_Zero = count_Zero(visited, NUM);
    }
    cout << seq << " ";
}

int main() {

    int NUM = 0;
    cout << "Enter a point number: ";
    cin >> NUM;

    const int DIMENSION = NUM;
    int* visited = new int[DIMENSION];
    for(int i = 0; i < DIMENSION; i++)
    {
        visited[i] = 0;
    }

    cout << "Initial points:\n";
    for(int i = 0;i<NUM;i++)
    {
        cout << visited[i]<<" ";
    }
    cout<<endl;

    int** Edges = new int*[DIMENSION];
    for(int i =0;i<DIMENSION;i++)
    {
        Edges[i] = new int[DIMENSION];
    }
    initialize_edges(NUM,Edges);
    displayMatrice(Edges,NUM);
    cout << endl;

    cout << "Depth first search sequence:" << endl;
    DFS(visited, Edges, NUM);
    cout << endl;


    for(int i = 0; i < DIMENSION; i++)
    {
        visited[i] = 0;
    }
    cout << "Breath first search sequence(in reverse order):" << endl;
    BFS(visited,Edges,NUM);
    cout << endl;

    return 0;
}