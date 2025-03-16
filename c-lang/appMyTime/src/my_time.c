#include "../includes/my_time.h"

timer tic () {
    timer _tic;
    gettimeofday(&_tic, NULL);
    return _tic;
}

timer tac() {
    return tic();
}

float compTime(timer tic, timer tac) {
    float _t = ((tac.tv_sec - tic.tv_sec) * 1000.0) +
               ((tac.tv_usec - tic.tv_usec) * 0.001);

    return _t;
}