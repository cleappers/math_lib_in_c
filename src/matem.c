#include "matem.h"

int p_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double p_acos(double x) {
  long double result;
  if (x < -1 || x > 1 || check_nan(x)) {
    result = M_NAN;
  } else if (p_fabs(x - 1.) < M_EPS) {
    result = 0;
  } else if (p_fabs(x + 1.) < M_EPS) {
    result = M_MPI;
  } else {
    result = (M_MPI / 2 - p_sin(x));
  }
  return result;
}

int check_nan(double x) { return (x != x); }

long double p_fabs(double x) {
  if (x < 0.0) x = -x;
  return x;
}

long double p_asin(double x) {
  double temp = x, result = x;
  if (x < -1 || x > 1) {
    result = M_NAN;
  } else if (x == -1 || x == 1) {
    result = M_MPI / 2 * x;
  } else {
    for (long double num = 1; p_fabs(temp) > M_EPS; num++) {
      temp *= ((x * x) * (2 * num - 1) * (2 * num - 1)) /
              ((2 * num) * (2 * num + 1));
      result += temp;
    }
  }
  return result;
}

long double atan_range(double x) {
  long double result = x, temp = x, index = 1;
  while (p_fabs(result) > M_EPS) {
    result *= -1 * p_pow(x, 2) * (2 * index - 1) / (2 * index + 1);
    index += 1;
    temp += result;
  }
  return temp;
}

long double p_atan(double x) {
  long double temp = 0;
  /* (x больше 16 значащих цифр) или не определен NAN или INF */
  if ((x >= (double)LLONG_MAX || x <= (double)LLONG_MIN) || x != x) {
    temp = x;
    /* x == 0,  atan равен 0 */
  } else if (x == 0) {
    temp = 0;
    /*  x принадлежит (-1; 1), используется разложение в ряды Маклорена
      (частный случай, рядов Тейлора в окрестности нужной точки) */
  } else if (x < 1 && x > -1) {
    temp = atan_range(x);
    /* x == 1 , atan = PI / 4
  <https://www.rapidtables.com/math/trigonometry/arctan/arctan-of-1.html > */
  } else if (x == 1) {
    temp = M_MPI / 4;
    /* x == -1, atan = -PI / 4, т.к. atan нечетная функция, поэтому
     * atan(-x)=-atan(x) */
  } else if (x == -1) {
    temp = -M_MPI / 4;
    /* x > 0,  т.к. atan определен на промежутке от -PI/2 до PI/2 оно не может
   быть больше этих значений,
   чтобы максимально к ним приблизиться используется ряд Маклорена для точки 1/х
 */
  } else if (x > 1) {
    temp = M_MPI / 2 - atan_range(1 / x);
  } else if (x < -1) {
    temp = -M_MPI / 2 - atan_range(1 / x);
  }
  return temp;
}