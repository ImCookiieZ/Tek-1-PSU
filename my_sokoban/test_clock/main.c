#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>

int main()
{
    sfClock *clock = sfClock_create();
    sfTime clockTime;
    long long now = 0;
    long long prev = 0;
    for (int i = 0; i < 100000000; i++) {
        clockTime = sfClock_getElapsedTime(clock);
        now = clockTime.microseconds / 1000000;
        if (now > prev)
            printf("Seconds : %lld\n", now);
        prev = now;
    }
    return (0);
}