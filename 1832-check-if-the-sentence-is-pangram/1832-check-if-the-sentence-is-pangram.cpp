class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> checkPangram(26, 0);
        int size = sentence.size();
        for (int i = 0; i < size; i++) {
            checkPangram[sentence[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (checkPangram[i] == 0)
                return false;
        }

        return true;
    }
};