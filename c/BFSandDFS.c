// DFS algorithm in C

// header files
#include <stdio.h>
#include <stdlib.h>
// for bfs queue
#define SIZE 100

// for the structure queue
struct queue {
  int items[SIZE];
  int front;
  int rear;
};

// structure for node
struct node 
{
  int vertex;
  struct node* next;
};

struct node* NewNode(int v);

// structure for the graph
struct Graph 
{
  int numVertices;
  int* visited;
  struct node** adjancent;
};

// Create a queue
struct queue* NewQueu() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}

// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}

// Adding elements into queue
void Enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nOh!, the queue is full\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}

// Removing elements from queue
int Dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("\nOops!, the queue is empty\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Queue us being changed\n");
      q->front = q->rear = -1;
    }
  }
  return item;
}

// Print the queue
void DisplayQueue(struct queue* q) {
  int i = q->front;

  if (isEmpty(q)) {
    printf("\nOops!, the queue is empty\n");
  } else {
    printf("\nQueue: \n");
    for (i = q->front; i < q->rear + 1; i++) {
      printf("%d ", q->items[i]);
    }
  }
}

// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = NewQueu();

  graph->visited[startVertex] = 1;
  Enqueue(q, startVertex);

  while (!isEmpty(q)) {
    DisplayQueue(q);
    int currentVertex = Dequeue(q);
    printf("Vertex visited %d\n", currentVertex);

    struct node* temp = graph->adjancent[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        Enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

// Build a new graph
struct Graph* BuildGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjancent = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjancent[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// This function will simply add a new edge
void NewEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = NewNode(dest);
  newNode->next = graph->adjancent[src];
  graph->adjancent[src] = newNode;

  // Add edge from dest to src
  newNode = NewNode(src);
  newNode->next = graph->adjancent[dest];
  graph->adjancent[dest] = newNode;
}

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjancent[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("It is Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Create a node
struct node* NewNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Print the graph
void Display(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjancent[v];
    printf("\nAdjacent to %d", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

// main function begins here
int main()
{ 
    printf("\nGRAPHS\n\n");
    int Vertices, Source, Destination, i = 0;

    printf("Enter the first Vertex: ");
    scanf("%d",&Vertices);
  
    // to store the source and destination
    // creating a graph
    struct Graph* NewGraph = BuildGraph(Vertices);
    printf("Enter the edge details...\n");
    while(1)
    {
        printf("Enter the Source vertex: ");   
        scanf("%d",&Source); 
        printf("Enter the destination vertices: ");
        scanf("%d",&Destination);
        NewEdge(NewGraph, Source, Vertices);

        printf("Do you want to continue(y(1)/n(0)): ");
        scanf("%d",&i);
        if(i == 0)
        {
          i = Source;  // for getting a random vertex so as to start the dfs execution
          break;
        }
    }

    // diplaying the original graph
    printf("the original graph is: \n");
    Display(NewGraph);

    // The DFS form
    printf("The DFS is: \n");
    DFS(NewGraph, i);

    // The DFS form
    printf("The BFS is: \n");
    bfs(NewGraph, i);

    return 0;

}