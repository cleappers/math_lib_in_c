#ifndef MATEM_H_
#define MATEM_H_

#include <limits.h>

#define M_EPS 1e-17
#define M_MPI 3.141592653589793238462643383
#define M_EPSEQ 1e-07
#define M_LN10 2.30258509299404590109
#define M_NAN 0.0 / 0.0
#define M_INFINITY 1.0 / 0.0

int p_abs(int x);  // вычисляет абсолютное значение целого числа

long double p_acos(double x); /* вычисляет арккосинус */
long double p_asin(double x); /* вычисляет арксинус */
long double p_atan(double x); /* вычисляет арктангенс */
long double p_ceil(double x); /* возвращает ближайшее целое число, не меньшее */
                              /* заданного значения */
long double p_cos(double x);  /* вычисляет косинус */
long double p_exp(
    double x); /* возвращает значение e, возведенное в заданную степень */
long double p_fabs(
    double x); /* вычисляет абсолютное значение числа с плавающей точкой */
long double p_floor(double x); /* возвращает ближайшее целое число, не
                                превышающее заданное значение */
long double p_fmod(double x,
                   double y); /* остаток операции деления с плавающей точкой */
long double p_log(double x); /* вычисляет натуральный логарифм */
long double p_pow(double base,
                  double exp); /* возводит число в заданную степень */
long double p_sin(double x); /* вычисляет синус */
long double p_sqrt(double x); /* вычисляет квадратный корень */
long double p_tan(double x); /* вычисляет тангенс */

// функция для проверки значений на равенстов одного того же числа
int check_nan(double x);
#endif  // MATEM_H_