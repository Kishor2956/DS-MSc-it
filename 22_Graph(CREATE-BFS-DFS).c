
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};

struct node *adj[20];
int n;

/* Create Graph */
void createGraph()
{
    int i, edges, u, v;
    struct node *newnode;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n <= 0 || n > 20)
    {
        printf("Invalid number of vertices.\n");
        n = 0;
        return;
    }

    for (i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (source destination), vertices 0 to %d:\n", n - 1);

    for (i = 0; i < edges; i++)
    {
        scanf("%d%d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge. Try again.\n");
            i--;
            continue;
        }

        /* Add edge u -> v */
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        newnode->vertex = v;
        newnode->next = adj[u];
        adj[u] = newnode;

        /* Add reverse edge for undirected graph */
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }

        newnode->vertex = u;
        newnode->next = adj[v];
        adj[v] = newnode;
    }

    printf("Graph created successfully.\n");
}

/* Breadth First Search */
void BFS()
{
    int queue[20], visited[20];
    int front, rear, start, i, v;
    struct node *temp;

    if (n == 0)
    {
        printf("Create the graph first.\n");
        return;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    front = 0;
    rear = 0;

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        temp = adj[v];

        while (temp != NULL)
        {
            if (!visited[temp->vertex])
            {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }

            temp = temp->next;
        }
    }

    printf("\n");
}

/* Depth First Search */
void DFSVisit(int v, int visited[])
{
    struct node *temp;

    visited[v] = 1;
    printf("%d ", v);

    temp = adj[v];

    while (temp != NULL)
    {
        if (!visited[temp->vertex])
            DFSVisit(temp->vertex, visited);

        temp = temp->next;
    }
}

void DFS()
{
    int visited[20];
    int start, i;

    if (n == 0)
    {
        printf("Create the graph first.\n");
        return;
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex.\n");
        return;
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFSVisit(start, visited);
    printf("\n");
}

int main()
{
    int choice;

    n = 0;

    do
    {
        printf("\n--- GRAPH MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. BFS Traversal\n");
        printf("3. DFS Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                createGraph();
                break;

            case 2:
                BFS();
                break;

            case 3:
                DFS();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}
