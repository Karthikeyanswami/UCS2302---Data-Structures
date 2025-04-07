#include <stdio.h>
#include <stdlib.h>

struct graph
{
  int num;
  int mat[50][50];
  int inDegree[50];
};

void init(struct graph *g, int n, int prev[])
{
  g->num = n;
  
  for(int i = 0; i < n; i++)
    {
      g->inDegree[i] = 0;
      for(int j = 0; j < n; j++)
        {
          g->mat[i][j] = 0;
        }
    }

  for(int i = 1; i < g->num; i++)
    {
      g->mat[prev[i]][i] = 1;
      g->inDegree[i]++;
    }
}

void display(struct graph *g)
{
  printf("\nAdjacency matrix : \n");
  for(int i = 0; i < g->num; i++)
  {
    for(int j = 0; j < g->num; j++)
      {
        printf("%d ", g->mat[i][j]);
      }
    printf("\n");
  }
  printf("\n");
  
}

void countSort(struct graph* g, int* visited, int* count) {
    int flag = 0;
    for (int i = 0; i < g->num; ++i) {
        if (g->inDegree[i] == 0 && visited[i] == 0) {
            for (int j = 0; j < g->num; ++j) {
                if (g->mat[i][j] == 1) {
                    g->inDegree[j]--;
                }
            }
            visited[i] = 1;
            countSort(g, visited, count);
            visited[i] = 0;
            for (int j = 0; j < g->num; ++j) {
                if (g->mat[i][j] == 1) {
                    g->inDegree[j]++;
                }
            }
            flag = 1;
        }
    }
    if (flag == 0) {
        (*count)++;
    }
}

int countTopologicalSorts(struct graph* g) {
    int visited[50] = {0};
    int count = 0;
    countSort(g, visited, &count);
    return count;
}

int main()
{
  struct graph g; 
  int n;
  printf("Enter num of rooms : ");
  scanf("%d", &n);
  int prev[n];
  for(int i=0; i<n; i++)
    {
      printf("Enter the room num of previous room of %d: ", i);
      scanf("%d", &prev[i]);
    }
  init(&g, n, prev);
  display(&g);
  printf("No. of ways : %d\n", countTopologicalSorts(&g));
  return 0;

}