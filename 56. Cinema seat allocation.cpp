/*
A cinema has n rows of seats, numbered from 1 to n and there are ten seats in each row, 
labelled from 1 to 10 as shown in the figure above.

Given the array reservedSeats containing the numbers of seats already reserved, for example, 
reservedSeats[i] = [3,8] means the seat located in row 3 and labelled with 8 is already reserved.

Return the maximum number of four-person groups you can assign on the cinema seats. A four-person group 
occupies four adjacent seats in one single row. Seats across an aisle (such as [3,3] and [3,4]) are not 
considered to be adjacent, but there is an exceptional case on which an aisle split a four-person group, 
in that case, the aisle split a four-person group in the middle, which means to have two people on each side.
*/

//code:

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> reserved;

        for(auto& r : reservedSeats)
            reserved[r[0]] += 1 << (r[1] - 1); 
        
        int ans = 2 * (n - reserved.size());

        for(auto [r, s] : reserved) {
            int seat25 = s & 0b0111100000;
            int seat47 = s & 0b0001111000;
            int seat69 = s & 0b0000011110;

            if(seat25 == 0 && seat69 == 0) ans += 2;
            else if(seat25 == 0 || seat47 == 0 || seat69 == 0) ans += 1;
        }
        return ans;
    }
};
