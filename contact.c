#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "populate.c"

void listContacts(AddressBook *addressBook)
{
	if(addressBook->contactCount == 0) {
        printf("No contacts found.\n");
        return;
    }
    for(int i=0; i<addressBook->contactCount; ++i) {
        printf("Contact %d:\n", i+1);
        printf("Name: %s\n", addressBook->contacts[i].name);
        printf("Phone: %s\n", addressBook->contacts[i].phone);
        printf("Email: %s\n", addressBook->contacts[i].email);
        printf("-------------------------\n");
    }

}

void createContact(AddressBook *addressBook)
{
    if(addressBook->contactCount >= 100) {
        printf("Address book is full. Cannot add more contacts.\n");
        return;
    }
    Contact newContact;
    printf("Enter name: ");
    fgets(newContact.name, sizeof(newContact.name), stdin);
    newContact.name[strcspn(newContact.name, "\n")] = '\0'; // Remove newline

    printf("Enter phone: ");
    fgets(newContact.phone, sizeof(newContact.phone), stdin);
    newContact.phone[strcspn(newContact.phone, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(newContact.email, sizeof(newContact.email), stdin);
    newContact.email[strcspn(newContact.email, "\n")] = '\0'; // Remove newline

    addressBook->contacts[addressBook->contactCount++] = newContact;
}

void searchContact(AddressBook *addressBook)
{
    char searchName[50];
    printf("Enter name to search: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    int found = 0;
    for(int i=0; i<addressBook->contactCount; ++i) {
        if(strcmp(addressBook->contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
}

void editContact(AddressBook *addressBook)
{
    char searchName[50];
    printf("Enter name of contact to edit: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    int found = 0;
    for(int i=0; i<addressBook->contactCount; ++i) {
        if(strcmp(addressBook->contacts[i].name, searchName) == 0) {
            printf("Contact found:\n");
            printf("Name: %s\n", addressBook->contacts[i].name);
            printf("Phone: %s\n", addressBook->contacts[i].phone);
            printf("Email: %s\n", addressBook->contacts[i].email);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
}

void deleteContact(AddressBook *addressBook)
{
    char searchName[50];
    printf("Enter name of contact to delete: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Remove newline

    int found = 0;
    for(int i=0; i<addressBook->contactCount; ++i) {
        if(strcmp(addressBook->contacts[i].name, searchName) == 0) {
            // Shift remaining contacts left
            for(int j=i; j<addressBook->contactCount-1; ++j) {
                addressBook->contacts[j] = addressBook->contacts[j+1];
            }
            addressBook->contactCount--;
            printf("Contact deleted successfully.\n");
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Contact not found.\n");
    }
}
