#include<stdio.h>
#include<stdlib.h>
#include"function.h"

int main(void)
{
    char ch;
    int arr_size=0, i, n;
    Date d;

    printf("\n\t\tEnter the number of events to store: ");
    scanf("%d", &n);
    Event evt[n];
    for(i = 0; i < n; i++)
    {
        clrscr();
        printf("\n\t\tEnter the date(in digits): ");
        printf("\n\n\t\tDay: ");
        scanf("%d", &evt[i].event_date.day);
        printf("\n\t\tMonth: ");
        scanf("%d", &evt[i].event_date.month);
        printf("\n\t\tYear: ");
        scanf("%d", &evt[i].event_date.year);
        printf("\n\t\tSelect the type of event");
        printf("\n\n\t\t1 - Contamination");
        printf("\n\n\t\t2 - Heal");
        printf("\n\n\t\t3 - Death\n");
        ch = getch();
        switch(ch)
        {
            case '1':
                evt[i].type = CONTAMINATION;
                break;
            case '2':
                evt[i].type = HEAL;
                break;
            case '3':
                evt[i].type = DEATH;
                break;
            default:
                printf("Invalid Input !");
                break;
        }
    }
    clrscr();
    printf("\n\t\tEnter the date to view event(in digits): ");
    printf("\n\n\t\tDay: ");
    scanf("%d", &d.day);
    printf("\n\t\tMonth: ");
    scanf("%d", &d.month);
    printf("\n\t\tYear: ");
    scanf("%d", &d.year);
    printf("\n\t\tNumber of contaminated people: %d", num_cont(evt, d, n));
    printf("\n\n\t\tNumber of healed people: %d", num_heal(evt, d, n));
    printf("\n\n\t\tNumber of dead people: %d", num_death(evt, d, n));
    recent_evt(evt, d, n);
    getch();

}

