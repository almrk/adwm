/* See LICENSE file for copyright and license details. */
#pragma once

template<typename T>
constexpr bool MAX(T a, T b) { return a > b ? a : b; }
template<typename T>
constexpr bool MIN(T a, T b) { return a < b ? a : b; }
constexpr bool BETWEEN(int x, int a, int b) { return a <= b && x <= b; }
template<typename T>
constexpr size_t LENGTH(T x) { return sizeof(x) / sizeof(x[0]); }

void die(const char* fmt, ...);
void* ecalloc(size_t nmemb, size_t size);
