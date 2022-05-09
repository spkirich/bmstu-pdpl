#ifndef PROC_H
#define PROC_H

//! Программное 32-битное сложение
float sadd32(float, float);

//! Аппаратное 32-битное сложение
float hadd32(float, float);

//! Программное 64-битное сложение
double sadd64(double, double);

//! Аппаратное 64-битное сложение
double hadd64(double, double);

//! Программное 80-битное сложение
long double sadd80(long double, long double);

//! Аппаратное 80-битное сложение
long double hadd80(long double, long double);

#define // PROC_H
