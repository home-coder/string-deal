#include <stdio.h>
#include <stdlib.h>

#define FIRST_TEST_STR {\
	"str is ok", \
	"srr is not ok", \
	"str 2 is ok", \
	"stt not ok", \
	"\0"\
	}

#define SECOND_TEST_STR {\
	"sstr nn ok", \
	"strstrstr", \
	"tstr nnn", \
	"tt str", \
	"\0" \
	}
/*
	#----------请反复重构------------#

	1.接收处理的字符串
	2.提取str开头的字符串
	3.截取前6个字符,组成新的字符串
	4.替换str为xplan
	5.替换xplan开头的字符串后半部分为good，并空格 eg: "xplan good"
	6.每一个xplan开头的字符串前面添加i hope, 如"i hope xplan good"
	7.将上面的字符串每一个含有"i hope xplan good"后面添加":"
	8.将上面的字符串以 ： 分隔符截取出来。
*/

struct strmachine {
	char ***test_data;
	void (*do_test)(struct strmachine *strm);
	char** (*get_str)(char ***get_str);
	void (*clip_six)(char **clip_str, char *new_str);
}; 

char** inner_get_str(char *test_str[][10], int col)
{
	int i, j, wid = 0;
	int row = (int)sizeof(test_str) / sizeof(test_str[0]);
	char **ret_str = (char **)malloc(sizeof(char *) * row * col);
	for (wid = 0; wid < row * col; wid++) {
		*ret_str = (char *)malloc(sizeof(char) * 32);
	}

	wid = 0;
	printf("debug1:%d, %d\n", (int)sizeof(test_str), (int)sizeof(test_str[0]));
	for (j = 0; j < (int)(sizeof(test_str) / sizeof(test_str[0])); j++) {
		for (i = 0; (i < col) && (test_str[j][i] != NULL); i++) {
			ret_str[wid] = test_str[j][i];
			printf("debug:%s\n", test_str[j][i]);
		}
		wid++;
	}

	return ret_str;
}

void inner_clip_six(char **clip_str, char *new_str)
{

}

void inner_do_test(struct strmachine *strm)
{
	char *first[] = FIRST_TEST_STR;
	char *second[] = SECOND_TEST_STR;
	//char *tmp[][10] = {FIRST_TEST_STR, SECOND_TEST_STR};
	char **tmp[][5] = {first, second};
	printf("tmp0 %s, tmp1 %s\n", *tmp[0][0], *tmp[0][1]);
	printf("degug:%d, %d\n", (int)sizeof(tmp), (int)sizeof(tmp[0]));
	char** str_get;
	str_get = inner_get_str(tmp, 10);
}

int main()
{
	struct strmachine strmach;

	strmach.get_str = inner_get_str;
	strmach.clip_six = inner_clip_six;

	strmach.do_test = inner_do_test;
	strmach.do_test(&strmach);

	return 0;
}
