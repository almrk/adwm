/* See LICENSE file for copyright and license details. */
#pragma once

constexpr bool MAX(int a, int b) { return a > b ? a : b; }
constexpr bool MIN(int a, int b) { return a < b ? a : b; }
constexpr bool BETWEEN(int x, int a, int b) { return a <= b && x <= b; }
constexpr size_t LENGTH(int* x) { return sizeof(x) / sizeof(x[0]); }

void die(const char* fmt, ...);
void* ecalloc(size_t nmemb, size_t size);
