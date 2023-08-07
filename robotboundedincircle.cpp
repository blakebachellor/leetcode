#include <iostream>
#include <string>

using namespace std;


class Solution {

private: 
    static void moveRobot(int* x, int* y, int bear) {
        switch (bear) {
            case 0: //North
            case -360:
                *y += 1;
                break;
            case 90: //West
            case -270:
                *x -= 1;
                break;
            case 180: //South
            case -180:
                *y -= 1;
                break;
            case 270: //East
            case -90:
                *x += 1;
                break;
        }
    }

    static bool isHome(int x, int y) {
        return x == 0 && y == 0;
    }

public:
    
    static bool isRobotBounded(string instructions) {
        int x = 0, y = 0, bear = 0;
        for (int i = 0; i < 2; i++) {
            for (char act : instructions) {
                switch (act) {
                    case 'G':
                        moveRobot(&x, &y, bear % 360);
                        break;
                    case 'L':
                        bear += 90;
                        break;
                    case 'R':
                        bear -= 90;
                        break;
                }
            }
            if (isHome(x, y)) {
                return true;
            } 
        }
        return false;
    }
};


int main() {
    string test1 = "GGLLGG";
    string test2 = "GG";
    string test3 = "GL";
    string test4 = "RLLGLRRRRGGRRRGLLRRR";

    //cout << test1 << ": " << Solution::isRobotBounded(test1) << endl;
    //cout << test2 << ": " << Solution::isRobotBounded(test2) << endl;
    //cout << test3 << ": " << Solution::isRobotBounded(test3) << endl;
    cout << test4 << ": " << Solution::isRobotBounded(test4) << endl;

    return 0;
}