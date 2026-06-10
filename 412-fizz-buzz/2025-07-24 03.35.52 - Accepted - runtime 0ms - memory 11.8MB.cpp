class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> answer;
        for(int i=0;i<n;i++){
            int p=i+1;
if(p%3==0 && p%5==0){
    answer.push_back("FizzBuzz");
}
            else if (p%3==0){
                answer.push_back("Fizz");

            }
            else if(p%5==0){
                answer.push_back("Buzz");
            }
            else{
                answer.push_back(to_string(p));
            }
        }

      return answer;  
    }
};