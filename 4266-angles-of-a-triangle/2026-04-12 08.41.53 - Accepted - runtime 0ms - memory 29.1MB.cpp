class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a=sides[0];
        double b=sides[1];
        double c=sides[2];
        if(!(a+b>c && a+c>b && b+c>a)){
            return {};
        }
        double aA=acos((b*b+c*c-a*a)/(2*b*c));
        double aB=acos((a*a+c*c-b*b)/(2*a*c));
        double aC=acos((a*a+b*b-c*c)/(2*a*b));
        const double pi=acos(-1.0);
        double deg=180.0/pi;
        vector<double> ang={
            aA*deg, aB*deg, aC*deg
        };
        sort(ang.begin(),ang.end());
        return ang;
    }
};