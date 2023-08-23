#include "main.h"
/**
 * init_params - clearstruct field and reset buffer
 * @params: parameters
 * @ptr: argument pointer
 */
void init_params(params_t *params, va_list ptr)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->minus_flag = 0;
	params->space_flag = 0;
	params->zero_flag = 0;
	params->hashtag_flag = 0;
	params->h_modifier = 0;
	params->l_modifier = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	(void) ptr;
}
