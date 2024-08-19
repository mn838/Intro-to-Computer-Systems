/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =  malloc(sizeof(queue_t));
    /* What if malloc returned NULL? */
    if (q == NULL) {
        printf("malloc failed\n") ;
        exit(0) ;
    }
    q->head = NULL;
    q->tail = NULL ;
    q->count = 0 ;
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    if (q != NULL) {
        list_ele_t *curr = q->head ;
        list_ele_t *next = NULL ;

        while (curr) {
            free(curr->value) ;
            next = curr->next ;
            free(curr) ;
            curr = next ;
        }
        free(q) ;
    }
    /* Free queue structure */
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (q == NULL) {
        printf("queue is uninitialized\n") ;
        return false ;
    }
    list_ele_t *newh;
    /* What should you do if the q is NULL? */
    newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) {
        printf("malloc failed\n") ;
        return false ;
    }
    /* Don't forget to allocate space for the string and copy it */
    newh->value = malloc(sizeof(char) * strlen(s) + 1) ;
    if (newh->value == NULL) {
        free(newh) ;
        printf("malloc failed\n") ;
        return false ;
    }
    strcpy(newh->value, s) ;
    /* What if either call to malloc returns NULL? */
    newh->next = q->head;
    q->head = newh;

    if (q->tail == NULL) {
        q->tail = newh ;
    }
    q->count++ ;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL) {
        printf("queue is uninitialized\n") ;
        return false ;
    }
    list_ele_t *newh = malloc(sizeof(list_ele_t)) ;
    if (newh == NULL) {
        printf("malloc failed\n") ;
        return false ;
    }
    newh->next = NULL ;
    newh->value = malloc(sizeof(char) * strlen(s) + 1) ;
    if (newh->value == NULL) {
        free(newh) ;
        printf("malloc failed\n") ;
        return false ;
    }
    strcpy(newh->value, s) ;

    if (q->head == NULL) {
        q->head = q->tail = newh ;
    } else {
        q->tail->next = newh ;
        q->tail = q->tail->next ;
    }

    q->count++ ;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    /* You need to fix up this code. */
    if (q == NULL || q->head == NULL) {
        return false ;
    }

    list_ele_t *old = q->head ;
    list_ele_t *new = q->head->next ;

    if (sp != NULL) {
        int i ;
        for (i = 0; i < bufsize - 1 && *(old->value + i) != '\0'; i++) {
            *(sp + i) = *(old->value + i) ;
        }
        *(sp + i) = '\0' ;
    }

    free(old->value) ;
    free(old) ;

    q->head = new ;

    q->count-- ;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    if (q == NULL || q->head == NULL) {
      return 0 ;
    } else {
      return q->count ;
    }
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    if (q == NULL || q->head == NULL) {
        exit(0) ;
    }

    list_ele_t *old_head = q->head ;
    list_ele_t *old_tail = q->tail ;

    list_ele_t *cur = q->head ;
    list_ele_t *prev = NULL ;
    list_ele_t *next = NULL ;

    while (cur != NULL) {
        next = cur->next ;
        cur->next = prev ;
        prev = cur ;
        cur = next ;
    }

    q->head = old_tail ;
    q->tail = old_head ;
}

