class Solution {
public:
    string replaceSpace(string s) {
        int index = 0;
        string resultStr = "";
        while (1){
            if (index >= s.length()){
                break;
            }
            if (s[index] != ' '){
                resultStr += s[index];
            }
            else{
                resultStr += "%20";
            }
            index++;
        }
        return resultStr;
    }
};

class Solution {
public:
    string replaceSpace(string s) {
    string::size_type pos(0);
    while(true){
        if((pos=s.find(" "))!=string::npos)//找到了空格
        s.replace(pos,1,"%20");//替换
        else break;
    }
    return s; 
    }
};
