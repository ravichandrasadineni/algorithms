/* Building adjacency list to represent the follwing graph */
#include<stdio.h>
#include<stdlib.h>
struct AdjacentNode {
    int destination;
    struct AdjacentNode *next;
};

struct AdjacentNodeList {
    struct AdjacentNode *head;
};

struct Graph {
    int num_vertices;
    struct AdjacentNodeList *adjNodeListArray;
};

struct Graph* createGraph(int num_vertices) {
     struct Graph* graph = ( struct Graph* )(malloc( sizeof(struct Graph) ));
     graph ->num_vertices = num_vertices;
     graph->adjNodeListArray = (struct AdjacentNodeList*)( malloc (num_vertices * sizeof (struct AdjacentNodeList )));
     int i;
     for(i=0; i<num_vertices; i++) {
         graph->adjNodeListArray[i].head= NULL;
     }
     return graph;
};

void addEdge( struct Graph *graph, int source, int destination) {
   

    struct AdjacentNode* adjNode = (struct AdjacentNode* )(malloc(sizeof(struct AdjacentNode)));
    adjNode->next = graph->adjNodeListArray[source].head;
    adjNode->destination = destination;
    graph->adjNodeListArray[source].head = adjNode;

    //symmetric nature of undirected graph has to be preserved
    adjNode = (struct AdjacentNode* )(malloc(sizeof(struct AdjacentNode)));
    adjNode->next = graph->adjNodeListArray[destination].head;
    adjNode->destination = source;
    graph->adjNodeListArray[destination].head = adjNode;
}


void printGraph(struct Graph *graph) {
    int i;
    for( i =0; i< graph->num_vertices; i++) {
        struct AdjacentNodeList currentAdjacentNodeList = graph->adjNodeListArray[i];
    
    
        struct AdjacentNode* adjNode = currentAdjacentNodeList.head;
        printf("head");
        while(adjNode) {
            printf("-> %d", adjNode->destination);
            adjNode = adjNode->next;
        }
        printf("\n");
    }
}

void freeMemory(struct Graph * graph) { 
    
    int i;
    for( i =0; i< graph->num_vertices; i++) {
        struct AdjacentNodeList currentAdjacentNodeList = graph->adjNodeListArray[i];
    
    
        struct AdjacentNode* adjNode = currentAdjacentNodeList.head;
        while(adjNode) {
            adjNode = adjNode->next;
            free(adjNode);
        }
    }
    free(graph->adjNodeListArray);
    free(graph);
}

int main() {
    //create the graph given in above fugure
    int V = 5; 
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);        
    // print the adjacency list representation of the above graph
    printGraph(graph);
    freeMemory(graph);

    return 0;
}
