#ifndef PROF_H
#define PROF_H

//! Программное 32-битное сложение
void sadd32(float *, float *, float *);

//! Программное 32-битное умножение
void smul32(float *, float *, float *);

//! Программное 64-битное сложение
void sadd64(double *, double *, double *);

//! Программное 64-битное умножение
void smul64(double *, double *, double *);

//! Программное 80-битное сложение
void sadd80(long double *, long double *, long double *);

//! Программное 80-битное умножение
void smul80(long double *, long double *, long double *);

//! Аппаратное 32-битное сложение
void hadd32(float *, float *, float *);

//! Аппаратное 32-битное умножение
void hmul32(float *, float *, float *);

//! Аппаратное 64-битное сложение
void hadd64(double *, double *, double *);

//! Аппаратное 64-битное умножение
void hmul64(double *, double *, double *);

//! Аппаратное 80-битное сложение
void hadd80(long double *, long double *, long double *);

//! Аппаратное 80-битное умножение
void hmul80(long double *, long double *, long double *);

#endif // PROF_H
