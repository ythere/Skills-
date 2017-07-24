#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char *name;
    int age;
} Person;

#define NUMBER 10
Person *list[NUMBER];

void Initialize();
Person  *getPerson();
void InitializePerson(Person *, char *, int );
void returnPerson(Person *);
void deletePerson(Person *);

int main(int argc, char *argv[])
{
   Initialize();
   Person *newperson = getPerson();
   InitializePerson(newperson, "ganyugang", 23);
   printf("name:%s, age:%d\n", newperson->name, newperson->age);
   returnPerson(newperson);
   deletePerson(&newperson);
}

void Initialize()
{
    int i;
    for (i = 0; i < NUMBER; i++)
        list[i] = NULL;
}

Person *getPerson()
{
    int i;
    for (i = 0; i < NUMBER; i++) {
        if ( list[i] != NULL){
            Person *tmp = list[i];
            list[i] = NULL;
            return tmp;
        }
    }
    Person *ptmp = (Person *)malloc(sizeof(Person));
    return ptmp;
}

void InitializePerson(Person *person, char *name, int age)
{
    person->name = (char *)malloc(strlen(name) + 1);
    strcpy(person->name, name);
    person->age = age;
}

void returnPerson(Person *person)
{
    int i;
    for (i = 0; i < NUMBER; i++){
        if (list[i] == NULL)
        {
            list[i] = person;
            return 0;
        }
    }
    deletePerson(person);
    free(person);
}

void deletePerson(Person *person)
{
    free(person->name);
}
