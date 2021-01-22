/*******************************************************************************
 * Title:
 *     989. Add to Array-Form of Integer
 *     989. 数组形式的整数加法
 * Address: 
 *     https://leetcode-cn.com/problems/add-to-array-form-of-integer/
 ******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> arr;
        while ( K > 0 ) {
            arr.push_back( K % 10 );
            K /= 10;
        }
        reverse( arr.begin(), arr.end() );

        if ( A.size() < arr.size() ) {
            swap( A, arr );
        }

        int n1 = A.size() - 1, n2 = arr.size() - 1;
        int flag = 0;
        int sum = 0;

        while ( n1 >= 0 ) {
            if ( n2 >= 0 ) {
                sum = A[n1] + arr[n2] + flag;
            }
            else {
                sum = A[n1] + flag;
            }

            A[n1] = sum % 10;
            flag = sum / 10;

            --n1; --n2;
        }

        if ( flag == 1 ) {
            A.insert( A.begin(), 1 );
        }

        return A;
    }
};

// 方法二：
class Solution_2 {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        string str_k = to_string( K );

        vector<int> res;
        int i = A.size() - 1, j = str_k.size() - 1;
        int flag = 0;

        while ( i >= 0 || j >= 0 || flag ) {
            int x = i >= 0 ? A[i] : 0;
            int y = j >= 0 ? str_k[j] - '0' : 0;
            int sum = x + y + flag;

            res.push_back( sum % 10 );
            flag = sum / 10;

            --i; --j;
        }

        reverse( res.begin(), res.end() );

        return res;
    }
};

int main()
{
    

    return 0;
}