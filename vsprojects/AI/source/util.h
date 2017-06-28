#pragma once

template <typename T> class Iterator;
template <typename T> class Collection;
template <typename T> class Comparable;

#include "util-iterator.h"
#include "util-comparable.h"
#include "util-collection.h"

/*
//http://create.stephan-brumme.com/fnv-hash/

/// hash a C-style string
uint32_t fnv1a(const char* text, uint32_t hash = Seed)
{
assert(text);
while (*text)
hash = fnv1a((unsigned char)*text++, hash);
return hash;
}
/// hash an std::string
uint32_t fnv1a(const std::string& text, uint32_t hash = Seed)
{
return fnv1a(text.c_str(), text.length(), hash);
}
*/