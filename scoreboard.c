#ifndef SCOREBOARD_C
#define SCOREBOARD_C

uint16_t score = 0;

void increment_score() {
    score++;
}

void reset_score() {
    score = 0;
}

#endif