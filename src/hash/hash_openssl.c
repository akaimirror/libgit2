/*
 * Copyright (C) the libgit2 contributors. All rights reserved.
 *
 * This file is part of libgit2, distributed under the GNU GPL v2 with
 * a Linking Exception. For full terms see the included COPYING file.
 */

#include "hash_openssl.h"

int git_hash_global_init(void)
{
	return 0;
}

int git_hash_ctx_init(git_hash_ctx *ctx)
{
	return git_hash_init(ctx);
}

void git_hash_ctx_cleanup(git_hash_ctx *ctx)
{
	GIT_UNUSED(ctx);
}

int git_hash_init(git_hash_ctx *ctx)
{
	assert(ctx);

	if (SHA1_Init(&ctx->c) != 1) {
		git_error_set(GIT_ERROR_SHA1, "hash_openssl: failed to initialize hash context");
		return -1;
	}

	return 0;
}

int git_hash_update(git_hash_ctx *ctx, const void *data, size_t len)
{
	assert(ctx);

	if (SHA1_Update(&ctx->c, data, len) != 1) {
		git_error_set(GIT_ERROR_SHA1, "hash_openssl: failed to update hash");
		return -1;
	}

	return 0;
}

int git_hash_final(git_oid *out, git_hash_ctx *ctx)
{
	assert(ctx);

	if (SHA1_Final(out->id, &ctx->c) != 1) {
		git_error_set(GIT_ERROR_SHA1, "hash_openssl: failed to finalize hash");
		return -1;
	}

	return 0;
}
