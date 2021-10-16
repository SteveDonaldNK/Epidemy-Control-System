#include"epidemy.h"

int check_date(Date d1, Date d2)
{
    if( d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
        return 1;
    else
        return 0;
}

int day_sep(Date d1, Date d2)
{
    //taking 1 month = 30 days
    int total_days = (d2.year - d1.year) * 365 + (d2.month - d1.month) * 30 + (d2.day - d1.day);

    // In case d1 is more recent than d2
    if (total_days < 0)
        total_days *= -1;

    return total_days;
}

int get_recent(int a,int b,int c)
{
    if(a < b)
    {
        if(a < c)
            return a;
        else
            return c;
    }
    else
    {
        if(b < c)
            return b;
        else
            return c;
    }

}

void recent_evt(Event *e, Date d, int length)
{
    int i,index1 = 0, index2 = 0, index3 = 0;
    int a, b, c;
    int recent = day_sep(d, e[0].event_date);

    for(i = 1; i < length; i++)
    {
        if( (day_sep(d, e[i].event_date) < recent)  && (e[i].type == CONTAMINATION))
            index1 = i;
    }
    for(i = 1; i < length; i++)
    {
        if( (day_sep(d, e[i].event_date) < recent)  && (e[i].type == HEAL))
            index2 = i;
    }
    for(i = 1; i < length; i++)
    {
        if( (day_sep(d, e[i].event_date) < recent)  && (e[i].type == DEATH))
            index3 = i;
    }
    a = day_sep(d, e[index1].event_date);
    b = day_sep(d, e[index2].event_date);
    c = day_sep(d, e[index3].event_date);
    recent = get_recent(a, b, c);
    if(recent == a)
    {
        printf("\n\n\t\tMost recent evnt is a contamination : %d-%d-%d", e[index1].event_date.day, e[index1].event_date.month, e[index1].event_date.year);
    }
    else if(recent == b)
    {
        printf("\n\n\t\tMost recent evnt is heal : %d-%d-%d", e[index2].event_date.day, e[index2].event_date.month, e[index2].event_date.year);
    }
    else
    {
        printf("\n\n\t\tMost recent evnt is Death : %d-%d-%d", e[index3].event_date.day, e[index3].event_date.month, e[index3].event_date.year);
    }

}

int num_cont(Event *e, Date d, int length)
{
    int i,cnt = 0;

    for(i = 0; i < length; i++)
    {
        if((check_date(d, e[i].event_date) == 1) && (e[i].type == CONTAMINATION))
            cnt += 1;
    }

    return cnt;

}

int num_heal(Event *e, Date d, int length)
{
    int i,cnt = 0;

    for(i = 0; i < length; i++)
    {
        if((check_date(d, e[i].event_date) == 1) && (e[i].type == HEAL))
            cnt += 1;
    }

    return cnt;

}

int num_death(Event *e, Date d, int length)
{
    int i,cnt = 0;

    for(i = 0; i < length; i++)
    {
        if((check_date(d, e[i].event_date) == 1) && (e[i].type == DEATH))
            cnt += 1;
    }

    return cnt;

}

void clrscr()
{
    system("cls");
}

