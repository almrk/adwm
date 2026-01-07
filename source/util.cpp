/* See LICENSE file for copyright and license details. */
#include <cerrno>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "util.hpp"

void die(const char* fmt, ...) {
	int savedErrno{ errno };

    va_list ap;
    va_start(ap, fmt);
    std::vfprintf(stderr, fmt, ap);
    va_end(ap);

	if (fmt[0] && fmt[strlen(fmt)-1] == ':')
		std::fprintf(stderr, " %s", strerror(savedErrno));
    std::fputc('\n', stderr);

    std::exit(1);
}

void* ecalloc(size_t nmemb, size_t size) {
	void* p = calloc(nmemb, size);
	if (p == nullptr)
		die("calloc:");
	return p;
}
