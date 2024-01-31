/*
You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.

For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
The score of si is the length of the longest common prefix between si and sn (Note that s == sn).

Given the final string s, return the sum of the score of every si.

*/

//code:

#define MAXN 100010

class Solution {
	int Z[MAXN];

	void getZarr(string str, int Z[]){
		int n = str.length();
		int L, R, k;

		Z[0] = n;

		L = R = 0;
		for (int i = 1; i < n; ++i){
			if (i > R){
				L = R = i;

				while (R < n && str[R - L] == str[R])
					R++;
				Z[i] = R - L;
				R--;
			}else{
				k = i - L;

				if (Z[k] < R - i + 1)
					Z[i] = Z[k];
				else{
					L = i;
					while (R < n && str[R - L] == str[R])
						R++;
					Z[i] = R - L;
					R--;
				}
			}
		}
	}

public:
	long long sumScores(string s) {
		long long n = s.length(), i, j, k, ans = 0;
		getZarr(s, Z);
		for (i = 0; i < n; i++)
    {
      ans += Z[i];
    }
		return ans;
	}
};
