#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

/**
 * @file search.h
 * @brief Header for searching the cards or lists in the Tello_Project_Management_System
 * @author Data_Structures_Project_Group_01
 */

#include"lists.h"
#include"cards.h"

/**
 * @brief Search the desired list from the system
 * @param head The pointer to the very first list
 * @param desired_List The name of the list to search
 */
void search_List(LIST* head,char desired_List[MAX_NAME_LENGTH]);

/**
 * @brief Search the desired card from the system
 * @param head The pointer to the very first card
 * @param desired_List The name of the card to search
 */
void search_Card(CARD* head, char desired_Card[MAX_NAME_LENGTH]);
#endif
