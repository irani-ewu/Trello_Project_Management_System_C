#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED


/**
 * @file cards.h
 * @brief Header for managing the cards in the Tello_Project_Management_System
 * @author Data_Structures_Project_Group_01
 */

 /**
  * @brief Maximum number of characters allowed for writing description
  */
#define MAX_DESCRIPTION_LENGTH 250

 /**
  * @brief Maximum number of characters allowed for writing name
  */
#define MAX_NAME_LENGTH 30

 /**
  * @brief To make the code readable, function will return DONE means 1
  */
#define DONE 1

 /**
  * @brief To make the code readable, function will return NOT_DONE means 0
  */
#define NOT_DONE 0
#include<stdbool.h>
/**
 * @brief Represents a Card in Trello_Project_Management_System
 */
typedef struct CARD
{
    char name[MAX_NAME_LENGTH]; /**< CARD name */
    char description[MAX_DESCRIPTION_LENGTH]; /**< CARD description */
    struct CARD* next_card; /**< A pointer to the next card */
    struct CARD* prev_card; /**< A pointer to the previous card */
}CARD;

/**
 * @brief Creates a new card in the system
 * @param name The unique name of the card
 * @param description The about information of the new card
 * @return A pointer to the new card
 */
CARD* create_Card(char name[MAX_NAME_LENGTH],char description[MAX_DESCRIPTION_LENGTH]);

/**
 * @brief Insert a new card after the existing one
 * @param head The pointer to the very first card
 */
void add_a_Card(CARD* head);

/**
 * @brief Delete any of the existing card from the system
 * @param head The pointer to the very first card
 * @return A pointer to the new first card, if the very first card removed
 */
CARD* delete_a_Card(CARD* head);

/**
 * @brief Delete the very first card from the system
 * @param head The pointer to the existing first card
 * @return A pointer to the new first card
 */
CARD* delete_First_Card(CARD* head);

/**
 * @brief Delete any of the existing card from the system without the first one
 * @param head The pointer to the very first card
 * @return A pointer to the first card
 */
CARD* delete_Intermediate_or_Last_Card(CARD* head);

/**
 * @brief Check whether the task of this card is done or not
 * @return DONE if the task has been completed, NOT_DONE if that is incomplete
 */
bool checkList();
#endif
