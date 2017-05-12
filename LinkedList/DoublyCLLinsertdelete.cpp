#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    struct node *prev;
    int data;
    struct node *next;
}cdll;

cdll *head;

void insert( int item ){
    // First check if the item being inserted forms the first node. //
    if( head == NULL ){
        head = ( cdll * )malloc( sizeof( cdll ) );
        head -> prev = head;
        head -> data = item;
        head -> next = head;
    }
    else{
        // Initialise a pointer temp to traverse the list. //
        cdll *temp = head;
        while( temp -> next != head ){
            temp = temp -> next;
        }
        // now temp contains last node. //
        // Now take the element. //
        cdll *var = ( cdll * )malloc( sizeof( cdll ) );
        temp -> next = var;
        var -> prev = temp;
        var -> data = item;
        var -> next = head;
        head -> prev = var;
    }
    printf("Element inserted.\n");
} // End of insert() function. //

int deleteNode( int item ){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;

        while( temp -> next != head ){
            if( temp -> data == item ){
                if( temp == head ){
                    cdll *prev_node = temp -> prev;
                    cdll *next_node = temp -> next;
                    prev_node -> next = next_node;
                    next_node -> prev = prev_node;
                    head = next_node;
                    cdll *temp1 = temp;
                    temp = head;
                }
                else{
                    cdll *prev_node = temp -> prev;
                    cdll *next_node = temp -> next;
                    prev_node -> next = next_node;
                    next_node -> prev = prev_node;
                    cdll *temp1 = temp;
                    temp = head;
                    free( temp1 );
                }
            }
            else{
                temp = temp -> next;
            }
        }
        if( temp -> data == item ){ // Since above while loop will not work for the last node. //
            if( temp -> prev == temp -> next ){
                head = NULL;
                free( temp );
            }
            else{
                cdll *prev_node = temp -> prev;
                cdll *next_node = temp -> next;
                prev_node -> next = next_node;
                next_node -> prev = prev_node;
                cdll *temp1 = temp;
                temp = head;
                free( temp1 );
            }
        }
    }
    return 0;
} // End of delete() function. //

int insertmid( int item, int index ){
    // If the list is empty, simply add the element at first position. //
    if( head == NULL ){
        insert( item );
    }
    else{
        // Initialise temp pointer and pos variable. //
        cdll *temp = head;
        int pos = 0;

        while( temp -> next != head ){
            if( pos == index ){
                if( temp -> prev == temp -> next ){
                    // Take the variable in random node. //
                    cdll *var = ( cdll * )malloc( sizeof( cdll ) );
                    var -> data = item;
                    head = var;
                    head -> prev = temp;
                    head -> next = temp;
                    temp -> prev = head;
                    temp -> next = head;
                    // Element is inserted at 0th position. //
                    break;
                }
                else{
                    // Now here check if the element is to be inserted at 0th position. //
                    if( index == 0 ){
                        cdll *prev_node = head -> prev;
                        cdll *next_node = head -> next;
                        cdll *var = ( cdll * )malloc( sizeof( cdll ) );
                        var -> data = item;
                        var -> next = temp;
                        var -> prev = prev_node;
                        temp -> prev = var;
                        head = var;
                        prev_node -> next = var;
                        break;
                    }
                    else{
                        // first form the new node. //
                        cdll *var = ( cdll * )malloc( sizeof( cdll ) );
                        var -> data = item;
                        // Now new node's previous is temp -> prev and new node's next is temp itself. //
                        var -> prev = temp -> prev;
                        var -> next = temp;
                        cdll *previous_node = temp -> prev;
                        previous_node -> next = var;
                        temp -> prev = var;
                        break;
                    }
                }
            }
            else{
                pos += 1;
                temp = temp -> next;
            }
        }
        /* Now if temp == head, that means user wants to enter the element
        at last node. */

        if( temp -> next == head ){
            if( pos == index ){
                // first form the new node. //
                cdll *var = ( cdll * )malloc( sizeof( cdll ) );
                var -> data = item;
                // Now new node's previous is temp -> prev and new node's next is temp itself. //
                var -> prev = temp -> prev;
                var -> next = temp;
                cdll *previous_node = temp -> prev;
                previous_node -> next = var;
                temp -> prev = var;
            }
        }
    }
    return 0;
} // End of insertmid() function. //

void del_at_pos( int index ){
    // First check if list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // If there is only one element in the list. //
        if( head -> prev == head -> next ){
            cdll *temp = head;
            head = NULL;
            free( temp );
        }
        else{
            // Here also if index is zero. //
            cdll *temp = head;
            int pos = 0;
            
            while( temp -> next != head ){
                if( pos == index ){
                    if( index == 0 ){
                        head = head -> next;
                        cdll *prev_node = temp -> prev;
                        cdll *next_node = temp -> next;
                        head -> prev = prev_node;
                        prev_node -> next = head;
                        free( temp );
                        break;
                    }
                    else{
                        cdll *prev_node = temp -> prev;
                        cdll *next_node = temp -> next;
                        prev_node -> next = temp -> next;
                        next_node -> prev = prev_node;
                        free( temp );
                        break;
                    }
                }
                else{
                    pos += 1;
                    temp = temp -> next;
                }
            }
            // Now if the element was to be inserted at last position. //
            if( temp -> next == head ){
                if( pos == index ){
                    cdll *prev_node = temp -> prev;
                    prev_node -> next = head;
                    head -> prev = prev_node;
                    free( temp );
                }
            }
        }
    }
} // End of del_at_pos() function. //

void search( int item ){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;
        int index = -1;
        while( temp -> next != head ){
            index += 1;
            if( temp -> data == item ){
                printf("Element found at index %d. \n", index);
            }
            temp = temp -> next;
        }
        index += 1;
        if( temp -> data == item ){
            printf("Element found at index %d. \n", index);
        }
    }
} // End of search() function. //

void display(){
    // Check if the list is empty or not. //
    if( head == NULL ){
        printf("The list is empty.\n");
    }
    else{
        // To traverse the list, initialise the temp pointer. //
        cdll *temp = head;

        while( temp -> next != head ){
            printf("%d\n", temp -> data);
            temp = temp -> next;
        }
        printf("%d\n", temp -> data);
    }
} // End of display() function. //

int main(){
	head=NULL;
    int ch = 1;
    while( ch == 1 ){
        printf("1. Insert.\n");
        printf("2. Delete.\n");
        printf("3. Search.\n");
        printf("4. Display.\n");
        printf("5. Exit.\n");
        printf("6. Insert at a position.\n");
        printf("7. Delete at a position.\n");

        int x;
        printf("Enter choice: ");
        scanf("%d", &x);

        if( x == 1 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            insert( elem );
        }
        else if( x == 2 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            deleteNode( elem );
        }
        else if( x == 3 ){
            int elem;
            printf("Enter item: ");
            scanf("%d", &elem);
            search( elem );
        }
        else if( x == 4 ){
            display();
        }
        else if( x == 5 ){
            ch = 0;
        }
        else if( x == 6 ){
            // Take the position and the element. //
            int elem, pos;
            printf("Enter element: ");
            scanf("%d", &elem);
            printf("Enter position: ");
            scanf("%d", &pos);
            // Make a call to insertmid() function. //
            insertmid( elem, pos );
        }
        else if( x == 7 ){
            // Take the position only. //
            int pos;
            printf("Enter the position: ");
            scanf("%d", &pos);
            // Make a call to del_at_pos() function. //
            del_at_pos( pos );
        }
        else{
            printf("Invalid choice.\n");
        }
    }
    return 0;
} // End of main() function. //
