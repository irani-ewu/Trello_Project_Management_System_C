#ifndef USER_ENTRY_H_INCLUDED
#define USER_ENTRY_H_INCLUDED

/**
 * @file user_entry.h
 * @brief Header for managing user entry
 * @author Data_Structures_Project_Group_01
 */

 /**
  * @brief Maximum number of characters allowed for name and email-id
  */
#define MAX_LENGTH 16

/**
 * @brief Represents a identity of a user
 */
typedef struct USER
{
    char name[MAX_LENGTH]; /**< USER name */
    char email_id[MAX_LENGTH]; /**< USER email id */
}USER;

/**
 * @brief Store the information of the user for further Log In
 */
void registration();

/**
 * @brief Compare the stored information of the user from file to provide access
 */
int log_In();
#endif
