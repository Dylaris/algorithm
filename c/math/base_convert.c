/*
 * NAME
 ** Base Convert
 *
 * PURPOSE
 ** Convert a dicimal to a n-based number string
 * 
 * PSEUDO-CODE
 ** IF n is zero:
 **   RETURN "0"
 ** IF n is negative:
 **   RETURN "-" + result generated by positive case
 ** ans = ""
 ** WHILE n is not zero:
 **   ans = n % base + ans
 **   n = n // base
 ** RETURN ans
 *
 * COST
 ** time:  O(log |n|)
 ** space: O(log |n|) -> use char array to store result
 **        or O(log 1) -> modify the string directly
 */

#include <stdio.h>

static void base_convert(char *buf, int n, int base)
{
    char characters[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    };

    if (n == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    int is_negative = 0;
    if (n < 0) {
        is_negative = 1;
        n = -n;
    }

    int pos = 0;
    while (n) {
        buf[pos++] = characters[n % base];
        n /= base;
    }

    if (is_negative) buf[pos++] = '-';
    buf[pos] = '\0';
}

int main(void)
{
    char buf[100];  /* Store the result with reverse order */

    base_convert(buf, 100, 7);
    printf("100(7): %s\n", buf);
    base_convert(buf, -100, 7);
    printf("-100(7): %s\n", buf);
    base_convert(buf, 100, 6);
    printf("100(6): %s\n", buf);

    return 0;
}
