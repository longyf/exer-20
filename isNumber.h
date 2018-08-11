#ifndef IS_NUMBER_H
#define IS_NUMBER_H
bool isValidElement(const char *);

bool isNumber(const char *str) {
	if (str == nullptr)
		return false;
	else {
		char *ptrTemp = str;
		unsigned int numPoint = 0;
		unsigned int numExp = 0;
		bool appearExp = false;

		while(*ptrTemp != '\0') {
			if (!isValidElement(ptrTemp++)) return false;//检查是否有非法输入。
			else {
				//最多只能出现一个小数点。
				if (*ptrTemp == '.') numPoint++;
				if (numPoint > 1) return false;

				//最多只能出现一个E/e。
				if (*ptrTemp == 'E' || *ptrTemp == 'e') {
					numExp++;
					appearExp = true;
				}
				else {
					appearExp = false;
				}

				// E/e的后面不可有小数存在。
				if (numExp == 1) {
					if (*ptrTemp == '.') return false;
				}
				if (numExp > 1) return false;
			}
		}
		// E/e的后面不能什么都没有。
		if (appearExp) return false;
	}
}

bool isValidElement(const char *ch1) {
	if (ch1 == nullptr) return false;
	if ( (*ch1 >= 48 && *ch1 <= 57) || (*ch1 == 'e') || (*ch1 == 'E') || (*ch1 == '.') || (*ch1 == '+') || (*ch1 == '-') ) return true;
	else return false;
}
#endif
