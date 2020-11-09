#include <bits/stdc++.h>
using namespace std;

int calculateMinimumSession(int numOfBankers, int numOfParticipants, vector<vector<int>> bankersPreferences, vector<vector<int>> participantsPreferences) {
	vector<set<int>> bankersPreferences2(numOfBankers);
	vector<set<int>> participantsPreferences2(numOfParticipants);

	for (int b=0; b<numOfBankers; b++)
		for (int p : bankersPreferences[b]) {
			bankersPreferences2[b].insert(p-1);
			participantsPreferences2[p-1].insert(b);
		}
    
	for (int p=0; p<numOfParticipants; p++)
		for (int b : participantsPreferences[p]) {
			bankersPreferences2[b-1].insert(p);
			participantsPreferences2[p].insert(b-1);
		}
  
	int maxValue = 0;
	for (int i=0; i<numOfBankers; i++) {
		int size = bankersPreferences2[i].size();
		if (size > maxValue)
			maxValue = size;
	}

	for (int i=0; i<numOfParticipants; i++) {
		int size = participantsPreferences2[i].size();
		if (size > maxValue)
			maxValue = size;
	}

	return maxValue;
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
    strings.push_back(stoi(str.substr(start, end - start)));
  }
  return strings;
}

int main() {
  int numOfBankers, numOfParticipants;
  vector<vector<int>> bankersPreferences;
  vector<vector<int>> participantsPreferences;
  cin >> numOfBankers;
  string bankersPreferencesStr;
  cin >> bankersPreferencesStr;
  vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');
  for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin(); i != bankersPreferencesVecByComma.end(); ++i) {
    vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
    bankersPreferences.push_back(bankerPreferenceVecByAnd);
  }
  string participantsPreferencesStr;
  cin >> numOfParticipants;
  cin >> participantsPreferencesStr;
  vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');
  for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin(); i != participantsPreferencesVecByComma.end(); ++i) {
    vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
    participantsPreferences.push_back(participantPreferenceVecByAnd);
  }
  int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);

  // Do not remove below line
  cout << result << "\n";
  // Do not print anything after this line
  return 0;
}