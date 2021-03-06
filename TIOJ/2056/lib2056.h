#ifndef LIB2056J_H_INCLUDED
#define LIB2056J_H_INCLUDED

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <cmath>
#include <iostream>

#define t                  TIOJ_2056_varible_t_FaBcemwhV98OHG3sJAPC
#define n                  TIOJ_2056_varible_n_dqfpkwbgDWTTKjqGXU8Q
#define p                  TIOJ_2056_varible_p_1PDfbLsRLcvhUBzHNBhF
#define q                  TIOJ_2056_varible_q_xwFGL757CUC6tu7tIaTk
#define r                  TIOJ_2056_varible_r_ZuGWHvKaWXABnj0Gs5mN
#define qc                 TIOJ_2056_varible_qc_2U7IYEowCk5QI8PG0Oig
#define qnow               TIOJ_2056_varible_qnow_uDSqCVPkaGAXjVTDZXbX
#define qlimit             TIOJ_2056_varible_qlimit_twHumqIBGBtYola0De1G
#define win                TIOJ_2056_varible_win_Q5aKFEr8tMRG9jH6CjHd
#define lost               TIOJ_2056_varible_list_rcuUErStZe7zxRyEP6rO
#define qt                 TIOJ_2056_varible_qt_NQAVaSkHTAE0RGrwBCRD
#define rat                TIOJ_2056_varible_rat_X1Ct8aYzAs1QntrI3DYM
#define winning_percentage TIOJ_2056_varible_winning_percentage_F7J0uPMwBTnWl11b05FR
#define v                  TIOJ_2056_varible_v_XTWTyNNYolLjtutzXx71
#define correct            TIOJ_2056_varible_correct_A1hxhz5eNAXSZDuq5rya
#define AC                 TIOJ_2056_function_AC_apcIEP76sp2d2BZEsOfM
#define Win                TIOJ_2056_function_Win_EoQJRxUqBmjWWXG6xBsI

int t, n, *p, *q, *r, qc, qnow, limit, win, lose, qt;
double rat, winning_percentage;
bool *v, correct;

void AC() { puts("Yeah you got an 6MQ91zu46JGgSz9vhoKY"); }
void WA() { puts("No you got a WA"); }
void Win() { ++win; }
void Lose() { ++lose; }

/* void generate_permutation() {
    while (true) {
        std::random_shuffle(p, p + n);
        memset(v, false, sizeof(bool) * n);
        bool valid = true;
        for (int i = 0; i < n; ++i) if (!v[i]) {
            int cycle_length = 0;
            int now = i;
            while (!v[now]) v[now] = true, ++cycle_length, now = p[now];
            valid &= (cycle_length <= limit);
        }
        if (valid) break;
    }
} */

int Testcase() {
    srand(time(nullptr));
    scanf("%d", &t);
    scanf("%d %lf %lf", &n, &rat, &winning_percentage);
    qt = 0;
    return t;
}

int Init() {
    ++qt;
    p = new int[n]; q = new int[n]; v = new bool[n];
    for (int i = 0; i < n; ++i) p[i] = i, q[i] = i;
    std::random_shuffle(q, q + n);
    std::random_shuffle(p, p + n);
    qc = 0; qnow = 0;
    limit = ceil(rat * n);
    // printf("%d\n", limit);
    // generate_permutation();
    correct = true;
    return n;
}

int Query(int pos) {
    if (pos < 0 || pos >= n) correct = false;
    ++qc;
    if (qc > limit) correct = false;
    return p[pos];
}

void Answer(int pos) {
    if (p[pos] != qnow) correct = false;
    // else if (p[pos] == qnow && correct) Win();
    qnow++;
    if (qnow == n) {
        if (correct) Win();
        else Lose();
        if (qt == t) {
            double percentage = 1.0 * win / (win + lose);
            if (percentage >= winning_percentage) AC();
            else WA();
            exit(0);
        }
        delete p; delete q; delete v;
        p = nullptr; q = nullptr; v = nullptr;
        return;
    }
    qc = 0;
    r = new int[n];
	std::random_shuffle(q, q + n);
    for (int i = 0; i < n; ++i) r[i] = p[i];
    for (int i = 0; i < n; ++i) p[q[i]] = q[r[i]];
    // for (int i = 0; i < n; ++i) printf("%2d ",i); std::cout << std::endl;
    // for (int i = 0; i < n; ++i) printf("%2d ",p[i]); std::cout << std::endl;
    delete r; 
}

#undef t
#undef n
#undef p
#undef q
#undef r
#undef qc
#undef qnow
#undef qlimit
#undef win
#undef lost
#undef qt
#undef rat
#undef winning_percentage
#undef v
#undef correct
#undef AC
#undef Win

#endif

