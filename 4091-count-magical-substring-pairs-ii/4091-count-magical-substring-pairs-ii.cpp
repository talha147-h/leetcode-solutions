#include <string>
#include <vector>
#include <array>

using namespace std;

class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.length();
        
        // L[j][c] stores the number of valid starting positions i 
        // such that substring s[i..j] contains exactly c distinct characters.
        vector<array<int, 27>> L(n);
        
        int list[26];
        int list_sz = 0;
        int last_idx[26];
        for (int i = 0; i < 26; i++) last_idx[i] = -1;
        
        // Forward Pass: Calculate distinct character counts for all s[i..j]
        for (int j = 0; j < n; ++j) {
            int c = s[j] - 'a';
            
            // Find character 'c' in the ordered list
            int pos = -1;
            for (int i = 0; i < list_sz; ++i) {
                if (list[i] == c) {
                    pos = i;
                    break;
                }
            }
            
            // Shift elements right to make room at the front
            if (pos != -1) {
                for (int i = pos; i > 0; --i) {
                    list[i] = list[i - 1];
                }
            } else {
                for (int i = list_sz; i > 0; --i) {
                    list[i] = list[i - 1];
                }
                list_sz++;
            }
            
            // Put current character at the front (largest index in forward pass)
            list[0] = c;
            last_idx[c] = j;
            
            // Store frequencies using the naturally sorted intervals
            for (int i = 0; i < list_sz; ++i) {
                int curr_idx = last_idx[list[i]];
                int next_idx = (i + 1 < list_sz) ? last_idx[list[i + 1]] : -1;
                L[j][i + 1] = curr_idx - next_idx;
            }
        }
        
        long long ans = 0;
        int r_list[26];
        int r_list_sz = 0;
        int first_idx[26];
        for (int i = 0; i < 26; i++) first_idx[i] = n;
        
        // Reverse Pass: Map out choices dynamically for s[j+1..k] and calculate `ans`
        for (int j = n - 2; j >= 0; --j) {
            int jp = j + 1; 
            int c = s[jp] - 'a';
            
            // Find character 'c' in the ordered reverse list
            int pos = -1;
            for (int i = 0; i < r_list_sz; ++i) {
                if (r_list[i] == c) {
                    pos = i;
                    break;
                }
            }
            
            // Shift elements right to make room at the front
            if (pos != -1) {
                for (int i = pos; i > 0; --i) {
                    r_list[i] = r_list[i - 1];
                }
            } else {
                for (int i = r_list_sz; i > 0; --i) {
                    r_list[i] = r_list[i - 1];
                }
                r_list_sz++;
            }
            
            // Put current character at the front (smallest index in reverse pass)
            r_list[0] = c;
            first_idx[c] = jp;
            
            // Calculate valid lengths and multiply by the forward pass mappings
            for (int i = 0; i < r_list_sz; ++i) {
                int curr_idx = first_idx[r_list[i]];
                int next_idx = (i + 1 < r_list_sz) ? first_idx[r_list[i + 1]] : n;
                
                int distinct = i + 1;
                ans += 1LL * L[j][distinct] * (next_idx - curr_idx);
            }
        }
        
        return ans;
    }
};