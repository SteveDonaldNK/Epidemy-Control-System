typedef enum {
    CONTAMINATION,
    HEAL,
    DEATH
} evt_type;

typedef struct DATE {
    int day;
    int month;
    int year;
}Date;

typedef struct EVENT {
    int SSN;
    Date event_date;
    evt_type type;
}Event;

