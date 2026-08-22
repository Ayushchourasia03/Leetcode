// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
//         int count5 =0 ; 
//         int count10 = 0; 
//         int count20 = 0;
//         int n = bills.size();

//         for(int i=0;i<n;i++){
//             // sum = sum + arr[i];
//             if(bills[i]==5){
//                 return true;
//                 count5++;
//             }else if(bills[i]==10){
//                 count10++;
//                 if(count5>=1){
//                     return true;
//                     count5--;
//                 }
//             }
//             else if(bills[i] == 20){
//                 count20++;
//                 if(count5>=3){
//                     return true;
//                     count5 = count5 - 3;
//                 }else if (count5>=1 && count10>=1){
//                     return true;
//                     count5 = count5-1;
//                     count10 = count10-1;
//                 }
//             }
//             else return false;
//         }
//     }
// };

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;
        int n = bills.size();

        for(int i=0;i<n;i++){
            if(bills[i]==5){
                count5++;
            }
            else if(bills[i]==10){
                if(count5>=1){
                    count5--;
                    count10++;
                } else {
                    return false;
                }
            }
            else if(bills[i]==20){
                if(count5>=1 && count10>=1){
                    count5--;
                    count10--;
                } else if(count5>=3){
                    count5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};