#include <string.h>
#include "../includes/stringmanip.h"
#include "../includes/constants.h"

namespace KP {

int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace,
		int len_tag, int len_tag_replacement) {

	int output = 0;

	output = len_src - (numbTagsToReplace * len_tag)
			+ (numbTagsToReplace * len_tag_replacement);

	return output + 1;

}

int replace(const char *src, char *new_src, const char *tag,
		const char *tag_replacement) {

	if (src == NULL || new_src == NULL || tag == NULL || tag_replacement == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}

	int src_len = strlen(src);
	int tag_len = strlen(tag);
	int tagr_len = strlen(tag_replacement);
	int i = 0;
	int j = 0;
	while (i < src_len) {
		if (*(src + i) == tag[0]) {
			if (strncmp((src + i), tag, tag_len) == 0) {

				strncat((new_src + j), tag_replacement, tagr_len);
				i += tag_len;
				j += tagr_len;

				*(new_src + j) = *(src + i);

			}
		}
		*(new_src + j) = *(src + i);
		j++;

		i++;

	}
	return SUCCESS;
}

int findNumbOccurrences(const char *src, const char *tag) {

	if (src == NULL || tag == NULL) {
		return INVALID_NULL_PTR_DETECTED;
	}

	int src_len = strlen(src);
	int tag_len = strlen(tag);
	int i = 0;
	int count = 0;
	while (i < src_len) {
		if (*(src + i) == tag[0]) {
			if (strncmp((src + i), tag, tag_len) == 0) {
				count++;
			}
		}
		i++;
	}
	return count;
}
}
