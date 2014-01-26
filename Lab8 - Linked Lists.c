//
// APS105-F12 Lab 8 Lab8.c
//
// Program for maintaining a bookstore inventory.
//
// Uses a linked list to hold the books.
//
// Author: Shimeng Cui
// Student Number:
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

//**********************************************************************
// Linked List Definitions
//  Define your linked list node and pointer types
//  here for use throughout the file.
//
//
//   ADD STATEMENT(S) HERE
typedef struct node{ //node with title, author, rating, category and a pointer to the next link
    char *title;
    char *author;
    int rate;
    char cat;
    struct node *link;
}Node,*NodePointer;


//**********************************************************************
// Linked List Function Declarations
//
// Functions that modify the linked list.
//   Declare your linked list functions here.
//
//   ADD STATEMENT(S) HERE
NodePointer newNode(char *title, char *author, int rate, char cat, NodePointer np);
NodePointer insert(NodePointer head, char *title, char *author, int rate, char cat);
NodePointer deleteBook(NodePointer head, char *title);
void print(NodePointer head);
void search(NodePointer head, char *title);
void higherRating(NodePointer head, int rate);
NodePointer deleteAll(NodePointer head);


//**********************************************************************
// Support Function Declarations
//

void safegets (char s[], int arraySize);        // gets without buffer overflow
void bookNameDuplicate (char bookName[]);   // marker/tester friendly
void bookNameFound (char bookName[]);       //   functions to print
void bookNameNotFound (char bookName[]);    //     messages to user
void bookNameDeleted (char bookName[]);
void printInventoryEmpty (void);
void printInventoryTitle (void);
void printNoBooksWithHigherRating (int rating);

//**********************************************************************
// Program-wide Constants
//

const int MAX_LENGTH = 1023;
const char NULL_CHAR = '\0';
const char NEWLINE = '\n';
const char FICTION = 'F';
const char HISTORY = 'H';
const char PHILOSOPHY = 'P';
const char ART = 'A';


//**********************************************************************
// Main Program
//

int main (void)
{
    const char bannerString[]
        = "Online Bookstore Inventory Management Program.\n\n";
    const char commandList[]
        = "Commands are I (insert), D (delete), S (search by name),\n"
          "  V (search by rating), P (print), Q (quit).\n";
    NodePointer list = NULL;

    // Declare linked list head.
    //   ADD STATEMENT(S) HERE TO DECLARE LINKED LIST HEAD.


    // announce start of program
    printf("%s", bannerString);
    printf("%s", commandList);

    char response;
    char input[MAX_LENGTH+1];
    do
    {
        char *title = (char *)malloc((MAX_LENGTH+1)*sizeof(char)); //each time a user inputs a command places to store the information are made. Thus later on the function does not point to the same array, messings things up
        char *author = (char *)malloc((MAX_LENGTH+1)*sizeof(char));
        int rate;
        char cat;
        printf("\nCommand?: ");
        safegets(input, MAX_LENGTH + 1);
        // Response is first char entered by user.
        // Convert to uppercase to simplify later comparisons.
        response = toupper(input[0]);

        if (response == 'I')
        {
            // Insert a book entry into the linked list.
            // Maintain the list in correct order (F, H, P, A).
            //   ADD STATEMENT(S) HERE

            // USE THE FOLLOWING PRINTF STATEMENTS WHEN PROMPTING FOR DATA:
            printf("  book: "); //gets the user input
            safegets(title,MAX_LENGTH+1);
            printf("  author: ");
            safegets(author,MAX_LENGTH+1);
            printf("  rating: ");
            scanf("%d",&rate);
            getchar(); //takes up new line character
            printf("  category: ");
            scanf("%c",&cat);
            getchar();
            list = insert(list, title, author, rate, cat); //calls insert which returns the new head, and thus revised linked list

        }
        else if (response == 'D')
        {
            // Delete a book from the list.

            printf("\nEnter the book name to delete: ");

            //   ADD STATEMENT(S) HERE
            safegets(title, MAX_LENGTH+1); //user input
            list = deleteBook(list, title); //deletes book and return new head of revised linked list
        }
        else if (response == 'S')
        {
            // Search for a book by a name.

            printf("\nEnter the book name to search for: ");

            //   ADD STATEMENT(S) HERE
            safegets(title, MAX_LENGTH+1);
            search(list, title); //searches for book

        }
        else if (response == 'V')
        {
            // Search for books that are rated higher than or equal to a rating.

            printf("\nEnter rating: ");

            //   ADD STATEMENT(S) HERE
            scanf("%d",&rate);
            getchar();
            higherRating(list,rate); //gets books with higher ratings

        }
        else if (response == 'P')
        {
            // Print the bookstore inventory.

            //   ADD STATEMENT(S) HERE
            print(list); //prints bookstore

        }
        else if (response == 'Q')
        {
            ; // do nothing, we'll catch this case below
        }
        else
        {
            // do this if no command matched ...
            printf("\nInvalid command.\n%s\n", commandList);
        }
    } while (response != 'Q');

    // Delete the entire linked list that hold the bookstore inventory.
    //   ADD STATEMENT(S) HERE
    list = deleteAll(list); //when the user quits the program deletes all elements of the linked list
    list = NULL; //makes head point to NULL

    // Print the linked list to confirm deletion.
    //   ADD STATEMENT(S) HERE
    print(list); //prints bookstore to make sure that it's empty

    return 0;
}

//**********************************************************************
// Support Function Definitions

// Function to get a line of input without overflowing target char array.
void safegets (char s[], int arraySize)
{
    int i = 0, maxIndex = arraySize - 1;
    char c;
    while (i < maxIndex && (c = getchar()) != NEWLINE)
    {
        s[i] = c;
        i = i + 1;
    }
    s[i] = NULL_CHAR;
}

// Function to call when a user is trying to insert a book name
// that is already in the inventory.
void bookNameDuplicate (char bookName[])
{
    printf("\nAn entry for <%s> is already in the bookstore inventory!\n"
           "New entry not entered.\n", bookName);
}

// Function to call when a book with this name was found in the inventory.
void bookNameFound (char bookName[])
{
    printf("\nThe book with name <%s> was found in the bookstore inventory.\n",
             bookName);
}

// Function to call when a book with this name was not found in the inventory.
void bookNameNotFound (char bookName[])
{
    printf("\nThe book with name <%s> is not in the bookstore inventory.\n",
             bookName);
}

// Function to call when a name that is to be deleted
// was found in the inventory.
void bookNameDeleted (char bookName[])
{
    printf("\nDeleting book with name <%s> from the bookstore inventory.\n",
             bookName);
}

// Function to call when printing an empty bookstore inventory.
void printInventoryEmpty (void)
{
    printf("\nThe bookstore inventory is empty.\n");
}

// Function to call to print title when the entire inventory is printed.
void printInventoryTitle (void)
{
    printf("\nMy Inventory: \n");
}

// Function to call when no book in the bookstore inventory has higher
// or equal rating to the given rating
void printNoBooksWithHigherRating (int rating)
{
	printf("\nNo book(s) in the bookstore inventory is rated higher than or equal to <%d>.\n", rating);
}

//**********************************************************************
// Add your functions below this line.
NodePointer newNode(char *title, char *author, int rate, char cat, NodePointer np){ //makes a new node
	NodePointer p = (NodePointer)malloc(sizeof(Node)); //creats new node
	p->title = malloc((MAX_LENGTH+1)*sizeof(char)); //fills new node with information
	p->author = malloc((MAX_LENGTH+1)*sizeof(char));
    p->title = title;
    p->author = author;
    p->rate = rate;
    p->cat = cat;
    p->link = np; //points the new node to another node
	return p; //returns the node
}

NodePointer insert(NodePointer head, char *title1, char *author, int rate, char cat){ //inserts a new entry into the bookstore following the order F, H, P, A
    NodePointer current = head; //keeps track of current location
    bool found = false; //flag to see if the new entry already exists
    while(current!=NULL){ //goes through linked list until it is NULL
        if(strcmp((current->title),title1)==0){
            found = true; //checks if the entry title and node title are the same
        }
        current = current->link; // moves on to next node
    }
    current = head; //resets current to the front, head
    if(head == NULL){
        head = newNode(title1,author,rate,cat,NULL); //if the list is empty, the function simply points head to the new node
        return head;
    }
    if((cat == FICTION && head->cat!=FICTION) || (cat == HISTORY && (head->cat==ART || head->cat==PHILOSOPHY)) || (cat==PHILOSOPHY && head->cat==ART)){
        if(found == false){ //this functions is for inserting before the first element
            NodePointer temp = head;
            head = newNode(title1, author, rate, cat, temp);
            return head;
        }
    }
    else{ //this is for inserting elsewhere
        while(current != NULL && found == false){
            //print(head);
            if(cat==FICTION && found == false){
                if(current->link == NULL || current->link->cat!=FICTION){ //this confirms that the position is right before the next catagory of books
                    NodePointer temp = current;
                    current->link = newNode(title1, author, rate, cat, temp->link); //makes the current link point to new node, and the new node points to the node after the current
                    break;
                }
            }
            else if(cat==HISTORY && found == false){ //same as above but with other category of book
                if(current->link ==NULL || current->link->cat==ART || current->link->cat==PHILOSOPHY){
                    NodePointer temp = current;
                    current->link = newNode(title1, author, rate, cat, temp->link);
                    break;
                }
            }
            else if(cat==PHILOSOPHY && found == false){
                if(current->link == NULL || current->link->cat==ART){
                    NodePointer temp = current;
                    current->link = newNode(title1, author, rate, cat, temp->link);
                    break;
                }
            }
            else if(cat==ART && current->link==NULL && found == false){
                current->link = newNode(title1, author, rate, cat, NULL);
                break;
            }
            current = current->link;
        }
        if(found==true){
            bookNameDuplicate(title1); //if there is a duplicate it tells the user
        }
        return head;
    }
}

NodePointer deleteBook(NodePointer head, char *title){ //this is for deleting a node
    NodePointer current = head;
    if(head==NULL){ //if the list is empty
        bookNameNotFound(title); //prints error
        return head;
    }
    else if(head->link == NULL && strcmp(head->title, title)==0){ //if there is only 1 element in the list and it is the one to delete
        free(head); //just free head
        head = NULL;
        bookNameDeleted(title); //and print that the book ahs been deleted
        return head;
    }
    else if(strcmp(head->title,title)==0){ //if there is more than 1 node but the first one needs to be deleted
        NodePointer temp = head->link; //makes temp point to second node
        free(head); //deletes the head and thus first node
        bookNameDeleted(title);
        return temp; //the Node that is returned points to the second node
    }
    else{ //otherwise
        while(current->link != NULL){ //go through list
            if(strcmp(current->link->title,title)==0){ //if the next link is the one to be deleted
                if(current->link->link == NULL){ //if the next node is the last one
                    free(current->link); //frees next node
                    current->link = NULL; //makes current one point to NULL
                    bookNameDeleted(title);
                    return head;
                }
                else{ //if next node is not the last one
                    NodePointer temp1 = current->link->link; //temporary node that points to the node after the next
                    free(current->link); //frees next node
                    current->link = temp1; //makes current node point the one after the next
                    bookNameDeleted(title);
                    return head;
                }
            }
            current = current->link; //moves to next node
        }
    }
    bookNameNotFound(title); //if by this point the function does not return, it means that the title was not found
    return head;
}

void print(NodePointer head){
    if(head == NULL){
        printInventoryEmpty(); //error if the list is empty
    }
    else{
        NodePointer current = head;
        printInventoryTitle();
        while(current != NULL){ //goes through list and prints info
            printf("%s\n%s\n%d\n%c\n\n", current->title, current->author, current->rate, current->cat);
            current = current->link;
        }
    }
}

void search(NodePointer head, char *title){
    NodePointer current = head;
    bool found = false;
    while(current != NULL){ //goes through list to see if the title matches the title in the node
        if(strcmp(current->title,title)==0){
            found = true; //if it matches it make the flag true and prints the book info
            bookNameFound(title);
            printf("\n%s\n%s\n%d\n%c\n\n", current->title, current->author, current->rate, current->cat);
        }
        current = current->link; //moves onto next node
    }
    if(found == false){ //gives error if book is not found
        bookNameNotFound(title);
    }
}

void higherRating(NodePointer head, int rate){ //checks for books of higher rating
    NodePointer current = head;
    bool found = false;
    while(current != NULL){ //goes through list
        if((current->rate) >= rate){ //checks if rating of the current node is greater or equal to the user required rating
            found = true; //makes flag true and prints info of book
            printf("%s\n%s\n%d\n%c\n\n", current->title, current->author, current->rate, current->cat);
        }
        current = current->link;
    }
    if(found == false){ //if the book is not found it gives an error
        printNoBooksWithHigherRating(rate);
    }
}
NodePointer deleteAll(NodePointer head){ //erases entire list
	while(head!=NULL){ //goes through list
		NodePointer temp = head; //deletes everything
		head = head->link;
		free(temp);
	}
	return head;
}

