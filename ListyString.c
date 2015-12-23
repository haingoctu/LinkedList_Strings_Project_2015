/*
*   Hai Tu
*   h1674776
*   COP 3502C
*   Dr. Szumlanski
*   Assignment #3: Listy Strings
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListyString.h"

#define MAX 1024

node *stringToList(char *str);
node *replaceChar(node *head, char key, char *str);
node *reverseList(node *head);
node *insertNode(node *head, char data);
node *createNode(char data);
void printList(node *head);
void recursivePrint(node *head);
node *findTail(node *head);
node *deleteNode(node *head, char key);

int main(int argc, char **argv)
{
    FILE *fp;
    node *head = NULL;
    char buffer[MAX];
    int strVirginity = 1;

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        return 0;
    }

	//	read in each line of the input file fp
    while (fgets(buffer, MAX + 1, fp) != NULL)
    {
    	//	track and check if this is the first line
        if (strVirginity == 1)
        {
            head = stringToList(buffer);
            strVirginity = 0;
        }

		//	commands
        if(buffer[0] == '!')
        {
            printList(head);
        }
        else if(buffer[0] == '~')
        {
            head = reverseList(head);
        }
        else if(buffer[0] == '-')
        {
            head = deleteNode(head, buffer[2]);
        }
        else if(buffer[0] == '@')
        {
            head = replaceChar(head, buffer[2], buffer+4);
        }
    }
	
	fclose(fp);
    return 0;
}

/*
* 	returns head of the new linked list. convert the string to a linked list.
* 	each char is its own node 
*/
node *stringToList(char *str)
{
	int tracker = 0;
	node *head = NULL;
	
    if (str == NULL || !strcmp(str, ""))
    {
        return NULL;
    }

	//as long as the element not a new line, create the node
    while (str[tracker] != '\n')
    {
        head = insertNode(head, str[tracker++]);
    }
    
    return head;
}

/*
*	returns the head of modified linked list.
*	takes in head, char (key) to be changed and the string that will replace it.
*	if string is NULL or empty, delete the nodes that matched chars.
*/
node *replaceChar(node *head, char key, char *str)
{
	node *current = head;
	node *temp = NULL;
	
    if(head == NULL)
        return head;
	
    if (str == NULL || !strcmp(str, ""))
    {
        return deleteNode(head, key);
    }
	
	//	check just the head.
	if (current->data == key)
    	{
    		temp = current; //copy the node's address to temp
    		//create the new string and set it as new head and current.
    		head = current = stringToList(str);
    		current = findTail(current); //find the tail and set current it.
    		//link the new string's tail with the old head's next.
			current->next = temp->next;
    		free(temp); //clean up the old node.
		}
	
	//	check everything after the head.
    while (current != NULL)
    {
    	if (current->next != NULL && current->next->data == key)
    	{
            temp = current->next; //copy the next's address to temp
            //create the new string and set it as new next.
            current->next = stringToList(str);
            current = findTail(current); //find the tail and set current it.
            //link the new string's tail with the old node's next.
			current->next = temp->next;
            free(temp); //clean up the old node.
		}
		else
		{
			current = current->next; //nothing happens
		}
    }
    
	return head;
}

/*
*	returns the head after linked list is sorted in reverse order.
*	takes in head.
*/
node *reverseList(node *head)
{
    int tracker = 0;
    
	if (head == NULL || head->next == NULL) //base case
	{
		return head;
	}

	node *temp = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return temp;
}

/*
*	returns head of our linked list.
*	takes in the head and char to create a node for linked list.
*/
node *insertNode(node *head, char data)
{
    node *temp;
    
    if (head == NULL) //if there is no head, we create one.
    {
        return createNode(data);
    }

    temp = findTail(head);
    temp->next = createNode(data);
	
    return head;
}

/*
*	returns a node.
*	takes in the char to be created.
*/
node *createNode(char data)
{
    node *temp = malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

/*
*	print string (based on Dr. Szumlanski's recursive print).
*/
void printList(node *head)
{
    if (head == NULL)
    {
        printf("(empty string)\n");
        return;
    }

    recursivePrint(head);
    printf("\n");

}

/*
*	recursive print function (based on Dr. Szumlanski's recursive print).
*/
void recursivePrint(node *head)
{
    if (head == NULL)
        return;

    printf("%c", head->data);

    recursivePrint(head->next);
}

/*
*	returns the tail. takes in the head.
*/
node *findTail(node *head)
{
	if (head == NULL)
	{
		return NULL;
	}
    node *temp;

    for (temp = head; temp->next != NULL; temp = temp->next)
        ;

    return temp;
}

/*
*	returns the head. takes in head and char(key).
*	searches through linked list for nodes with key and removes it. then
*	we link the one before and after the removed together.
*/
node *deleteNode(node *head, char key)
{
	node *current = head;
	node *tempDel = NULL;

	if (head == NULL)
	{
		return head;
	}
	
	while (current != NULL)
	{
		if (current->data == key) //checking head
		{
			tempDel = current; //copy head to tempDel
			head = current = current->next; //set head's next as new head
			free(tempDel); //clean up the old head
		}
		//check the next node and delete if it's a match
		else if (current->next != NULL && current->next->data == key)
		{
			tempDel = current->next; 
			current->next = current->next->next;
			free(tempDel);
		}
		else
		{
			current = current->next;
		}		
	}
	return head;
}

