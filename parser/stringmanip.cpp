
#include <string.h>
#include "../includes/stringmanip.h"
#include "../includes/constants.h"

namespace KP{


int amountOfMemoryToAllocateForNewString(int len_src, int numbTagsToReplace, int len_tag, int len_tag_replacement){

	int output = 0;

	output = len_src - (numbTagsToReplace * len_tag) + (numbTagsToReplace * len_tag_replacement);

	return output + 1;

}

/**
	 * If src,new_src, tag or tag_replacment are null then returns INVALID_NULL_PTR_DETECTED
	 *
	 * Copies src char string to new_src char string, replaces all tag occurrences with tag_replacement.
	 * Please ensure that new_src is allocated and of proper size before calling this function
	 *
	 * ex.
	 * 	src ="a large bucket on a large ship"
		tag="large"
		tag_replacement="really large"
		then when the function returns
		new_src="a really large bucket on a really large ship"
	 *
	 * \param src  initial char string, may be deleted and reallocated by this function
	 * \param new_src char string with enough space to hold src string with all tag occurrences replaced by tag_replacement
	 * \param tag  the tag to search for
	 * \param tag_replacement  replaces all occurrences of tag
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, tag or tag_replacement is NULL
	 * 		   SUCCESS everything went well, src contains the
	 */

int replace(const char *src, char *new_src, const char *tag, const char *tag_replacement){

	if (src == NULL|| new_src == NULL || tag == NULL || tag_replacement ==NULL){
		return INVALID_NULL_PTR_DETECTED;
	}

	//char *output = new char(amountOfMemoryToAllocateForNewString())
	int src_len = strlen(src);
	int tag_len = strlen(tag);
	int tagr_len = strlen(tag_replacement);
	int i = 0;
	int j = 0;
	while (i < src_len){
		if(*(src + i) == tag[0]){
			if(strncmp((src+i), tag, tag_len) == 0){

				strncat((new_src + j), tag_replacement, tagr_len);
				i+= tag_len;
				j+=tagr_len;
				*(new_src +j) = *(src + i);

			}
		}
		i++;

	}
	return SUCCESS;
}

/**
	 * how often does the string in tag occur in src?
	 *
	 * \param src  initial char string
	 * \param tag  the tag to search for
	 * \return INVALID_NULL_PTR_DETECTED one or more of src, or tag is NULL
	 *         otherwise the number of times tag occurs in src
	 */
int findNumbOccurrences(const char *src,  const char *tag){

	if (src == NULL|| tag == NULL){
			return INVALID_NULL_PTR_DETECTED;
		}

	int src_len = strlen(src);
	int tag_len = strlen(tag);
	int i =0;
	int count =0;
	while (i < src_len){
			if(*(src + i) == tag[0]){
				if(strncmp((src+i), tag, tag_len) == 0){
					count++;
				}
			}
			i++;
	}
	return count;
}
}
