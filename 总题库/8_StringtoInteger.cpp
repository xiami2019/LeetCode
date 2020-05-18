class Solution{
    public:
        int myAtoi(string str){
            bool nagetive = false;
            int index = 0; //索引；
            long long result = 0;
            
            while (index < str.size() && str[index] == ' '){
                index++;
            } //指向第一个非空格字符；
            
            if (index == str.size()){
                return 0;
            }
            
            if (str[index] == '-'){
                nagetive = true;
                index++;
            }
            else if (str[index] == '+'){
                nagetive = false;
                index++;
            }

            while (index < str.size() && isdigit(str[index])){
                result = result * 10 + str[index++] - '0';
                if (result >= 2147483648){
                    if (nagetive) return INT_MIN;
                    else return INT_MAX;
                }
            }
            return nagetive ? result * (-1) : result;
        }
};
