#include <stdio.h>
#include <conio.h>

enum states { READY, PREPFRE, WAIT, CHANGE, RETURN }; //состояние конечного автомата для варки кофе
enum signals { ONE_RUBLE, TWO_RUBLES, CANCEL, NONE }; //сигналы инициализирующие переход состояний коненчого автомата

enum signals getUserSignal(void) {
    char choice;
    while (1)
    {
        printf("1. Put one ruble\n2. Put two rubles\n0. Cancel\n");
        choice = getche();
        switch (choice)
        {
            case '1': return ONE_RUBLE;
            case '2': return TWO_RUBLES;
            case '0': return CANCEL;
            default:
                printf("Not valid answer\n");
                break;
        }
    }
}

/**
 * @brief 
 * Конечный автомат (КА) — математическая абстракция, модель дискретного устройства, имеющего один вход, один выход и в каждый момент времени находящегося в одном состоянии из множества возможных.
 */
int main(int args, char** argv) {
    enum states state = READY;
    enum signals signal = NONE;

    while (1)
    {
        switch (state)
        {
            case READY:
                printf("READY");
                signal = getUserSignal();
                if (signal == ONE_RUBLE) state = WAIT;
                if (signal == TWO_RUBLES) state = PREPFRE;
                break;
            case PREPFRE:
                printf("PREPFRE. Prepare the coffee...\n");
                state = READY;
                break;
            case WAIT:
                printf("WAIT. Put one more ruble or press cancel to change\n");
                signal = getUserSignal();
                if (signal == ONE_RUBLE) state = PREPFRE;
                if (signal == TWO_RUBLES) state = CHANGE;
                if (signal == CANCEL) state = RETURN;
                break;
            case CHANGE:
                printf("CHANGE. Return one ruble\n");
                state = PREPFRE;
                break;
            case RETURN:
                printf("RETURN. Return one ruble\n");
                state = READY;
                break;
            default:
                break;
        }
    }
}