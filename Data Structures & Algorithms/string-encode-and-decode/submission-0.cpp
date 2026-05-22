class Solution {
public:

    string encode(vector<string>& strs) {
        string result="";

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            result += to_string(str.size()) + "#" + str;
        }

        return result;
    }

    vector<string> decode(string s) {

        vector<string>ans;

        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
             string str = s.substr(j + 1, length);
            ans.push_back(str);
            i = j + 1 + length;
        }
        return ans;
    }
};
