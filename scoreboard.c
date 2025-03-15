#ifndef SCOREBOARD_C
#define SCOREBOARD_C

uint16_t score = 0;

void increment_score() {
    score++;
}

void reset() {
    score = 0;
}

#endif