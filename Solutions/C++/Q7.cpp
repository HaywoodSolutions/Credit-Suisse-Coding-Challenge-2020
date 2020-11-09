#include <bits/stdc++.h>

using namespace std;

int has(vector<int> s, int val) {
	return find(s.begin(), s.end(), val) != s.end();
}

string findSuspiciousUserId(int numOfQuestions, vector<vector<int>> questionAndAnswerVecOfVec) {	
  vector<bool> flagged(numOfQuestions);
	for (int q=0; q<numOfQuestions; q++)
		flagged[q] = false;

	for (int q=0; q<numOfQuestions; q++)
		for (int aId=0; aId<questionAndAnswerVecOfVec[q].size(); aId++) {
			int answerer = questionAndAnswerVecOfVec[q][aId];
			if (has(questionAndAnswerVecOfVec[answerer], q))
        flagged[q] = flagged[answerer] = true;
		}

	bool foundOne = true;
	while (foundOne) {
		foundOne = false;
		
		for (int q=0; q<numOfQuestions; q++) {
			if (!flagged[q]) {
				int count = 0;
				for (int child : questionAndAnswerVecOfVec[q])
					if (flagged[child])
						count++;
				if (count >= 2)
					flagged[q] = foundOne = true;
			}
		}
	}

	string str = "";
	bool doneFirst;
	for (int q=0; q<numOfQuestions; q++)
		if (flagged[q]) {
			if (doneFirst)
				str += ",";
			str += to_string(q+1);
			doneFirst = true;
		}

	return str;
}

vector<string> split(const string& str, char delim) {
  vector<string> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
      end = str.find(delim, start);
      strings.push_back(str.substr(start, end - start));
  }
  return strings;
}

vector<int> splitStringToInt(const string& str, char delim) {
  vector<int> strings;
  size_t start;
  size_t end = 0;
  while ((start = str.find_first_not_of(delim, end)) != string::npos) {
    end = str.find(delim, start);
    strings.push_back(stoi(str.substr(start, end - start)) - 1);
  }
  return strings;
}

int main() {
  string firstLine;
  getline(cin, firstLine);

  int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);;

  string questionAndAnswerStr;
  getline(cin, questionAndAnswerStr);

  vector<vector<int>> questionAndAnswerVecOfVec;
  vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

  for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin(); i != questionAndAnswerVecByComma.end(); ++i) {
    vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
		bankerPreferenceVecByAnd.erase (bankerPreferenceVecByAnd.begin(), bankerPreferenceVecByAnd.begin() + 1);
    questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
  }

  string result = findSuspiciousUserId(numOfQuestions, questionAndAnswerVecOfVec);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line

  return 0;
}
