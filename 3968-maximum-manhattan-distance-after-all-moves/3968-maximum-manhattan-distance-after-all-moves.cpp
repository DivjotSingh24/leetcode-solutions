class Solution {
public:
    int maxDistance(string moves) {
        int vertical=0;
        int horizontal=0;
        int blank=0;
        for(char c: moves){
            if(c=='U')
                vertical++;
            if(c=='D')
                vertical--;
            if(c=='L')
                horizontal--;
            if(c=='R')
                horizontal++;
            if(c=='_')
                blank++;
        }
        return abs(horizontal)+abs(vertical)+blank;
    }
};