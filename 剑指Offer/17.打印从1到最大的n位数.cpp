// 数字排列的解法
void print1ToMaxOfNDigits (int n) {
    if (n <= 0) return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        print1ToMaxOfNDigitsRecursively(number, n, 0);
    }

    delete[] number;
}

void print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
    if (index == length - 1) {
        // 已经完成了一个全排列，可以打印;
        printNumber(number);
        return;
    }

    for (int i = 0; i < 10; ++i) {
        number[index + 1] = i + '0';
        print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

void printNumber(char* number) {
    bool isBeginning0 = true;
    int numLen = strlen(number);

    for (int i = 0; i < numLen; ++i) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            printf("%c", number[i]);
        }
    }
    printf('\t');
}

// 在字符串上模拟数字的加法
void print1ToMaxOfNDigits(int n) {
    if (n <= 0) return;

    char* number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';

    while (!increment(number)) {
        printNumber(number);
    }

    delete[] number;
}

bool increment(char* number) {
    // 进行加一操作，并且返回一个布尔变量来表示是否发生了溢出
    bool isOverflow = false;
    int nTakeOver = 0; // 进位
    int numLen = strlen(number);
    for (int i = numLen - 1; i >= 0; i--) {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == numLen - 1) {
            // 完成加一操作
            nSum++;
            if (nSum >= 10) {
                // 发生进位
                if(i == 0) {
                    // 第一位发生进位，说明产生了溢出
                    isOverflow = true;
                }
                else {
                    nSum -= 10;
                    nTakeOver = 1;
                    number[i] = '0' + nSum;
                }
            }
            else {
                number[i] = '0' + nSum;
                break;
            }
        }
    }
    return isOverflow;
}

void printNumber(char* number) {
    bool isBeginning0 = true;
    int numLen = strlen(number);
    for (int i = 0; i < numLen; ++i) {
        if (isBeginning0 && number[i] != '0') {
            isBeginning0 = false;
        }
        if (!isBeginning0) {
            printf("%c", number[i]);
        }
    }
    printf('\t');
}