/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#ifndef INCLUDE_hash_hash_openssl_h__
#define INCLUDE_hash_hash_openssl_h__

#include "common.h"

#include "hash.h"

#include <openssl/sha.h>

struct git_hash_ctx {
	SHA_CTX c;
};

#endif
