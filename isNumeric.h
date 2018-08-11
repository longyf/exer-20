#ifndef IS_NUMERIC_H
#define IS_NUMERIC_H
#include <iostream>
bool scanUnsignedInteger(const char **);
bool scanInteger(const char **);

bool isNumeric(const char *str) {
	if (str == nullptr)
		return false;

	bool numeric = scanInteger(&str);

	if (*str == '.') {
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	if (*str == 'e' || *str == 'E') {
		++str;
		numeric = numeric && scanInteger(&str);
	}

	return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char **str) {
	const char *before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	return *str > before;
}

bool scanInteger(const char **str) {
	if (**str == '+' || **str == '-')
		++(*str);
	return scanUnsignedInteger(str);
}
#endif
