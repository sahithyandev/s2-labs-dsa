#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */
int twoStacks(int maxSum, vector<int> a, vector<int> b)
{
	int count = 0;
	int sum = 0;
	int a_index = 0;
	int b_index = 0;
	int n = a.size();
	int m = b.size();

	// Add elements from stack a
	while (a_index < n && sum + a[a_index] <= maxSum)
	{
		sum += a[a_index];
		a_index++;
		count++;
	}

	int maxCount = count;

	// Try to add elements from stack b
	while (b_index < m && a_index >= 0)
	{
		sum += b[b_index];
		b_index++;

		// Remove elements from stack a if sum exceeds maxSum
		while (sum > maxSum && a_index > 0)
		{
			a_index--;
			sum -= a[a_index];
		}

		if (sum > maxSum && a_index == 0)
		{
			break;
		}

		maxCount = max(maxCount, a_index + b_index);
	}

	return maxCount;
}

int main()
{

	string g_temp;
	getline(cin, g_temp);

	int g = stoi(ltrim(rtrim(g_temp)));

	for (int g_itr = 0; g_itr < g; g_itr++)
	{
		string first_multiple_input_temp;
		getline(cin, first_multiple_input_temp);

		vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

		int n = stoi(first_multiple_input[0]);

		int m = stoi(first_multiple_input[1]);

		int maxSum = stoi(first_multiple_input[2]);

		string a_temp_temp;
		getline(cin, a_temp_temp);

		vector<string> a_temp = split(rtrim(a_temp_temp));

		vector<int> a(n);

		for (int i = 0; i < n; i++)
		{
			int a_item = stoi(a_temp[i]);

			a[i] = a_item;
		}

		string b_temp_temp;
		getline(cin, b_temp_temp);

		vector<string> b_temp = split(rtrim(b_temp_temp));

		vector<int> b(m);

		for (int i = 0; i < m; i++)
		{
			int b_item = stoi(b_temp[i]);

			b[i] = b_item;
		}

		int result = twoStacks(maxSum, a, b);

		cout << result << "\n";
	}

	return 0;
}

string ltrim(const string &str)
{
	string s(str);

	s.erase(
			s.begin(),
			find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

	return s;
}

string rtrim(const string &str)
{
	string s(str);

	s.erase(
			find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
			s.end());

	return s;
}

vector<string> split(const string &str)
{
	vector<string> tokens;

	string::size_type start = 0;
	string::size_type end = 0;

	while ((end = str.find(" ", start)) != string::npos)
	{
		tokens.push_back(str.substr(start, end - start));

		start = end + 1;
	}

	tokens.push_back(str.substr(start));

	return tokens;
}
