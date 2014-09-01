#include<stdio.h>
#include<stdlib.h>

struct QueueNode {
    int data;
    struct QueueNode* next;
};

typedef  struct QueueNode QueueNode;

struct Queue {
    QueueNode* head;
    QueueNode*tail;
};

typedef struct Queue Queue; 

struct GraphNode {
    int destination;
    struct GraphNode* next;
};

typedef struct GraphNode GraphNode;


struct NodeList {

     GraphNode* head;
};

typedef struct NodeList NodeList;

struct Graph {
    int num_vertices;
    NodeList* nodeListArray;
};

typedef struct Graph Graph;


Graph* create_graph(int num_vertices) {
    Graph* graph = (Graph*)(malloc ( sizeof (Graph)));
    graph->nodeListArray = (NodeList *)(malloc ( num_vertices * sizeof ( NodeList )));
    int i;
    for (i = 0; i < num_vertices; i ++) {
        graph->nodeListArray[i].head = NULL;
    }
    return graph;
}

void addEdge(Graph * graph, int source, int destination) {
    GraphNode* newNode = ( GraphNode* )( malloc ( sizeof( GraphNode )));
    newNode->destination = destination ;
    newNode->next = graph->nodeListArray[source].head;
    graph->nodeListArray[source].head = newNode;


    newNode = ( GraphNode* )( malloc ( sizeof( GraphNode )));
    newNode->destination = source ;
    newNode->next = graph->nodeListArray[destination].head;
    graph->nodeListArray[destination].head = newNode;
}


void printBfsTree(Graph* graph,int startPoint) {
    int num_vertices = graph->num_vertices;
    int* is_visited = (int *)( calloc( num_vertices, sizeof ( int )));
    Queue* queue = (Queue *) (malloc (sizeof (Queue)));
    QueueNode* queueNode = (QueueNode *)(malloc (sizeof (QueueNode)));
    is_visited[startPoint] = 1;
    queueNode-> data = startPoint;
    queue->head = queue->tail = queueNode;
    QueueNode* currentQueueNode = queue->head;
    while(currentQueueNode) {
        int source = currentQueueNode->data;
        GraphNode* nextLevelNode = graph->nodeListArray[source].head;
        while(nextLevelNode) {
           if(!is_visited[nextLevelNode->destination]) {
                QueueNode* queueNode = (QueueNode *)(malloc (sizeof (QueueNode)));
                is_visited[nextLevelNode->destination] = 1;
                queueNode->data = nextLevelNode->destination;
                queueNode->next = NULL;
                queue->tail->next = queueNode;
                queue->tail = queueNode;
                printf("-> %d", nextLevelNode->destination);
           }
           nextLevelNode = nextLevelNode->next;
        }
        currentQueueNode = currentQueueNode->next;
    }

}
int main() {
    //create the graph given in above fugure
    int V = 5; 
    Graph* graph = create_graph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printBfsTree(graph,2);
}
