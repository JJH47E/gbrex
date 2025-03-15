#ifndef GLOBALS_C
#define GLOBALS_C

#define GROUND_Y 120
#define GRAVITY 1

typedef void (*ScoreIncrementFunction)();

ScoreIncrementFunction increment_score_callback;

void set_increment_score_callback(ScoreIncrementFunction callback) {
    increment_score_callback = callback;
}

#endif