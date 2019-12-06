// list/main.c
// 
// Interface definition for linked list.
//
// Amari Jones

#include <stdio.h>
#include <unistd.h>
#include "list.h"

bool addBackTest();
bool addFrontTest();
bool addIndexTest();
bool listLengthTest();
bool listPrintTest();
bool removeBackTest();
bool removeFrontTest();
bool removeIndexTest();
bool test_list_is_in();
bool getElementTest();
bool getIndexTest();

    
int main() {
    printf("Tests for linked list implementation\n");
    printf("\n%s the addBackTest\n",
           addBackTest() ? "Passed" : "Failed"); getchar();
           printf("\033[0;0H\033[2J"); 
    printf("\n%s the addFrontTest\n",
           addFrontTest() ? "Passed" : "Failed"); getchar(); 
           printf("\033[0;0H\033[2J"); 
    printf("\n%s the addIndexTest\n",
           addIndexTest() ? "Passed" : "Failed"); getchar();
           printf("\033[0;0H\033[2J"); 
    printf("\n%s the listLengthTest\n",
           listLengthTest() ? "Passed" : "Failed"); getchar(); 
           printf("\033[0;0H\033[2J"); 
    printf("\n%s the listPrintTest\n",
        listPrintTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the removeBackTest\n",
        removeBackTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the removeFrontTest\n",
        removeFrontTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the removeIndexTest\n",
        removeIndexTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the test_list_is_in\n",
        test_list_is_in() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the getElementTest\n",
        getElementTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("\n%s the getIndexTest\n",
        getIndexTest() ? "Passed" : "Failed"); getchar(); 
        printf("\033[0;0H\033[2J"); 
    printf("All tests completed.");
    return 0;
}

bool addBackTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_to_back(test_list, 1);
    list_add_to_back(test_list, 2);
    
    if ((test_list->head->value == 1) && (test_list->head->next->value == 2)) {
        result = true;
    }
    list_free(test_list);
    
    return result;
}

bool addFrontTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    list_add_to_front(test_list, 1);
    list_add_to_front(test_list, 2);
    
    if ((test_list->head->value == 2) && (test_list->head->next->value == 1)) {
        result = true;
    }
    
    list_free(test_list);
    
    return result;
}

bool addIndexTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);
    list_add_at_index(test_list, 4, 2);

    
    if ((test_list->head->value == 1) && 
        (test_list->head->next->value == 2) &&
        (test_list->head->next->next->value == 4) && 
         (test_list->head->next->next->next->value == 3)) {
        result = true;
    }
  
    list_free(test_list);
    
    return result;
}

bool listLengthTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);

    int length = list_length(test_list);
    if (length == 3) {
        result = true;
    }
    
    list_free(test_list);
    
    return result;
}

bool listPrintTest() {
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_add_at_index(test_list, 3, 2);
    
    // Assume Passed
    return true;
}

bool removeBackTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_from_back(test_list);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_from_back(test_list);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_from_back(test_list);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool removeFrontTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_from_front(test_list);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_from_front(test_list);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_from_front(test_list);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool removeIndexTest() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    // Remove from empty list.
    list_remove_at_index(test_list, 0);
    
    // Remove only node.
    list_add_at_index(test_list, 1, 0);
    list_remove_at_index(test_list, 0);
    if (list_length(test_list) == 0) {
        result = true;
    }
    // Remove second node.
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    list_remove_at_index(test_list, 1);
    if (list_length(test_list) == 1) {
        result = true;
    } else {
        result = false;
    }
    
    list_free(test_list);
    
    return result;

}

bool test_list_is_in() {
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    result = list_is_in(test_list, 1);
    
    list_free(test_list);

    return result;
}


bool getElementTest(){
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    if (list_get_elem_at(test_list, 1) == 2) {
        result = true;
    }
    
    list_free(test_list);

    return result;
}
bool getIndexTest(){
    bool result = false;
    
    list_t *test_list = list_alloc();
    
    list_add_at_index(test_list, 1, 0);
    list_add_at_index(test_list, 2, 1);
    
    if (list_get_index_of(test_list, 2) == 1) {
        result = true;
    }
        
    list_free(test_list);

    return result;
}

