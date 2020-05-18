/*
本题可采用《编译原理》里面的确定的有限状态机（DFA）解决。构造一个DFA并实现，构造方法可以先写正则表达式，然后转化为DFA，也可以直接写。
*/
//解法一：构造DFA，使用状态转换表判断输入的字符串是否合法；
class Solution {
public:
    bool isNumber(string s) {
        int state = 0;
        int finals = 0b101101000;
        int transfer[][] = {{ 0, 1, 6, 2,-1},
                            {-1,-1, 6, 2,-1},
                            {-1,-1, 3,-1,-1},
                            { 8,-1, 3,-1, 4},
                            {-1, 7, 5,-1,-1},
                            { 8,-1, 5,-1,-1},
                            { 8,-1, 6, 3, 4},
                            {-1,-1, 5,-1,-1},
                            { 8,-1,-1,-1,-1}};
    }
};

//解法二：写出正则表达式，按照正则表达式的步骤逐步判断：
class Solution {
public:
    bool isNumber(string &s) {
        // regex r("\\s*[+-]?(\\d+\\.?\\d*|\\.\\d+)(e[+-]?\\d+)?\\s*$");
        int index = s.find_first_not_of(' ');
        int d1=0, dot=0, d2=0, e=0, d3=0;
        if (s[i]=='+' || s[i]=='-'){
            ++i;
        }
        for(; i<s.length() && isdigit(s[i]); d1=++i);
        if(i<s.length() && s[i]=='.') dot=++i;
        for(; i<s.length() && isdigit(s[i]); d2=++i);
        if(dot && !d1 && !d2) return false;
        if(i<s.length() && (d1||d2) && s[i]=='e') e=++i;
        if(i<s.length() && e && (s[i]=='+'|s[i]=='-')) ++i;
        for(; i<s.length() && isdigit(s[i]); d3=++i);
        if(e && (!(d1||d2) || !d3)) return false;
        for(; i<s.length() && s[i]==' '; ++i);
        return i==s.length();
    }
};

//解法三：直接法：把当前的输入分成几类，再用几个标志位来判断当前位置是否合法。
class Solution {
public:
    bool isNumber(string &s) 
    {
        if (s.empty()) return false;
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        bool point = false;
        bool e = false;
        bool number = false;
        bool numberAfterE = true;
        for (int i = 0; i < s.length(); i++){
            if (isdigit(s[i])){
                number = true;
                numberAfterE = true;
            }
            else if (s[i] == '.'){
                if (e || point){
                    return false;
                }
                point = true;
            }
            else if (s[i] == 'e'){
                if (e || !number){
                    return false;
                }
                numberAfterE = false;
                e = true;
            }
            else if (s[i] == '-' || s[i] == '+'){
                if (i != 0 && s[i-1] != 'e'){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return number && numberAfterE;
    }
};

//或者直接遍历,按可能出现的情况的顺序判断当前输入是否合法，把遇到不符合的都返回false，到最后成功到达末尾就返回true。
class Solution {
public:
    bool isNumber(string &s) 
    {
        int i = 0;

        //skip the whilespace;
        for (; s[i] == ' '; i++);

        //check the sign if exist;
        if (s[i] == '+' || s[i] == '-') i++;

        //a trick
        int n_nm, n_pt;
        for (n_nm = 0, n_pt = 0; isdigit(s[i]) || s[i] == '.'; i++){
            s[i] == '.' ? n_pt++ : n_nm++;
        }
        if (n_pt > 1 || n_nm < 1) return false;

        //check the exponent if exist
        if (s[i] == 'e'){
            i++;
            if (s[i] == '+' || s[i] == '-') i++;

            int n_nm = 0;
            for (; isdigit(s[i]); i++, n_nm++);
            if (n_nm < 1) return false;
        }

        //skip the trailing whitespaces
        for (; s[i] == ' '; i++);

        return s[i] == 0;
    }
};
