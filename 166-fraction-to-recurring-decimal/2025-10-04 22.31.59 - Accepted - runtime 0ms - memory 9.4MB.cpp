class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result = "";
        if((numerator>0) ^ (denominator>0)){
            result += "-";
        }
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);

        result.append(to_string(num/den));
        long long remainder = num%den;
        if(remainder == 0) return result;
        

        result += ".";
        unordered_map<long long, int> rems;

        while(remainder!=0){
            if(rems.find(remainder) != rems.end()){
                int pos = rems[remainder];
                result.insert(pos, "(");
                result += ')';
                break;
            }
            rems[remainder] = result.length();
            remainder = remainder*10;
            result += to_string(remainder/den);
            remainder = remainder%den;
        }
        return result;
    }
};