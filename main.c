#include <stdio.h>
#include <stdlib.h>
#include "statistics.h"

int statistics[256] = {0};
int order[256] = {0};
int map[256] = {0};

typedef struct node {
    int item, stat;
    struct node *left, *right, *next;
} node;

int comparator(const void *a, const void *b) {
    return statistics[*(int*) b] - statistics[*(int*) a];
}

node * combine(node *first, node *second);
void build_map(node *head, int i, int n);
void create_archive(node *head, char *ofile);
node * extract_tree(char *file);

int main(int argc, char** argv) {
    int i;
    int size = 0;
    
    if (!strcmp(argv[2], "-c")) {
        get_statistics(statistics, argv[1]);
        
        for (i = 0; i < 255; i++) { order[i] = i; };
        
        qsort(order, 256, sizeof (int), comparator);

        while (statistics[order[size]] && size < 256) { size++; }
        printf("size %d\n", size);
        
        node *head = NULL;
        
        for (i = 0; i < size; i++) {
            node *n = malloc(sizeof(node));
            n -> item = order[i];
            n -> stat = statistics[order[i]];
            n -> left = NULL;
            n -> right = NULL;
            n -> next = head;
            head = n;
        };
           
        while (head -> next) { head = combine(head, head -> next); }        
        build_map(head, 1, 1);
        
        create_archive(head, argv[3]);
        
//        for (i = 0; i < 256; i++)
//        {
//            if (map[i]){
//                printf("%d - %d - %d\n", i, map[i], statistics[i]);  
//            };
//        }        
        return (EXIT_SUCCESS);
    };


    if (!strcmp(argv[2], "-x")) {
        node *head = NULL;
        head = extract_tree(argv[1]);
        build_map(head, 1, 1);
        
        printf("extracted\n");
        return (EXIT_SUCCESS);
    };
} 

node * combine(node *first, node *second){
    node *n = NULL, *head = NULL;
    n = malloc(sizeof(node));        
    n -> item = -1;
    n -> stat = first -> stat + second -> stat;
    n -> left = first;
    n -> right = second;
    n -> next = NULL;
            
    head = second -> next;
    
    if (!head) { return n; };
     
    node *prev, *current;
    
    prev = head;
    current = head -> next;
            
    while (current && ((n -> stat) > (current -> stat))){ 
        prev = current;
        current = current -> next; 
    };
    
    prev -> next = n;
    n -> next = current; 
    
    return head;
}

void build_map(node *head, int i, int n){
    if (head -> item > 0) {
        map[head->item] = i;
        statistics[head->item] = n;
    }    
    if (head -> left) { build_map(head -> left, (i << 1) + 1, n+1); };
    if (head -> right) { build_map(head -> right, (i << 1), n+1); };
}

void create_archive(node *head, char *ofile){
    printf(ofile);
//    archive_tree();
//    archive_data();
};

node * extract_tree(char *file){
    NULL;
}
        